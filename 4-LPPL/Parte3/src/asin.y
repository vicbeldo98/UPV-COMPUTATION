/*****************************************************************************/
/**  Analizador Sintactico       2019-2020 <vicbeldo@inf.upv.es> **/
/*****************************************************************************/
%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libtds.h"
#include "libgci.h"
%}

%union{
  int cent;
  char *str;
  LC lc;
  EXP exp;
  FLUJO flujo;
}

%token STRUCT_ READ_ PRINT_ INT_

%token ABRIRPARENTESIS_ CERRARPARENTESIS_ ABRIRBRACKETS_ CERRARBRACKETS_
%token ABRIRCORCHETES_ CERRARCORCHETES_ PUNTO_ PUNTOYCOMA_
%token BOOL_ TRUE_ FALSE_ IF_ ELSE_ WHILE_

%token <cent> CTE_ OPMOD_ OPDIV_ OPMULT_ OPEXCL_ OPRESTA_ OPSUMA_ OPINCREMENTO_ OPDECREMENTO_ OPOR_ OPAND_ OPDIF_ OPIGU_ OPMAIG_ OPMA_ OPMEIG_ OPMEN_
%token <cent> OPDIVASIG_ OPMULTASIG_ OPRESTASIG_ OPSUMASIG_ OPASIG_
%token <str> ID_
%type <cent> tipoSimple operadorAditivo operadorAsignacion operadorIgualdad operadorIncremento
%type <cent> operadorLogico operadorMultiplicativo operadorRelacional operadorUnario
%type <lc> listaCampos
%type <exp> expresion expresionLogica expresionAditiva expresionIgualdad expresionMultiplicativa
%type <exp> expresionRelacional expresionSufija expresionUnaria constante


%%

programa	: 
		{ 
			dvar=0; 
			si=0;
		}
        ABRIRBRACKETS_ secuenciaSentencias CERRARBRACKETS_
		{ if(verTDS) verTdS(); }
		;

secuenciaSentencias	: sentencia
		| secuenciaSentencias sentencia
		;

sentencia	: declaracion
		| instruccion
		;

declaracion	: tipoSimple ID_ PUNTOYCOMA_
		{
			if( ! insTdS($2, $1, dvar, -1))
				yyerror("Identificador repetido");
			else {
				dvar += TALLA_TIPO_SIMPLE;
			}
		}
		| tipoSimple ID_ OPASIG_ constante PUNTOYCOMA_
		{
			if( $1!=$4.tipo){
				yyerror("Tipo no compatible");
			}
			else if( ! insTdS($2, $1, dvar, -1)){
				yyerror("Identificador repetido");
			}
			else {
				dvar += TALLA_TIPO_SIMPLE;
			}
			SIMB sim=obtTdS($2);
			emite(EASIG,crArgPos($4.pos),crArgNul(),crArgPos(sim.desp));
		}
		| tipoSimple ID_ ABRIRCORCHETES_ CTE_ CERRARCORCHETES_ PUNTOYCOMA_
		{
			//int numelem = $4;
			if($4<=0){
				yyerror("Talla inapropiada del array");
				//numelem=0;
			}
			else{
				int refe = insTdA($1, $4);
				if(!insTdS($2,T_ARRAY, dvar, refe)){
					yyerror("Identificador repetido");
				}
				else{
					dvar+=TALLA_TIPO_SIMPLE * $4;
				}
			}
		}
		| STRUCT_ ABRIRBRACKETS_ listaCampos CERRARBRACKETS_ ID_ PUNTOYCOMA_
		{
			if(!insTdS($5,T_RECORD,dvar,$3.ref)){
				yyerror("Identificador repetido");
			}
			else{
				dvar+=$3.talla;
			}
		}
		;

tipoSimple	: INT_
		{
			$$ = T_ENTERO;
		}
		| BOOL_
		{
			$$ = T_LOGICO;
		}
		;

listaCampos	: tipoSimple ID_ PUNTOYCOMA_
		{
			$$.ref=insTdR(-1,$2,$1,0);
			$$.talla=TALLA_TIPO_SIMPLE;
		}
		| listaCampos tipoSimple ID_ PUNTOYCOMA_
		{
			if(insTdR($1.ref,$3,$2,$1.talla)==-1){
				yyerror("Campo repetido");
			}
			else{
				$$.ref=$1.ref;
				$$.talla=$1.talla + TALLA_TIPO_SIMPLE;
			}

		}
		;

