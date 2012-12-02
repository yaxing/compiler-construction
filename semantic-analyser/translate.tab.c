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
    
extern FILE *yyin;
extern int count;
extern char* yytext;
    
int const CONTEXT_NORMAL = 0;
int const CONTEXT_ARRAY = 1;
int const CONTEXT_RECORD = 2;

int parameterCount = 0;
int curRecordScopeHash = 0;

int context = 0;
    
idresp *curVarIdResp = NULL;
idresp *curTypeIdResp = NULL;
int curTypeIdDefScopeId = -2;
    
curArrayType *curArrayTypeInfo = NULL;
    
void printLineNo();
    
void yyerror_unequal_type(struct TypeInfo *type1, struct TypeInfo *type2);
    
int getConstantInt(char *sign, int num);

void addCurParamCounter(int delta);

void cleanCurParamCounter();

int setIdListType(struct TypeInfo *retType);

void handleFuncProcDeclaration(struct IdResp *id, typeinfost *retType, int paramQty, char *funcProc);

int enterNewScope(struct IdResp *id);

int setSymbolTypeAttr(int idAddr, int typeEntry, typeinfost *typedata, int attrTag);

int typeHandler(idresp **idResp);

int isIdDefined(struct IdResp *id);
    
int certainTypeCheck(struct TypeInfo *type, char *typeToCheck);

int contextSwitch(struct IdResp *idInfo);
    
