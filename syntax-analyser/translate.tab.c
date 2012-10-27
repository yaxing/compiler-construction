/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BEGINSYM = 258,
     FORWARD = 259,
     DIV = 260,
     DO = 261,
     ELSE = 262,
     END = 263,
     FOR = 264,
     FUNCTION = 265,
     IF = 266,
     ARRAY = 267,
     MOD = 268,
     NOT = 269,
     OF = 270,
     OR = 271,
     PROCEDURE = 272,
     PROGRAM = 273,
     RECORD = 274,
     THEN = 275,
     TO = 276,
     TYPE = 277,
     VAR = 278,
     WHILE = 279,
     OP_ADD = 280,
     OP_MUL = 281,
     OP_MIN = 282,
     OP_EQUAL = 283,
     OP_LESS = 284,
     OP_LESS_EQ = 285,
     OP_GREATER = 286,
     OP_GREATER_EQ = 287,
     OP_NOT_EQ = 288,
     DOT = 289,
     COMMA = 290,
     COLON = 291,
     SEMICOLON = 292,
     ASSIGN = 293,
     DOUBLE_DOT = 294,
     BRACE_L = 295,
     BRACE_R = 296,
     BRACKET_L = 297,
     BRACKET_R = 298,
     INT = 299,
     NUM = 300,
     ID = 301,
     STRING = 302,
     AND = 303
   };
#endif
/* Tokens.  */
#define BEGINSYM 258
#define FORWARD 259
#define DIV 260
#define DO 261
#define ELSE 262
#define END 263
#define FOR 264
#define FUNCTION 265
#define IF 266
#define ARRAY 267
#define MOD 268
#define NOT 269
#define OF 270
#define OR 271
#define PROCEDURE 272
#define PROGRAM 273
#define RECORD 274
#define THEN 275
#define TO 276
#define TYPE 277
#define VAR 278
#define WHILE 279
#define OP_ADD 280
#define OP_MUL 281
#define OP_MIN 282
#define OP_EQUAL 283
#define OP_LESS 284
#define OP_LESS_EQ 285
#define OP_GREATER 286
#define OP_GREATER_EQ 287
#define OP_NOT_EQ 288
#define DOT 289
#define COMMA 290
#define COLON 291
#define SEMICOLON 292
#define ASSIGN 293
#define DOUBLE_DOT 294
#define BRACE_L 295
#define BRACE_R 296
#define BRACKET_L 297
#define BRACKET_R 298
#define INT 299
#define NUM 300
#define ID 301
#define STRING 302
#define AND 303




/* Copy the first part of user declarations.  */
#line 1 "translate.y"

#include "header.h"

extern FILE *yyin;
extern int count;
extern char* yytext;

int parameterCount = 0;

void addCurParamCounter(int delta);

void cleanCurParamCounter();

