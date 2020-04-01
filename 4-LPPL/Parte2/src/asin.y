/*****************************************************************************/
/**  Analizador Sintactico       2019-2020 <vicbeldo@inf.upv.es> **/
/*****************************************************************************/
%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libtds.h"
%}

%union{
  int cent;
  char *str;
  LC lc;
  EXP exp;
}

%token STRUCT_ READ_ PRINT_ INT_

%token ABRIRPARENTESIS_ CERRARPARENTESIS_ ABRIRBRACKETS_ CERRARBRACKETS_
%token ABRIRCORCHETES_ CERRARCORCHETES_ PUNTO_ PUNTOYCOMA_

%token OPDIVASIG_ OPMULTASIG_ OPRESTASIG_ OPSUMASIG_ OPASIG_
%token OPOR_ OPAND_ OPDIF_ OPIGU_ OPMAIG_ OPMA_ OPMEIG_ OPMEN_

%token OPMOD_ OPDIV_ OPMULT_ OPEXCL_ OPRESTA_ OPSUMA_
%token OPINCREMENTO_ OPDECREMENTO_
%token BOOL_ TRUE_ FALSE_ IF_ ELSE_ WHILE_

%token <cent> CTE_ 
%token <str> ID_ 
%type <cent> tipoSimple constante operadorUnario operadorAsignacion
%type <lc> listaCampos
%type <exp> expresion expresionLogica expresionAditiva expresionIgualdad expresionMultiplicativa
%type <exp> expresionRelacional expresionSufija expresionUnaria


%%

programa	: { dvar=0; }
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
			if( $1!=$4){
				yyerror("Tipo no compatible");
			}
			else if( ! insTdS($2, $1, dvar, -1)){ 
				yyerror("Identificador repetido");
			}
			else {
				dvar += TALLA_TIPO_SIMPLE;
			}
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
							}
		| PRINT_ ABRIRPARENTESIS_ expresion CERRARPARENTESIS_ PUNTOYCOMA_
		{
			if($3.tipo==T_ERROR){}
			else if($3.tipo!=T_ENTERO){ yyerror("La expresion del 'print' debe ser 'entera'");}
		}
		;

instruccionSeleccion	: IF_ ABRIRPARENTESIS_ expresion CERRARPARENTESIS_
						{
							if($3.tipo==T_ERROR){}
							else if($3.tipo!=T_LOGICO){ yyerror("La expresion del 'if' debe ser 'logica'");}
						}
						  instruccion
		ELSE_ instruccion
		;

instruccionIteracion	: WHILE_ ABRIRPARENTESIS_ expresion CERRARPARENTESIS_ 
						{
							if($3.tipo==T_ERROR){}
							else if($3.tipo!=T_LOGICO){ yyerror("La expresion del 'while' debe ser 'logica'");}
						}
						instruccion
						
		;

instruccionExpresion	: expresion PUNTOYCOMA_
		| PUNTOYCOMA_
		;

expresion	: expresionLogica
		{
			$$.tipo=$1.tipo;
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
			else if ($3.tipo==T_LOGICO && $2!=T_ENTLOG) yyerror("Error de tipos de operador en 'asignacion'");
			else $$.tipo=sim.tipo;

		}
		| ID_ ABRIRCORCHETES_ expresion CERRARCORCHETES_ operadorAsignacion expresion
		{
			$$.tipo=T_ERROR;
			SIMB sim=obtTdS($1);
			if($6.tipo==T_ERROR){}
			else if (sim.tipo==T_ERROR) yyerror("Objeto no declarado");
			else if (sim.tipo != T_ARRAY) yyerror("El identificador debe ser de tipo 'array'");
			else if ($3.tipo != T_ENTERO) yyerror("El indice del 'array' debe ser entero");
			else if ($6.tipo==T_LOGICO && $5!=T_ENTLOG) yyerror("Error de tipos de operador en 'asignacion'");
			else{
				DIM dim=obtTdA(sim.ref);
				if( dim.telem != $6.tipo) yyerror("Error de tipos en la 'asignacion'");
				else 
					$$.tipo = dim.telem;
			}

		}
		| ID_ PUNTO_ ID_ operadorAsignacion expresion
		{
			$$.tipo=T_ERROR;
			SIMB sim=obtTdS($1);
			if($5.tipo==T_ERROR){}
			else if (sim.tipo==T_ERROR) yyerror("Objeto no declarado");
			else if (sim.tipo != T_RECORD) yyerror("El identificador debe ser 'struct'");
			else if($5.tipo==T_LOGICO && $4!=T_ENTLOG) yyerror("Error de tipos de operador en 'asignacion'");
			else{
				CAMP camp=obtTdR(sim.ref,$3);
				if (camp.tipo == T_ERROR ) yyerror("Campo no declarado");
				else if ( camp.tipo != $5.tipo ) yyerror("Error de tipos en la 'asignacion'");
				else{
					$$.tipo= camp.tipo;
				}
			}
		}
		;

