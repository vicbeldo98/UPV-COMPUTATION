/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 4 "src/asin.y" /* yacc.c:339  */

#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libtds.h"
#include "libgci.h"

#line 74 "asin.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "asin.h".  */
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
#line 12 "src/asin.y" /* yacc.c:355  */

  int cent;
  char *str;
  LC lc;
  EXP exp;
  FLUJO flujo;

#line 166 "asin.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASIN_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 183 "asin.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   236

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    39,    39,    39,    47,    48,    51,    52,    55,    63,
      77,    94,   105,   109,   115,   120,   133,   134,   135,   136,
     137,   138,   141,   142,   145,   152,   161,   168,   160,   180,
     184,   179,   197,   198,   201,   205,   222,   249,   277,   281,
     304,   308,   326,   330,   348,   352,   365,   369,   385,   389,
     410,   426,   430,   443,   459,   468,   485,   493,   499,   505,
     513,   517,   521,   525,   529,   535,   539,   545,   549,   554,
     558,   562,   566,   572,   576,   582,   586,   590,   596,   600,
     604,   610,   614
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRUCT_", "READ_", "PRINT_", "INT_",
  "ABRIRPARENTESIS_", "CERRARPARENTESIS_", "ABRIRBRACKETS_",
  "CERRARBRACKETS_", "ABRIRCORCHETES_", "CERRARCORCHETES_", "PUNTO_",
  "PUNTOYCOMA_", "BOOL_", "TRUE_", "FALSE_", "IF_", "ELSE_", "WHILE_",
  "CTE_", "OPMOD_", "OPDIV_", "OPMULT_", "OPEXCL_", "OPRESTA_", "OPSUMA_",
  "OPINCREMENTO_", "OPDECREMENTO_", "OPOR_", "OPAND_", "OPDIF_", "OPIGU_",
  "OPMAIG_", "OPMA_", "OPMEIG_", "OPMEN_", "OPDIVASIG_", "OPMULTASIG_",
  "OPRESTASIG_", "OPSUMASIG_", "OPASIG_", "ID_", "$accept", "programa",
  "$@1", "secuenciaSentencias", "sentencia", "declaracion", "tipoSimple",
  "listaCampos", "instruccion", "listaInstrucciones",
  "instruccionEntradaSalida", "instruccionSeleccion", "@2", "$@3",
  "instruccionIteracion", "@4", "$@5", "instruccionExpresion", "expresion",
  "expresionLogica", "expresionIgualdad", "expresionRelacional",
  "expresionAditiva", "expresionMultiplicativa", "expresionUnaria",
  "expresionSufija", "constante", "operadorAsignacion", "operadorLogico",
  "operadorIgualdad", "operadorRelacional", "operadorAditivo",
  "operadorMultiplicativo", "operadorUnario", "operadorIncremento", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF -81

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-81)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -81,     6,     4,   -81,    50,     7,    17,    30,   -81,   170,
      87,   -81,   -81,   -81,   -81,    32,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   142,     5,   -81,   -81,     1,   -81,   -81,
     -81,   -81,   -81,    44,    -2,     9,   123,    34,    27,   -81,
     -81,   -81,   193,    19,    12,    26,   170,    65,   -81,   -81,
     119,   170,    75,   170,    40,   -81,   -81,   -81,   -81,   -81,
     170,   -81,   -81,   -81,    -7,   -81,   -81,   -81,   193,   -81,
     -81,   193,   -81,   -81,   -81,   -81,   193,   -81,   -81,   193,
     -81,   -81,   -81,   193,    61,   -81,   -81,    41,    96,    78,
      80,   -81,   -81,   -81,    90,   170,    83,   163,   -81,    79,
     -81,    64,     9,   123,    34,    27,   -81,   170,    67,   104,
      76,    77,   108,   111,   -81,   126,   163,   170,   129,   117,
     130,   -81,   -81,   124,   135,   -81,   -81,   147,   -81,   170,
     -81,   136,   -81,   -81,   -81,   -81,   -81,   147,   -81,   -81,
     150,   -81,   147,   -81
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     0,    12,     0,
       0,    33,    13,    58,    59,     0,    29,    57,    80,    79,
      78,    81,    82,    54,     0,     4,     6,     0,     7,    18,
      19,    20,    21,     0,    34,    38,    40,    42,    44,    46,
      48,    56,     0,     0,     0,     0,     0,     0,    16,    22,
       0,     0,     0,     0,     0,    64,    63,    62,    61,    60,
       0,    52,     3,     5,     0,    32,    66,    65,     0,    68,
      67,     0,    71,    69,    72,    70,     0,    74,    73,     0,
      77,    76,    75,     0,    54,    49,    50,     0,     0,     0,
       0,    51,    17,    23,     0,     0,     0,    55,    35,     0,
       8,     0,    39,    41,    43,    45,    47,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    53,     0,     0,     0,
       0,    55,    14,     0,     0,    24,    25,     0,    30,     0,
      37,     0,     9,    53,    11,    15,    27,     0,    36,    10,
       0,    31,     0,    28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -81,   -81,   -81,   -81,   154,   -81,   -41,   -81,   -10,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,    -8,   -81,
      98,    72,   103,   106,   -37,   -81,    88,   -80,   -81,   -81,
     -81,   -81,   -81,   -81,   -21
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    24,    25,    26,    27,    88,    28,    50,
      29,    30,   127,   140,    31,    52,   137,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    60,    68,    71,
      76,    79,    83,    42,    43
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      49,    47,    61,    87,    99,    85,     3,   100,     5,     6,
       7,     8,     9,     4,    10,    62,    44,   117,     8,    11,
      12,    13,    14,    15,    45,    16,    17,    12,    66,    67,
      18,    19,    20,    21,    22,   101,   129,    46,    90,    51,
      93,    69,    70,    94,    64,    96,   106,   111,    23,    80,
      81,    82,    98,     5,     6,     7,     8,     9,    65,    10,
      77,    78,    86,    61,    11,    12,    13,    14,    15,    89,
      16,    17,   107,    91,   108,    18,    19,    20,    21,    22,
      13,    14,    95,    97,   109,    17,   112,   115,   113,    21,
      22,     6,     7,    23,     9,   116,    10,    48,   114,   120,
     118,    11,     8,    13,    14,    15,   110,    16,    17,   130,
     121,    12,    18,    19,    20,    21,    22,   136,   122,   123,
     124,   138,   125,     6,     7,   126,     9,   141,    10,    92,
      23,   132,   143,    11,   128,    13,    14,    15,   134,    16,
      17,   131,   133,   103,    18,    19,    20,    21,    22,   135,
     139,     6,     7,    53,     9,    54,    10,    72,    73,    74,
      75,    11,    23,    13,    14,    15,   102,    16,    17,   142,
      21,    22,    18,    19,    20,    21,    22,     9,    63,   104,
      55,    56,    57,    58,    59,   105,    13,    14,     0,   119,
      23,    17,     0,     0,     0,    18,    19,    20,    21,    22,
       9,    55,    56,    57,    58,    59,     0,     0,     0,    13,
      14,     0,     0,    23,    17,     0,     0,     0,    18,    19,
      20,    21,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84
};