char * itoa(int a);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 18 "translate.y"
{
    double doubleType;
    int intType;
    int idEntryType;
    char *stringType;
    struct IDLIST *idListType;
}
/* Line 193 of yacc.c.  */
#line 217 "translate.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 230 "translate.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   187

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNRULES -- Number of states.  */
#define YYNSTATES  192

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    16,    23,    30,    38,    46,    54,
      63,    66,    69,    73,    76,    79,    83,    87,    90,    92,
      94,    98,   102,   110,   120,   122,   124,   129,   130,   136,
     137,   139,   142,   146,   148,   152,   154,   156,   158,   160,
     161,   165,   170,   172,   177,   184,   189,   198,   200,   209,
     213,   215,   218,   220,   222,   226,   228,   230,   232,   234,
     236,   238,   241,   243,   248,   250,   252,   254,   256,   259,
     262,   263,   265,   267,   269,   271,   273,   275,   277,   279,
     282,   286,   291,   294,   298,   303,   304,   307,   308,   312,
     313,   316,   320,   321,   323
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    18,    46,    37,    65,    34,    -1,    18,
      46,    37,    51,    65,    34,    -1,    18,    46,    37,    53,
      65,    34,    -1,    18,    46,    37,    55,    65,    34,    -1,
      18,    46,    37,    51,    53,    65,    34,    -1,    18,    46,
      37,    53,    55,    65,    34,    -1,    18,    46,    37,    51,
      55,    65,    34,    -1,    18,    46,    37,    51,    53,    55,
      65,    34,    -1,    22,    52,    -1,    57,    37,    -1,    57,
      37,    52,    -1,    23,    54,    -1,    58,    37,    -1,    58,
      37,    54,    -1,    56,    37,    56,    -1,    56,    37,    -1,
      59,    -1,    60,    -1,    46,    28,    72,    -1,    89,    36,
      72,    -1,    17,    46,    40,    62,    41,    37,    61,    -1,
      10,    46,    40,    62,    41,    36,    73,    37,    61,    -1,
      64,    -1,     4,    -1,    89,    36,    72,    63,    -1,    -1,
      37,    89,    36,    72,    63,    -1,    -1,    65,    -1,    53,
      65,    -1,     3,    66,     8,    -1,    67,    -1,    66,    37,
      67,    -1,    68,    -1,    71,    -1,    69,    -1,    70,    -1,
      -1,    85,    38,    75,    -1,    46,    40,    87,    41,    -1,
      65,    -1,    11,    75,    20,    67,    -1,    11,    75,    20,
      67,     7,    67,    -1,    24,    75,     6,    67,    -1,     9,
      46,    38,    75,    21,    75,     6,    67,    -1,    46,    -1,
      12,    42,    74,    39,    74,    43,    15,    72,    -1,    19,
      62,     8,    -1,    46,    -1,    91,    44,    -1,    44,    -1,
      77,    -1,    77,    76,    77,    -1,    28,    -1,    29,    -1,
      30,    -1,    31,    -1,    32,    -1,    33,    -1,    91,    78,
      -1,    78,    -1,    80,    79,    80,    78,    -1,    80,    -1,
      25,    -1,    27,    -1,    16,    -1,    83,    81,    -1,    82,
      80,    -1,    -1,    26,    -1,     5,    -1,    13,    -1,    48,
      -1,    44,    -1,    47,    -1,    85,    -1,    84,    -1,    14,
      83,    -1,    40,    75,    41,    -1,    46,    40,    87,    41,
      -1,    46,    86,    -1,    34,    46,    86,    -1,    42,    75,
      43,    86,    -1,    -1,    75,    88,    -1,    -1,    35,    75,
      88,    -1,    -1,    46,    90,    -1,    35,    46,    90,    -1,
      -1,    25,    -1,    27,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    78,    78,    79,    80,    81,    82,    83,    84,    85,
      88,    91,    92,    95,    98,    99,   102,   103,   106,   107,
     110,   113,   118,   121,   124,   125,   128,   131,   134,   137,
     140,   141,   144,   147,   148,   151,   152,   155,   156,   157,
     160,   163,   166,   167,   168,   169,   170,   173,   174,   175,
     178,   181,   182,   185,   186,   189,   190,   191,   192,   193,
     194,   197,   198,   201,   202,   205,   206,   207,   210,   213,
     214,   217,   218,   219,   220,   223,   224,   225,   226,   227,
     228,   231,   234,   237,   238,   239,   242,   243,   246,   247,
     250,   256,   260,   263,   264
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BEGINSYM", "FORWARD", "DIV", "DO",
  "ELSE", "END", "FOR", "FUNCTION", "IF", "ARRAY", "MOD", "NOT", "OF",
  "OR", "PROCEDURE", "PROGRAM", "RECORD", "THEN", "TO", "TYPE", "VAR",
  "WHILE", "OP_ADD", "OP_MUL", "OP_MIN", "OP_EQUAL", "OP_LESS",
  "OP_LESS_EQ", "OP_GREATER", "OP_GREATER_EQ", "OP_NOT_EQ", "DOT", "COMMA",
  "COLON", "SEMICOLON", "ASSIGN", "DOUBLE_DOT", "BRACE_L", "BRACE_R",
  "BRACKET_L", "BRACKET_R", "INT", "NUM", "ID", "STRING", "AND", "$accept",
  "Program", "TypeDefinitions", "TypeDefinitionList",
  "VariableDeclarations", "VariableDeclarationList",
  "SubprogramDeclarations", "SubprogramDeclaration", "TypeDefinition",
  "VariableDeclaration", "ProcedureDeclaration", "FunctionDeclaration",
  "PFDeclarationFollow", "FormalParameterList", "FormalParameterListMore",
  "Block", "CompoundStatement", "StatementSequence", "Statement",
  "SimpleStatement", "AssignmentStatement", "ProcedureStatement",
  "StructuredStatement", "Type", "ResultType", "Constant", "Expression",
  "RelationalOp", "SimpleExpression", "AddOpTerm", "AddOp", "Term",
  "MulOpTerm", "MulOp", "Factor", "FunctionReference", "Variable",
  "ComponentSelection", "ActualParameterList", "ExpressionMore",
  "IdentifierList", "IdentifierListMore", "Sign", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    50,    50,    50,    50,    50,    50,
      51,    52,    52,    53,    54,    54,    55,    55,    56,    56,
      57,    58,    59,    60,    61,    61,    62,    62,    63,    63,
      64,    64,    65,    66,    66,    67,    67,    68,    68,    68,
      69,    70,    71,    71,    71,    71,    71,    72,    72,    72,
      73,    74,    74,    75,    75,    76,    76,    76,    76,    76,
      76,    77,    77,    78,    78,    79,    79,    79,    80,    81,
      81,    82,    82,    82,    82,    83,    83,    83,    83,    83,
      83,    84,    85,    86,    86,    86,    87,    87,    88,    88,
      89,    90,    90,    91,    91
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     6,     6,     6,     7,     7,     7,     8,
       2,     2,     3,     2,     2,     3,     3,     2,     1,     1,
       3,     3,     7,     9,     1,     1,     4,     0,     5,     0,
       1,     2,     3,     1,     3,     1,     1,     1,     1,     0,
       3,     4,     1,     4,     6,     4,     8,     1,     8,     3,
       1,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     2,     1,     4,     1,     1,     1,     1,     2,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     4,     2,     3,     4,     0,     2,     0,     3,     0,
       2,     3,     0,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    39,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    19,     0,     0,     0,
       0,    85,    42,     0,    33,    35,    37,    38,    36,     0,
       0,     0,     0,    10,     0,    92,    13,     0,     0,     0,
       0,     0,     0,     0,     0,    17,     2,     0,     0,    93,
      94,     0,    75,    85,    76,     0,    53,    62,    64,    70,
      78,    77,     0,     0,     0,    87,     0,    82,    32,    39,
       0,    27,    27,     0,    11,     0,    90,    14,     0,     0,
       0,     0,     3,     0,     4,     5,    16,     0,    79,     0,
      87,    39,    55,    56,    57,    58,    59,    60,     0,    67,
      65,    66,     0,    72,    73,    71,    74,    68,     0,    61,
      39,    85,    89,     0,     0,    34,    40,     0,     0,     0,
       0,    27,    47,    20,    12,    92,    15,    21,     0,     6,
       8,     7,     0,    80,     0,    43,    54,     0,    69,    45,
      83,     0,    86,    41,    85,     0,     0,     0,     0,     0,
      91,     9,     0,    81,    39,    63,    89,    84,     0,    29,
       0,    52,     0,     0,    49,     0,    44,    88,    50,     0,
       0,    26,    25,     0,    22,    24,    30,     0,    51,    39,
       0,     0,    31,     0,    46,    23,     0,     0,    29,     0,
      28,    48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    11,    33,   173,    36,    13,    14,    34,    37,
      15,    16,   174,   117,   171,   175,    22,    23,    24,    25,
      26,    27,    28,   123,   169,   162,   112,    98,    56,    57,
     102,    58,   107,   108,    59,    60,    61,    67,   113,   142,
     118,    76,    62
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -121
static const yytype_int16 yypact[] =
{
      11,   -16,    32,     4,  -121,    61,    15,     7,    31,    41,
      44,    76,    79,    53,    54,  -121,  -121,    58,    55,    -2,
      -2,    63,  -121,     9,  -121,  -121,  -121,  -121,  -121,    71,
      72,    75,    83,  -121,    80,    81,  -121,    90,    82,    79,
      53,    94,    53,    95,    96,    85,  -121,    93,    29,  -121,
    -121,    -2,  -121,    64,  -121,   112,    92,  -121,    38,    14,
    -121,  -121,    29,   127,    88,    -2,    -2,  -121,  -121,    15,
      -2,    44,    44,     1,    41,    89,  -121,    44,     1,    53,
     102,   104,  -121,   105,  -121,  -121,  -121,    -2,  -121,    99,
      -2,    15,  -121,  -121,  -121,  -121,  -121,  -121,    -2,  -121,
    -121,  -121,    29,  -121,  -121,  -121,  -121,  -121,    29,  -121,
      15,    25,   106,   101,   100,  -121,  -121,   103,   109,   107,
     108,    44,  -121,  -121,  -121,    81,  -121,  -121,   113,  -121,
    -121,  -121,   125,  -121,   111,   142,  -121,    29,  -121,  -121,
    -121,    -2,  -121,  -121,    25,   117,     1,   119,   -11,   146,
    -121,  -121,    -2,  -121,    15,  -121,   106,  -121,   114,   120,
      77,  -121,   123,   115,  -121,   152,  -121,  -121,  -121,   126,
      44,  -121,  -121,    53,  -121,  -121,  -121,   -11,  -121,    15,
      77,   128,  -121,   122,  -121,  -121,     1,   151,   120,     1,
    -121,  -121
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,  -121,    97,    47,   110,    10,   124,  -121,  -121,
    -121,  -121,   -13,   -61,   -18,  -121,    -5,  -121,   -60,  -121,
    -121,  -121,  -121,   -76,  -121,    -4,   -15,  -121,    74,   -52,
    -121,     6,  -121,  -121,   129,  -121,    -3,   -96,    84,    22,
      -9,    56,  -120
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      17,    38,   127,    29,    55,    63,    41,    43,    44,   115,
     109,   119,    48,   120,    49,   140,    50,    68,     6,   103,
     121,    40,    42,    49,    18,    50,    19,   104,   163,     1,
       3,   135,     4,   161,    80,    81,    89,    83,    51,    20,
     105,     5,    52,    48,    53,    54,    69,   122,   157,    79,
     139,   114,    12,    30,    99,   116,     6,   163,    39,    64,
     149,    21,   106,   100,     6,   101,    29,    66,    38,    51,
     159,     7,   132,    52,   128,    53,    54,    31,     8,     6,
       6,   172,     6,     9,    10,   155,     7,    32,    29,     7,
      35,    45,    46,     8,   166,     7,     8,    64,    64,    10,
      10,    47,     8,    65,    90,    66,    66,    29,   137,    70,
     188,    73,    71,   191,   138,    72,    75,    74,    78,   184,
      92,    93,    94,    95,    96,    97,   156,    77,    82,    84,
      85,    87,    91,   110,   111,   125,   129,   165,   130,   131,
     133,   141,   143,   144,   145,   146,   152,   151,   147,   154,
     148,    29,   153,   158,   164,   176,   160,   170,   179,   178,
     168,   181,   177,   180,   186,   187,   189,   185,   182,    86,
     190,   124,   136,   183,   134,   176,    29,    88,   167,     0,
       0,   150,     0,     0,     0,     0,     0,   126
};

