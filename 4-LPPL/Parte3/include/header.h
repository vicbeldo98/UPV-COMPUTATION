/*****************************************************************************/
/*****************************************************************************/
#ifndef _HEADER_H
#define _HEADER_H

/****************************************************** Constantes generales */
#define TRUE  1
#define FALSE 0
#define TALLA_TIPO_SIMPLE 1
#define T_ENTLOG 999
#define EAND 998
#define EOR 997



typedef struct lcampos{
    int ref;
    int talla;
} LC;

typedef struct exp{
    int tipo;
    int pos;
} EXP;

typedef struct flujo{
    int condicion;
    int salto;
} FLUJO;

/******************************* Variableexternas definidas en las librerias */
extern int si;


/************************************* Variables externas definidas en el AL */
extern int yylex();
extern int yyparse();

extern FILE *yyin;
extern int   yylineno;
/********************************* Funciones y variables externas auxiliares */
extern int verbosidad;                   /* Flag si se desea una traza       */
extern int verTDS;

extern void yyerror(const char * msg) ;      /* Tratamiento de errores       */

#endif  /* _HEADER_H */
/*****************************************************************************/
/*****************************************************************************/