static const yytype_int16 yycheck[] =
{
      10,     9,    23,    44,    11,    42,     0,    14,     3,     4,
       5,     6,     7,     9,     9,    10,     9,    97,     6,    14,
      15,    16,    17,    18,     7,    20,    21,    15,    30,    31,
      25,    26,    27,    28,    29,    42,   116,     7,    46,     7,
      50,    32,    33,    51,    43,    53,    83,    88,    43,    22,
      23,    24,    60,     3,     4,     5,     6,     7,    14,     9,
      26,    27,    43,    84,    14,    15,    16,    17,    18,    43,
      20,    21,    11,     8,    13,    25,    26,    27,    28,    29,
      16,    17,     7,    43,    43,    21,     8,    95,     8,    28,
      29,     4,     5,    43,     7,    12,     9,    10,     8,   107,
      21,    14,     6,    16,    17,    18,    10,    20,    21,   117,
      43,    15,    25,    26,    27,    28,    29,   127,    14,    43,
      43,   129,    14,     4,     5,    14,     7,   137,     9,    10,
      43,    14,   142,    14,     8,    16,    17,    18,    14,    20,
      21,    12,    12,    71,    25,    26,    27,    28,    29,    14,
      14,     4,     5,    11,     7,    13,     9,    34,    35,    36,
      37,    14,    43,    16,    17,    18,    68,    20,    21,    19,
      28,    29,    25,    26,    27,    28,    29,     7,    24,    76,
      38,    39,    40,    41,    42,    79,    16,    17,    -1,   101,
      43,    21,    -1,    -1,    -1,    25,    26,    27,    28,    29,
       7,    38,    39,    40,    41,    42,    -1,    -1,    -1,    16,
      17,    -1,    -1,    43,    21,    -1,    -1,    -1,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    46,     0,     9,     3,     4,     5,     6,     7,
       9,    14,    15,    16,    17,    18,    20,    21,    25,    26,
      27,    28,    29,    43,    47,    48,    49,    50,    52,    54,
      55,    58,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    77,    78,     9,     7,     7,    62,    10,    52,
      53,     7,    59,    11,    13,    38,    39,    40,    41,    42,
      71,    78,    10,    48,    43,    14,    30,    31,    72,    32,
      33,    73,    34,    35,    36,    37,    74,    26,    27,    75,
      22,    23,    24,    76,    43,    68,    43,    50,    51,    43,
      62,     8,    10,    52,    62,     7,    62,    43,    62,    11,
      14,    42,    64,    65,    66,    67,    68,    11,    13,    43,
      10,    50,     8,     8,     8,    62,    12,    71,    21,    70,
      62,    43,    14,    43,    43,    14,    14,    56,     8,    71,
      62,    12,    14,    12,    14,    14,    52,    60,    62,    14,
      57,    52,    19,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    46,    45,    47,    47,    48,    48,    49,    49,
      49,    49,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    52,    53,    53,    54,    54,    56,    57,    55,    59,
      60,    58,    61,    61,    62,    62,    62,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      68,    69,    69,    69,    69,    69,    69,    70,    70,    70,
      71,    71,    71,    71,    71,    72,    72,    73,    73,    74,
      74,    74,    74,    75,    75,    76,    76,    76,    77,    77,
      77,    78,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     4,     1,     2,     1,     1,     3,     5,
       6,     6,     1,     1,     3,     4,     2,     3,     1,     1,
       1,     1,     1,     2,     5,     5,     0,     0,     9,     0,
       0,     7,     2,     1,     1,     3,     6,     5,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     2,
       2,     3,     2,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 39 "src/asin.y" /* yacc.c:1646  */
    { 
			dvar=0; 
			si=0;
		}
#line 1392 "asin.c" /* yacc.c:1646  */
    break;

  case 3:
#line 44 "src/asin.y" /* yacc.c:1646  */
    { if(verTDS) verTdS(); }
#line 1398 "asin.c" /* yacc.c:1646  */
    break;

  case 8:
#line 56 "src/asin.y" /* yacc.c:1646  */
    {
			if( ! insTdS((yyvsp[-1].str), (yyvsp[-2].cent), dvar, -1))
				yyerror("Identificador repetido");
			else {
				dvar += TALLA_TIPO_SIMPLE;
			}
		}
#line 1410 "asin.c" /* yacc.c:1646  */
    break;

  case 9:
#line 64 "src/asin.y" /* yacc.c:1646  */
    {
			if( (yyvsp[-4].cent)!=(yyvsp[-1].exp).tipo){
				yyerror("Tipo no compatible");
			}
			else if( ! insTdS((yyvsp[-3].str), (yyvsp[-4].cent), dvar, -1)){
				yyerror("Identificador repetido");
			}
			else {
				dvar += TALLA_TIPO_SIMPLE;
			}
			SIMB sim=obtTdS((yyvsp[-3].str));
			emite(EASIG,crArgPos((yyvsp[-1].exp).pos),crArgNul(),crArgPos(sim.desp));
		}
#line 1428 "asin.c" /* yacc.c:1646  */
    break;

  case 10:
#line 78 "src/asin.y" /* yacc.c:1646  */
    {
			//int numelem = $4;
			if((yyvsp[-2].cent)<=0){
				yyerror("Talla inapropiada del array");
				//numelem=0;
			}
			else{
				int refe = insTdA((yyvsp[-5].cent), (yyvsp[-2].cent));
				if(!insTdS((yyvsp[-4].str),T_ARRAY, dvar, refe)){
					yyerror("Identificador repetido");
				}
				else{
					dvar+=TALLA_TIPO_SIMPLE * (yyvsp[-2].cent);
				}
			}
		}
#line 1449 "asin.c" /* yacc.c:1646  */
    break;

  case 11:
#line 95 "src/asin.y" /* yacc.c:1646  */
    {
			if(!insTdS((yyvsp[-1].str),T_RECORD,dvar,(yyvsp[-3].lc).ref)){
				yyerror("Identificador repetido");
			}
			else{
				dvar+=(yyvsp[-3].lc).talla;
			}
		}
#line 1462 "asin.c" /* yacc.c:1646  */
    break;

  case 12:
#line 106 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent) = T_ENTERO;
		}
