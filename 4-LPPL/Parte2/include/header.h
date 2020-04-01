/*****************************************************************************/
/*****************************************************************************/
#ifndef _HEADER_H
#define _HEADER_H

/****************************************************** Constantes generales */
#define TRUE  1
#define FALSE 0
#define TALLA_TIPO_SIMPLE 1
#define T_ENTLOG 6



typedef struct lcampos{
    int ref;
    int talla;
} LC;

typedef struct exp{
    int tipo;
    int valor;   
} EXP;


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