instruccion	: ABRIRBRACKETS_ CERRARBRACKETS_
		| ABRIRBRACKETS_ listaInstrucciones CERRARBRACKETS_
		| instruccionEntradaSalida
		| instruccionSeleccion
		| instruccionIteracion
		| instruccionExpresion
		;

listaInstrucciones	: instruccion
		| listaInstrucciones instruccion
		;

instruccionEntradaSalida	: READ_ ABRIRPARENTESIS_ ID_ CERRARPARENTESIS_ PUNTOYCOMA_
		{
			SIMB sim=obtTdS($3);
			if(sim.tipo==T_ERROR) yyerror("El argumento del 'read' debe estar declarado");
			else if (sim.tipo!= T_ENTERO) yyerror("El argumento del 'read' debe ser 'entero'");
			emite(EREAD,crArgNul(),crArgNul(),crArgPos(sim.desp));
		}
		| PRINT_ ABRIRPARENTESIS_ expresion CERRARPARENTESIS_ PUNTOYCOMA_
		{
			if($3.tipo==T_ERROR){}
			else if($3.tipo!=T_ENTERO){ yyerror("La expresion del 'print' debe ser 'entera'");}
			emite(EWRITE,crArgNul(),crArgNul(),crArgPos($3.pos));
		}
		;

instruccionSeleccion	: IF_ ABRIRPARENTESIS_ expresion CERRARPARENTESIS_
		{
			if($3.tipo==T_ERROR){}
			else if($3.tipo!=T_LOGICO){ yyerror("La expresion del 'if' debe ser 'logica'");}
			$<flujo>$.condicion=creaLans(si);
			emite(EIGUAL,crArgPos($3.pos),crArgEnt(FALSE),crArgEtq(-1));
		}
		instruccion
		{
			$<flujo>5.salto=creaLans(si);
			emite(GOTOS,crArgNul(),crArgNul(),crArgEtq(-1));
			completaLans($<flujo>5.condicion, crArgEtq(si));
		}
		ELSE_ instruccion
		{
			completaLans($<flujo>5.salto,crArgEtq(si));
		}
		;

instruccionIteracion	: WHILE_ 
		{
			$<flujo>$.salto=si;
		}
		ABRIRPARENTESIS_ expresion CERRARPARENTESIS_
		{
			if($4.tipo==T_ERROR){}
			else if($4.tipo!=T_LOGICO) yyerror("La expresion del 'while' debe ser 'logica'");
			$<flujo>2.condicion=creaLans(si);
			emite(EIGUAL,crArgPos($4.pos),crArgEnt(FALSE),crArgEtq(-1));
		}
		instruccion
		{
			emite(GOTOS,crArgNul(),crArgNul(),crArgEtq($<flujo>2.salto));
			completaLans($<flujo>2.condicion,crArgEtq(si));
		}
		;

instruccionExpresion	: expresion PUNTOYCOMA_
		| PUNTOYCOMA_
		;