#line 1470 "asin.c" /* yacc.c:1646  */
    break;

  case 13:
#line 110 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent) = T_LOGICO;
		}
#line 1478 "asin.c" /* yacc.c:1646  */
    break;

  case 14:
#line 116 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.lc).ref=insTdR(-1,(yyvsp[-1].str),(yyvsp[-2].cent),0);
			(yyval.lc).talla=TALLA_TIPO_SIMPLE;
		}
#line 1487 "asin.c" /* yacc.c:1646  */
    break;

  case 15:
#line 121 "src/asin.y" /* yacc.c:1646  */
    {
			if(insTdR((yyvsp[-3].lc).ref,(yyvsp[-1].str),(yyvsp[-2].cent),(yyvsp[-3].lc).talla)==-1){
				yyerror("Campo repetido");
			}
			else{
				(yyval.lc).ref=(yyvsp[-3].lc).ref;
				(yyval.lc).talla=(yyvsp[-3].lc).talla + TALLA_TIPO_SIMPLE;
			}

		}
#line 1502 "asin.c" /* yacc.c:1646  */
    break;

  case 24:
#line 146 "src/asin.y" /* yacc.c:1646  */
    {
			SIMB sim=obtTdS((yyvsp[-2].str));
			if(sim.tipo==T_ERROR) yyerror("El argumento del 'read' debe estar declarado");
			else if (sim.tipo!= T_ENTERO) yyerror("El argumento del 'read' debe ser 'entero'");
			emite(EREAD,crArgNul(),crArgNul(),crArgPos(sim.desp));
		}