void resetCurTypeEnvironment();


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
#line 52 "translate.y"
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
#line 260 "translate.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 273 "translate.tab.c"

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
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNRULES -- Number of states.  */
#define YYNSTATES  197

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
     186,   193,   198,   207,   209,   218,   219,   224,   226,   229,
     231,   233,   237,   239,   241,   243,   245,   247,   249,   252,
     254,   258,   260,   262,   264,   266,   269,   271,   274,   276,
     278,   280,   282,   284,   286,   288,   290,   293,   297,   298,
     302,   303,   307,   308,   309,   310,   318,   319,   320,   324,
     325,   326,   331,   332,   335,   338,   339,   341
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
      62,    -1,    65,    -1,    46,    28,    81,    -1,   105,    36,
      81,    -1,    -1,    -1,    17,    46,    63,    40,    69,    41,
      37,    64,    68,    -1,    -1,    -1,    10,    46,    66,    40,
      69,    41,    36,    83,    37,    67,    68,    -1,    72,    -1,
       4,    -1,    -1,    70,    71,    -1,   105,    36,    81,    -1,
      37,    69,    -1,    -1,    73,    -1,    56,    73,    -1,     3,
      74,     8,    -1,    75,    -1,    74,    37,    75,    -1,    76,
      -1,    80,    -1,    77,    -1,    78,    -1,    -1,    94,    38,
      85,    -1,    -1,    46,    79,    40,   101,    41,    -1,    73,
      -1,    11,    85,    20,    75,    -1,    11,    85,    20,    75,
       7,    75,    -1,    24,    85,     6,    75,    -1,     9,    46,
      38,    85,    21,    85,     6,    75,    -1,    46,    -1,    12,
      42,    84,    39,    84,    43,    15,    81,    -1,    -1,    19,
      82,    69,     8,    -1,    46,    -1,   107,    44,    -1,    44,
      -1,    87,    -1,    87,    86,    87,    -1,    28,    -1,    29,
      -1,    30,    -1,    31,    -1,    32,    -1,    33,    -1,   107,
      88,    -1,    88,    -1,    90,    89,    88,    -1,    90,    -1,
      25,    -1,    27,    -1,    16,    -1,    93,    91,    -1,    93,
      -1,    92,    90,    -1,    26,    -1,     5,    -1,    13,    -1,
      48,    -1,    44,    -1,    47,    -1,    78,    -1,    94,    -1,
      14,    93,    -1,    40,    85,    41,    -1,    -1,    46,    95,
      96,    -1,    -1,    34,    97,    94,    -1,    -1,    -1,    -1,
      42,    98,    85,    99,    43,   100,    96,    -1,    -1,    -1,
      85,   102,   103,    -1,    -1,    -1,    35,    85,   104,   103,
      -1,    -1,    46,   106,    -1,    35,   105,    -1,    -1,    25,
      -1,    27,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   130,   130,   131,   132,   133,   134,   135,   136,   137,
     140,   143,   144,   147,   155,   156,   159,   160,   163,   164,
     167,   179,   191,   199,   191,   213,   222,   213,   236,   237,
     240,   241,   247,   257,   258,   261,   262,   265,   268,   269,
     272,   273,   276,   277,   278,   281,   293,   293,   338,   339,
     347,   353,   359,   370,   382,   396,   396,   417,   435,   436,
     439,   446,   459,   460,   461,   462,   463,   464,   467,   473,
     482,   500,   509,   510,   511,   514,   531,   539,   547,   548,
     549,   550,   553,   562,   571,   577,   583,   591,   600,   600,
     662,   662,   691,   699,   704,   691,   731,   737,   737,   742,
     745,   745,   753,   756,   765,   766,   769,   770
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
  "Type", "@6", "ResultType", "Constant", "Expression", "RelationalOp",
  "SimpleExpression", "AddOpTerm", "AddOp", "Term", "MulOpTerm", "MulOp",
  "Factor", "Variable", "@7", "ComponentSelection", "@8", "@9", "@10",
  "@11", "ActualParameterList", "@12", "ExpressionMore", "@13",
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
      80,    80,    80,    81,    81,    82,    81,    83,    84,    84,
      85,    85,    86,    86,    86,    86,    86,    86,    87,    87,
      88,    88,    89,    89,    89,    90,    90,    91,    92,    92,
      92,    92,    93,    93,    93,    93,    93,    93,    95,    94,
      97,    96,    98,    99,   100,    96,    96,   102,   101,   101,
     104,   103,   103,   105,   106,   106,   107,   107
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     6,     6,     6,     7,     7,     7,     8,
       2,     2,     3,     2,     2,     3,     3,     2,     1,     1,
       3,     3,     0,     0,     9,     0,     0,    11,     1,     1,
       0,     2,     3,     2,     0,     1,     2,     3,     1,     3,
       1,     1,     1,     1,     0,     3,     0,     5,     1,     4,
       6,     4,     8,     1,     8,     0,     4,     1,     2,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     1,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     0,     3,
       0,     3,     0,     0,     0,     7,     0,     0,     3,     0,
       0,     4,     0,     2,     2,     0,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    44,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    19,     0,     0,     0,
       0,    88,    48,     0,    38,    40,    42,    43,    41,     0,
      25,    22,     0,    10,     0,   105,    13,     0,     0,     0,
       0,     0,     0,     0,     0,    17,     2,     0,     0,   106,
     107,     0,    82,    83,    84,     0,    60,    69,    71,    76,
      85,     0,     0,     0,    96,    37,    44,     0,     0,     0,
       0,    11,     0,   103,    14,     0,     0,     0,     0,     3,
       0,     4,     5,    16,     0,    86,     0,    44,    62,    63,
      64,    65,    66,    67,     0,    74,    72,    73,     0,    79,
      80,    78,    81,    75,     0,    68,    44,    99,    90,    92,
      89,    39,    45,    30,    30,     0,    55,    53,    20,    12,
     104,    15,    21,     0,     6,     8,     7,     0,    87,    49,
      61,    70,    77,    51,    97,     0,     0,     0,     0,    34,
       0,     0,     0,    30,     9,     0,    44,   102,    47,    88,
      91,    93,     0,    30,    31,     0,     0,    59,     0,     0,
       0,     0,    50,     0,    98,     0,     0,    33,    32,    23,
       0,    58,    56,    44,   100,    94,    57,     0,     0,     0,
      52,   102,    96,    26,    29,     0,    24,    28,    35,     0,
     101,    95,     0,    36,     0,    27,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    11,    33,   185,    36,    13,    14,    34,    37,
      15,    69,   178,    16,    68,   192,   186,   138,   139,   154,
     187,    22,    23,    24,    25,    26,    54,    63,    28,   118,
     143,   177,   158,    55,    94,    56,    57,    98,    58,   103,
     104,    59,    60,    64,   110,   136,   137,   165,   182,   135,
     147,   164,   181,   140,    73,    61
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -126
static const yytype_int16 yypact[] =
{
       6,   -21,    29,     1,  -126,    87,     7,    21,    23,    32,
      35,    69,    95,    40,    19,  -126,  -126,    13,    49,    30,
      30,    56,  -126,     5,  -126,  -126,  -126,  -126,  -126,    62,
    -126,  -126,    73,  -126,    70,    71,  -126,    74,    72,    95,
      40,    79,    40,    80,    81,    42,  -126,    82,    47,  -126,
    -126,    30,  -126,  -126,  -126,    97,   105,  -126,    48,    10,
    -126,    47,   113,    83,   -14,  -126,     7,    30,    85,    88,
       0,    32,    35,  -126,    35,     0,    40,    93,    96,  -126,
     106,  -126,  -126,  -126,    30,  -126,    90,     7,  -126,  -126,
    -126,  -126,  -126,  -126,    30,  -126,  -126,  -126,    47,  -126,
    -126,  -126,  -126,  -126,    47,  -126,     7,    30,  -126,  -126,
    -126,  -126,  -126,    35,    35,    99,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,   111,  -126,  -126,  -126,   100,  -126,   115,
    -126,  -126,  -126,  -126,  -126,    98,   101,    30,   107,    92,
     110,   108,    55,    35,  -126,    30,     7,   116,  -126,  -126,
    -126,  -126,   114,    35,  -126,     0,   117,  -126,   118,   109,
     144,   149,  -126,    30,  -126,   119,   112,  -126,  -126,  -126,
      55,  -126,  -126,     7,  -126,  -126,  -126,   122,    18,   120,
    -126,   116,   -14,  -126,  -126,    40,  -126,  -126,  -126,   141,
    -126,  -126,    18,  -126,     0,  -126,  -126
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -126,  -126,  -126,    89,    28,    91,    15,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,   -31,  -103,  -126,  -126,
    -126,    -5,  -126,   -57,  -126,  -126,    -3,  -126,  -126,   -70,
    -126,  -126,    -2,   -19,  -126,    77,   -47,  -126,    60,  -126,
    -126,   124,    -4,  -126,   -16,  -126,  -126,  -126,  -126,  -126,
    -126,    -7,  -126,    -6,  -126,  -125
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -47
static const yytype_int16 yytable[] =
{
      17,    62,    29,    27,    38,   122,    41,    43,    44,   111,
       6,   141,   115,    65,   105,    99,    18,   159,    19,   116,
     108,     6,   184,   100,     1,     3,    40,    42,   109,     4,
     129,    20,    86,    12,    77,    78,   101,    80,     5,    39,
     160,    10,    66,     6,    48,   159,   117,    46,   112,   133,
     167,   131,     7,    21,    76,    49,    45,    50,   102,     8,
      83,    48,    29,    27,    95,   127,   120,    30,    38,    31,
      51,   123,     6,    96,    52,    97,    21,    53,    32,     7,
      49,    35,    50,    29,    27,   168,     8,    51,   134,   162,
       6,    52,    10,    21,    53,    47,   -46,     7,     6,   157,
      67,    70,    29,    27,     8,     7,    72,    71,    75,     9,
      10,    74,     8,    79,    81,    82,   180,    87,   151,   106,
      84,   145,   146,   107,   196,   113,   161,   124,   114,   153,
     125,   128,   150,    88,    89,    90,    91,    92,    93,   148,
     126,   142,    29,    27,   174,   144,   155,   149,   152,   156,
     166,   163,   172,   171,   169,   173,   194,   170,   176,   183,
     119,   195,   175,   189,   132,   121,   191,     0,   179,    29,
      27,   130,    85,   188,   190,     0,     0,     0,     0,     0,
     193,     0,     0,     0,     0,     0,     0,   188
};

static const yytype_int16 yycheck[] =
{
       5,    20,     6,     6,    10,    75,    11,    12,    13,    66,
       3,   114,    12,     8,    61,     5,     9,   142,    11,    19,
      34,     3,     4,    13,    18,    46,    11,    12,    42,     0,
      87,    24,    51,     5,    39,    40,    26,    42,    37,    11,
     143,    23,    37,     3,    14,   170,    46,    34,    67,   106,
     153,    98,    10,    46,    39,    25,    37,    27,    48,    17,
      45,    14,    66,    66,    16,    84,    72,    46,    74,    46,
      40,    76,     3,    25,    44,    27,    46,    47,    46,    10,
      25,    46,    27,    87,    87,   155,    17,    40,   107,   146,
       3,    44,    23,    46,    47,    46,    40,    10,     3,    44,
      38,    28,   106,   106,    17,    10,    35,    37,    36,    22,
      23,    37,    17,    34,    34,    34,   173,    20,   137,     6,
      38,    21,     7,    40,   194,    40,   145,    34,    40,    37,
      34,    41,   136,    28,    29,    30,    31,    32,    33,    41,
      34,    42,   146,   146,   163,    34,    36,    46,    41,    41,
      36,    35,     8,    44,    37,     6,    15,    39,    46,    37,
      71,   192,    43,    43,   104,    74,   182,    -1,   170,   173,
     173,    94,    48,   178,   181,    -1,    -1,    -1,    -1,    -1,
     185,    -1,    -1,    -1,    -1,    -1,    -1,   192
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    53,    46,     0,    37,     3,    10,    17,    22,
      23,    54,    56,    58,    59,    62,    65,    73,     9,    11,
      24,    46,    73,    74,    75,    76,    77,    78,    80,    94,
      46,    46,    46,    55,    60,    46,    57,    61,   105,    56,
      58,    73,    58,    73,    73,    37,    34,    46,    14,    25,
      27,    40,    44,    47,    78,    85,    87,    88,    90,    93,
      94,   107,    85,    79,    95,     8,    37,    38,    66,    63,
      28,    37,    35,   106,    37,    36,    58,    73,    73,    34,
      73,    34,    34,    58,    38,    93,    85,    20,    28,    29,
      30,    31,    32,    33,    86,    16,    25,    27,    89,     5,
      13,    26,    48,    91,    92,    88,     6,    40,    34,    42,
      96,    75,    85,    40,    40,    12,    19,    46,    81,    55,
     105,    57,    81,    73,    34,    34,    34,    85,    41,    75,
      87,    88,    90,    75,    85,   101,    97,    98,    69,    70,
     105,    69,    42,    82,    34,    21,     7,   102,    41,    46,
      94,    85,    41,    37,    71,    36,    41,    44,    84,   107,
      69,    85,    75,    35,   103,    99,    36,    69,    81,    37,
      39,    44,     8,     6,    85,    43,    46,    83,    64,    84,
      75,   104,   100,    37,     4,    56,    68,    72,    73,    43,
     103,    96,    67,    73,    15,    68,    81
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
#line 130 "translate.y"
    {if(MODE_DEBUG == 1){printf("Program\n");};}
    break;

  case 3:
#line 131 "translate.y"
    {if(MODE_DEBUG == 1){printf("Program\n");};}
    break;

  case 4:
#line 132 "translate.y"
    {if(MODE_DEBUG == 1){printf("Program\n");};}
    break;

  case 5:
#line 133 "translate.y"
    {if(MODE_DEBUG == 1){printf("Program\n");};}
    break;

  case 6:
#line 134 "translate.y"
    {if(MODE_DEBUG == 1){printf("Program\n");};}
    break;

  case 7:
#line 135 "translate.y"
    {if(MODE_DEBUG == 1){printf("Program\n");};}
    break;

  case 8:
#line 136 "translate.y"
    {if(MODE_DEBUG == 1){printf("Program\n");};}
    break;

  case 9:
#line 137 "translate.y"
    {if(MODE_DEBUG == 1){printf("Program\n");};}
    break;

  case 10:
#line 140 "translate.y"
    {if(MODE_DEBUG == 1){printf("TypeDef_Mul\n");}cleanCurParamCounter();;}
    break;

  case 11:
#line 143 "translate.y"
    {if(MODE_DEBUG == 1){printf("TypeDefList\n");};}
    break;

  case 12:
#line 144 "translate.y"
    {if(MODE_DEBUG == 1){printf("TypeDefList_Multi\n");};}
    break;

  case 13:
#line 147 "translate.y"
    {
                            if(MODE_DEBUG == 1){
                                printf("VarDecl_Mul\n");
                            }
                            cleanCurParamCounter();
                        ;}
    break;

  case 14:
#line 155 "translate.y"
    {if(MODE_DEBUG == 1){printf("VarDeclList\n");};}
    break;

  case 15:
#line 156 "translate.y"
    {if(MODE_DEBUG == 1){printf("VarDeclList_Mul\n");};}
    break;

  case 16:
#line 159 "translate.y"
    {if(MODE_DEBUG == 1){printf("SubDecl_mul\n");};}
    break;

  case 17:
#line 160 "translate.y"
    {if(MODE_DEBUG == 1){printf("SubDecl_Mul\n");};}
    break;

  case 18:
#line 163 "translate.y"
    {if(MODE_DEBUG == 1){printf("SubDeclP\n");};}
    break;

  case 19:
#line 164 "translate.y"
    {if(MODE_DEBUG == 1){printf("SubDeclF\n");};}
    break;

  case 20:
#line 167 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("TypeDef: id: %d type: %d tag: %d\n", (yyvsp[(1) - (3)].idrespType)->idEntry, (yyvsp[(3) - (3)].typeinfo)->typeEntry, (yyvsp[(3) - (3)].typeinfo)->tag);
    }
    if(setSymbolTypeAttr((yyvsp[(1) - (3)].idrespType)->idEntry, (yyvsp[(3) - (3)].typeinfo)->typeEntry, (yyvsp[(3) - (3)].typeinfo), ATTR_TYPE) != 0) {
        //YYERROR;
    }
    free((yyvsp[(3) - (3)].typeinfo));
    resetCurTypeEnvironment();
;}
    break;

  case 21:
#line 180 "translate.y"
    {
                          if(MODE_DEBUG == 1){
                              printf("VarDecl\n");
                          }
                          if(setIdListType((yyvsp[(3) - (3)].typeinfo)) == 0) {
                            //YYERROR;
                          }
                          free((yyvsp[(3) - (3)].typeinfo));
                      ;}
    break;

  case 22:
#line 191 "translate.y"
    {
                                        char *name = getNameInCurScope((yyvsp[(2) - (2)].idrespType)->idEntry);
                                        if(enterNewScope((yyvsp[(2) - (2)].idrespType)) != 0) {
                                            //YYERROR;
                                        }
                                        cleanCurFuncProcCallParamCounter();
                                    ;}
    break;

  case 23:
#line 199 "translate.y"
    {
                            if(MODE_DEBUG == 1){
                                printf("setting proc: %d %s\n", (yyvsp[(2) - (7)].idrespType)->idEntry, itoa(funcProcParamCount));
                            }
                            handleFuncProcDeclaration((yyvsp[(2) - (7)].idrespType), NULL, funcProcParamCount, "procedure");
                        ;}
    break;

  case 24:
#line 205 "translate.y"
    {
                            if(MODE_DEBUG == 1){
                                printf("ProcDecl\n");
                            }
                            popScopeStack();
                        ;}
    break;

  case 25:
#line 213 "translate.y"
    {
                                    char *name = getNameInCurScope((yyvsp[(2) - (2)].idrespType)->idEntry);
                                    if(enterNewScope((yyvsp[(2) - (2)].idrespType)) != 0) {
                                        //YYERROR;
                                    }
                                    registerSymbolInCurScope(name);
                                    cleanCurFuncProcCallParamCounter();
                                   ;}
    break;

  case 26:
#line 222 "translate.y"
    {
                                    if(MODE_DEBUG == 1){
                                        printf("setting func: %d %s %d\n", (yyvsp[(2) - (9)].idrespType)->idEntry, itoa(funcProcParamCount), (yyvsp[(8) - (9)].typeinfo)->typeEntry);
                                    }
                                    handleFuncProcDeclaration((yyvsp[(2) - (9)].idrespType), (yyvsp[(8) - (9)].typeinfo), funcProcParamCount, "function");
                                ;}
    break;

  case 27:
#line 228 "translate.y"
    {
                          if(MODE_DEBUG == 1){
                              printf("FuncDecl\n");
                          }
                          popScopeStack();
                      ;}
    break;

  case 28:
#line 236 "translate.y"
    {if(MODE_DEBUG == 1){printf("PFDecl_Block\n");};}
    break;

  case 29:
#line 237 "translate.y"
    {if(MODE_DEBUG == 1){printf("PFDecl_Forward\n");};}
    break;

  case 30:
#line 240 "translate.y"
    {if(MODE_DEBUG == 1){printf("empty paramlist\n");};}
    break;

  case 31:
#line 242 "translate.y"
    {
                          if(MODE_DEBUG == 1){printf("FormalPList\n");}
                      ;}
    break;

  case 32:
#line 247 "translate.y"
    {
                                                        if(MODE_DEBUG == 1){
                                                            printf("Plist_single\n");
                                                        }
                                                        if(setIdListType((yyvsp[(3) - (3)].typeinfo)) == 0) {
                                                            //YYERROR;
                                                        }
                                                        funcProcParamCount = parameterCount;
                                                      ;}
    break;

  case 33:
#line 257 "translate.y"
    {if(MODE_DEBUG == 1){printf("PList_M\n");};}
    break;

  case 35:
#line 261 "translate.y"
    {if(MODE_DEBUG == 1){printf("Block_CompState\n");};}
    break;

  case 36:
#line 262 "translate.y"
    {if(MODE_DEBUG == 1){printf("Block_CompSt_V\n");};}
    break;

  case 37:
#line 265 "translate.y"
    {if(MODE_DEBUG == 1){printf("CompStBE\n");};}
    break;

  case 38:
#line 268 "translate.y"
    {if(MODE_DEBUG == 1){printf("SteS\n");};}
    break;

  case 39:
#line 269 "translate.y"
    {if(MODE_DEBUG == 1){printf("SteSSte\n");};}
    break;

  case 40:
#line 272 "translate.y"
    {if(MODE_DEBUG == 1){printf("Statement_Simple\n");};}
    break;

  case 41:
#line 273 "translate.y"
    {if(MODE_DEBUG == 1){printf("Statement_Structured\n");};}
    break;

  case 42:
#line 276 "translate.y"
    {if(MODE_DEBUG == 1){printf("SimpleS_AssignState\n");};}
    break;

  case 43:
#line 277 "translate.y"
    {if(MODE_DEBUG == 1){printf("SimpleSS_ProState\n");};}
    break;

  case 45:
#line 281 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("AssiState\n");
        printf("assign var type: %d\n", (yyvsp[(1) - (3)].typeinfo)->typeEntry);
    }
    if(!typeCheck((yyvsp[(1) - (3)].typeinfo), (yyvsp[(3) - (3)].typeinfo))) {
        yyerror_unequal_type((yyvsp[(1) - (3)].typeinfo), (yyvsp[(3) - (3)].typeinfo));
    }
;}
    break;

  case 46:
#line 293 "translate.y"
    {
                        cleanCurFuncProcCallParamCounter();
                    ;}
    break;

  case 47:
#line 296 "translate.y"
    {
                        int defined;
                        int preDefEntry;
                        char *info;
                        defined = isIdDefined((yyvsp[(1) - (5)].idrespType));
                        if(MODE_DEBUG == 1){
                            printf("ProFuncStat\n");
                            printf("checking func/proc %d %s\n", (yyvsp[(1) - (5)].idrespType)->idEntry, (yyvsp[(1) - (5)].idrespType)->idStr);
                        }
                        if(defined == 0) {
                            preDefEntry = getFuncProcDefInParentScope((yyvsp[(1) - (5)].idrespType)->idStr);
                            if(preDefEntry >= 0) {
                                if(MODE_DEBUG == 1){
                                    printf("func/proc %s defined in enclosing scope at %d\n", (yyvsp[(1) - (5)].idrespType)->idStr, preDefEntry);
                                }
                                removeTailSymbolFromCurScope();
                                (yyvsp[(1) - (5)].idrespType)->idEntry = preDefEntry;
                                (yyvsp[(1) - (5)].idrespType)->idRespStatus = IDRESP_DEF_IN_PARENT;//defined in enclosing scope
                                defined = 1;
                            }
                            else {
                                printLineNo();
                                fprintf(stderr, "Undeclared func/proc: %s\n", (yyvsp[(1) - (5)].idrespType)->idStr);
                                //YYERROR;
                            }
                        }
                        if(defined) {
                            info = checkFuncProcCallParamType((yyvsp[(1) - (5)].idrespType));
                            if(info != NULL) {
                                fprintf(stderr, "%s\n", info);
                                free(info);
                                //YYERROR;
                            }
                        }
                        destroyParamTypeList();
                        cleanCurFuncProcCallParamCounter();
                        constructTypeInfoFromIdResp(&(yyval.typeinfo), (yyvsp[(1) - (5)].idrespType));
                        (yyval.typeinfo)->tag = ATTR_VAR;
                        //put in table, create tmp
                    ;}
    break;

  case 48:
#line 338 "translate.y"
    {if(MODE_DEBUG == 1){printf("Struc_Comp\n");};}
    break;

  case 49:
#line 339 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("if_else\n");
    }
    if(!certainTypeCheck((yyvsp[(2) - (4)].typeinfo), "boolean")) {
        fprintf(stderr, "If Condition is not boolean\n");
    }
;}
    break;

  case 50:
#line 347 "translate.y"
    {
    if(MODE_DEBUG == 1){printf("if_else_m\n");}
    if(!certainTypeCheck((yyvsp[(2) - (6)].typeinfo), "boolean")) {
        fprintf(stderr, "If Condition is not boolean\n");
    }
;}
    break;

  case 51:
#line 353 "translate.y"
    {
    if(MODE_DEBUG == 1){printf("while_do\n");}
    if(!certainTypeCheck((yyvsp[(2) - (4)].typeinfo), "boolean")) {
        fprintf(stderr, "While Condition is not boolean\n");
    }
;}
    break;

  case 52:
#line 359 "translate.y"
    {
    if(MODE_DEBUG == 1){printf("for_to\n");}
    struct TypeInfo *idType;
    constructTypeInfoFromIdResp(&idType, (yyvsp[(2) - (8)].idrespType));
    if(!typeCheck(idType, (yyvsp[(4) - (8)].typeinfo))) {
        yyerror_unequal_type(idType, (yyvsp[(4) - (8)].typeinfo));
    }
    free(idType);
;}
    break;

  case 53:
#line 370 "translate.y"
    {
            if(MODE_DEBUG == 1){
                printf("TypeID %d\n", (yyvsp[(1) - (1)].idrespType)->idEntry);
            }
            typeHandler(&(yyvsp[(1) - (1)].idrespType));
            constructTypeInfoFromIdResp(&(yyval.typeinfo), (yyvsp[(1) - (1)].idrespType));
            (yyval.typeinfo)->tag = ATTR_TYPE;
            if(MODE_DEBUG == 1){
                printAllSymbolTable();
            }
            curTypeIdResp = (yyvsp[(1) - (1)].idrespType);
          ;}
    break;

  case 54:
#line 383 "translate.y"
    {
           if(MODE_DEBUG == 1){
               printf("Type_Array\n");
           }
           (yyval.typeinfo) = (struct TypeInfo*)malloc(sizeof(struct TypeInfo));
           (yyval.typeinfo)->typeEntry = getPredefType("array");
           (yyval.typeinfo)->defScopeId = getCurScopeId();
           (yyval.typeinfo)->attrInfo.arrayInfo.boundLow = (yyvsp[(3) - (8)].intType);
           (yyval.typeinfo)->attrInfo.arrayInfo.boundUp = (yyvsp[(5) - (8)].intType);
           (yyval.typeinfo)->attrInfo.arrayInfo.typeEntry = curTypeIdResp->idEntry;
           (yyval.typeinfo)->attrInfo.arrayInfo.typeDefScopeId = curTypeIdDefScopeId;
           (yyval.typeinfo)->tag = ATTR_TYPE;
       ;}
    break;

  case 55:
#line 396 "translate.y"
    {
         if(MODE_DEBUG == 1){
             printf("Type_Record_Init\n");
         }
         curRecordScopeHash = recordIdHashCode();
         newScopeAndPush(curRecordScopeHash);
         pushRecordHashInStack(curRecordScopeHash);
     ;}
    break;

  case 56:
#line 404 "translate.y"
    {
           if(MODE_DEBUG == 1){
               printf("Type_Record\n");
           }
           (yyval.typeinfo) = (struct TypeInfo*)malloc(sizeof(struct TypeInfo));
           (yyval.typeinfo)->typeEntry = getPredefType("record");
           (yyval.typeinfo)->attrInfo.recordInfo.scopeHashCode = curRecordScopeHash;
           (yyval.typeinfo)->tag = ATTR_TYPE;
           (yyval.typeinfo)->defScopeId = getCurScopeId();
           curRecordScopeHash = handleRecordEnd();
       ;}
    break;

  case 57:
#line 417 "translate.y"
    {
                    if(MODE_DEBUG == 1){
                        printf("ResultType\n");
                    }
                    typeHandler(&(yyvsp[(1) - (1)].idrespType));
                    constructTypeInfoFromIdResp(&(yyval.typeinfo), (yyvsp[(1) - (1)].idrespType));
                    (yyval.typeinfo)->tag = ATTR_TYPE;
                    if(MODE_DEBUG == 1){
                        printf("return type: %d\n", (yyval.typeinfo)->typeEntry);
                    }
                    if((yyval.typeinfo)->typeEntry == 5) {
                        if(MODE_DEBUG == 1){
                            printf("return array type: %d, scope: %d\n", (yyval.typeinfo)->attrInfo.arrayInfo.typeEntry, (yyval.typeinfo)->attrInfo.arrayInfo.typeDefScopeId);
                        }
                    }
                ;}
    break;

  case 58:
#line 435 "translate.y"
    {if(MODE_DEBUG == 1){printf("Constant_SIGN_INT\n");} (yyval.intType) = getConstantInt((yyvsp[(1) - (2)].stringType), (yyvsp[(2) - (2)].intType));;}
    break;

  case 59:
#line 436 "translate.y"
    {if(MODE_DEBUG == 1){printf("Constant_INT\n");} (yyval.intType) = getConstantInt(NULL, (yyvsp[(1) - (1)].intType));;}
    break;

  case 60:
#line 439 "translate.y"
    {
                                (yyval.typeinfo) = (yyvsp[(1) - (1)].typeinfo);
                                if(MODE_DEBUG == 1){
                                    printf("Exp_simp\n");
                                    printf("type reduced as %d\n", (yyval.typeinfo)->typeEntry);
                                }
                              ;}
    break;

  case 61:
#line 447 "translate.y"
    {
                                if(!typeCheck((yyvsp[(1) - (3)].typeinfo), (yyvsp[(3) - (3)].typeinfo))) {
                                    yyerror_unequal_type((yyvsp[(1) - (3)].typeinfo), (yyvsp[(3) - (3)].typeinfo));
                                }
                                constructTypeInfoForCertainSimpleType(&(yyval.typeinfo), "boolean");
                                if(MODE_DEBUG == 1){
                                    printf("Exp_Simp_Ro\n");
                                    printf("type reduced as %d\n", (yyval.typeinfo)->typeEntry);
                                }
                              ;}
    break;

  case 62:
#line 459 "translate.y"
    {if(MODE_DEBUG == 1){printf("RelationalOp_EQ\n");};}
    break;

  case 63:
#line 460 "translate.y"
    {if(MODE_DEBUG == 1){printf("RelationslOp_Less\n");};}
    break;

  case 64:
#line 461 "translate.y"
    {if(MODE_DEBUG == 1){printf("RelationslOp_LE\n");};}
    break;

  case 65:
#line 462 "translate.y"
    {if(MODE_DEBUG == 1){printf("RelationslOp_G\n");};}
    break;

  case 66:
#line 463 "translate.y"
    {if(MODE_DEBUG == 1){printf("RelationslOp_GE\n");};}
    break;

  case 67:
#line 464 "translate.y"
    {if(MODE_DEBUG == 1){printf("RelationslOp_NE\n");};}
    break;

  case 68:
#line 467 "translate.y"
    {
                                    if(MODE_DEBUG == 1){
                                        printf("SimpleExp_Sign_AddTerm\n");
                                    }
                                    (yyval.typeinfo) = (yyvsp[(2) - (2)].typeinfo);
                                  ;}
    break;

  case 69:
#line 473 "translate.y"
    {
                                (yyval.typeinfo) = (yyvsp[(1) - (1)].typeinfo);
                                if(MODE_DEBUG == 1){
                                    printf("SimpleExp_AddTerm\n");
                                    printf("type reduced as %d\n", (yyval.typeinfo)->typeEntry);
                                }
                             ;}
    break;

  case 70:
#line 482 "translate.y"
    {
                                    if(MODE_DEBUG == 1){
                                        printf("AddOpTerm_Mul\n");
                                    }
                                    char *type1;
                                    char *type2;
                                    if(typeCheck((yyvsp[(1) - (3)].typeinfo), (yyvsp[(3) - (3)].typeinfo))) {
                                        (yyval.typeinfo) = (yyvsp[(3) - (3)].typeinfo);
                                        setReduceTypeInfo(&(yyval.typeinfo), (yyvsp[(1) - (3)].typeinfo), (yyvsp[(3) - (3)].typeinfo), 1);
                                    }
                                    else {
                                        yyerror_unequal_type((yyvsp[(1) - (3)].typeinfo), (yyvsp[(3) - (3)].typeinfo));
                                        setReduceTypeInfo(&(yyval.typeinfo), (yyvsp[(1) - (3)].typeinfo), (yyvsp[(3) - (3)].typeinfo), 0);
                                    }
                                    if(MODE_DEBUG == 1){
                                        printf("type reduced as %d\n", (yyval.typeinfo)->typeEntry);
                                    }
                                 ;}
    break;

  case 71:
#line 500 "translate.y"
    {
                    (yyval.typeinfo) = (yyvsp[(1) - (1)].typeinfo);
                    if(MODE_DEBUG == 1){
                        printf("AddOpTerm_Single\n");
                        printf("type reduced as %d\n", (yyval.typeinfo)->typeEntry);
                    }
                 ;}
    break;

  case 72:
#line 509 "translate.y"
    {if(MODE_DEBUG == 1){printf("AddOp_Add\n");};}
    break;

  case 73:
#line 510 "translate.y"
    {if(MODE_DEBUG == 1){printf("AddOp_Min\n");};}
    break;

  case 74:
#line 511 "translate.y"
    {if(MODE_DEBUG == 1){printf("AddOp_OR\n");};}
    break;

  case 75:
#line 514 "translate.y"
    {
                            if(MODE_DEBUG == 1){
                                printf("Term_Fac_Mul\n");
                            }
                            if(typeCheck((yyvsp[(1) - (2)].typeinfo), (yyvsp[(2) - (2)].typeinfo))) {
                                (yyval.typeinfo) = (yyvsp[(2) - (2)].typeinfo);
                                setReduceTypeInfo(&(yyval.typeinfo), (yyvsp[(1) - (2)].typeinfo), (yyvsp[(2) - (2)].typeinfo), 1);
                            }
                            else {
                                yyerror_unequal_type((yyvsp[(1) - (2)].typeinfo), (yyvsp[(2) - (2)].typeinfo));
                                (yyval.typeinfo) = (struct TypeInfo*)malloc(sizeof(struct TypeInfo));
                                setReduceTypeInfo(&(yyval.typeinfo), (yyvsp[(1) - (2)].typeinfo), (yyvsp[(2) - (2)].typeinfo), 0);
                            }
                            if(MODE_DEBUG == 1){
                                printf("type reduced as %d\n", (yyval.typeinfo)->typeEntry);
                            }
                        ;}
    break;

  case 76:
#line 531 "translate.y"
    {
                (yyval.typeinfo) = (yyvsp[(1) - (1)].typeinfo);
                if(MODE_DEBUG == 1){
                    printf("type reduced as %d\n", (yyval.typeinfo)->typeEntry);
                }
              ;}
    break;

  case 77:
#line 539 "translate.y"
    {
                            if(MODE_DEBUG == 1){
                                printf("MulOpTerm\n");
                            }
                            (yyval.typeinfo) = (yyvsp[(2) - (2)].typeinfo);
                       ;}
    break;

  case 78:
#line 547 "translate.y"
    {if(MODE_DEBUG == 1){printf("MulOp_MUL\n");};}
    break;

  case 79:
#line 548 "translate.y"
    {if(MODE_DEBUG == 1){printf("MulOp_DIV\n");};}
    break;

  case 80:
#line 549 "translate.y"
    {if(MODE_DEBUG == 1){printf("MulOp_MOD\n");};}
    break;

  case 81:
#line 550 "translate.y"
    {if(MODE_DEBUG == 1){printf("MulOp_AND\n");};}
    break;

  case 82:
#line 553 "translate.y"
    {
                if(MODE_DEBUG == 1){
                    printf("Factor_INT\n");
                }
                (yyval.typeinfo) = (struct TypeInfo*)malloc(sizeof(struct TypeInfo));
                (yyval.typeinfo)->typeEntry = getPredefType("integer");
                (yyval.typeinfo)->tag = ATTR_VAR;
                (yyval.typeinfo)->code = itoa(yylval.intType);
             ;}
    break;

  case 83:
#line 562 "translate.y"
    {
                    if(MODE_DEBUG == 1){
                        printf("Factor_String\n");
                    }
                    (yyval.typeinfo) = (struct TypeInfo*)malloc(sizeof(struct TypeInfo));
                    (yyval.typeinfo)->typeEntry = getPredefType("string");
                    (yyval.typeinfo)->tag = ATTR_VAR;
                    (yyval.typeinfo)->code = strcpy2(yylval.stringType);
                ;}
    break;

  case 84:
#line 571 "translate.y"
    {
                                if(MODE_DEBUG == 1){
                                    printf("Factor_FuncRef\n");
                                }
                                (yyval.typeinfo) = (yyvsp[(1) - (1)].typeinfo);
                           ;}
    break;

  case 85:
#line 577 "translate.y"
    {
                    if(MODE_DEBUG == 1){
                        printf("Factor_Var\n");
                    }
                    (yyval.typeinfo) = (yyvsp[(1) - (1)].typeinfo);
                  ;}
    break;

  case 86:
#line 583 "translate.y"
    {
                        if(MODE_DEBUG == 1){
                            printf("Factor_N_Fac\n");
                        }
                        (yyval.typeinfo) = (struct TypeInfo*)malloc(sizeof(struct TypeInfo));
                        (yyval.typeinfo)->typeEntry = getPredefType("bool");
                        (yyval.typeinfo)->tag = ATTR_VAR;
                    ;}
    break;

  case 87:
#line 591 "translate.y"
    {
                                        if(MODE_DEBUG == 1){
                                            printf("Factor_Exp\n");
                                        }
                                        (yyval.typeinfo) = (yyvsp[(2) - (3)].typeinfo);
                                    ;}
    break;

  case 88:
#line 600 "translate.y"
    {
                if(MODE_DEBUG == 1){
                    printf("Var_ID\n");
                    printf("checking var %d %s\n", (yyvsp[(1) - (1)].idrespType)->idEntry, (yyvsp[(1) - (1)].idrespType)->idStr);
                }
                int defined = 0;
                int preDefEntry;
                defined = isIdDefined((yyvsp[(1) - (1)].idrespType));
                if((yyvsp[(1) - (1)].idrespType)->idRespStatus == IDRESP_NORMAL
                    && !defined) {
                    preDefEntry = getDefInParentScope((yyvsp[(1) - (1)].idrespType)->idStr, ATTR_VAR);
                    if(preDefEntry >= 0) {
                        if(MODE_DEBUG == 1){
                            printf("var %s defined in enclosing scope at %d\n", (yyvsp[(1) - (1)].idrespType)->idStr, preDefEntry);
                        }
                        removeTailSymbolFromCurScope();
                        (yyvsp[(1) - (1)].idrespType)->idEntry = preDefEntry;
                        (yyvsp[(1) - (1)].idrespType)->idRespStatus = IDRESP_DEF_IN_PARENT;//defined in enclosing scope
                        defined = 1;
                    }
                    else {
                        printLineNo();
                        fprintf(stderr, "Undeclared var: %s\n", (yyvsp[(1) - (1)].idrespType)->idStr);
                        //YYERROR;
                    }
                }
                if(defined) {
                    //enter record scope
                    curVarIdResp = (yyvsp[(1) - (1)].idrespType);
                    if(MODE_DEBUG == 1){
                        printf("var id: %s\n", (yyvsp[(1) - (1)].idrespType)->idStr);
                        printf("curVarIdResp changed to: %d\n", curVarIdResp->idEntry);
                    }
                }
                else {
                    curVarIdResp = NULL;
                    if(MODE_DEBUG == 1){
                        printf("curVarIdResp changed to: NULL\n");
                    }
                }
            ;}
    break;

  case 89:
#line 641 "translate.y"
    {
                if(MODE_DEBUG == 1){
                    printf("Var_Comp\n");
                }
                //exit record scope
                if((yyvsp[(3) - (3)].typeinfo)->typeEntry == -1) {
                    free((yyvsp[(3) - (3)].typeinfo));
                    constructTypeInfoFromIdResp(&(yyval.typeinfo), (yyvsp[(1) - (3)].idrespType));
                    (yyval.typeinfo)->tag = ATTR_VAR;
                }
                else {
                    (yyval.typeinfo) = (yyvsp[(3) - (3)].typeinfo);
                    (yyval.typeinfo)->code = strcat((yyvsp[(1) - (3)].idrespType)->idStr, (yyval.typeinfo)->code);
                }
                if(MODE_DEBUG == 1){
                    printf("var type: %d\n", (yyval.typeinfo)->typeEntry);
                }
            ;}
    break;

  case 90:
#line 662 "translate.y"
    {
                         if(!isTypeConstructor(curVarIdResp, "record")) {
                             fprintf(stderr, "Invalid var: %s is not a record\n", curVarIdResp->idStr);
                         }
                         else {
                             curRecordScopeHash = handleRecordStart(curVarIdResp);
                             if(curRecordScopeHash != 0) {
                                 if(MODE_DEBUG == 1){
                                     printf("enter recordhash: %d\n", curRecordScopeHash);
                                 }
                             }
                         }
                     ;}
    break;

  case 91:
#line 675 "translate.y"
    {
                         if(MODE_DEBUG == 1){
                             printf("CompSel_Record\n");
                         }
                         (yyval.typeinfo) = (yyvsp[(3) - (3)].typeinfo);
                         (yyval.typeinfo)->code = strcat2(".", (yyval.typeinfo)->code);
                         curRecordScopeHash = handleRecordEnd();
                         if(curRecordScopeHash != 0) {
                             if(MODE_DEBUG == 1){
                                 printf("out recordhash: %d\n", curRecordScopeHash);
                             }
                         }
                         if(MODE_DEBUG) {
                             printf("reduced as type: %d\n", (yyvsp[(3) - (3)].typeinfo)->typeEntry);
                         }
                     ;}
    break;

  case 92:
#line 691 "translate.y"
    {
                       if(!isTypeConstructor(curVarIdResp, "array")) {
                           fprintf(stderr, "Invalid var: structure is not an array\n", curVarIdResp->idStr);
                       }
                       else {
                            pushArrayIdRespInStack(curVarIdResp);
                       }
                   ;}
    break;

  case 93:
#line 699 "translate.y"
    {
                         if(!certainTypeCheck((yyvsp[(3) - (3)].typeinfo), "integer")) {
                             fprintf(stderr, "Invalid array index\n");
                         }
                     ;}
    break;

  case 94:
#line 704 "translate.y"
    {
                         curArrayTypeInfo = NULL;
                         curVarIdResp = popArrayIdResp();
                         handleArrayVar(&curVarIdResp, &curArrayTypeInfo);
                         if(MODE_DEBUG) {
                            printf("curVarIdResp changed to: %d\n", curVarIdResp->idEntry);
                         }
                     ;}
    break;

  case 95:
#line 712 "translate.y"
    {
                         if(MODE_DEBUG == 1){
                             printf("CompSel_Array\n");
                         }
                         if((yyvsp[(7) - (7)].typeinfo)->typeEntry == -1) {
                             constructTypeInfoFromArrayTypeInfo(&(yyval.typeinfo), curArrayTypeInfo);
                             free(curArrayTypeInfo);
                         }
                         else {
                             (yyval.typeinfo) = (yyvsp[(7) - (7)].typeinfo);
                         }
                         (yyval.typeinfo)->tag = ATTR_VAR;
                         if(MODE_DEBUG) {
                             printf("reduced as type: %d\n", (yyvsp[(3) - (7)].typeinfo)->typeEntry);
                         }
                         (yyval.typeinfo)->code = strcat2("[", (yyvsp[(3) - (7)].typeinfo)->code);
                         (yyval.typeinfo)->code = strcat2((yyval.typeinfo)->code, "]");
                         (yyval.typeinfo)->code = strcat2((yyval.typeinfo)->code, (yyvsp[(7) - (7)].typeinfo)->code);
                     ;}
    break;

  case 96:
#line 731 "translate.y"
    {
                       (yyval.typeinfo) = (struct TypeInfo*)malloc(sizeof(struct TypeInfo));
                       (yyval.typeinfo)->typeEntry = -1;
                     ;}
    break;

  case 97:
#line 737 "translate.y"
    {
    addCurFuncProcParamCallCounter(1);
    appendToParamTypeList((yyvsp[(1) - (1)].typeinfo));
;}
    break;

  case 98:
#line 741 "translate.y"
    {if(MODE_DEBUG == 1){printf("ActualParamL\n");};}
    break;

  case 99:
#line 742 "translate.y"
    {if(MODE_DEBUG == 1){printf("ActualParamL\n");};}
    break;

  case 100:
#line 745 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("ExpM\n");
    }
    addCurFuncProcParamCallCounter(1);
    appendToParamTypeList((yyvsp[(2) - (2)].typeinfo));
;}
    break;

  case 103:
#line 756 "translate.y"
    {
                                        if(MODE_DEBUG == 1){
                                            printf("IdList\n");
                                        }
                                        addCurParamCounter(1);
                                        appendToIdList((yyvsp[(1) - (2)].idrespType)->idEntry);
                                       ;}
    break;

  case 104:
#line 765 "translate.y"
    {if(MODE_DEBUG == 1){printf("IdListM\n");};}
    break;

  case 106:
#line 769 "translate.y"
    {if(MODE_DEBUG == 1){printf("Sign_Add\n");} (yyval.stringType) = "+";;}
    break;

  case 107:
#line 770 "translate.y"
    {if(MODE_DEBUG == 1){printf("Sign_Min\n");} (yyval.stringType) = "-";;}
    break;


/* Line 1267 of yacc.c.  */
#line 2608 "translate.tab.c"
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


#line 773 "translate.y"


yyerror(char *s)
{
    printLineNo();
    fprintf(stderr, "error: %s\n", s);
}

void printLineNo() {
//    fprintf(stderr, "Line: %d  ", getLineNo());
}

void yyerror_unequal_type(struct TypeInfo *typeInfo1, struct TypeInfo *typeInfo2) {
    char *type1;
    char *type2;
    char *tag1;
    char *tag2;
    type1 = getTypeName(typeInfo1);
    type2 = getTypeName(typeInfo2);
    
    switch(typeInfo1->tag) {
        case -1:
            tag1 = "Default";
            break;
        case 0:
            tag1 = "Type";
            break;
        case 1:
            tag1 = "Var";
            break;
    }
    
    switch(typeInfo2->tag) {
        case -1:
        tag2 = "Default";
        break;
        case 0:
        tag2 = "Type";
        break;
        case 1:
        tag2 = "Var";
        break;
    }
    printLineNo();
    fprintf(stderr, "Operation Betwween Incompatiable Types: ");
    fprintf(stderr, "%s(%s), %s(%s)\n", tag1, type1, tag2, type2);
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

int setIdListType(struct TypeInfo *retType) {
    if(MODE_DEBUG == 1){
        printf("setting idlist\n");
    }
    char *info = NULL;
    info = setIdListTypeAttr(retType->typeEntry, retType->attrInfo, ATTR_VAR);
    if(MODE_DEBUG == 1){
        printf("set idlist\n");
    }
    destroyCurIdList();
    cleanLatestSetList();
    if(info != NULL) {
        fprintf(stderr, "%s\n", info);
        free(info);
        return 0;
    }
    return 1;
}

void handleFuncProcDeclaration(struct IdResp *id, struct TypeInfo *retType, int paramQty, char *funcProc) {
        union SymbolEntryAttr attr;
        union ARGINFO quadArg1;
        if(strcmp(funcProc, "function") == 0) {
            //set function parameter's type as return type
            setFuncVarInScope(id->idStr, id->idEntry, retType->typeEntry, retType->attrInfo);
            registerFunc(id->idEntry, retType->typeEntry, retType->attrInfo, paramQty);
        }
        else {
            registerProc(id->idEntry, paramQty);
        }
        cleanCurParamCounter();
        cleanCurFuncProcCallParamCounter();

        quadArg1.strInfo = strcpy2(id->idStr);
        insertQuadruple(getCurQueadrupleTable(), QUAD_OP_LABEL, buildArg(ARGTYPE_VAR_STR, quadArg1), NULL, NULL);
}

int enterNewScope(struct IdResp *id) {
    char *name = "";
    if(id->idRespStatus != IDRESP_NORMAL) {
        name = getNameInCurScope(id->idEntry);
        printLineNo();
        fprintf(stderr, "invalid function/procedure ID: %s\n", name);
        return -1;
    }
    newScopeAndPush(id->idEntry);
    return 0;
}

int setSymbolTypeAttr(int idAddr, int typeEntry, struct TypeInfo *typedata, int attrTag) {
    int resp;
    char *name;
    entryAttr attr;
    int i = 0;
    if(typeEntry == getPredefType("array")) {
        attr.arrayInfo.boundLow = typedata->attrInfo.arrayInfo.boundLow;
        attr.arrayInfo.boundUp = typedata->attrInfo.arrayInfo.boundUp;
        attr.arrayInfo.typeEntry = typedata->attrInfo.arrayInfo.typeEntry;
        attr.arrayInfo.typeDefScopeId = typedata->attrInfo.arrayInfo.typeDefScopeId;
    }
    if(typeEntry == getPredefType("record")) {
        attr.recordInfo.scopeHashCode = typedata->attrInfo.recordInfo.scopeHashCode;
    }

    resp = setSymbolTypeAttrInCurScope(idAddr, typeEntry, attr, attrTag);
    if(resp == -1) {
        name = getNameInCurScope(idAddr);
        printLineNo();
        fprintf(stderr, "Redefinition of symbol %s\n", name);
        return -1;
    }
    return 0;
}

int typeHandler(struct IdResp **idResp) {
    char *name = "";
    if(MODE_DEBUG == 1){
        printf("handling type: %s\n", (*idResp)->idStr);
    }
    int entry;
    if((*idResp)->idRespStatus == IDRESP_PREDEF_TYPE) {
        curTypeIdDefScopeId = -2;
        return 1;
    }
    entry = getTypeDefAddr((*idResp)->idStr);
    if(entry >= 0) {
        (*idResp)->idEntry = entry;
        (*idResp)->idRespStatus = IDRESP_NORMAL;
        curTypeIdDefScopeId = getCurScopeId();
        return 1;
    }
    else {
        entry = getTypeDefInParentScope((*idResp)->idStr);
        if(entry >= 0) {
            (*idResp)->idRespStatus = IDRESP_DEF_IN_PARENT;
            (*idResp)->idEntry = entry;
            removeTailSymbolFromCurScope();
            curTypeIdDefScopeId = getParentScopeId();
            return 1;
        }
    }
    printLineNo();
    (*idResp)->idRespStatus = IDRESP_UNDEF;
    (*idResp)->idEntry = -1;
    fprintf(stderr, "Undeclared type: %s\n", (*idResp)->idStr);
    return 0;
}

int isIdDefined(struct IdResp *id) {
    if(getIDTypeStr(id->idEntry) == NULL) {
        return 0;
    }
    return 1;
}

//check if a certain type match
int certainTypeCheck(struct TypeInfo *type, char *typeToCheck) {
    struct TypeInfo *tmp = (struct TypeInfo *)malloc(sizeof(struct TypeInfo));
    tmp->typeEntry = getPredefType(typeToCheck);
    tmp->tag = type->tag;
    if(!typeCheck(type, tmp)) {
        return 0;
    }
    return 1;
}

void resetCurTypeEnvironment() {
    curTypeIdResp = NULL;
    curTypeIdDefScopeId = -2;
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
    fstream = stdout;
    if(MODE_DEBUG == 1){
        stdout=fopen("parser_debug.out","w");
    }
    yyparse();
    if(MODE_DEBUG == 1){
        close(stdout);
    }
    stdout = fstream;
    if(MODE_DEBUG == 1){
        printf("\n\nParsing done (debugging info: parser_debug.out).\n\n");
        stdout=fopen("symtable.out","w");
        printAllSymbolTable();
        close(stdout);
        stdout = fstream;
        close(fstream);
        printf("Done, symbole table: symtable.out\n\n");
    }
    else {
        printf("\n\nParsing done\n\n");
    }
    return 0;
}
