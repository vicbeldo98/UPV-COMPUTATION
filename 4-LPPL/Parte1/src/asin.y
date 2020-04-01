/*****************************************************************************/
/**  Analizador Sintactico       2019-2020 <vicbeldo@inf.upv.es> **/
/*****************************************************************************/
%{
#include <stdio.h>
#include <string.h>
#include "header.h"
%}

%token IF_ ELSE_ STRUCT_ READ_ PRINT_ WHILE_ INT_ BOOL_ TRUE_ FALSE_
%token CTE_ ID_

%token ABRIRPARENTESIS_ CERRARPARENTESIS_ ABRIRBRACKETS_ CERRARBRACKETS_
%token ABRIRCORCHETES_ CERRARCORCHETES_ PUNTO_ PUNTOYCOMA_

%token OPDIVASIG_ OPMULTASIG_ OPRESTASIG_ OPSUMASIG_ OPASIG_
%token OPOR_ OPAND_ OPDIF_ OPIGU_ OPMAIG_ OPMA_ OPMEIG_ OPMEN_

%token OPMOD_ OPDIV_ OPMULT_ OPEXCL_ OPRESTA_ OPSUMA_
%token OPINCREMENTO_ OPDECREMENTO_

%%

programa	: ABRIRBRACKETS_ secuenciaSentencias CERRARBRACKETS_
		;

secuenciaSentencias	: sentencia
		| secuenciaSentencias sentencia
		;

sentencia	: declaracion
		| instruccion
		;

declaracion	: tipoSimple ID_ PUNTOYCOMA_
		| tipoSimple ID_ OPASIG_ constante PUNTOYCOMA_
		| tipoSimple ID_ ABRIRCORCHETES_ CTE_ CERRARCORCHETES_ PUNTOYCOMA_
		| STRUCT_ ABRIRBRACKETS_ listaCampos CERRARBRACKETS_ ID_ PUNTOYCOMA_
		;

tipoSimple	: INT_
		| BOOL_
		;

listaCampos	: tipoSimple ID_ PUNTOYCOMA_
		| listaCampos tipoSimple ID_ PUNTOYCOMA_
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
		| PRINT_ ABRIRPARENTESIS_ expresion CERRARPARENTESIS_ PUNTOYCOMA_
		;

instruccionSeleccion	: IF_ ABRIRPARENTESIS_ expresion CERRARPARENTESIS_ instruccion 
		ELSE_ instruccion
		;

instruccionIteracion	: WHILE_ ABRIRPARENTESIS_ expresion CERRARPARENTESIS_ instruccion
		;

instruccionExpresion	: expresion PUNTOYCOMA_
		| PUNTOYCOMA_
		;

expresion	: expresionLogica
		| ID_ operadorAsignacion expresion
		| ID_ ABRIRCORCHETES_ expresion CERRARCORCHETES_ operadorAsignacion expresion
		| ID_ PUNTO_ ID_ operadorAsignacion expresion
		;

expresionLogica	: expresionIgualdad
		| expresionLogica operadorLogico expresionIgualdad
		;

expresionIgualdad	: expresionRelacional
		| expresionIgualdad operadorIgualdad expresionRelacional
		;

expresionRelacional	: expresionAditiva
		| expresionRelacional operadorRelacional expresionAditiva
		;

expresionAditiva	: expresionMultiplicativa
		| expresionAditiva operadorAditivo	expresionMultiplicativa
		;

expresionMultiplicativa	: expresionUnaria
		| expresionMultiplicativa operadorMultiplicativo expresionUnaria
		;

expresionUnaria	: expresionSufija
		| operadorUnario expresionUnaria
		| operadorIncremento ID_
		;

expresionSufija	: ABRIRPARENTESIS_ expresion CERRARPARENTESIS_
		| ID_ operadorIncremento
		| ID_ ABRIRCORCHETES_ expresion CERRARCORCHETES_
		| ID_
		| ID_ PUNTO_ ID_
		| constante
		;

constante	: CTE_
		| TRUE_
		| FALSE_
		;

operadorAsignacion	: OPASIG_
		| OPSUMASIG_
		| OPRESTASIG_
		| OPMULTASIG_
		| OPDIVASIG_
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
		| OPRESTA_
		| OPEXCL_
		;

operadorIncremento	: OPINCREMENTO_
		| OPDECREMENTO_
		;

%%
