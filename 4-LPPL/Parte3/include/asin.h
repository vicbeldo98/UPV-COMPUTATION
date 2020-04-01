/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_ASIN_H_INCLUDED
# define YY_YY_ASIN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    STRUCT_ = 258,
    READ_ = 259,
    PRINT_ = 260,
    INT_ = 261,
    ABRIRPARENTESIS_ = 262,
    CERRARPARENTESIS_ = 263,
    ABRIRBRACKETS_ = 264,
    CERRARBRACKETS_ = 265,
    ABRIRCORCHETES_ = 266,
    CERRARCORCHETES_ = 267,
    PUNTO_ = 268,
    PUNTOYCOMA_ = 269,
    BOOL_ = 270,
    TRUE_ = 271,
    FALSE_ = 272,
    IF_ = 273,
    ELSE_ = 274,
    WHILE_ = 275,
    CTE_ = 276,
    OPMOD_ = 277,
    OPDIV_ = 278,
    OPMULT_ = 279,
    OPEXCL_ = 280,
    OPRESTA_ = 281,
    OPSUMA_ = 282,
    OPINCREMENTO_ = 283,
    OPDECREMENTO_ = 284,
    OPOR_ = 285,
    OPAND_ = 286,
    OPDIF_ = 287,
    OPIGU_ = 288,
    OPMAIG_ = 289,
    OPMA_ = 290,
    OPMEIG_ = 291,
    OPMEN_ = 292,
    OPDIVASIG_ = 293,
    OPMULTASIG_ = 294,
    OPRESTASIG_ = 295,
    OPSUMASIG_ = 296,
    OPASIG_ = 297,
    ID_ = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "src/asin.y" /* yacc.c:1909  */

  int cent;
  char *str;
  LC lc;
  EXP exp;
  FLUJO flujo;

#line 106 "asin.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASIN_H_INCLUDED  */