static const yytype_int16 yycheck[] =
{
       5,    10,    78,     6,    19,    20,    11,    12,    13,    69,
      62,    72,    14,    12,    25,   111,    27,     8,     3,     5,
      19,    11,    12,    25,     9,    27,    11,    13,   148,    18,
      46,    91,     0,    44,    39,    40,    51,    42,    40,    24,
      26,    37,    44,    14,    46,    47,    37,    46,   144,    39,
     110,    66,     5,    46,    16,    70,     3,   177,    11,    34,
     121,    46,    48,    25,     3,    27,    69,    42,    77,    40,
     146,    10,    87,    44,    79,    46,    47,    46,    17,     3,
       3,     4,     3,    22,    23,   137,    10,    46,    91,    10,
      46,    37,    34,    17,   154,    10,    17,    34,    34,    23,
      23,    46,    17,    40,    40,    42,    42,   110,   102,    38,
     186,    28,    40,   189,   108,    40,    35,    37,    36,   179,
      28,    29,    30,    31,    32,    33,   141,    37,    34,    34,
      34,    38,    20,     6,    46,    46,    34,   152,    34,    34,
      41,    35,    41,    43,    41,    36,    21,    34,    41,     7,
      42,   154,    41,    36,     8,   160,    37,    37,     6,    44,
      46,   170,    39,    37,    36,    43,    15,   180,   173,    45,
     188,    74,    98,   177,    90,   180,   179,    48,   156,    -1,
      -1,   125,    -1,    -1,    -1,    -1,    -1,    77
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    50,    46,     0,    37,     3,    10,    17,    22,
      23,    51,    53,    55,    56,    59,    60,    65,     9,    11,
      24,    46,    65,    66,    67,    68,    69,    70,    71,    85,
      46,    46,    46,    52,    57,    46,    54,    58,    89,    53,
      55,    65,    55,    65,    65,    37,    34,    46,    14,    25,
      27,    40,    44,    46,    47,    75,    77,    78,    80,    83,
      84,    85,    91,    75,    34,    40,    42,    86,     8,    37,
      38,    40,    40,    28,    37,    35,    90,    37,    36,    55,
      65,    65,    34,    65,    34,    34,    56,    38,    83,    75,
      40,    20,    28,    29,    30,    31,    32,    33,    76,    16,
      25,    27,    79,     5,    13,    26,    48,    81,    82,    78,
       6,    46,    75,    87,    75,    67,    75,    62,    89,    62,
      12,    19,    46,    72,    52,    46,    54,    72,    65,    34,
      34,    34,    75,    41,    87,    67,    77,    80,    80,    67,
      86,    35,    88,    41,    43,    41,    36,    41,    42,    62,
      90,    34,    21,    41,     7,    78,    75,    86,    36,    72,
      37,    44,    74,    91,     8,    75,    67,    88,    46,    73,
      37,    63,     4,    53,    61,    64,    65,    39,    44,     6,
      37,    89,    65,    74,    67,    61,    36,    43,    72,    15,
      63,    72
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 78 "translate.y"
    {printf("Program\n");;}
    break;

  case 3:
#line 79 "translate.y"
    {printf("Program\n");;}
    break;

  case 4:
#line 80 "translate.y"
    {printf("Program\n");;}
    break;

  case 5:
#line 81 "translate.y"
    {printf("Program\n");;}
    break;

  case 6:
#line 82 "translate.y"
    {printf("Program\n");;}
    break;

  case 7:
#line 83 "translate.y"
    {printf("Program\n");;}
    break;

  case 8:
#line 84 "translate.y"
    {printf("Program\n");;}
    break;

  case 9:
#line 85 "translate.y"
    {printf("Program\n");;}
    break;

  case 10:
#line 88 "translate.y"
    {;}
    break;

  case 11:
#line 91 "translate.y"
    {;}
    break;

  case 12:
#line 92 "translate.y"
    {;}
    break;

  case 14:
#line 98 "translate.y"
    {;}
    break;

  case 15:
#line 99 "translate.y"
    {;}
    break;

  case 16:
#line 102 "translate.y"
    {;}
    break;

  case 17:
#line 103 "translate.y"
    {;}
    break;

  case 18:
#line 106 "translate.y"
    {;}
    break;

  case 19:
#line 107 "translate.y"
    {;}
    break;

  case 20:
#line 110 "translate.y"
    {setSymbolEntyTypeAttr((yyvsp[(1) - (3)].idEntryType), (yyvsp[(3) - (3)].idEntryType), NULL);;}
    break;

  case 21:
#line 113 "translate.y"
    {
                                                    setIdListTypeAttr((yyvsp[(3) - (3)].idEntryType), NULL);
                                                ;}
    break;

  case 22:
#line 118 "translate.y"
    {;}
    break;

  case 23:
#line 121 "translate.y"
    {;}
    break;

  case 24:
#line 124 "translate.y"
    {;}
    break;

  case 25:
#line 125 "translate.y"
    {;}
    break;

  case 26:
#line 128 "translate.y"
    {
                                                                            setIdListTypeAttr((yyvsp[(3) - (4)].idEntryType), NULL);
                                                                        ;}
    break;

  case 28:
#line 134 "translate.y"
    {
                                                                                        setIdListTypeAttr((yyvsp[(4) - (5)].idEntryType), NULL);
                                                                                      ;}
    break;

  case 30:
#line 140 "translate.y"
    {;}
    break;

  case 31:
#line 141 "translate.y"
    {;}
    break;

  case 32:
#line 144 "translate.y"
    {;}
    break;

  case 33:
#line 147 "translate.y"
    {;}
    break;

  case 34:
#line 148 "translate.y"
    {;}
    break;

  case 35:
#line 151 "translate.y"
    {;}
    break;

  case 36:
#line 152 "translate.y"
    {;}
    break;

  case 40:
#line 160 "translate.y"
    {;}
    break;

  case 41:
#line 163 "translate.y"
    {;}
    break;

  case 42:
#line 166 "translate.y"
    {;}
    break;

  case 43:
#line 167 "translate.y"
    {;}
    break;

  case 44:
#line 168 "translate.y"
    {;}
    break;

  case 45:
#line 169 "translate.y"
    {;}
    break;

  case 46:
#line 170 "translate.y"
    {;}
    break;

  case 47:
#line 173 "translate.y"
    {setSymbolTypeAttrDirec((yyvsp[(1) - (1)].idEntryType), NULL, NULL);;}
    break;

  case 48:
#line 174 "translate.y"
    {;}
    break;

  case 49:
#line 175 "translate.y"
    {;}
    break;

  case 50:
#line 178 "translate.y"
    {;}
    break;

  case 51:
#line 181 "translate.y"
    {;}
    break;

  case 52:
#line 182 "translate.y"
    {;}
    break;

  case 53:
#line 185 "translate.y"
    {;}
    break;

  case 54:
#line 186 "translate.y"
    {;}
    break;

  case 55:
#line 189 "translate.y"
    {;}
    break;

  case 56:
#line 190 "translate.y"
    {;}
    break;

  case 57:
#line 191 "translate.y"
    {;}
    break;

  case 58:
#line 192 "translate.y"
    {;}
    break;

  case 59:
#line 193 "translate.y"
    {;}
    break;

  case 60:
#line 194 "translate.y"
    {;}
    break;

  case 61:
#line 197 "translate.y"
    {;}
    break;

  case 62:
#line 198 "translate.y"
    {;}
    break;

  case 63:
#line 201 "translate.y"
    {;}
    break;

  case 65:
#line 205 "translate.y"
    {;}
    break;

  case 66:
#line 206 "translate.y"
    {;}
    break;

  case 67:
#line 207 "translate.y"
    {;}
    break;

  case 68:
#line 210 "translate.y"
    {;}
    break;

  case 69:
#line 213 "translate.y"
    {;}
    break;

  case 71:
#line 217 "translate.y"
    {;}
    break;

  case 72:
#line 218 "translate.y"
    {;}
    break;

  case 73:
#line 219 "translate.y"
    {;}
    break;

  case 74:
#line 220 "translate.y"
    {;}
    break;

  case 75:
#line 223 "translate.y"
    {;}
    break;

  case 76:
#line 224 "translate.y"
    {;}
    break;

  case 77:
#line 225 "translate.y"
    {;}
    break;

  case 78:
#line 226 "translate.y"
    {;}
    break;

  case 79:
#line 227 "translate.y"
    {;}
    break;

  case 80:
#line 228 "translate.y"
    {;}
    break;

  case 81:
#line 231 "translate.y"
    {;}
    break;

  case 82:
#line 234 "translate.y"
    {;}
    break;

  case 83:
#line 237 "translate.y"
    {;}
    break;

  case 84:
#line 238 "translate.y"
    {;}
    break;

  case 86:
#line 242 "translate.y"
    {;}
    break;

  case 88:
#line 246 "translate.y"
    {;}
    break;

  case 90:
#line 250 "translate.y"
    {
                                        addCurParamCounter(1);
                                        appendToIdList((yyvsp[(1) - (2)].idEntryType));
                                       ;}
    break;

  case 91:
#line 256 "translate.y"
    {
                                                    addCurParamCounter(1); 
                                                    appendToIdList((yyvsp[(2) - (3)].idEntryType));
                                                 ;}
    break;

  case 93:
#line 263 "translate.y"
    {;}
    break;

  case 94:
#line 264 "translate.y"
    {;}
    break;


/* Line 1267 of yacc.c.  */
#line 2021 "translate.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 267 "translate.y"

yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
}

void addCurParamCounter(int delta) {
    parameterCount += delta;
}

void cleanCurParamCounter() {
    parameterCount = 0;
}

char * itoa(int a) {
    char * buf = (char *)malloc(sizeof(a) + 1);
    sprintf(buf, "%d", a);
    return buf;
}

int main(int argc, const char * argv[]) {
    //registerKeywords(keywords, 23);
    ++argv, --argc;    /* skip argv[0] */
    if (argc > 0) {
        yyin = fopen(argv[0], "r");
    } else {
        yyin = stdin;
    }
    printf("\n\nParsing...:\n\n");
//    freopen("rule.out","w",stdout);
    yyparse();

//    freopen("symtable.out","w",stdout);
    printf("done.\n");
    printf("\n\nSymbol Table:\n");
    printSymbolTable();
    int i;
}

