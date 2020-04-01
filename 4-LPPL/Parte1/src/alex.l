/*****************************************************************************/
/**  Analizador lexico            2019-2020 <vicbeldo@inf.upv.es> **/
/*****************************************************************************/
%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "asin.h"

#define  retornar(x) {if (verbosidad) ECHO; return(x);}
%}
/*-----------------------------------------------------------------------------
  Estas opciones evitan "warnings" innecesarios y permiten obtener el
  numero de linea actual en la variable global "yylineno".
-----------------------------------------------------------------------------*/
%option noinput
%option nounput
%option yylineno

letraMayus		[A-Z]
letraMinus		[a-z]
delimitador		[ \t\n]+
digito			[0-9]
entero			{digito}+
real				{entero}[.]{entero}|[.]{entero}|{entero}[.]
comentario		[/][/].*[\n]
id					{letraMinus}({letraMinus}|{letraMayus}|{digito}|[_])*|{letraMayus}({letraMinus}|{letraMayus}|{digito}|[_])*
%%


{delimitador}  { if (verbosidad) ECHO; }
{comentario}	{ if (verbosidad) ECHO; }
"if"				{ retornar(IF_);}
"else"			{ retornar(ELSE_);}
"struct"			{ retornar(STRUCT_);}
"read"			{ retornar(READ_);}
"print"			{ retornar(PRINT_);}
"while"			{ retornar(WHILE_);}
"int"				{ retornar(INT_);}
"bool"			{ retornar(BOOL_);}
"("				{ retornar(ABRIRPARENTESIS_);}
")"				{ retornar(CERRARPARENTESIS_);}
"{"				{ retornar(ABRIRBRACKETS_);}
"}"				{ retornar(CERRARBRACKETS_);}
"["				{ retornar(ABRIRCORCHETES_);}
"]"				{ retornar(CERRARCORCHETES_);}
"."				{ retornar(PUNTO_);}
";"				{ retornar(PUNTOYCOMA_);}
"true"			{ retornar(TRUE_);}
"false"			{ retornar(FALSE_);}
"/="				{ retornar(OPDIVASIG_);}
"*="				{ retornar(OPMULTASIG_);}
"-="				{ retornar(OPRESTASIG_);}
"+="				{ retornar(OPSUMASIG_);}
"||"				{ retornar(OPOR_);}
"&&"				{ retornar(OPAND_);}
"!="				{ retornar(OPDIF_);}
">="				{ retornar(OPMAIG_);}
">"				{ retornar(OPMA_);}
"<="				{ retornar(OPMEIG_);}
"<"				{ retornar(OPMEN_);}
"%"				{ retornar(OPMOD_);}
"/"				{ retornar(OPDIV_);}
"*"				{ retornar(OPMULT_);}
"!"				{ retornar (OPEXCL_);}
"++"				{ retornar (OPINCREMENTO_);}
"+"				{ retornar (OPSUMA_);}
"--"				{ retornar (OPDECREMENTO_);}
"-"				{ retornar (OPRESTA_);}
"=="				{ retornar(OPIGU_);}
"="				{ retornar(OPASIG_);}
{entero}  		{ retornar (CTE_);}
{real}   		{ retornar (CTE_);}
{id}     		{ retornar (ID_);}
.	       		{ yyerror("Caracter desconocido"); }

%%