#line 1513 "asin.c" /* yacc.c:1646  */
    break;

  case 25:
#line 153 "src/asin.y" /* yacc.c:1646  */
    {
			if((yyvsp[-2].exp).tipo==T_ERROR){}
			else if((yyvsp[-2].exp).tipo!=T_ENTERO){ yyerror("La expresion del 'print' debe ser 'entera'");}
			emite(EWRITE,crArgNul(),crArgNul(),crArgPos((yyvsp[-2].exp).pos));
		}
#line 1523 "asin.c" /* yacc.c:1646  */
    break;

  case 26:
#line 161 "src/asin.y" /* yacc.c:1646  */
    {
			if((yyvsp[-1].exp).tipo==T_ERROR){}
			else if((yyvsp[-1].exp).tipo!=T_LOGICO){ yyerror("La expresion del 'if' debe ser 'logica'");}
			(yyval.flujo).condicion=creaLans(si);
			emite(EIGUAL,crArgPos((yyvsp[-1].exp).pos),crArgEnt(FALSE),crArgEtq(-1));
		}
#line 1534 "asin.c" /* yacc.c:1646  */
    break;

  case 27:
#line 168 "src/asin.y" /* yacc.c:1646  */
    {
			(yyvsp[-1].flujo).salto=creaLans(si);
			emite(GOTOS,crArgNul(),crArgNul(),crArgEtq(-1));
			completaLans((yyvsp[-1].flujo).condicion, crArgEtq(si));
		}
#line 1544 "asin.c" /* yacc.c:1646  */
    break;

  case 28:
#line 174 "src/asin.y" /* yacc.c:1646  */
    {
			completaLans((yyvsp[-4].flujo).salto,crArgEtq(si));
		}
#line 1552 "asin.c" /* yacc.c:1646  */
    break;

  case 29:
#line 180 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.flujo).salto=si;
		}
#line 1560 "asin.c" /* yacc.c:1646  */
    break;

  case 30:
#line 184 "src/asin.y" /* yacc.c:1646  */
    {
			if((yyvsp[-1].exp).tipo==T_ERROR){}
			else if((yyvsp[-1].exp).tipo!=T_LOGICO) yyerror("La expresion del 'while' debe ser 'logica'");
			(yyvsp[-3].flujo).condicion=creaLans(si);
			emite(EIGUAL,crArgPos((yyvsp[-1].exp).pos),crArgEnt(FALSE),crArgEtq(-1));
		}
#line 1571 "asin.c" /* yacc.c:1646  */
    break;

  case 31:
#line 191 "src/asin.y" /* yacc.c:1646  */
    {
			emite(GOTOS,crArgNul(),crArgNul(),crArgEtq((yyvsp[-5].flujo).salto));
			completaLans((yyvsp[-5].flujo).condicion,crArgEtq(si));
		}
#line 1580 "asin.c" /* yacc.c:1646  */
    break;

  case 34:
#line 202 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp)=(yyvsp[0].exp);
		}
#line 1588 "asin.c" /* yacc.c:1646  */
    break;

  case 35:
#line 206 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp).tipo=T_ERROR;
			SIMB sim=obtTdS((yyvsp[-2].str));
			if((yyvsp[0].exp).tipo==T_ERROR){}
			else if(sim.tipo==T_ERROR) yyerror("Objeto no declarado");
			else if (! (((sim.tipo == (yyvsp[0].exp).tipo) == T_ENTERO) ||
						((sim.tipo == (yyvsp[0].exp).tipo) == T_LOGICO)))
				yyerror("Error de tipos en la 'asignacion'");
				else (yyval.exp).tipo=sim.tipo;
			(yyval.exp).pos=creaVarTemp();
			if((yyvsp[-1].cent)==EASIG) emite((yyvsp[-1].cent),crArgPos((yyvsp[0].exp).pos),crArgNul(),crArgPos(sim.desp));
			else emite((yyvsp[-1].cent),crArgPos(sim.desp),crArgPos((yyvsp[0].exp).pos),crArgPos(sim.desp));
			// Porque 'expresion' es utilizado en otras reglas
			// por lo tanto puede necesitar .pos
			emite(EASIG,crArgPos(sim.desp),crArgNul(),crArgPos((yyval.exp).pos));
		}