expresionLogica	: expresionIgualdad
		{
			$$.tipo= $1.tipo;
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
		}
		;

expresionIgualdad	: expresionRelacional
		{
			$$.tipo= $1.tipo;
		}
		| expresionIgualdad operadorIgualdad expresionRelacional
		{
			$$.tipo=T_ERROR;
			if($1.tipo!=T_ERROR && $3.tipo!=T_ERROR){
				if($1.tipo!=$3.tipo){
					yyerror("Error en 'expresion igualdad'");
				}
				else if($1.tipo!=T_ENTERO && $1.tipo!=T_LOGICO) yyerror("Error en 'expresion igualdad'");
				else{
					if($1.tipo == T_LOGICO)$$.tipo=T_LOGICO;
					else $$.tipo=T_ENTERO;
				}
			}
		}
		;

expresionRelacional	: expresionAditiva
		{
			$$.tipo= $1.tipo;
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
		}
		;

expresionAditiva	: expresionMultiplicativa
		{
			$$.tipo= $1.tipo;
		}
		| expresionAditiva operadorAditivo expresionMultiplicativa
		{
			$$.tipo=T_ERROR;
			if($1.tipo==T_ERROR || $3.tipo==T_ERROR){}
			else if(! (($1.tipo==$3.tipo)==T_ENTERO)) yyerror("Error en 'expresion aditiva'");
			else $$.tipo = $1.tipo;

		}
		;

expresionMultiplicativa	: expresionUnaria
		{
			$$.tipo= $1.tipo;
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
		}
		;

expresionUnaria	: expresionSufija
		{
			$$.tipo= $1.tipo;
		}
		| operadorUnario expresionUnaria
		{
			$$.tipo=T_ERROR;
			if($2.tipo==T_ERROR){}
			else if($1!=$2.tipo) yyerror("Error en 'expresion unaria'");
			else $$.tipo=$2.tipo;
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
		}
		;

expresionSufija	: ABRIRPARENTESIS_ expresion CERRARPARENTESIS_
		{
			$$.tipo=$2.tipo;
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
		}
		| ID_
		{
			$$.tipo=T_ERROR;
			SIMB sim=obtTdS($1);
			if(sim.tipo==T_ERROR) yyerror("Objeto no declarado");
			else $$.tipo=sim.tipo;
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
		}
		| constante
		{
			$$.tipo = $1;
		}
		;

constante	: CTE_
		{
			$$ = T_ENTERO;
		}
		| TRUE_
		{
			$$ = T_LOGICO;
		}
		| FALSE_
		{
			$$ = T_LOGICO;
		}
		;

operadorAsignacion	: OPASIG_
		{
			$$=T_ENTLOG;
		}
		| OPSUMASIG_
		{
			$$=T_ENTERO;
		}
		| OPRESTASIG_
		{
			$$=T_ENTERO;
		}
		| OPMULTASIG_
		{
			$$=T_ENTERO;
		}
		| OPDIVASIG_
		{
			$$=T_ENTERO;
		}
		;

operadorLogico	: OPAND_
		| OPOR_
		;

operadorIgualdad	: OPIGU_
		| OPDIF_
		;
operadorRelacional	: OPMA_
		| OPMEN_
		| OPMAIG_
		| OPMEIG_
		;

operadorAditivo	: OPSUMA_
		| OPRESTA_
		;

operadorMultiplicativo	: OPMULT_
		| OPDIV_
		| OPMOD_
		;

operadorUnario	: OPSUMA_
		{
			$$=T_ENTERO;
		}
		| OPRESTA_
		{
			$$=T_ENTERO;
		}
		| OPEXCL_
		{
			$$=T_LOGICO;
		}
		;

operadorIncremento	: OPINCREMENTO_
		| OPDECREMENTO_
		;

%%