expresion	: expresionLogica
		{
			$$=$1;
		}
		| ID_ operadorAsignacion expresion
		{
			$$.tipo=T_ERROR;
			SIMB sim=obtTdS($1);
			if($3.tipo==T_ERROR){}
			else if(sim.tipo==T_ERROR) yyerror("Objeto no declarado");
			else if (! (((sim.tipo == $3.tipo) == T_ENTERO) ||
						((sim.tipo == $3.tipo) == T_LOGICO)))
				yyerror("Error de tipos en la 'asignacion'");
				else $$.tipo=sim.tipo;
			$$.pos=creaVarTemp();
			if($2==EASIG) emite($2,crArgPos($3.pos),crArgNul(),crArgPos(sim.desp));
			else emite($2,crArgPos(sim.desp),crArgPos($3.pos),crArgPos(sim.desp));
			// Porque 'expresion' es utilizado en otras reglas
			// por lo tanto puede necesitar .pos
			emite(EASIG,crArgPos(sim.desp),crArgNul(),crArgPos($$.pos));
		}
		| ID_ ABRIRCORCHETES_ expresion CERRARCORCHETES_ operadorAsignacion expresion
		{
			$$.tipo=T_ERROR;
			SIMB sim=obtTdS($1);
			if($6.tipo==T_ERROR){}
			else if (sim.tipo==T_ERROR) yyerror("Objeto no declarado");
			else if (sim.tipo != T_ARRAY) yyerror("El identificador debe ser de tipo 'array'");
			else if ($3.tipo != T_ENTERO) yyerror("El indice del 'array' debe ser entero");
			else{
				DIM dim=obtTdA(sim.ref);
				if( dim.telem != $6.tipo) yyerror("Error de tipos en la 'asignacion'");
				else
					$$.tipo = dim.telem;
			}
			emite(EMULT,crArgPos($3.pos),crArgEnt(TALLA_TIPO_SIMPLE),crArgPos($3.pos));
					$$.pos=creaVarTemp();
			if($5==EASIG) {
				emite(EVA,crArgPos(sim.desp),crArgPos($3.pos),crArgPos($6.pos));
			}
			else{
				emite(EAV,crArgPos(sim.desp),crArgPos($3.pos),crArgPos($$.pos));
				emite($5,crArgPos($$.pos),crArgPos($6.pos),crArgPos($$.pos));
				emite(EVA,crArgPos(sim.desp),crArgPos($3.pos),crArgPos($$.pos));
			}
			emite(EAV,crArgPos(sim.desp),crArgPos($3.pos),crArgPos($$.pos));

		}
		| ID_ PUNTO_ ID_ operadorAsignacion expresion
		{
			$$.tipo=T_ERROR;
			SIMB sim=obtTdS($1);
			if($5.tipo==T_ERROR){}
			else if (sim.tipo==T_ERROR) yyerror("Objeto no declarado");
			else if (sim.tipo != T_RECORD) yyerror("El identificador debe ser 'struct'");
			else{
				CAMP camp=obtTdR(sim.ref,$3);
				if (camp.tipo == T_ERROR ) yyerror("Campo no declarado");
				else if ( camp.tipo != $5.tipo ) yyerror("Error de tipos en la 'asignacion'");
				else{
					$$.tipo= camp.tipo;
				}
			}
			CAMP camp2=obtTdR(sim.ref,$3);
			int pos=sim.desp+camp2.desp;
			$$.pos=creaVarTemp();
			if($4==EASIG) {
				emite(EASIG,crArgPos($5.pos),crArgNul(),crArgPos(pos));
			}
			else{
				emite($4,crArgPos(pos),crArgPos($5.pos),crArgPos(pos));
			}
			emite(EASIG,crArgPos(pos),crArgNul(),crArgPos($$.pos));
		}
		;

expresionLogica	: expresionIgualdad
		{
			$$=$1;
		}
		| expresionLogica operadorLogico expresionIgualdad
		{
			$$.tipo=T_ERROR;
			if($1.tipo!=T_ERROR && $3.tipo!=T_ERROR){
				if($1.tipo!=$3.tipo || $1.tipo!=T_LOGICO){
					yyerror("Error en 'expresion logica'");
				}
				else{
					$$.tipo=T_LOGICO;
				}
			}
			$$.pos=creaVarTemp();
			if($2==EAND){
				emite(EMULT,crArgPos($1.pos),crArgPos($3.pos),crArgPos($$.pos));
			}
			else{
				emite(ESUM,crArgPos($1.pos),crArgPos($3.pos),crArgPos($$.pos));
				emite(EMENEQ,crArgPos($$.pos),crArgEnt(1),crArgEtq(si+2));
				emite(EASIG,crArgEnt(TRUE),crArgNul(),crArgPos($$.pos));
			}
		}
		;

expresionIgualdad	: expresionRelacional
		{
			$$=$1;
		}
		| expresionIgualdad operadorIgualdad expresionRelacional
		{
			$$.tipo=T_ERROR;
			if($1.tipo!=T_ERROR && $3.tipo!=T_ERROR){
				if($1.tipo!=$3.tipo || $1.tipo==T_ARRAY || $1.tipo==T_RECORD || $1.tipo == T_VACIO){
					yyerror("Error en 'expresion igualdad'");
				}
				else{
					$$.tipo=T_LOGICO;
				}
			}
			$$.pos=creaVarTemp();
			emite(EASIG,crArgEnt(TRUE),crArgNul(),crArgPos($$.pos));
			emite($2,crArgPos($1.pos),crArgPos($3.pos),crArgEtq(si+2));
			emite(EASIG,crArgEnt(FALSE),crArgNul(),crArgPos($$.pos));
		}
		;