#line 1609 "asin.c" /* yacc.c:1646  */
    break;

  case 36:
#line 223 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp).tipo=T_ERROR;
			SIMB sim=obtTdS((yyvsp[-5].str));
			if((yyvsp[0].exp).tipo==T_ERROR){}
			else if (sim.tipo==T_ERROR) yyerror("Objeto no declarado");
			else if (sim.tipo != T_ARRAY) yyerror("El identificador debe ser de tipo 'array'");
			else if ((yyvsp[-3].exp).tipo != T_ENTERO) yyerror("El indice del 'array' debe ser entero");
			else{
				DIM dim=obtTdA(sim.ref);
				if( dim.telem != (yyvsp[0].exp).tipo) yyerror("Error de tipos en la 'asignacion'");
				else
					(yyval.exp).tipo = dim.telem;
			}
			emite(EMULT,crArgPos((yyvsp[-3].exp).pos),crArgEnt(TALLA_TIPO_SIMPLE),crArgPos((yyvsp[-3].exp).pos));
					(yyval.exp).pos=creaVarTemp();
			if((yyvsp[-1].cent)==EASIG) {
				emite(EVA,crArgPos(sim.desp),crArgPos((yyvsp[-3].exp).pos),crArgPos((yyvsp[0].exp).pos));
			}
			else{
				emite(EAV,crArgPos(sim.desp),crArgPos((yyvsp[-3].exp).pos),crArgPos((yyval.exp).pos));
				emite((yyvsp[-1].cent),crArgPos((yyval.exp).pos),crArgPos((yyvsp[0].exp).pos),crArgPos((yyval.exp).pos));
				emite(EVA,crArgPos(sim.desp),crArgPos((yyvsp[-3].exp).pos),crArgPos((yyval.exp).pos));
			}
			emite(EAV,crArgPos(sim.desp),crArgPos((yyvsp[-3].exp).pos),crArgPos((yyval.exp).pos));

		}
#line 1640 "asin.c" /* yacc.c:1646  */
    break;

  case 37:
#line 250 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp).tipo=T_ERROR;
			SIMB sim=obtTdS((yyvsp[-4].str));
			if((yyvsp[0].exp).tipo==T_ERROR){}
			else if (sim.tipo==T_ERROR) yyerror("Objeto no declarado");
			else if (sim.tipo != T_RECORD) yyerror("El identificador debe ser 'struct'");
			else{
				CAMP camp=obtTdR(sim.ref,(yyvsp[-2].str));
				if (camp.tipo == T_ERROR ) yyerror("Campo no declarado");
				else if ( camp.tipo != (yyvsp[0].exp).tipo ) yyerror("Error de tipos en la 'asignacion'");
				else{
					(yyval.exp).tipo= camp.tipo;
				}
			}
			CAMP camp2=obtTdR(sim.ref,(yyvsp[-2].str));
			int pos=sim.desp+camp2.desp;
			(yyval.exp).pos=creaVarTemp();
			if((yyvsp[-1].cent)==EASIG) {
				emite(EASIG,crArgPos((yyvsp[0].exp).pos),crArgNul(),crArgPos(pos));
			}
			else{
				emite((yyvsp[-1].cent),crArgPos(pos),crArgPos((yyvsp[0].exp).pos),crArgPos(pos));
			}
			emite(EASIG,crArgPos(pos),crArgNul(),crArgPos((yyval.exp).pos));
		}
#line 1670 "asin.c" /* yacc.c:1646  */
    break;

  case 38:
#line 278 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp)=(yyvsp[0].exp);
		}
#line 1678 "asin.c" /* yacc.c:1646  */
    break;

  case 39:
#line 282 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp).tipo=T_ERROR;
			if((yyvsp[-2].exp).tipo!=T_ERROR && (yyvsp[0].exp).tipo!=T_ERROR){
				if((yyvsp[-2].exp).tipo!=(yyvsp[0].exp).tipo || (yyvsp[-2].exp).tipo!=T_LOGICO){
					yyerror("Error en 'expresion logica'");
				}
				else{
					(yyval.exp).tipo=T_LOGICO;
				}
			}
			(yyval.exp).pos=creaVarTemp();
			if((yyvsp[-1].cent)==EAND){
				emite(EMULT,crArgPos((yyvsp[-2].exp).pos),crArgPos((yyvsp[0].exp).pos),crArgPos((yyval.exp).pos));
			}
			else{
				emite(ESUM,crArgPos((yyvsp[-2].exp).pos),crArgPos((yyvsp[0].exp).pos),crArgPos((yyval.exp).pos));
				emite(EMENEQ,crArgPos((yyval.exp).pos),crArgEnt(1),crArgEtq(si+2));
				emite(EASIG,crArgEnt(TRUE),crArgNul(),crArgPos((yyval.exp).pos));
			}
		}
#line 1703 "asin.c" /* yacc.c:1646  */
    break;

  case 40:
#line 305 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp)=(yyvsp[0].exp);
		}
#line 1711 "asin.c" /* yacc.c:1646  */
    break;

  case 41:
#line 309 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp).tipo=T_ERROR;
			if((yyvsp[-2].exp).tipo!=T_ERROR && (yyvsp[0].exp).tipo!=T_ERROR){
				if((yyvsp[-2].exp).tipo!=(yyvsp[0].exp).tipo || (yyvsp[-2].exp).tipo==T_ARRAY || (yyvsp[-2].exp).tipo==T_RECORD || (yyvsp[-2].exp).tipo == T_VACIO){
					yyerror("Error en 'expresion igualdad'");
				}
				else{
					(yyval.exp).tipo=T_LOGICO;
				}
			}
			(yyval.exp).pos=creaVarTemp();
			emite(EASIG,crArgEnt(TRUE),crArgNul(),crArgPos((yyval.exp).pos));
			emite((yyvsp[-1].cent),crArgPos((yyvsp[-2].exp).pos),crArgPos((yyvsp[0].exp).pos),crArgEtq(si+2));
			emite(EASIG,crArgEnt(FALSE),crArgNul(),crArgPos((yyval.exp).pos));
		}
#line 1731 "asin.c" /* yacc.c:1646  */
    break;

  case 42:
#line 327 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp)=(yyvsp[0].exp);;
		}
#line 1739 "asin.c" /* yacc.c:1646  */
    break;

  case 43:
#line 331 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp).tipo=T_ERROR;
			if((yyvsp[-2].exp).tipo!=T_ERROR && (yyvsp[0].exp).tipo!=T_ERROR){
				if((yyvsp[-2].exp).tipo!=(yyvsp[0].exp).tipo || (yyvsp[-2].exp).tipo!=T_ENTERO){
					yyerror("Error en 'expresion relacional'");
				}
				else{
					(yyval.exp).tipo=T_LOGICO;
				}
			}
			(yyval.exp).pos=creaVarTemp();
			emite(EASIG,crArgEnt(TRUE),crArgNul(),crArgPos((yyval.exp).pos));
			emite((yyvsp[-1].cent),crArgPos((yyvsp[-2].exp).pos),crArgPos((yyvsp[0].exp).pos),crArgEtq(si+2));
			emite(EASIG,crArgEnt(FALSE),crArgNul(),crArgPos((yyval.exp).pos));
		}
#line 1759 "asin.c" /* yacc.c:1646  */
    break;

  case 44:
#line 349 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp)=(yyvsp[0].exp);
		}
#line 1767 "asin.c" /* yacc.c:1646  */
    break;

  case 45:
#line 353 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp).tipo=T_ERROR;
			if((yyvsp[-2].exp).tipo==T_ERROR || (yyvsp[0].exp).tipo==T_ERROR){}
			else if(! (((yyvsp[-2].exp).tipo==(yyvsp[0].exp).tipo)==T_ENTERO)) yyerror("Error en 'expresion aditiva'");
			else (yyval.exp).tipo = (yyvsp[-2].exp).tipo;
			//Si hay error igual no va a ejecutar este codigo
			(yyval.exp).pos=creaVarTemp();
			emite((yyvsp[-1].cent),crArgPos((yyvsp[-2].exp).pos),crArgPos((yyvsp[0].exp).pos),crArgPos((yyval.exp).pos));

		}
#line 1782 "asin.c" /* yacc.c:1646  */
    break;

  case 46:
#line 366 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp)=(yyvsp[0].exp);
		}
#line 1790 "asin.c" /* yacc.c:1646  */
    break;

  case 47:
#line 370 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp).tipo=T_ERROR;
			if((yyvsp[-2].exp).tipo!=T_ERROR && (yyvsp[0].exp).tipo!=T_ERROR){
				if((yyvsp[-2].exp).tipo!=(yyvsp[0].exp).tipo || (yyvsp[-2].exp).tipo!=T_ENTERO){
					yyerror("Error en 'expresion multiplicativa'");
				}
				else{
					(yyval.exp).tipo=T_ENTERO;
				}
			}
			(yyval.exp).pos=creaVarTemp();
			emite((yyvsp[-1].cent),crArgPos((yyvsp[-2].exp).pos),crArgPos((yyvsp[0].exp).pos),crArgPos((yyval.exp).pos));
		}
#line 1808 "asin.c" /* yacc.c:1646  */
    break;

  case 48:
#line 386 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp)=(yyvsp[0].exp);
		}
#line 1816 "asin.c" /* yacc.c:1646  */
    break;

  case 49:
#line 390 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp).tipo=T_ERROR;
			if((yyvsp[0].exp).tipo==T_ERROR){}
			else if(((yyvsp[-1].cent)==ESUM||(yyvsp[-1].cent)==EDIF) && (yyvsp[0].exp).tipo!=T_ENTERO) yyerror("Error en 'expresion unaria'");
			else if((yyvsp[-1].cent)==EDIST && (yyvsp[0].exp).tipo!=T_ENTERO){
				if((yyvsp[0].exp).tipo!=T_LOGICO) {
					yyerror("Error en 'expresion unaria'");
				}
			}
			else (yyval.exp).tipo=(yyvsp[0].exp).tipo;
			(yyval.exp).pos=creaVarTemp();
			if((yyvsp[-1].cent)==EDIST){
				//AQUI SE HACE LA NEGACION
				emite(EDIF,crArgEnt(1),crArgPos((yyvsp[0].exp).pos),crArgPos((yyval.exp).pos));
			}
			else if((yyvsp[-1].cent)==EDIF){
				emite(ESIG,crArgPos((yyvsp[0].exp).pos),crArgNul(),crArgPos((yyval.exp).pos));
			}

		}
#line 1841 "asin.c" /* yacc.c:1646  */
    break;

  case 50:
#line 411 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp).tipo=T_ERROR;
			SIMB sim=obtTdS((yyvsp[0].str));
			if(sim.tipo==T_ERROR) yyerror("Objeto no declarado");
			else if ( sim.tipo != T_ENTERO) yyerror("El identificador debe ser entero");
			else{
				(yyval.exp).tipo=sim.tipo;
			}
			(yyval.exp).pos=creaVarTemp();
			emite((yyvsp[-1].cent),crArgPos(sim.desp),crArgEnt(1),crArgPos((yyval.exp).pos));
			emite(EASIG,crArgPos((yyval.exp).pos),crArgNul(),crArgPos(sim.desp));

		}
#line 1859 "asin.c" /* yacc.c:1646  */
    break;

  case 51:
#line 427 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp)=(yyvsp[-1].exp);
		}
#line 1867 "asin.c" /* yacc.c:1646  */
    break;

  case 52:
#line 431 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp).tipo=T_ERROR;
			SIMB sim=obtTdS((yyvsp[-1].str));
			if(sim.tipo==T_ERROR) yyerror("Objeto no declarado");
			else if ( sim.tipo != T_ENTERO) yyerror("Objeto debe ser de tipo entero");
			else{
				(yyval.exp).tipo=sim.tipo;
			}
			(yyval.exp).pos=creaVarTemp();
			emite(EASIG,crArgPos(sim.desp),crArgNul(),crArgPos((yyval.exp).pos));
			emite((yyvsp[0].cent),crArgPos(sim.desp),crArgEnt(1),crArgPos(sim.desp));
		}
#line 1884 "asin.c" /* yacc.c:1646  */
    break;

  case 53:
#line 444 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp).tipo=T_ERROR;
			SIMB sim=obtTdS((yyvsp[-3].str));
			if(sim.tipo==T_ERROR) yyerror("Objeto no declarado");
			else if ( sim.tipo != T_ARRAY) yyerror("El identificador debe ser de tipo 'array'");
			else if ( (yyvsp[-1].exp).tipo != T_ENTERO ) yyerror("El índice del 'array' debe ser entero");
			else{
				DIM dim=obtTdA(sim.ref);
				(yyval.exp).tipo = dim.telem;
			}
			emite(EMULT,crArgPos((yyvsp[-1].exp).pos),crArgEnt(TALLA_TIPO_SIMPLE),crArgPos((yyvsp[-1].exp).pos));
			(yyval.exp).pos=creaVarTemp();
			emite(EAV,crArgPos(sim.desp),crArgPos((yyvsp[-1].exp).pos),crArgPos((yyval.exp).pos));

		}
#line 1904 "asin.c" /* yacc.c:1646  */
    break;

  case 54:
#line 460 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp).tipo=T_ERROR;
			SIMB sim=obtTdS((yyvsp[0].str));
			if(sim.tipo==T_ERROR) yyerror("Objeto no declarado");
			else (yyval.exp).tipo=sim.tipo;
			(yyval.exp).pos=creaVarTemp();
			emite(EASIG,crArgPos(sim.desp),crArgNul(),crArgPos((yyval.exp).pos));
		}
#line 1917 "asin.c" /* yacc.c:1646  */
    break;

  case 55:
#line 469 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp).tipo=T_ERROR;
			SIMB sim=obtTdS((yyvsp[-2].str));
			if(sim.tipo==T_ERROR) yyerror("Objeto no declarado");
			else if (sim.tipo != T_RECORD) yyerror("El identificador debe ser de tipo 'struct'");
			else{
				CAMP camp=obtTdR(sim.ref,(yyvsp[0].str));
				if (camp.tipo == T_ERROR ) yyerror("Campo no declarado");
				else (yyval.exp).tipo=camp.tipo;
			}
			CAMP camp2=obtTdR(sim.ref,(yyvsp[0].str));
			int pos=sim.desp+camp2.desp;
			(yyval.exp).pos=creaVarTemp();
			emite(EASIG,crArgPos(pos),crArgNul(),crArgPos((yyval.exp).pos));

		}
