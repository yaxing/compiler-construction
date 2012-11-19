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
     AND = 303,
     NIL = 304,
     TRUE = 305,
     FALSE = 306
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
#define NIL 304
#define TRUE 305
#define FALSE 306




/* Copy the first part of user declarations.  */
#line 1 "translate.y"

#include "header.h"
#include "flex-bison-header.h"
extern FILE *yyin;
extern int count;
extern char* yytext;

int parameterCount = 0;
int funcProcParamCount = 0;

int getConstantInt(char *sign, int num);

void addCurParamCounter(int delta);

void cleanCurParamCounter();

void cleanCurFuncProcParamCounter();

char * itoa(int a);

int setIdListType(struct TypeInfo *retType);

void handleFuncProcDeclaration(struct IdResp *id, typeinfost *retType, int paramQty, char *funcProc);

int enterNewScope(struct IdResp *id);

int setSymbolTypeAttr(int idAddr, int typeEntry, typeinfost *typedata);

int typeHandler(idresp *idResp);

int isIdDefined(struct IdResp *id);



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
#line 35 "translate.y"
{
    double doubleType;
    int intType;
    int idEntryType;
    char *stringType;
    struct IDLIST *idListType;
    struct IdResp *idrespType;
    struct TypeInfo *typeinfo;
    int paramList[100];
}
/* Line 193 of yacc.c.  */
#line 243 "translate.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 256 "translate.tab.c"

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
#define YYLAST   180

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNRULES -- Number of states.  */
#define YYNSTATES  190

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    16,    23,    30,    38,    46,    54,
      63,    66,    69,    73,    76,    79,    83,    87,    90,    92,
      94,    98,   102,   103,   104,   114,   115,   116,   128,   130,
     132,   133,   136,   140,   143,   144,   146,   149,   153,   155,
     159,   161,   163,   165,   167,   168,   172,   173,   179,   181,
     186,   193,   198,   207,   209,   218,   222,   224,   227,   229,
     231,   235,   237,   239,   241,   243,   245,   247,   250,   252,
     256,   258,   260,   262,   264,   267,   270,   271,   273,   275,
     277,   279,   281,   283,   285,   287,   290,   294,   295,   299,
     303,   308,   309,   312,   313,   317,   318,   321,   324,   325,
     327
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    18,    46,    37,    73,    34,    -1,    18,
      46,    37,    54,    73,    34,    -1,    18,    46,    37,    56,
      73,    34,    -1,    18,    46,    37,    58,    73,    34,    -1,
      18,    46,    37,    54,    56,    73,    34,    -1,    18,    46,
      37,    56,    58,    73,    34,    -1,    18,    46,    37,    54,
      58,    73,    34,    -1,    18,    46,    37,    54,    56,    58,
      73,    34,    -1,    22,    55,    -1,    60,    37,    -1,    60,
      37,    55,    -1,    23,    57,    -1,    61,    37,    -1,    61,
      37,    57,    -1,    59,    37,    58,    -1,    59,    37,    -1,
      62,    -1,    65,    -1,    46,    28,    81,    -1,    98,    36,
      81,    -1,    -1,    -1,    17,    46,    63,    40,    69,    41,
      37,    64,    68,    -1,    -1,    -1,    10,    46,    66,    40,
      69,    41,    36,    82,    37,    67,    68,    -1,    72,    -1,
       4,    -1,    -1,    70,    71,    -1,    98,    36,    81,    -1,
      37,    69,    -1,    -1,    73,    -1,    56,    73,    -1,     3,
      74,     8,    -1,    75,    -1,    74,    37,    75,    -1,    76,
      -1,    80,    -1,    77,    -1,    78,    -1,    -1,    93,    38,
      84,    -1,    -1,    46,    79,    40,    96,    41,    -1,    73,
      -1,    11,    84,    20,    75,    -1,    11,    84,    20,    75,
       7,    75,    -1,    24,    84,     6,    75,    -1,     9,    46,
      38,    84,    21,    84,     6,    75,    -1,    46,    -1,    12,
      42,    83,    39,    83,    43,    15,    81,    -1,    19,    69,
       8,    -1,    46,    -1,   100,    44,    -1,    44,    -1,    86,
      -1,    86,    85,    86,    -1,    28,    -1,    29,    -1,    30,
      -1,    31,    -1,    32,    -1,    33,    -1,   100,    87,    -1,
      87,    -1,    89,    88,    87,    -1,    89,    -1,    25,    -1,
      27,    -1,    16,    -1,    92,    90,    -1,    91,    89,    -1,
      -1,    26,    -1,     5,    -1,    13,    -1,    48,    -1,    44,
      -1,    47,    -1,    78,    -1,    93,    -1,    14,    92,    -1,
      40,    84,    41,    -1,    -1,    46,    94,    95,    -1,    34,
      46,    95,    -1,    42,    84,    43,    95,    -1,    -1,    84,
      97,    -1,    -1,    35,    84,    97,    -1,    -1,    46,    99,
      -1,    35,    98,    -1,    -1,    25,    -1,    27,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   104,   104,   105,   106,   107,   108,   109,   110,   111,
     114,   117,   118,   121,   128,   129,   132,   133,   136,   137,
     140,   155,   163,   171,   163,   182,   190,   182,   201,   202,
     205,   206,   211,   219,   220,   223,   224,   227,   230,   231,
     234,   235,   238,   239,   240,   243,   246,   246,   249,   250,
     251,   252,   253,   256,   263,   270,   282,   292,   293,   296,
     297,   300,   301,   302,   303,   304,   305,   308,   309,   312,
     313,   316,   317,   318,   321,   324,   325,   328,   329,   330,
     331,   334,   335,   336,   337,   338,   339,   342,   342,   365,
     366,   367,   370,   371,   374,   375,   378,   385,   386,   389,
     390
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
  "BRACKET_L", "BRACKET_R", "INT", "NUM", "ID", "STRING", "AND", "NIL",
  "TRUE", "FALSE", "$accept", "Program", "TypeDefinitions",
  "TypeDefinitionList", "VariableDeclarations", "VariableDeclarationList",
  "SubprogramDeclarations", "SubprogramDeclaration", "TypeDefinition",
  "VariableDeclaration", "ProcedureDeclaration", "@1", "@2",
  "FunctionDeclaration", "@3", "@4", "PFDeclarationFollow",
  "FormalParameterList", "FormalParameterListSingle",
  "FormalParameterListMore", "Block", "CompoundStatement",
  "StatementSequence", "Statement", "SimpleStatement",
  "AssignmentStatement", "ProcFuncStatement", "@5", "StructuredStatement",
  "Type", "ResultType", "Constant", "Expression", "RelationalOp",
  "SimpleExpression", "AddOpTerm", "AddOp", "Term", "MulOpTerm", "MulOp",
  "Factor", "Variable", "@6", "ComponentSelection", "ActualParameterList",
  "ExpressionMore", "IdentifierList", "IdentifierListMore", "Sign", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    53,    53,    53,    53,    53,    53,
      54,    55,    55,    56,    57,    57,    58,    58,    59,    59,
      60,    61,    63,    64,    62,    66,    67,    65,    68,    68,
      69,    69,    70,    71,    71,    72,    72,    73,    74,    74,
      75,    75,    76,    76,    76,    77,    79,    78,    80,    80,
      80,    80,    80,    81,    81,    81,    82,    83,    83,    84,
      84,    85,    85,    85,    85,    85,    85,    86,    86,    87,
      87,    88,    88,    88,    89,    90,    90,    91,    91,    91,
      91,    92,    92,    92,    92,    92,    92,    94,    93,    95,
      95,    95,    96,    96,    97,    97,    98,    99,    99,   100,
     100
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     6,     6,     6,     7,     7,     7,     8,
       2,     2,     3,     2,     2,     3,     3,     2,     1,     1,
       3,     3,     0,     0,     9,     0,     0,    11,     1,     1,
       0,     2,     3,     2,     0,     1,     2,     3,     1,     3,
       1,     1,     1,     1,     0,     3,     0,     5,     1,     4,
       6,     4,     8,     1,     8,     3,     1,     2,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     1,     1,     2,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     0,     3,     3,
       4,     0,     2,     0,     3,     0,     2,     2,     0,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    44,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    19,     0,     0,     0,
       0,    87,    48,     0,    38,    40,    42,    43,    41,     0,
      25,    22,     0,    10,     0,    98,    13,     0,     0,     0,
       0,     0,     0,     0,     0,    17,     2,     0,     0,    99,
     100,     0,    81,    82,    83,     0,    59,    68,    70,    76,
      84,     0,     0,     0,    91,    37,    44,     0,     0,     0,
       0,    11,     0,    96,    14,     0,     0,     0,     0,     3,
       0,     4,     5,    16,     0,    85,     0,    44,    61,    62,
      63,    64,    65,    66,     0,    73,    71,    72,     0,    78,
      79,    77,    80,    74,     0,    67,    44,    93,     0,     0,
      88,    39,    45,    30,    30,     0,    30,    53,    20,    12,
      97,    15,    21,     0,     6,     8,     7,     0,    86,    49,
      60,    69,    75,    51,    95,     0,    91,     0,     0,    34,
       0,     0,     0,     0,     9,     0,    44,     0,    92,    47,
      89,    91,     0,    30,    31,     0,     0,    58,     0,     0,
      55,     0,    50,    95,    90,     0,    33,    32,    23,     0,
      57,    44,    94,    56,     0,     0,     0,    52,    26,    29,
       0,    24,    28,    35,     0,     0,    36,     0,    27,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    11,    33,   180,    36,    13,    14,    34,    37,
      15,    69,   175,    16,    68,   185,   181,   138,   139,   154,
     182,    22,    23,    24,    25,    26,    54,    63,    28,   118,
     174,   158,    55,    94,    56,    57,    98,    58,   103,   104,
      59,    60,    64,   110,   135,   148,   140,    73,    61
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -123
static const yytype_int16 yypact[] =
{
      11,   -18,    33,     5,  -123,    89,     7,    13,    21,    36,
      40,    98,    35,    78,     6,  -123,  -123,    22,    49,    30,
      30,    56,  -123,    32,  -123,  -123,  -123,  -123,  -123,    67,
    -123,  -123,    72,  -123,    70,    74,  -123,    73,    77,    35,
      78,    82,    78,    84,    85,    62,  -123,    86,    47,  -123,
    -123,    30,  -123,  -123,  -123,   100,   101,  -123,    48,    10,
    -123,    47,   116,    83,   -17,  -123,     7,    30,    87,    95,
       0,    36,    40,  -123,    40,     0,    78,    91,   102,  -123,
     103,  -123,  -123,  -123,    30,  -123,    97,     7,  -123,  -123,
    -123,  -123,  -123,  -123,    30,  -123,  -123,  -123,    47,  -123,
    -123,  -123,  -123,  -123,    47,  -123,     7,    30,    94,    30,
    -123,  -123,  -123,    40,    40,    99,    40,  -123,  -123,  -123,
    -123,  -123,  -123,   105,  -123,  -123,  -123,   123,  -123,   138,
    -123,  -123,  -123,  -123,   111,   106,   -17,   107,   108,   114,
     112,   113,    53,   144,  -123,    30,     7,    30,  -123,  -123,
    -123,   -17,   117,    40,  -123,     0,   118,  -123,   119,   115,
    -123,   150,  -123,   111,  -123,   120,  -123,  -123,  -123,    53,
    -123,     7,  -123,  -123,   124,    18,   121,  -123,  -123,  -123,
      78,  -123,  -123,  -123,   142,    18,  -123,     0,  -123,  -123
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -123,  -123,  -123,    92,    93,    88,    15,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,   -25,  -103,  -123,  -123,
    -123,    -5,  -123,   -57,  -123,  -123,    -4,  -123,  -123,   -70,
    -123,     2,   -19,  -123,    71,   -47,  -123,    65,  -123,  -123,
     125,    -3,  -123,  -112,  -123,     9,    -6,  -123,  -122
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -47
static const yytype_int16 yytable[] =
{
      17,    62,    27,    29,    38,   122,    41,    43,    44,   111,
       6,   141,   115,   143,   105,    99,    18,   108,    19,   116,
     159,     6,   179,   100,   150,   109,    40,    42,     3,     1,
     129,    20,    86,     4,    77,    78,   101,    80,     6,   164,
      65,    10,     5,    45,    48,     7,   117,   159,   112,   133,
     166,   131,     8,    21,    76,    49,    46,    50,   102,    30,
      83,    48,    27,    29,    95,   127,   120,    31,    38,    66,
      51,   123,     7,    96,    52,    97,    21,    53,    49,     8,
      50,     6,    32,    27,    29,   167,    35,    51,   134,   162,
     137,    52,     6,    21,    53,    47,   -46,   157,    12,     7,
      70,     6,    27,    29,    39,    67,     8,    71,     7,    72,
      74,     9,    10,    75,   177,     8,    79,   189,    81,    82,
      87,    10,   106,   107,    84,   124,   161,   113,   163,    88,
      89,    90,    91,    92,    93,   114,   125,   126,   128,   144,
     136,   142,    27,    29,   145,   146,   147,   149,   155,   152,
     151,   153,   160,   165,   156,   168,   171,   187,   169,   170,
     188,   178,   121,   119,   184,   130,   173,    27,    29,   132,
     183,   176,   172,    85,     0,   186,     0,     0,     0,     0,
     183
};

static const yytype_int16 yycheck[] =
{
       5,    20,     6,     6,    10,    75,    11,    12,    13,    66,
       3,   114,    12,   116,    61,     5,     9,    34,    11,    19,
     142,     3,     4,    13,   136,    42,    11,    12,    46,    18,
      87,    24,    51,     0,    39,    40,    26,    42,     3,   151,
       8,    23,    37,    37,    14,    10,    46,   169,    67,   106,
     153,    98,    17,    46,    39,    25,    34,    27,    48,    46,
      45,    14,    66,    66,    16,    84,    72,    46,    74,    37,
      40,    76,    10,    25,    44,    27,    46,    47,    25,    17,
      27,     3,    46,    87,    87,   155,    46,    40,   107,   146,
     109,    44,     3,    46,    47,    46,    40,    44,     5,    10,
      28,     3,   106,   106,    11,    38,    17,    37,    10,    35,
      37,    22,    23,    36,   171,    17,    34,   187,    34,    34,
      20,    23,     6,    40,    38,    34,   145,    40,   147,    28,
      29,    30,    31,    32,    33,    40,    34,    34,    41,    34,
      46,    42,   146,   146,    21,     7,    35,    41,    36,    41,
      43,    37,     8,    36,    41,    37,     6,    15,    39,    44,
     185,    37,    74,    71,    43,    94,    46,   171,   171,   104,
     175,   169,   163,    48,    -1,   180,    -1,    -1,    -1,    -1,
     185
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    53,    46,     0,    37,     3,    10,    17,    22,
      23,    54,    56,    58,    59,    62,    65,    73,     9,    11,
      24,    46,    73,    74,    75,    76,    77,    78,    80,    93,
      46,    46,    46,    55,    60,    46,    57,    61,    98,    56,
      58,    73,    58,    73,    73,    37,    34,    46,    14,    25,
      27,    40,    44,    47,    78,    84,    86,    87,    89,    92,
      93,   100,    84,    79,    94,     8,    37,    38,    66,    63,
      28,    37,    35,    99,    37,    36,    58,    73,    73,    34,
      73,    34,    34,    58,    38,    92,    84,    20,    28,    29,
      30,    31,    32,    33,    85,    16,    25,    27,    88,     5,
      13,    26,    48,    90,    91,    87,     6,    40,    34,    42,
      95,    75,    84,    40,    40,    12,    19,    46,    81,    55,
      98,    57,    81,    73,    34,    34,    34,    84,    41,    75,
      86,    87,    89,    75,    84,    96,    46,    84,    69,    70,
      98,    69,    42,    69,    34,    21,     7,    35,    97,    41,
      95,    43,    41,    37,    71,    36,    41,    44,    83,   100,
       8,    84,    75,    84,    95,    36,    69,    81,    37,    39,
      44,     6,    97,    46,    82,    64,    83,    75,    37,     4,
      56,    68,    72,    73,    43,    67,    73,    15,    68,    81
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
#line 104 "translate.y"
    {printf("Program\n");;}
    break;

  case 3:
#line 105 "translate.y"
    {printf("Program\n");;}
    break;

  case 4:
#line 106 "translate.y"
    {printf("Program\n");;}
    break;

  case 5:
#line 107 "translate.y"
    {printf("Program\n");;}
    break;

  case 6:
#line 108 "translate.y"
    {printf("Program\n");;}
    break;

  case 7:
#line 109 "translate.y"
    {printf("Program\n");;}
    break;

  case 8:
#line 110 "translate.y"
    {printf("Program\n");;}
    break;

  case 9:
#line 111 "translate.y"
    {printf("Program\n");;}
    break;

  case 10:
#line 114 "translate.y"
    {printf("TypeDef_Mul\n");cleanCurParamCounter();;}
    break;

  case 11:
#line 117 "translate.y"
    {printf("TypeDefList\n");;}
    break;

  case 12:
#line 118 "translate.y"
    {printf("TypeDefList_Multi\n");;}
    break;

  case 13:
#line 122 "translate.y"
    {
                            printf("VarDecl_Mul\n");
                            cleanCurParamCounter();
                        ;}
    break;

  case 14:
#line 128 "translate.y"
    {printf("VarDeclList\n");;}
    break;

  case 15:
#line 129 "translate.y"
    {printf("VarDeclList_Mul\n");;}
    break;

  case 16:
#line 132 "translate.y"
    {printf("SubDecl_mul\n");;}
    break;

  case 17:
#line 133 "translate.y"
    {printf("SubDecl_Mul\n");;}
    break;

  case 18:
#line 136 "translate.y"
    {printf("SubDeclP\n");;}
    break;

  case 19:
#line 137 "translate.y"
    {printf("SubDeclF\n");;}
    break;

  case 20:
#line 140 "translate.y"
    {
                                    printf("TypeDef: %d %d\n", (yyvsp[(1) - (3)].idrespType)->idEntry, (yyvsp[(3) - (3)].typeinfo)->typeEntry);
                                    if((yyvsp[(3) - (3)].typeinfo)->additionType != NULL) {
                                        if(setSymbolTypeAttr((yyvsp[(1) - (3)].idrespType)->idEntry, -1, (yyvsp[(3) - (3)].typeinfo)) != 0) {
                                            //YYERROR;
                                        }
                                    }
                                    else {
                                        if(setSymbolTypeAttr((yyvsp[(1) - (3)].idrespType)->idEntry, (yyvsp[(3) - (3)].typeinfo)->typeEntry, (yyvsp[(3) - (3)].typeinfo)) != 0) {
                                            //YYERROR;
                                        }
                                    }
                                  ;}
    break;

  case 21:
#line 155 "translate.y"
    {
                                                    printf("VarDecl\n");
                                                    if(setIdListType((yyvsp[(3) - (3)].typeinfo)) == 0) {
                                                        //YYERROR;
                                                    }
                                                ;}
    break;

  case 22:
#line 163 "translate.y"
    {
                                        char *name = getNameInCurScope((yyvsp[(2) - (2)].idrespType)->idEntry);
                                        if(enterNewScope((yyvsp[(2) - (2)].idrespType)) != 0) {
                                            //YYERROR;
                                        }
                                        registerSymbolInCurScope(name);
                                    ;}
    break;

  case 23:
#line 171 "translate.y"
    {
                            printf("setting proc: %d %s\n", (yyvsp[(2) - (7)].idrespType)->idEntry, itoa(funcProcParamCount));
                            handleFuncProcDeclaration((yyvsp[(2) - (7)].idrespType), NULL, funcProcParamCount, "procedure");
                        ;}
    break;

  case 24:
#line 176 "translate.y"
    {
                        printf("ProcDecl\n");
                        popScopeStack();
                    ;}
    break;

  case 25:
#line 182 "translate.y"
    {
                                    char *name = getNameInCurScope((yyvsp[(2) - (2)].idrespType)->idEntry);
                                    if(enterNewScope((yyvsp[(2) - (2)].idrespType)) != 0) {
                                        //YYERROR;
                                    }
                                    registerSymbolInCurScope(name);
                                   ;}
    break;

  case 26:
#line 190 "translate.y"
    {
                                    printf("setting func: %d %s %d\n", (yyvsp[(2) - (9)].idrespType)->idEntry, itoa(funcProcParamCount), (yyvsp[(8) - (9)].typeinfo)->typeEntry);
                                    handleFuncProcDeclaration((yyvsp[(2) - (9)].idrespType), (yyvsp[(8) - (9)].typeinfo), funcProcParamCount, "function");
                                ;}
    break;

  case 27:
#line 195 "translate.y"
    {
                        printf("FuncDecl\n");
                        popScopeStack();
                    ;}
    break;

  case 28:
#line 201 "translate.y"
    {printf("PFDecl_Block\n");;}
    break;

  case 29:
#line 202 "translate.y"
    {printf("PFDecl_Forward\n");;}
    break;

  case 30:
#line 205 "translate.y"
    {printf("empty paramlist\n");;}
    break;

  case 31:
#line 206 "translate.y"
    {
                                                                            printf("FormalPList\n");
                                                                        ;}
    break;

  case 32:
#line 211 "translate.y"
    {
                                                        printf("Plist_single\n");
                                                        if(setIdListType((yyvsp[(3) - (3)].typeinfo)) == 0) {
                                                            //YYERROR;
                                                        }
                                                        funcProcParamCount = parameterCount;
                                                      ;}
    break;

  case 33:
#line 219 "translate.y"
    {printf("PList_M\n");;}
    break;

  case 35:
#line 223 "translate.y"
    {printf("Block_CompState\n");;}
    break;

  case 36:
#line 224 "translate.y"
    {printf("Block_CompSt_V\n");;}
    break;

  case 37:
#line 227 "translate.y"
    {printf("CompStBE\n");;}
    break;

  case 38:
#line 230 "translate.y"
    {printf("SteS\n");;}
    break;

  case 39:
#line 231 "translate.y"
    {printf("SteSSte\n");;}
    break;

  case 40:
#line 234 "translate.y"
    {printf("Statement_Simple\n");;}
    break;

  case 41:
#line 235 "translate.y"
    {printf("Statement_Structured\n");;}
    break;

  case 42:
#line 238 "translate.y"
    {printf("SimpleS_AssignState\n");;}
    break;

  case 43:
#line 239 "translate.y"
    {printf("SimpleSS_ProState\n");;}
    break;

  case 45:
#line 243 "translate.y"
    {printf("AssiState\n");;}
    break;

  case 46:
#line 246 "translate.y"
    {;}
    break;

  case 47:
#line 246 "translate.y"
    {printf("ProFuncStat\n");;}
    break;

  case 48:
#line 249 "translate.y"
    {printf("Struc_Comp\n");;}
    break;

  case 49:
#line 250 "translate.y"
    {printf("if_else\n");;}
    break;

  case 50:
#line 251 "translate.y"
    {printf("if_else_m\n");;}
    break;

  case 51:
#line 252 "translate.y"
    {printf("while_do\n");;}
    break;

  case 52:
#line 253 "translate.y"
    {printf("for_to\n");;}
    break;

  case 53:
#line 256 "translate.y"
    {
            printf("TypeID\n");
            if(typeHandler((yyvsp[(1) - (1)].idrespType)) == 0) {
                //YYERROR;
            }
            (yyval.typeinfo)->typeEntry = (yyvsp[(1) - (1)].idrespType)->idEntry;
          ;}
    break;

  case 54:
#line 263 "translate.y"
    {
                                                                        printf("Type_Array\n"); 
                                                                        (yyval.typeinfo)->typeEntry = (yyvsp[(8) - (8)].typeinfo)->typeEntry;
                                                                        (yyval.typeinfo)->additionType = "array";
                                                                        (yyval.typeinfo)->attrInfo.arrayInfo.boundLow = (yyvsp[(3) - (8)].intType);
                                                                        (yyval.typeinfo)->attrInfo.arrayInfo.boundUp = (yyvsp[(5) - (8)].intType);
                                                                      ;}
    break;

  case 55:
#line 270 "translate.y"
    {
                                        int i = 0;
                                        printf("Type_sub\n"); 
                                        (yyval.typeinfo)->typeEntry = -1;
                                        (yyval.typeinfo)->additionType = "record";
                                        (yyval.typeinfo)->attrInfo.recordInfo.qty = maxSetEntryId;
                                        for(i = 0; i < maxSetEntryId; i ++) {
                                            (yyval.typeinfo)->attrInfo.recordInfo.recordMembers[i] = latestSetEntries[i];
                                        }
                                      ;}
    break;

  case 56:
#line 282 "translate.y"
    {
                    printf("ResultType\n");
                    if(typeHandler((yyvsp[(1) - (1)].idrespType)) == 0) {
                        //YYERROR;
                    }
                    (yyval.typeinfo)->typeEntry = (yyvsp[(1) - (1)].idrespType)->idEntry;
                    printf("result type: %d\n", (yyval.typeinfo)->typeEntry);
                ;}
    break;

  case 57:
#line 292 "translate.y"
    {printf("Constant_SIGN_INT\n"); (yyval.intType) = getConstantInt((yyvsp[(1) - (2)].stringType), (yyvsp[(2) - (2)].intType));;}
    break;

  case 58:
#line 293 "translate.y"
    {printf("Constant_INT\n"); (yyval.intType) = getConstantInt(NULL, (yyvsp[(1) - (1)].intType));;}
    break;

  case 59:
#line 296 "translate.y"
    {printf("Exp_simp\n");;}
    break;

  case 60:
#line 297 "translate.y"
    {printf("Exp_Simp_Ro\n");;}
    break;

  case 61:
#line 300 "translate.y"
    {printf("RelationalOp_EQ\n");;}
    break;

  case 62:
#line 301 "translate.y"
    {printf("RelationslOp_Less\n");;}
    break;

  case 63:
#line 302 "translate.y"
    {printf("RelationslOp_LE\n");;}
    break;

  case 64:
#line 303 "translate.y"
    {printf("RelationslOp_G\n");;}
    break;

  case 65:
#line 304 "translate.y"
    {printf("RelationslOp_GE\n");;}
    break;

  case 66:
#line 305 "translate.y"
    {printf("RelationslOp_NE\n");;}
    break;

  case 67:
#line 308 "translate.y"
    {printf("SimpleExp_Sign_AddTerm\n");;}
    break;

  case 68:
#line 309 "translate.y"
    {printf("SimpleExp_AddTerm\n");;}
    break;

  case 69:
#line 312 "translate.y"
    {printf("AddOpTerm_Mul\n");;}
    break;

  case 70:
#line 313 "translate.y"
    {printf("AddOpTerm_Single\n");;}
    break;

  case 71:
#line 316 "translate.y"
    {printf("AddOp_Add\n");;}
    break;

  case 72:
#line 317 "translate.y"
    {printf("AddOp_Min\n");;}
    break;

  case 73:
#line 318 "translate.y"
    {printf("AddOp_OR\n");;}
    break;

  case 74:
#line 321 "translate.y"
    {printf("Term_Fac_Mul\n");;}
    break;

  case 75:
#line 324 "translate.y"
    {printf("MulOpTerm\n");;}
    break;

  case 77:
#line 328 "translate.y"
    {printf("MulOp_MUL\n");;}
    break;

  case 78:
#line 329 "translate.y"
    {printf("MulOp_DIV\n");;}
    break;

  case 79:
#line 330 "translate.y"
    {printf("MulOp_MOD\n");;}
    break;

  case 80:
#line 331 "translate.y"
    {printf("MulOp_AND\n");;}
    break;

  case 81:
#line 334 "translate.y"
    {printf("Factor_INT\n");;}
    break;

  case 82:
#line 335 "translate.y"
    {printf("Factor_String\n");;}
    break;

  case 83:
#line 336 "translate.y"
    {printf("Factor_FuncRef\n");;}
    break;

  case 84:
#line 337 "translate.y"
    {printf("Factor_Var\n");;}
    break;

  case 85:
#line 338 "translate.y"
    {printf("Factor_N_Fac\n");;}
    break;

  case 86:
#line 339 "translate.y"
    {printf("Factor_Exp\n");;}
    break;

  case 87:
#line 342 "translate.y"
    {
                int isDefined;
                int preDefEntry;
                printf("Var\n");
                printf("checking var %d %s\n", (yyvsp[(1) - (1)].idrespType)->idEntry, (yyvsp[(1) - (1)].idrespType)->idStr);
                if(isIdDefined((yyvsp[(1) - (1)].idrespType)) == 0) {
                    preDefEntry = getDefInParentScope((yyvsp[(1) - (1)].idrespType)->idStr);
                    if(preDefEntry >= 0) {
                        printf("var %s defined in enclosing scope at %d\n", 
                            (yyvsp[(1) - (1)].idrespType)->idStr, preDefEntry);
                        removeTailSymbolFromCurScope();
                        (yyvsp[(1) - (1)].idrespType)->idEntry = preDefEntry;
                        (yyvsp[(1) - (1)].idrespType)->idRespStatus = -3;//defined in enclosing scope
                    }
                    else {
                        fprintf(stderr, "Undeclared var: %s\n", (yyvsp[(1) - (1)].idrespType)->idStr);
                        //YYERROR;
                    }
                }
              ;}
    break;

  case 89:
#line 365 "translate.y"
    {printf("CompSel_Dot\n");;}
    break;

  case 90:
#line 366 "translate.y"
    {printf("CompSel_Exp\n");;}
    break;

  case 92:
#line 370 "translate.y"
    {printf("ActualParamL\n");;}
    break;

  case 93:
#line 371 "translate.y"
    {printf("ActualParamL\n");;}
    break;

  case 94:
#line 374 "translate.y"
    {printf("ExpM\n");;}
    break;

  case 96:
#line 378 "translate.y"
    {
                                        printf("IdList\n");
                                        addCurParamCounter(1);
                                        appendToIdList((yyvsp[(1) - (2)].idrespType)->idEntry);
                                       ;}
    break;

  case 97:
#line 385 "translate.y"
    {printf("IdListM\n");;}
    break;

  case 99:
#line 389 "translate.y"
    {printf("Sign_Add\n"); (yyval.stringType) = "+";;}
    break;

  case 100:
#line 390 "translate.y"
    {printf("Sign_Min\n"); (yyval.stringType) = "-";;}
    break;


/* Line 1267 of yacc.c.  */
#line 2196 "translate.tab.c"
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


#line 393 "translate.y"

yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
}

int getConstantInt(char *sign, int num) {
    if(sign == NULL || strcmp(sign, "+") == 0) {
        return num;
    }
    return 0 - num;
}

void addCurParamCounter(int delta) {
    parameterCount += delta;
}

void cleanCurParamCounter() {
    parameterCount = 0;
}

void cleanCurFuncProcParamCounter() {
    funcProcParamCount = 0;
}

char * itoa(int a) {
    char * buf = (char *)malloc(sizeof(a) + 1);
    sprintf(buf, "%d", a);
    return buf;
}

int setIdListType(struct TypeInfo *retType) {
    char *info = setIdListTypeAttr(retType->typeEntry, retType->attrInfo);
    if(info != NULL) {
        fprintf(stderr, "%s", info);
        return 0;
    }
    return 1;
}

void handleFuncProcDeclaration(struct IdResp *id, struct TypeInfo *retType, int paramQty, char *funcProc) {
        union SymbolEntryAttr attr;
        attr.attr = NULL;
        if(strcmp(funcProc, "function") == 0) {
            //set function parameter's type as return type
            setFuncVarInScope(id->idStr, id->idEntry, retType->typeEntry, attr);
            registerFunc(id->idEntry, retType->typeEntry, retType->attrInfo, paramQty);
        }
        else {
            setSymbolTypeAttrInCurScope(0, getType("NIL"), attr);
            registerProc(id->idEntry, paramQty);
        }
        cleanCurParamCounter();
        cleanCurFuncProcParamCounter();
}

int enterNewScope(struct IdResp *id) {
    char *name = "";
    if(id->idRespStatus != 0) {
        name = getNameInCurScope(id->idEntry);
        fprintf(stderr, "invalid function/procedure ID: %s\n", name);
        return -1;
    }
    newScopeAndPush(id->idEntry);
    return 0;
}

int setSymbolTypeAttr(int idAddr, int typeEntry, struct TypeInfo *typedata) {
    int resp;
    char *name;
    entryAttr attr;
    int i = 0;

    if(typedata->additionType != NULL) {
        typeEntry = getType(typedata->additionType);
        if(strcmp(typedata->additionType, "array")) {
            attr.arrayInfo.boundLow = typedata->attrInfo.arrayInfo.boundLow;
            attr.arrayInfo.boundUp = typedata->attrInfo.arrayInfo.boundUp;
            attr.arrayInfo.typeEntry = typedata->typeEntry;
        }
        else if(strcmp(typedata->additionType, "record")) {
            attr.recordInfo.qty = typedata->attrInfo.recordInfo.qty;
            for(i = 0; i < attr.recordInfo.qty; i ++) {
                attr.recordInfo.recordMembers[i] = typedata->attrInfo.recordInfo.recordMembers[i];
            }
        }
    }

    resp = setSymbolTypeAttrInCurScope(idAddr, typeEntry, attr);
    if(resp == -1) {
        name = getNameInCurScope(idAddr);
        fprintf(stderr, "Redefinition of symbol %s\n", name);
        return -1;
    }
    return 0;
}

int typeHandler(struct IdResp *idResp) {
    char *name = "";
    printf("handling type: %s\n", idResp->idStr);
    int entry;
    if(idResp->idRespStatus == -1) {
        return 1;
    }
    entry = getType(idResp->idStr);
    if(entry >= 0) {
        idResp->idEntry = entry;
        return 1;
    }
    else {
        entry = getTypeInParentScope(idResp->idStr);
        if(entry >= 0) {
            idResp->idEntry = entry;
            idResp->idRespStatus = -2;
            return 1;
        }
    }
    fprintf(stderr, "Invalid type: %s\n", idResp->idStr);
    return 0;
}

int isIdDefined(struct IdResp *id) {
    if(getIDTypeStr(id->idEntry) == NULL) {
        return 0;
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    FILE * fstream;
    initTypeDescList();
    initPredefinedSymboltable();
    initScope();
    ++argv, --argc;    /* skip argv[0] */
    if (argc > 0) {
        yyin = fopen(argv[0], "r");
    } else {
        yyin = stdin;
    }
    printf("\n\nParsing...:\n\n");
    //fstream = stdout;
    //stdout=fopen("parser_debug.out","w");
    yyparse();
    //close(stdout);
    //stdout = fstream;
    printf("\n\nParsing done (debugging info: parser_debug.out).\n\n");
    //stdout=fopen("symtable.out","w");
    printAllSymbolTable();
    //close(stdout);
    //stdout = fstream;
    printf("Done, symbole table: symtable.out\n\n");
    //close(fstream);
    return 0;
}