expresionRelacional	: expresionAditiva
		{
			$$=$1;;
		}
		| expresionRelacional operadorRelacional expresionAditiva
		{
			$$.tipo=T_ERROR;
			if($1.tipo!=T_ERROR && $3.tipo!=T_ERROR){
				if($1.tipo!=$3.tipo || $1.tipo!=T_ENTERO){
					yyerror("Error en 'expresion relacional'");
				}
				else{
					$$.tipo=T_LOGICO;
				}
			}
			$$.pos=creaVarTemp();
			emite(EASIG,crArgEnt(TRUE),crArgNul(),crArgPos($$.pos));
			emite($2,crArgPos($1.pos),crArgPos($3.pos),crArgEtq(si+2));
			emite(EASIG,crArgEnt(FALSE),crArgNul(),crArgPos($$.pos));
		}
		;

expresionAditiva	: expresionMultiplicativa
		{
			$$=$1;
		}
		| expresionAditiva operadorAditivo expresionMultiplicativa
		{
			$$.tipo=T_ERROR;
			if($1.tipo==T_ERROR || $3.tipo==T_ERROR){}
			else if(! (($1.tipo==$3.tipo)==T_ENTERO)) yyerror("Error en 'expresion aditiva'");
			else $$.tipo = $1.tipo;
			//Si hay error igual no va a ejecutar este codigo
			$$.pos=creaVarTemp();
			emite($2,crArgPos($1.pos),crArgPos($3.pos),crArgPos($$.pos));

		}
		;

expresionMultiplicativa	: expresionUnaria
		{
			$$=$1;
		}
		| expresionMultiplicativa operadorMultiplicativo expresionUnaria
		{
			$$.tipo=T_ERROR;
			if($1.tipo!=T_ERROR && $3.tipo!=T_ERROR){
				if($1.tipo!=$3.tipo || $1.tipo!=T_ENTERO){
					yyerror("Error en 'expresion multiplicativa'");
				}
				else{
					$$.tipo=T_ENTERO;
				}
			}
			$$.pos=creaVarTemp();
			emite($2,crArgPos($1.pos),crArgPos($3.pos),crArgPos($$.pos));
		}
		;

expresionUnaria	: expresionSufija
		{
			$$=$1;
		}
		| operadorUnario expresionUnaria
		{
			$$.tipo=T_ERROR;
			if($2.tipo==T_ERROR){}
			else if(($1==ESUM||$1==EDIF) && $2.tipo!=T_ENTERO) yyerror("Error en 'expresion unaria'");
			else if($1==EDIST && $2.tipo!=T_ENTERO){
				if($2.tipo!=T_LOGICO) {
					yyerror("Error en 'expresion unaria'");
				}
			}
			else $$.tipo=$2.tipo;
			$$.pos=creaVarTemp();
			if($1==EDIST){
				//AQUI SE HACE LA NEGACION
				emite(EDIF,crArgEnt(1),crArgPos($2.pos),crArgPos($$.pos));
			}
			else if($1==EDIF){
				emite(ESIG,crArgPos($2.pos),crArgNul(),crArgPos($$.pos));
			}

		}
		| operadorIncremento ID_
		{
			$$.tipo=T_ERROR;
			SIMB sim=obtTdS($2);
			if(sim.tipo==T_ERROR) yyerror("Objeto no declarado");
			else if ( sim.tipo != T_ENTERO) yyerror("El identificador debe ser entero");
			else{
				$$.tipo=sim.tipo;
			}
			$$.pos=creaVarTemp();
			emite($1,crArgPos(sim.desp),crArgEnt(1),crArgPos($$.pos));
			emite(EASIG,crArgPos($$.pos),crArgNul(),crArgPos(sim.desp));

		}
		;