#line 1938 "asin.c" /* yacc.c:1646  */
    break;

  case 56:
#line 486 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp).tipo = (yyvsp[0].exp).tipo;
			(yyval.exp).pos=creaVarTemp();
			emite(EASIG,crArgPos((yyvsp[0].exp).pos),crArgNul(),crArgPos((yyval.exp).pos));
		}
#line 1948 "asin.c" /* yacc.c:1646  */
    break;

  case 57:
#line 494 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp).tipo = T_ENTERO;
			(yyval.exp).pos=creaVarTemp();
			emite(EASIG,crArgEnt((yyvsp[0].cent)),crArgNul(),crArgPos((yyval.exp).pos));
		}
#line 1958 "asin.c" /* yacc.c:1646  */
    break;

  case 58:
#line 500 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp).tipo = T_LOGICO;
			(yyval.exp).pos=creaVarTemp();
			emite(EASIG,crArgEnt(TRUE),crArgNul(),crArgPos((yyval.exp).pos));
		}
#line 1968 "asin.c" /* yacc.c:1646  */
    break;

  case 59:
#line 506 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.exp).tipo = T_LOGICO;
			(yyval.exp).pos=creaVarTemp();
			emite(EASIG,crArgEnt(FALSE),crArgNul(),crArgPos((yyval.exp).pos));
		}
#line 1978 "asin.c" /* yacc.c:1646  */
    break;

  case 60:
#line 514 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)=EASIG;
		}
#line 1986 "asin.c" /* yacc.c:1646  */
    break;

  case 61:
#line 518 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)=ESUM;
		}
#line 1994 "asin.c" /* yacc.c:1646  */
    break;

  case 62:
#line 522 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)=EDIF;
		}
#line 2002 "asin.c" /* yacc.c:1646  */
    break;

  case 63:
#line 526 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)=EMULT;
		}
#line 2010 "asin.c" /* yacc.c:1646  */
    break;

  case 64:
#line 530 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)=EDIVI;
		}
#line 2018 "asin.c" /* yacc.c:1646  */
    break;

  case 65:
#line 536 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)=EAND;
		}
#line 2026 "asin.c" /* yacc.c:1646  */
    break;

  case 66:
#line 540 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)=EOR;
		}
#line 2034 "asin.c" /* yacc.c:1646  */
    break;

  case 67:
#line 546 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)=EIGUAL;
		}
#line 2042 "asin.c" /* yacc.c:1646  */
    break;

  case 68:
#line 550 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)=EDIST;
		}
#line 2050 "asin.c" /* yacc.c:1646  */
    break;

  case 69:
#line 555 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)=EMAY;
		}
#line 2058 "asin.c" /* yacc.c:1646  */
    break;

  case 70:
#line 559 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)=EMEN;
		}
#line 2066 "asin.c" /* yacc.c:1646  */
    break;

  case 71:
#line 563 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)=EMAYEQ;
		}
#line 2074 "asin.c" /* yacc.c:1646  */
    break;

  case 72:
#line 567 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)=EMENEQ;
		}
#line 2082 "asin.c" /* yacc.c:1646  */
    break;

  case 73:
#line 573 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)=ESUM;
		}
#line 2090 "asin.c" /* yacc.c:1646  */
    break;

  case 74:
#line 577 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)=EDIF;
		}
#line 2098 "asin.c" /* yacc.c:1646  */
    break;

  case 75:
#line 583 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)= EMULT;
		}
#line 2106 "asin.c" /* yacc.c:1646  */
    break;

  case 76:
#line 587 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)=EDIVI;
		}
#line 2114 "asin.c" /* yacc.c:1646  */
    break;

  case 77:
#line 591 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)=RESTO;
		}
#line 2122 "asin.c" /* yacc.c:1646  */
    break;

  case 78:
#line 597 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)=ESUM;
		}
#line 2130 "asin.c" /* yacc.c:1646  */
    break;

  case 79:
#line 601 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)=EDIF;
		}
#line 2138 "asin.c" /* yacc.c:1646  */
    break;

  case 80:
#line 605 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)=EDIST;
		}
#line 2146 "asin.c" /* yacc.c:1646  */
    break;

  case 81:
#line 611 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)=ESUM;
		}
#line 2154 "asin.c" /* yacc.c:1646  */
    break;

  case 82:
#line 615 "src/asin.y" /* yacc.c:1646  */
    {
			(yyval.cent)=EDIF;
		}
#line 2162 "asin.c" /* yacc.c:1646  */
    break;


#line 2166 "asin.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 620 "src/asin.y" /* yacc.c:1906  */