expresionSufija	: ABRIRPARENTESIS_ expresion CERRARPARENTESIS_
		{
			$$=$2;
		}
		| ID_ operadorIncremento
		{
			$$.tipo=T_ERROR;
			SIMB sim=obtTdS($1);
			if(sim.tipo==T_ERROR) yyerror("Objeto no declarado");
			else if ( sim.tipo != T_ENTERO) yyerror("Objeto debe ser de tipo entero");
			else{
				$$.tipo=sim.tipo;
			}
			$$.pos=creaVarTemp();
			emite(EASIG,crArgPos(sim.desp),crArgNul(),crArgPos($$.pos));
			emite($2,crArgPos(sim.desp),crArgEnt(1),crArgPos(sim.desp));
		}
		| ID_ ABRIRCORCHETES_ expresion CERRARCORCHETES_
		{
			$$.tipo=T_ERROR;
			SIMB sim=obtTdS($1);
			if(sim.tipo==T_ERROR) yyerror("Objeto no declarado");
			else if ( sim.tipo != T_ARRAY) yyerror("El identificador debe ser de tipo 'array'");
			else if ( $3.tipo != T_ENTERO ) yyerror("El índice del 'array' debe ser entero");
			else{
				DIM dim=obtTdA(sim.ref);
				$$.tipo = dim.telem;
			}
			emite(EMULT,crArgPos($3.pos),crArgEnt(TALLA_TIPO_SIMPLE),crArgPos($3.pos));
			$$.pos=creaVarTemp();
			emite(EAV,crArgPos(sim.desp),crArgPos($3.pos),crArgPos($$.pos));

		}
		| ID_
		{
			$$.tipo=T_ERROR;
			SIMB sim=obtTdS($1);
			if(sim.tipo==T_ERROR) yyerror("Objeto no declarado");
			else $$.tipo=sim.tipo;
			$$.pos=creaVarTemp();
			emite(EASIG,crArgPos(sim.desp),crArgNul(),crArgPos($$.pos));
		}
		| ID_ PUNTO_ ID_
		{
			$$.tipo=T_ERROR;
			SIMB sim=obtTdS($1);
			if(sim.tipo==T_ERROR) yyerror("Objeto no declarado");
			else if (sim.tipo != T_RECORD) yyerror("El identificador debe ser de tipo 'struct'");
			else{
				CAMP camp=obtTdR(sim.ref,$3);
				if (camp.tipo == T_ERROR ) yyerror("Campo no declarado");
				else $$.tipo=camp.tipo;
			}
			CAMP camp2=obtTdR(sim.ref,$3);
			int pos=sim.desp+camp2.desp;
			$$.pos=creaVarTemp();
			emite(EASIG,crArgPos(pos),crArgNul(),crArgPos($$.pos));

		}
		| constante
		{
			$$.tipo = $1.tipo;
			$$.pos=creaVarTemp();
			emite(EASIG,crArgPos($1.pos),crArgNul(),crArgPos($$.pos));
		}
		;

constante	: CTE_
		{
			$$.tipo = T_ENTERO;
			$$.pos=creaVarTemp();
			emite(EASIG,crArgEnt($1),crArgNul(),crArgPos($$.pos));
		}
		| TRUE_
		{
			$$.tipo = T_LOGICO;
			$$.pos=creaVarTemp();
			emite(EASIG,crArgEnt(TRUE),crArgNul(),crArgPos($$.pos));
		}
		| FALSE_
		{
			$$.tipo = T_LOGICO;
			$$.pos=creaVarTemp();
			emite(EASIG,crArgEnt(FALSE),crArgNul(),crArgPos($$.pos));
		}
		;

operadorAsignacion	: OPASIG_
		{
			$$=EASIG;
		}
		| OPSUMASIG_
		{
			$$=ESUM;
		}
		| OPRESTASIG_
		{
			$$=EDIF;
		}
		| OPMULTASIG_
		{
			$$=EMULT;
		}
		| OPDIVASIG_
		{
			$$=EDIVI;
		}
		;

operadorLogico	: OPAND_
		{
			$$=EAND;
		}
		| OPOR_
		{
			$$=EOR;
		}
		;

operadorIgualdad	: OPIGU_
		{
			$$=EIGUAL;
		}
		| OPDIF_
		{
			$$=EDIST;
		}
		;
operadorRelacional	: OPMA_
		{
			$$=EMAY;
		}
		| OPMEN_
		{
			$$=EMEN;
		}
		| OPMAIG_
		{
			$$=EMAYEQ;
		}
		| OPMEIG_
		{
			$$=EMENEQ;
		}
		;

operadorAditivo	: OPSUMA_
		{
			$$=ESUM;
		}
		| OPRESTA_
		{
			$$=EDIF;
		}
		;

operadorMultiplicativo	: OPMULT_
		{
			$$= EMULT;
		}
		| OPDIV_
		{
			$$=EDIVI;
		}
		| OPMOD_
		{
			$$=RESTO;
		}
		;

operadorUnario	: OPSUMA_
		{
			$$=ESUM;
		}
		| OPRESTA_
		{
			$$=EDIF;
		}
		| OPEXCL_
		{
			$$=EDIST;
		}
		;

operadorIncremento	: OPINCREMENTO_
		{
			$$=ESUM;
		}
		| OPDECREMENTO_
		{
			$$=EDIF;
		}
		;

%%
