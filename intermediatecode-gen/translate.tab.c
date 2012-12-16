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
    
    // for recording enclosing scope for current var
    // before enter sub scope like record scopes
    quadrupleTable *curVarEnclosingQuadTable = NULL;
    
    //===declaration for funcs in translate.y===//
    
    void yyerror_unequal_type(struct TypeInfo *type1, struct TypeInfo *type2);
    
    int getConstantInt(char *sign, int num);
    
    void addCurParamCounter(int delta);
    
    void cleanCurParamCounter();
    
    int setIdListType(struct TypeInfo *retType);
    
    void handleFuncProcDeclaration(struct IdResp *id, typeinfost *retType,
    int paramQty, char *funcProc);
    
    void finishFuncProcDeclaration(struct IdResp *id, char *funcProc);
    
    int enterNewScope(struct IdResp *id);
    
    int setSymbolTypeAttr(int idAddr, int typeEntry,
    typeinfost *typedata, int attrTag);
    
    int typeHandler(idresp **idResp);
    
    int isIdDefined(struct IdResp *id);
    
    int certainTypeCheck(struct TypeInfo *type, char *typeToCheck);
    
    int contextSwitch(struct IdResp *idInfo);
    
    void resetCurTypeEnvironment();
    
    void handleBinop(struct TypeInfo **ruleHead,
    struct TypeInfo *op1,
    struct TypeInfo *op2,
    char *operator,
    char *designatedRuleHeadType,
    int relOp);
    
    void handleUnaryOpICTable(struct TypeInfo **ruleHead,
    struct TypeInfo *op1,
    char *operator);
    
    void handleAssignStatement(struct TypeInfo *assignTo,
    struct TypeInfo *assignFrom);
    
    void interCodeVarStart(char *varName);
    
    void arrayInterCodeHandling(char *expr);
    
    

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
#line 79 "translate.y"
{
    double doubleType;
    int intType;
    int idEntryType;
    char *stringType;
    struct IDLIST *idListType;
    struct IdResp *idrespType;
    struct TypeInfo *typeinfo;
    struct STRUCTUREDSTATEMENT *structuredStatementHeadType;
    int paramList[100];
}
/* Line 193 of yacc.c.  */
#line 288 "translate.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 301 "translate.tab.c"

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
#define YYLAST   198

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNRULES -- Number of states.  */
#define YYNSTATES  207

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
       0,     0,     3,     4,    10,    13,    17,    21,    25,    30,
      35,    40,    46,    49,    52,    56,    59,    62,    66,    70,
      73,    75,    77,    81,    85,    86,    87,    97,    98,    99,
     111,   113,   115,   116,   119,   123,   126,   127,   129,   132,
     136,   138,   142,   144,   146,   148,   150,   151,   155,   156,
     162,   164,   166,   167,   172,   173,   174,   181,   182,   183,
     184,   196,   197,   198,   205,   207,   216,   217,   222,   224,
     227,   229,   231,   235,   237,   239,   241,   243,   245,   247,
     250,   252,   256,   258,   260,   262,   264,   268,   270,   272,
     274,   276,   278,   280,   282,   284,   286,   289,   293,   294,
     298,   299,   303,   304,   305,   306,   314,   315,   316,   320,
     321,   322,   327,   328,   331,   334,   335,   337
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    -1,    18,    46,    37,    54,    55,    -1,
      75,    34,    -1,    56,    75,    34,    -1,    58,    75,    34,
      -1,    60,    75,    34,    -1,    56,    58,    75,    34,    -1,
      58,    60,    75,    34,    -1,    56,    60,    75,    34,    -1,
      56,    58,    60,    75,    34,    -1,    22,    57,    -1,    62,
      37,    -1,    62,    37,    57,    -1,    23,    59,    -1,    63,
      37,    -1,    63,    37,    59,    -1,    61,    37,    60,    -1,
      61,    37,    -1,    64,    -1,    67,    -1,    46,    28,    92,
      -1,   115,    36,    92,    -1,    -1,    -1,    17,    46,    65,
      40,    71,    41,    37,    66,    70,    -1,    -1,    -1,    10,
      46,    68,    40,    71,    41,    36,    94,    37,    69,    70,
      -1,    74,    -1,     4,    -1,    -1,    72,    73,    -1,   115,
      36,    92,    -1,    37,    71,    -1,    -1,    75,    -1,    58,
      75,    -1,     3,    76,     8,    -1,    77,    -1,    76,    37,
      77,    -1,    78,    -1,    82,    -1,    79,    -1,    80,    -1,
      -1,   104,    38,    96,    -1,    -1,    46,    81,    40,   111,
      41,    -1,    75,    -1,    89,    -1,    -1,    89,     7,    83,
      77,    -1,    -1,    -1,    24,    84,    96,    85,     6,    77,
      -1,    -1,    -1,    -1,     9,    86,    46,    38,    96,    87,
      21,    96,    88,     6,    77,    -1,    -1,    -1,    11,    90,
      96,    91,    20,    77,    -1,    46,    -1,    12,    42,    95,
      39,    95,    43,    15,    92,    -1,    -1,    19,    93,    71,
       8,    -1,    46,    -1,   117,    44,    -1,    44,    -1,    98,
      -1,    98,    97,    98,    -1,    28,    -1,    29,    -1,    30,
      -1,    31,    -1,    32,    -1,    33,    -1,   117,    99,    -1,
      99,    -1,   101,   100,    99,    -1,   101,    -1,    25,    -1,
      27,    -1,    16,    -1,   103,   102,   101,    -1,   103,    -1,
      26,    -1,     5,    -1,    13,    -1,    48,    -1,    44,    -1,
      47,    -1,    80,    -1,   104,    -1,    14,   103,    -1,    40,
      96,    41,    -1,    -1,    46,   105,   106,    -1,    -1,    34,
     107,   104,    -1,    -1,    -1,    -1,    42,   108,    96,   109,
      43,   110,   106,    -1,    -1,    -1,    96,   112,   113,    -1,
      -1,    -1,    35,    96,   114,   113,    -1,    -1,    46,   116,
      -1,    35,   115,    -1,    -1,    25,    -1,    27,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   161,   161,   161,   168,   173,   178,   183,   188,   193,
     198,   203,   211,   220,   225,   233,   242,   247,   255,   260,
     268,   273,   281,   295,   307,   315,   307,   332,   341,   332,
     359,   365,   373,   379,   385,   395,   401,   405,   410,   418,
     426,   431,   439,   444,   451,   457,   464,   468,   478,   478,
     526,   532,   537,   537,   551,   556,   551,   572,   575,   579,
     572,   607,   610,   607,   631,   644,   658,   658,   681,   702,
     709,   718,   726,   736,   743,   750,   757,   764,   771,   780,
     788,   798,   811,   821,   828,   835,   844,   857,   867,   874,
     881,   888,   897,   907,   918,   925,   932,   943,   952,   952,
    1030,  1030,  1068,  1077,  1083,  1068,  1123,  1130,  1130,  1141,
    1149,  1149,  1159,  1163,  1173,  1179,  1183,  1190
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
  "TRUE", "FALSE", "$accept", "Program", "@1", "Program_Comp",
  "TypeDefinitions", "TypeDefinitionList", "VariableDeclarations",
  "VariableDeclarationList", "SubprogramDeclarations",
  "SubprogramDeclaration", "TypeDefinition", "VariableDeclaration",
  "ProcedureDeclaration", "@2", "@3", "FunctionDeclaration", "@4", "@5",
  "PFDeclarationFollow", "FormalParameterList",
  "FormalParameterListSingle", "FormalParameterListMore", "Block",
  "CompoundStatement", "StatementSequence", "Statement", "SimpleStatement",
  "AssignmentStatement", "ProcFuncStatement", "@6", "StructuredStatement",
  "@7", "@8", "@9", "@10", "@11", "@12", "IfThenStatement", "@13", "@14",
  "Type", "@15", "ResultType", "Constant", "Expression", "RelationalOp",
  "SimpleExpression", "AddOpTerm", "AddOp", "Term", "MulOp", "Factor",
  "Variable", "@16", "ComponentSelection", "@17", "@18", "@19", "@20",
  "ActualParameterList", "@21", "ExpressionMore", "@22", "IdentifierList",
  "IdentifierListMore", "Sign", 0
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
       0,    52,    54,    53,    55,    55,    55,    55,    55,    55,
      55,    55,    56,    57,    57,    58,    59,    59,    60,    60,
      61,    61,    62,    63,    65,    66,    64,    68,    69,    67,
      70,    70,    71,    71,    72,    73,    73,    74,    74,    75,
      76,    76,    77,    77,    78,    78,    78,    79,    81,    80,
      82,    82,    83,    82,    84,    85,    82,    86,    87,    88,
      82,    90,    91,    89,    92,    92,    93,    92,    94,    95,
      95,    96,    96,    97,    97,    97,    97,    97,    97,    98,
      98,    99,    99,   100,   100,   100,   101,   101,   102,   102,
     102,   102,   103,   103,   103,   103,   103,   103,   105,   104,
     107,   106,   108,   109,   110,   106,   106,   112,   111,   111,
     114,   113,   113,   115,   116,   116,   117,   117
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     5,     2,     3,     3,     3,     4,     4,
       4,     5,     2,     2,     3,     2,     2,     3,     3,     2,
       1,     1,     3,     3,     0,     0,     9,     0,     0,    11,
       1,     1,     0,     2,     3,     2,     0,     1,     2,     3,
       1,     3,     1,     1,     1,     1,     0,     3,     0,     5,
       1,     1,     0,     4,     0,     0,     6,     0,     0,     0,
      11,     0,     0,     6,     1,     8,     0,     4,     1,     2,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     0,     3,
       0,     3,     0,     0,     0,     7,     0,     0,     3,     0,
       0,     4,     0,     2,     2,     0,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     2,     0,    46,     0,     0,
       0,     0,     3,     0,     0,     0,     0,    20,    21,     0,
      57,    61,    54,    98,    50,     0,    40,    42,    44,    45,
      43,    51,     0,    27,    24,     0,    12,     0,   115,    15,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     4,
       0,     0,     0,     0,   106,    39,    46,    52,     0,     0,
       0,     0,    13,     0,   113,    16,     0,     0,     0,     0,
       5,     0,     6,     7,    18,     0,     0,   116,   117,     0,
      92,    93,    94,    62,    71,    80,    82,    87,    95,     0,
      55,   109,   100,   102,    99,    41,    46,    47,    32,    32,
       0,    66,    64,    22,    14,   114,    17,    23,     0,     8,
      10,     9,     0,    96,     0,     0,    73,    74,    75,    76,
      77,    78,     0,    85,    83,    84,     0,    89,    90,    88,
      91,     0,    79,     0,   107,     0,     0,     0,    53,     0,
      36,     0,     0,     0,    32,    11,    58,    97,    46,    72,
      81,    86,    46,   112,    49,    98,   101,   103,     0,    32,
      33,     0,     0,    70,     0,     0,     0,     0,    63,    56,
       0,   108,     0,     0,    35,    34,    25,     0,    69,    67,
       0,   110,   104,    68,     0,     0,     0,    59,   112,   106,
      28,    31,     0,    26,    30,    37,     0,     0,   111,   105,
       0,    38,     0,    46,    29,    65,    60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,    12,    13,    36,   192,    39,    15,    16,
      37,    40,    17,    60,   185,    18,    59,   200,   193,   139,
     140,   160,   194,    24,    25,    26,    27,    28,    82,    53,
      30,    96,    52,   133,    50,   167,   197,    31,    51,   115,
     103,   144,   184,   164,    83,   122,    84,    85,   126,    86,
     131,    87,    88,    54,    94,   136,   137,   172,   189,   135,
     153,   171,   188,   141,    64,    89
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -139
static const yytype_int16 yypact[] =
{
       3,   -30,    32,    -4,  -139,  -139,    64,     6,   -12,   -10,
      26,    33,  -139,    82,    66,    75,    43,  -139,  -139,    54,
    -139,  -139,  -139,    51,  -139,    29,  -139,  -139,  -139,  -139,
    -139,    88,    58,  -139,  -139,    78,  -139,    77,    81,  -139,
      83,    79,    66,    75,    84,    75,    85,    87,    60,  -139,
      71,    57,    57,    90,     4,  -139,     6,  -139,    57,    91,
      92,     8,    26,    33,  -139,    33,     8,    75,    89,    93,
    -139,    99,  -139,  -139,  -139,    86,    15,  -139,  -139,    57,
    -139,  -139,  -139,  -139,    80,  -139,    48,     5,  -139,    15,
    -139,    57,  -139,  -139,  -139,  -139,     6,  -139,    33,    33,
      95,  -139,  -139,  -139,  -139,  -139,  -139,  -139,   100,  -139,
    -139,  -139,    57,  -139,    97,   102,  -139,  -139,  -139,  -139,
    -139,  -139,    57,  -139,  -139,  -139,    15,  -139,  -139,  -139,
    -139,    15,  -139,   119,  -139,    98,   101,    57,  -139,   103,
     111,   104,   109,     1,    33,  -139,  -139,  -139,     6,  -139,
    -139,  -139,     6,   116,  -139,  -139,  -139,  -139,   117,    33,
    -139,     8,   115,  -139,    96,   110,   120,   134,  -139,  -139,
      57,  -139,   113,   112,  -139,  -139,  -139,     1,  -139,  -139,
      57,  -139,  -139,  -139,   122,    21,   114,  -139,   116,     4,
    -139,  -139,    75,  -139,  -139,  -139,   145,   155,  -139,  -139,
      21,  -139,     8,     6,  -139,  -139,  -139
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,  -139,  -139,  -139,   105,    94,   106,     9,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,   -38,   -96,
    -139,  -139,  -139,    -2,  -139,   -54,  -139,  -139,    -6,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
     -59,  -139,  -139,   -14,   -44,  -139,    42,   -70,  -139,    34,
    -139,   108,    -7,  -139,   -23,  -139,  -139,  -139,  -139,  -139,
    -139,   -20,  -139,    -5,  -139,  -138
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -49
static const yytype_int16 yytable[] =
{
      32,    29,    95,   142,    19,   165,    41,   107,    90,     7,
     127,    44,    46,    47,    97,    20,     3,    21,   128,   132,
     100,     1,    43,    45,     7,   191,    77,   101,    78,    76,
      22,   129,     4,     5,    33,   114,    34,    55,    92,   165,
      68,    69,   138,    71,    11,   163,    93,   134,   166,    32,
      29,    67,    23,   130,   102,    79,   150,    74,   105,    80,
      41,    23,    81,   174,   123,   108,    56,     7,   146,     7,
       8,    76,    35,   124,     8,   125,     8,     9,     7,    38,
      48,     9,    77,     9,    78,     7,    10,    11,    49,    32,
      29,   -48,     8,   157,   168,    57,    58,    79,   169,     9,
      14,    80,   175,    23,    81,    11,    61,    42,   116,   117,
     118,   119,   120,   121,    62,    66,    63,    75,    70,    72,
      65,    73,   148,   109,   112,   152,   181,   110,   179,   156,
      91,    98,    99,   111,   145,   177,   187,   143,   147,   154,
     161,    32,    29,   205,   158,    32,    29,   155,   159,   206,
     162,   170,   176,   173,   178,   180,   182,   196,   183,   190,
     202,   203,   204,   186,   149,   151,   199,   104,   198,     0,
       0,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   195,   113,     0,     0,     0,     0,     0,
     201,     0,     0,     0,     0,     0,    32,    29,   195
};

static const yytype_int16 yycheck[] =
{
       7,     7,    56,    99,     6,   143,    11,    66,    52,     3,
       5,    13,    14,    15,    58,     9,    46,    11,    13,    89,
      12,    18,    13,    14,     3,     4,    25,    19,    27,    14,
      24,    26,     0,    37,    46,    79,    46,     8,    34,   177,
      42,    43,    96,    45,    23,    44,    42,    91,   144,    56,
      56,    42,    46,    48,    46,    40,   126,    48,    63,    44,
      65,    46,    47,   159,    16,    67,    37,     3,   112,     3,
      10,    14,    46,    25,    10,    27,    10,    17,     3,    46,
      37,    17,    25,    17,    27,     3,    22,    23,    34,    96,
      96,    40,    10,   137,   148,     7,    38,    40,   152,    17,
       6,    44,   161,    46,    47,    23,    28,    13,    28,    29,
      30,    31,    32,    33,    37,    36,    35,    46,    34,    34,
      37,    34,    20,    34,    38,     6,   170,    34,     8,   136,
      40,    40,    40,    34,    34,    39,   180,    42,    41,    41,
      36,   148,   148,   202,    41,   152,   152,    46,    37,   203,
      41,    35,    37,    36,    44,    21,    43,    43,    46,    37,
      15,     6,   200,   177,   122,   131,   189,    62,   188,    -1,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   185,    76,    -1,    -1,    -1,    -1,    -1,
     192,    -1,    -1,    -1,    -1,    -1,   203,   203,   200
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    53,    46,     0,    37,    54,     3,    10,    17,
      22,    23,    55,    56,    58,    60,    61,    64,    67,    75,
       9,    11,    24,    46,    75,    76,    77,    78,    79,    80,
      82,    89,   104,    46,    46,    46,    57,    62,    46,    59,
      63,   115,    58,    60,    75,    60,    75,    75,    37,    34,
      86,    90,    84,    81,   105,     8,    37,     7,    38,    68,
      65,    28,    37,    35,   116,    37,    36,    60,    75,    75,
      34,    75,    34,    34,    60,    46,    14,    25,    27,    40,
      44,    47,    80,    96,    98,    99,   101,   103,   104,   117,
      96,    40,    34,    42,   106,    77,    83,    96,    40,    40,
      12,    19,    46,    92,    57,   115,    59,    92,    75,    34,
      34,    34,    38,   103,    96,    91,    28,    29,    30,    31,
      32,    33,    97,    16,    25,    27,   100,     5,    13,    26,
      48,   102,    99,    85,    96,   111,   107,   108,    77,    71,
      72,   115,    71,    42,    93,    34,    96,    41,    20,    98,
      99,   101,     6,   112,    41,    46,   104,    96,    41,    37,
      73,    36,    41,    44,    95,   117,    71,    87,    77,    77,
      35,   113,   109,    36,    71,    92,    37,    39,    44,     8,
      21,    96,    43,    46,    94,    66,    95,    96,   114,   110,
      37,     4,    58,    70,    74,    75,    43,    88,   113,   106,
      69,    75,    15,     6,    70,    92,    77
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
#line 161 "translate.y"
    {
    insertQuadruple(getCurQuadrupleTable(), QUAD_OP_LABEL, buildStrArg((yyvsp[(2) - (3)].idrespType)->idStr), NULL, NULL);
;}
    break;

  case 4:
#line 168 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("Program\n");
    }
;}
    break;

  case 5:
#line 173 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("Program\n");
    }
;}
    break;

  case 6:
#line 178 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("Program\n");
    }
;}
    break;

  case 7:
#line 183 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("Program\n");
    }
;}
    break;

  case 8:
#line 188 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("Program\n");
    }
;}
    break;

  case 9:
#line 193 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("Program\n");
    }
;}
    break;

  case 10:
#line 198 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("Program\n");
    }
;}
    break;

  case 11:
#line 203 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("Program\n");
    }
;}
    break;

  case 12:
#line 211 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("TypeDef_Mul\n");
    }
    cleanCurParamCounter();
;}
    break;

  case 13:
#line 220 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("TypeDefList\n");
    }
;}
    break;

  case 14:
#line 225 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("TypeDefList_Multi\n");
    }
;}
    break;

  case 15:
#line 233 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("VarDecl_Mul\n");
    }
    cleanCurParamCounter();
;}
    break;

  case 16:
#line 242 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("VarDeclList\n");
    }
;}
    break;

  case 17:
#line 247 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("VarDeclList_Mul\n");
    }
;}
    break;

  case 18:
#line 255 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("SubDecl_mul\n");
    }
;}
    break;

  case 19:
#line 260 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("SubDecl_Mul\n");
    }
;}
    break;

  case 20:
#line 268 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("SubDeclP\n");
    }
;}
    break;

  case 21:
#line 273 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("SubDeclF\n");
    }
;}
    break;

  case 22:
#line 281 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("TypeDef: id: %d type: %d tag: %d\n",
        (yyvsp[(1) - (3)].idrespType)->idEntry, (yyvsp[(3) - (3)].typeinfo)->typeEntry, (yyvsp[(3) - (3)].typeinfo)->tag);
    }
    if(setSymbolTypeAttr((yyvsp[(1) - (3)].idrespType)->idEntry, (yyvsp[(3) - (3)].typeinfo)->typeEntry, (yyvsp[(3) - (3)].typeinfo), ATTR_TYPE) != 0) {
        //YYERROR;
    }
    free((yyvsp[(3) - (3)].typeinfo));
    resetCurTypeEnvironment();
;}
    break;

  case 23:
#line 295 "translate.y"
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

  case 24:
#line 307 "translate.y"
    {
    char *name = getNameInCurScope((yyvsp[(2) - (2)].idrespType)->idEntry);
    if(enterNewScope((yyvsp[(2) - (2)].idrespType)) != 0) {
        //YYERROR;
    }
    cleanCurFuncProcCallParamCounter();
;}
    break;

  case 25:
#line 315 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("setting proc: %d %s\n", (yyvsp[(2) - (7)].idrespType)->idEntry, itoa(funcProcParamCount));
    }
    handleFuncProcDeclaration((yyvsp[(2) - (7)].idrespType), NULL, funcProcParamCount, "procedure");
;}
    break;

  case 26:
#line 322 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("ProcDecl\n");
    }
    finishFuncProcDeclaration((yyvsp[(2) - (9)].idrespType), "procedure");
    popScopeStack();
;}
    break;

  case 27:
#line 332 "translate.y"
    {
    char *name = getNameInCurScope((yyvsp[(2) - (2)].idrespType)->idEntry);
    if(enterNewScope((yyvsp[(2) - (2)].idrespType)) != 0) {
        //YYERROR;
    }
    registerSymbolInCurScope(name);
    cleanCurFuncProcCallParamCounter();
;}
    break;

  case 28:
#line 341 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("setting func: %d %s %d\n",
        (yyvsp[(2) - (9)].idrespType)->idEntry, itoa(funcProcParamCount), (yyvsp[(8) - (9)].typeinfo)->typeEntry);
    }
    handleFuncProcDeclaration((yyvsp[(2) - (9)].idrespType), (yyvsp[(8) - (9)].typeinfo), funcProcParamCount, "function");
;}
    break;

  case 29:
#line 349 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("FuncDecl\n");
    }
    finishFuncProcDeclaration((yyvsp[(2) - (11)].idrespType), "function");
    popScopeStack();
;}
    break;

  case 30:
#line 359 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("PFDecl_Block\n");
    }
;}
    break;

  case 31:
#line 365 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("PFDecl_Forward\n");
    }
;}
    break;

  case 32:
#line 373 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("empty paramlist\n");
    }
;}
    break;

  case 33:
#line 379 "translate.y"
    {
    if(MODE_DEBUG == 1){printf("FormalPList\n");}
;}
    break;

  case 34:
#line 385 "translate.y"
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

  case 35:
#line 395 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("PList_M\n");
    }
;}
    break;

  case 37:
#line 405 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("Block_CompState\n");
    }
;}
    break;

  case 38:
#line 410 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("Block_CompSt_V\n");
    }
;}
    break;

  case 39:
#line 418 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("CompStBE\n");
    }
;}
    break;

  case 40:
#line 426 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("SteS\n");
    }
;}
    break;

  case 41:
#line 431 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("SteSSte\n");
    }
;}
    break;

  case 42:
#line 439 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("Statement_Simple\n");
    }
;}
    break;

  case 43:
#line 444 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("Statement_Structured\n");
    }
;}
    break;

  case 44:
#line 451 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("SimpleS_AssignState\n");
    }
;}
    break;

  case 45:
#line 457 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("SimpleSS_ProState\n");
    }
    free((yyvsp[(1) - (1)].typeinfo));
;}
    break;

  case 47:
#line 468 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("AssiState\n");
        printf("assign var type: %d\n", (yyvsp[(1) - (3)].typeinfo)->typeEntry);
    }
    handleAssignStatement((yyvsp[(1) - (3)].typeinfo), (yyvsp[(3) - (3)].typeinfo));
;}
    break;

  case 48:
#line 478 "translate.y"
    {
    cleanCurFuncProcCallParamCounter();
;}
    break;

  case 49:
#line 482 "translate.y"
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
                printf("func/proc %s defined in enclosing scope at %d\n",
                (yyvsp[(1) - (5)].idrespType)->idStr, preDefEntry);
            }
            removeTailSymbolFromCurScope();
            (yyvsp[(1) - (5)].idrespType)->idEntry = preDefEntry;
            (yyvsp[(1) - (5)].idrespType)->idRespStatus = IDRESP_DEF_IN_PARENT;//defined in enclosing scope
            defined = 1;
        }
        else {
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
    constructTypeInfoFromIdResp(&(yyval.typeinfo), (yyvsp[(1) - (5)].idrespType));
    (yyval.typeinfo)->tag = ATTR_VAR;
    handleFuncProcCallIntermediateCode(&(yyval.typeinfo));
    destroyParamTypeList();
    cleanCurFuncProcCallParamCounter();
    //put in table, create tmp
;}
    break;

  case 50:
#line 526 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("Struc_Comp\n");
    }
;}
    break;

  case 51:
#line 532 "translate.y"
    {
    insertQuadruple(getCurQuadrupleTable(), QUAD_OP_LABEL,
    buildStrArg((yyvsp[(1) - (1)].structuredStatementHeadType)->falseLabel), NULL, NULL);
;}
    break;

  case 52:
#line 537 "translate.y"
    {
    insertQuadruple(getCurQuadrupleTable(), QUAD_OP_GOTO,
    buildStrArg((yyvsp[(1) - (2)].structuredStatementHeadType)->nextLabel), NULL, NULL);
    insertQuadruple(getCurQuadrupleTable(), QUAD_OP_LABEL,
    buildStrArg((yyvsp[(1) - (2)].structuredStatementHeadType)->falseLabel), NULL, NULL);
;}
    break;

  case 53:
#line 543 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("if_else_m\n");
    }
    insertQuadruple(getCurQuadrupleTable(), QUAD_OP_LABEL,
    buildStrArg((yyvsp[(1) - (4)].structuredStatementHeadType)->nextLabel), NULL, NULL);
;}
    break;

  case 54:
#line 551 "translate.y"
    {
    (yyvsp[(1) - (1)].structuredStatementHeadType) = buildstructuredStatementHeadType();
    insertQuadruple(getCurQuadrupleTable(), QUAD_OP_LABEL,
    buildStrArg((yyvsp[(1) - (1)].structuredStatementHeadType)->trueLabel), NULL, NULL);
;}
    break;

  case 55:
#line 556 "translate.y"
    {
    insertQuadruple(getCurQuadrupleTable(), QUAD_OP_NOT, buildStrArg((yyvsp[(3) - (3)].typeinfo)->code), NULL, buildStrArg(createTmp()));
    insertQuadruple(getCurQuadrupleTable(), QUAD_OP_IF,
        NULL, NULL, buildStrArg((yyvsp[(1) - (3)].structuredStatementHeadType)->nextLabel));
;}
    break;

  case 56:
#line 561 "translate.y"
    {
    if(MODE_DEBUG == 1){printf("while_do\n");}
    if(!certainTypeCheck((yyvsp[(3) - (6)].typeinfo), "boolean")) {
        fprintf(stderr, "While Condition is not boolean\n");
    }
    insertQuadruple(getCurQuadrupleTable(), QUAD_OP_GOTO,
    buildStrArg((yyvsp[(1) - (6)].structuredStatementHeadType)->trueLabel), NULL, NULL);
    insertQuadruple(getCurQuadrupleTable(), QUAD_OP_LABEL,
    buildStrArg((yyvsp[(1) - (6)].structuredStatementHeadType)->nextLabel), NULL, NULL);
;}
    break;

  case 57:
#line 572 "translate.y"
    {
    (yyvsp[(1) - (1)].structuredStatementHeadType) = buildstructuredStatementHeadType();
;}
    break;

  case 58:
#line 575 "translate.y"
    {
    insertQuadruple(getCurQuadrupleTable(), ":=", buildStrArg((yyvsp[(5) - (5)].typeinfo)->code),
        NULL, buildStrArg((yyvsp[(3) - (5)].idrespType)->idStr));
;}
    break;

  case 59:
#line 579 "translate.y"
    {
    insertQuadruple(getCurQuadrupleTable(), QUAD_OP_LABEL,
        buildStrArg((yyvsp[(1) - (8)].structuredStatementHeadType)->trueLabel), NULL, NULL);
    insertQuadruple(getCurQuadrupleTable(), ">",
        buildStrArg((yyvsp[(3) - (8)].idrespType)->idStr), buildStrArg((yyvsp[(8) - (8)].typeinfo)->code), buildStrArg(createTmp()));
    insertQuadruple(getCurQuadrupleTable(), QUAD_OP_IF,
        NULL, NULL, buildStrArg((yyvsp[(1) - (8)].structuredStatementHeadType)->nextLabel));
;}
    break;

  case 60:
#line 587 "translate.y"
    {
    if(MODE_DEBUG == 1){printf("for_to\n");}
    struct TypeInfo *idType;
    constructTypeInfoFromIdResp(&idType, (yyvsp[(3) - (11)].idrespType));
    if(!typeCheck(idType, (yyvsp[(5) - (11)].typeinfo))) {
        yyerror_unequal_type(idType, (yyvsp[(5) - (11)].typeinfo));
    }
    free(idType);
    
    //handle inter-codegen
    insertQuadruple(getCurQuadrupleTable(), "+", buildStrArg((yyvsp[(3) - (11)].idrespType)->idStr),
    buildStrArg("1"), buildStrArg((yyvsp[(3) - (11)].idrespType)->idStr));
    insertQuadruple(getCurQuadrupleTable(), QUAD_OP_GOTO,
    buildStrArg((yyvsp[(1) - (11)].structuredStatementHeadType)->trueLabel), NULL, NULL);
    insertQuadruple(getCurQuadrupleTable(), QUAD_OP_LABEL,
    buildStrArg((yyvsp[(1) - (11)].structuredStatementHeadType)->nextLabel), NULL, NULL);
;}
    break;

  case 61:
#line 607 "translate.y"
    {
    (yyvsp[(1) - (1)].structuredStatementHeadType) = buildstructuredStatementHeadType();
;}
    break;

  case 62:
#line 610 "translate.y"
    {
    if(!certainTypeCheck((yyvsp[(3) - (3)].typeinfo), "boolean")) {
        fprintf(stderr, "If Condition is not boolean\n");
    }
    //handle inter-codegen
    insertQuadruple(getCurQuadrupleTable(), QUAD_OP_IF,
        NULL, NULL, buildStrArg((yyvsp[(1) - (3)].structuredStatementHeadType)->trueLabel));
    insertQuadruple(getCurQuadrupleTable(), QUAD_OP_GOTO,
        buildStrArg((yyvsp[(1) - (3)].structuredStatementHeadType)->falseLabel), NULL, NULL);
    insertQuadruple(getCurQuadrupleTable(), QUAD_OP_LABEL,
        buildStrArg((yyvsp[(1) - (3)].structuredStatementHeadType)->trueLabel), NULL, NULL);
    free((yyvsp[(3) - (3)].typeinfo));
;}
    break;

  case 63:
#line 622 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("if_else\n");
    }
    (yyval.structuredStatementHeadType) = (yyvsp[(1) - (6)].structuredStatementHeadType);
;}
    break;

  case 64:
#line 631 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("TypeID %d\n", (yyvsp[(1) - (1)].idrespType)->idEntry);
    }
    typeHandler(&(yyvsp[(1) - (1)].idrespType));
    constructTypeInfoFromIdResp(&(yyval.typeinfo), (yyvsp[(1) - (1)].idrespType));
    (yyval.typeinfo)->tag = ATTR_TYPE;
    if(MODE_DEBUG == 1) {
        printAllSymbolTable();
    }
    curTypeIdResp = (yyvsp[(1) - (1)].idrespType);
;}
    break;

  case 65:
#line 644 "translate.y"
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

  case 66:
#line 658 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("Type_Record_Init\n");
    }
    curRecordScopeHash = recordIdHashCode();
    newScopeAndPush(curRecordScopeHash);
    pushRecordHashInStack(curRecordScopeHash);
;}
    break;

  case 67:
#line 667 "translate.y"
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

  case 68:
#line 681 "translate.y"
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
            printf("return array type: %d, scope: %d\n",
            (yyval.typeinfo)->attrInfo.arrayInfo.typeEntry,
            (yyval.typeinfo)->attrInfo.arrayInfo.typeDefScopeId);
        }
    }
;}
    break;

  case 69:
#line 702 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("Constant_SIGN_INT\n");
    }
    (yyval.intType) = getConstantInt((yyvsp[(1) - (2)].stringType), (yyvsp[(2) - (2)].intType));
;}
    break;

  case 70:
#line 709 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("Constant_INT\n");
    }
    (yyval.intType) = getConstantInt(NULL, (yyvsp[(1) - (1)].intType));
;}
    break;

  case 71:
#line 718 "translate.y"
    {
    (yyval.typeinfo) = (yyvsp[(1) - (1)].typeinfo);
    if(MODE_DEBUG == 1){
        printf("Exp_simp\n");
        printf("type reduced as %d\n", (yyval.typeinfo)->typeEntry);
    }
;}
    break;

  case 72:
#line 726 "translate.y"
    {
    handleBinop(&(yyval.typeinfo), (yyvsp[(1) - (3)].typeinfo), (yyvsp[(3) - (3)].typeinfo), (yyvsp[(2) - (3)].stringType), "boolean", 1);
    if(MODE_DEBUG == 1){
        printf("Exp_Simp_Ro\n");
        printf("type reduced as %d\n", (yyval.typeinfo)->typeEntry);
    }
;}
    break;

  case 73:
#line 736 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("RelationalOp_EQ\n");
    }
    (yyval.stringType) = "=";
;}
    break;

  case 74:
#line 743 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("RelationslOp_Less\n");
    }
    (yyval.stringType) = "<";
;}
    break;

  case 75:
#line 750 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("RelationslOp_LE\n");
    }
    (yyval.stringType) = "<=";
;}
    break;

  case 76:
#line 757 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("RelationslOp_G\n");
    }
    (yyval.stringType) = ">";
;}
    break;

  case 77:
#line 764 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("RelationslOp_GE\n");
    }
    (yyval.stringType) = ">=";
;}
    break;

  case 78:
#line 771 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("RelationslOp_NE\n");
    }
    (yyval.stringType) = "<>";
;}
    break;

  case 79:
#line 780 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("SimpleExp_Sign_AddTerm\n");
    }
    (yyval.typeinfo) = (yyvsp[(2) - (2)].typeinfo);
    handleUnaryOpICTable(&(yyval.typeinfo), (yyvsp[(2) - (2)].typeinfo), (yyvsp[(1) - (2)].stringType));
;}
    break;

  case 80:
#line 788 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("SimpleExp_AddTerm\n");
        printf("type reduced as %d\n", (yyval.typeinfo)->typeEntry);
    }
    (yyval.typeinfo) = (yyvsp[(1) - (1)].typeinfo);
;}
    break;

  case 81:
#line 798 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("AddOpTerm_Mul\n");
    }
    handleBinop(&(yyval.typeinfo), (yyvsp[(1) - (3)].typeinfo), (yyvsp[(3) - (3)].typeinfo), (yyvsp[(2) - (3)].stringType), NULL, 0);
    if(strcmp((yyvsp[(2) - (3)].stringType), "or") == 0) {
        (yyval.typeinfo)->typeEntry = getPredefType("boolean");
    }
    if(MODE_DEBUG == 1){
        printf("type reduced as %d\n", (yyval.typeinfo)->typeEntry);
    }
;}
    break;

  case 82:
#line 811 "translate.y"
    {
    (yyval.typeinfo) = (yyvsp[(1) - (1)].typeinfo);
    if(MODE_DEBUG == 1){
        printf("AddOpTerm_Single\n");
        printf("type reduced as %d\n", (yyval.typeinfo)->typeEntry);
    }
;}
    break;

  case 83:
#line 821 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("AddOp_Add\n");
    }
    (yyval.stringType) = "+";
;}
    break;

  case 84:
#line 828 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("AddOp_Min\n");
    }
    (yyval.stringType) = "-";
;}
    break;

  case 85:
#line 835 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("AddOp_OR\n");
    }
    (yyval.stringType) = "or";
;}
    break;

  case 86:
#line 844 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("Term_Fac_Mul\n");
    }
    handleBinop(&(yyval.typeinfo), (yyvsp[(1) - (3)].typeinfo), (yyvsp[(3) - (3)].typeinfo), (yyvsp[(2) - (3)].stringType), NULL, 0);
    if(strcmp((yyvsp[(2) - (3)].stringType), "and") == 0) {
        (yyval.typeinfo)->typeEntry = getPredefType("boolean");
    }
    if(MODE_DEBUG == 1){
        printf("type reduced as %d\n", (yyval.typeinfo)->typeEntry);
    }
;}
    break;

  case 87:
#line 857 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("Term_Factor\n");
        printf("type reduced as %d\n", (yyval.typeinfo)->typeEntry);
    }
    (yyval.typeinfo) = (yyvsp[(1) - (1)].typeinfo);
;}
    break;

  case 88:
#line 867 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("MulOp_MUL\n");
    }
    (yyval.stringType) = "*";
;}
    break;

  case 89:
#line 874 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("MulOp_DIV\n");
    }
    (yyval.stringType) = "/";
;}
    break;

  case 90:
#line 881 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("MulOp_MOD\n");
    }
    (yyval.stringType) = "%";
;}
    break;

  case 91:
#line 888 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("MulOp_AND\n");
    }
    (yyval.stringType) = "and"
;}
    break;

  case 92:
#line 897 "translate.y"
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

  case 93:
#line 907 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("Factor_String\n");
    }
    (yyval.typeinfo) = (struct TypeInfo*)malloc(sizeof(struct TypeInfo));
    (yyval.typeinfo)->typeEntry = getPredefType("string");
    (yyval.typeinfo)->tag = ATTR_VAR;
    (yyval.typeinfo)->code = strcpy2(yylval.stringType);
    printf("String: %d %s\n", (yyval.typeinfo)->typeEntry, (yyval.typeinfo)->code);
;}
    break;

  case 94:
#line 918 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("Factor_FuncRef\n");
    }
    (yyval.typeinfo) = (yyvsp[(1) - (1)].typeinfo);
;}
    break;

  case 95:
#line 925 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("Factor_Var\n");
    }
    (yyval.typeinfo) = (yyvsp[(1) - (1)].typeinfo);
;}
    break;

  case 96:
#line 932 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("Factor_N_Fac\n");
    }
    (yyval.typeinfo) = (struct TypeInfo*)malloc(sizeof(struct TypeInfo));
    (yyval.typeinfo)->typeEntry = getPredefType("boolean");
    (yyval.typeinfo)->tag = ATTR_VAR;
    handleUnaryOpICTable(&(yyval.typeinfo), (yyvsp[(2) - (2)].typeinfo), "not");
    free((yyvsp[(2) - (2)].typeinfo));
;}
    break;

  case 97:
#line 943 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("Factor_Exp_Brace\n");
    }
    (yyval.typeinfo) = (yyvsp[(2) - (3)].typeinfo);
;}
    break;

  case 98:
#line 952 "translate.y"
    {
    arg *argTmp;
    char *tmp;
    char *tmpT;
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
    
    //intermediate code gen
    interCodeVarStart((yyvsp[(1) - (1)].idrespType)->idStr);
;}
    break;

  case 99:
#line 999 "translate.y"
    {
    char *tmp;
    quadrupleTable *curQuadTable = curVarEnclosingQuadTable;
    if(curQuadTable == NULL) {
        curQuadTable = getCurQuadrupleTable();
    }
    if(MODE_DEBUG == 1){
        printf("Var_Comp\n");
    }
    //exit var
    if((yyvsp[(3) - (3)].typeinfo)->typeEntry == -1) {
        free((yyvsp[(3) - (3)].typeinfo));
        constructTypeInfoFromIdResp(&(yyval.typeinfo), (yyvsp[(1) - (3)].idrespType));
        (yyval.typeinfo)->tag = ATTR_VAR;
        (yyval.typeinfo)->code = popVarReferStack();
        if(strcmp((yyval.typeinfo)->code, (yyvsp[(1) - (3)].idrespType)->idStr) != 0) {
            //meaning a tmp was generated for record selection (record)
            (yyval.typeinfo)->code = getLastArg1(curQuadTable);
            removeLastCode(curQuadTable);
        }
    }
    else {
        (yyval.typeinfo) = (yyvsp[(3) - (3)].typeinfo);
    }
    if(MODE_DEBUG == 1){
        printf("var type: %d\n", (yyval.typeinfo)->typeEntry);
    }
;}
    break;

  case 100:
#line 1030 "translate.y"
    {
    if(!isTypeConstructor(curVarIdResp, "record")) {
        fprintf(stderr, "Invalid var: %s is not a record\n", curVarIdResp->idStr);
    }
    else {
        if(curVarEnclosingQuadTable == NULL) {
            curVarEnclosingQuadTable = getCurQuadrupleTable();
            if(MODE_DEBUG) {
                printf("save enclosing quads(%d)\n", getCurScopeId());
            }
        }
        curRecordScopeHash = handleRecordStart(curVarIdResp);
        if(curRecordScopeHash != 0) {
            if(MODE_DEBUG == 1){
                printf("enter recordhash: %d\n", curRecordScopeHash);
            }
        }
    }
;}
    break;

  case 101:
#line 1050 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("CompSel_Record\n");
    }
    (yyval.typeinfo) = (yyvsp[(3) - (3)].typeinfo);
    curRecordScopeHash = handleRecordEnd();
    curVarEnclosingQuadTable = NULL;
    if(curRecordScopeHash != 0) {
        if(MODE_DEBUG == 1){
            printf("clean saved encosing quads\n");
            printf("out recordhash: %d\n", curRecordScopeHash);
        }
    }
    if(MODE_DEBUG) {
        printf("reduced as type: %d\n", (yyvsp[(3) - (3)].typeinfo)->typeEntry);
    }
;}
    break;

  case 102:
#line 1068 "translate.y"
    {
    if(!isTypeConstructor(curVarIdResp, "array")) {
        fprintf(stderr, "Invalid var: structure is not an array\n", curVarIdResp->idStr);
    }
    else {
        pushArrayIdRespInStack(curVarIdResp);
    }
;}
    break;

  case 103:
#line 1077 "translate.y"
    {
    if(!certainTypeCheck((yyvsp[(3) - (3)].typeinfo), "integer")) {
        fprintf(stderr, "Invalid array index\n");
    }
;}
    break;

  case 104:
#line 1083 "translate.y"
    {
    char *tmp;
    char *tmpT;
    curArrayTypeInfo = NULL;
    quadrupleTable *curQuadTable = curVarEnclosingQuadTable;
    if(curQuadTable == NULL) {
        curQuadTable = getCurQuadrupleTable();
    }
    curVarIdResp = popArrayIdResp();
    handleArrayVar(&curVarIdResp, &curArrayTypeInfo);
    if(MODE_DEBUG) {
        printf("curVarIdResp changed to: %d\n", curVarIdResp->idEntry);
    }
    //intermediate code handling
    arrayInterCodeHandling((yyvsp[(3) - (5)].typeinfo)->code);
;}
    break;

  case 105:
#line 1100 "translate.y"
    {
    quadrupleTable *curQuadTable = curVarEnclosingQuadTable;
    if(curQuadTable == NULL) {
        curQuadTable = getCurQuadrupleTable();
    }
    if(MODE_DEBUG == 1){
        printf("CompSel_Array\n");
    }
    if((yyvsp[(7) - (7)].typeinfo)->typeEntry == -1) {
        constructTypeInfoFromArrayTypeInfo(&(yyval.typeinfo), curArrayTypeInfo);
        free(curArrayTypeInfo);
        (yyval.typeinfo)->code = getLastArg1(curQuadTable);
        removeLastCode(curQuadTable);
    }
    else {
        (yyval.typeinfo) = (yyvsp[(7) - (7)].typeinfo);
    }
    (yyval.typeinfo)->tag = ATTR_VAR;
    if(MODE_DEBUG) {
        printf("reduced as type: %d\n", (yyvsp[(3) - (7)].typeinfo)->typeEntry);
    }
;}
    break;

  case 106:
#line 1123 "translate.y"
    {
    (yyval.typeinfo) = (struct TypeInfo*)malloc(sizeof(struct TypeInfo));
    (yyval.typeinfo)->typeEntry = -1;
;}
    break;

  case 107:
#line 1130 "translate.y"
    {
    addCurFuncProcParamCallCounter(1);
    appendToParamTypeList((yyvsp[(1) - (1)].typeinfo));
;}
    break;

  case 108:
#line 1135 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("ActualParamL\n");
    }
;}
    break;

  case 109:
#line 1141 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("ActualParamL\n");
    }
;}
    break;

  case 110:
#line 1149 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("ExpM\n");
    }
    addCurFuncProcParamCallCounter(1);
    appendToParamTypeList((yyvsp[(2) - (2)].typeinfo));
;}
    break;

  case 113:
#line 1163 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("IdList\n");
    }
    addCurParamCounter(1);
    appendToIdList((yyvsp[(1) - (2)].idrespType)->idEntry);
;}
    break;

  case 114:
#line 1173 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("IdListM\n");
    }
;}
    break;

  case 116:
#line 1183 "translate.y"
    {
    if(MODE_DEBUG == 1) {
        printf("Sign_Add\n");
    }
    (yyval.stringType) = "+";
;}
    break;

  case 117:
#line 1190 "translate.y"
    {
    if(MODE_DEBUG == 1){
        printf("Sign_Min\n");
    }
    (yyval.stringType) = "-";
;}
    break;


/* Line 1267 of yacc.c.  */
#line 2994 "translate.tab.c"
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


#line 1199 "translate.y"


yyerror(char *s)
{
    fprintf(stderr, "error: %s\n", s);
}

void yyerror_unequal_type(struct TypeInfo *typeInfo1,
struct TypeInfo *typeInfo2) {
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

void handleFuncProcDeclaration(struct IdResp *id,
struct TypeInfo *retType,
int paramQty,
char *funcProc) {
    union SymbolEntryAttr attr;
    union ARGINFO quadArg1;
    if(strcmp(funcProc, "function") == 0) {
        //set function parameter's type as return type
        setFuncVarInScope(id->idStr, id->idEntry,
        retType->typeEntry, retType->attrInfo);
        registerFunc(id->idEntry, retType->typeEntry,
        retType->attrInfo, paramQty);
    }
    else {
        registerProc(id->idEntry, paramQty);
    }
    cleanCurParamCounter();
    cleanCurFuncProcCallParamCounter();
    
    quadArg1.strInfo = strcpy2(id->idStr);
    insertQuadruple(getCurQuadrupleTable(), QUAD_OP_LABEL,
    buildArg(ARGTYPE_VAR_STR, quadArg1), NULL, NULL);
}

void finishFuncProcDeclaration(struct IdResp *id, char *funcProc) {
    char *op = QUAD_OP_RETURN;
    arg *returnArg = NULL;
    if(strcmp(funcProc, "function") == 0) {
        op = QUAD_OP_FUNRETURN;
        returnArg = buildStrArg(id->idStr);
    }
    insertQuadruple(getCurQuadrupleTable(), op,
    returnArg, NULL, NULL);
}

int enterNewScope(struct IdResp *id) {
    char *name = "";
    if(id->idRespStatus != IDRESP_NORMAL) {
        name = getNameInCurScope(id->idEntry);
        fprintf(stderr, "invalid function/procedure ID: %s\n", name);
        return -1;
    }
    newScopeAndPush(id->idEntry);
    return 0;
}

int setSymbolTypeAttr(int idAddr, int typeEntry,
struct TypeInfo *typedata, int attrTag) {
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

//handling binary operations: e.g. addops/mulops/relops
//including change current production rule's reducing type
//and set intermediate table
// if designatedRuleHeadType is NULL
// ruleHead would be pointed to one of the operands
// other wise ruleHead would be assigned as that type
void handleBinop(struct TypeInfo **ruleHead,
                    struct TypeInfo *op1,
                    struct TypeInfo *op2,
                    char *operator,
                    char *designatedRuleHeadType,
                                int relOp) {
    union ARGINFO arg1;
    union ARGINFO arg2;
    union ARGINFO arg_res;
    int eq = 0;
    quadrupleTable * curtable = curVarEnclosingQuadTable;
    if(curtable == NULL) {
        curtable = getCurQuadrupleTable();
    }
                                    
    arg1.strInfo = op1->code;
    arg2.strInfo = op2->code;
    //arg_res.strInfo = NULL;
    // if(!relOp) {
        arg_res.strInfo = createTmp();
    //}
    if(MODE_DEBUG) {
        printf("handling binop: %s %s %s -> %s\n", op1->code, operator, op2->code, arg_res.strInfo);
    }
    insertQuadruple(curtable, operator,
            buildArg(ARGTYPE_VAR_STR, arg1),
            buildArg(ARGTYPE_VAR_STR, arg2),
            buildArg(ARGTYPE_VAR_STR, arg_res));
    
    if(typeCheck(op1, op2)) {
        eq = 1;
    }
    else {
        yyerror_unequal_type(op1, op2);
        eq = 0;
    }
    
    if(designatedRuleHeadType == NULL) {
        setReduceTypeInfo(&(*ruleHead), op1, op2, eq);
    }
    else {
        constructTypeInfoForCertainSimpleType(&(*ruleHead), designatedRuleHeadType);
    }
    (*ruleHead)->code = arg_res.strInfo;
}

//handling unaryOperator's intermediate code table operation
// e.g. NOT, -
// including setting rulehead's reducing code as tmp name
// setting intermediate code accordingly
void handleUnaryOpICTable(struct TypeInfo **ruleHead,
struct TypeInfo *op1,
char *operator) {
    union ARGINFO arginfo1;
    union ARGINFO arginfo_res;
    arginfo1.strInfo = op1->code;
    (*ruleHead)->code = createTmp();
    arginfo_res.strInfo = (*ruleHead)->code;
    insertQuadruple(getCurQuadrupleTable(), operator,
    buildArg(ARGTYPE_VAR_STR, arginfo1),
    NULL,
    buildArg(ARGTYPE_VAR_STR, arginfo_res));
}

//handling assignsatement
// including insert into intermediate table
// and typechecking, free var
void handleAssignStatement(struct TypeInfo *assignTo,
struct TypeInfo *assignFrom) {
    union ARGINFO arginfo1;
    union ARGINFO arginfo_res;
    if(!typeCheck(assignTo, assignFrom)) {
        yyerror_unequal_type(assignTo, assignFrom);
    }
    arginfo1.strInfo = assignTo->code;
    arginfo_res.strInfo = assignFrom->code;
    insertQuadruple(getCurQuadrupleTable(), ":=",
    buildArg(ARGTYPE_VAR_STR, arginfo_res),
    NULL,
    buildArg(ARGTYPE_VAR_STR, arginfo1));
    free(assignTo);
    free(assignFrom);
}

void interCodeVarStart(char *varName) {
    char *tmp;
    char *tmpT;
    quadrupleTable *curQuads = curVarEnclosingQuadTable;
    if(curQuads == NULL) {
        curQuads = getCurQuadrupleTable();
    }
    if(expecting_record_member) {
        tmp = popVarReferStack();
        tmpT = createTmp();
        tmp = strcat2(tmp, ".");
        tmp = strcat2(tmp, varName);
        insertQuadruple(curQuads, ":=",
        buildStrArg(tmp), NULL, buildStrArg(tmpT));
        pushVarReferStack(tmpT);
        expecting_record_member = 0;
    }
    else {
        pushVarReferStack(varName);
    }
}

void arrayInterCodeHandling(char *expr) {
    char *tmp;
    char *tmpT;
    quadrupleTable *curQuads = curVarEnclosingQuadTable;
    if(curQuads == NULL) {
        curQuads = getCurQuadrupleTable();
    }
    tmp = popVarReferStack();
    tmp = strcat2(tmp, "[");
    tmp = strcat2(tmp, expr);
    tmp = strcat2(tmp, "]");
    tmpT = createTmp();
    insertQuadruple(curQuads, ":=",
        buildStrArg(tmp), NULL, buildStrArg(tmpT));
    pushVarReferStack(tmpT);
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
        //stdout=fopen("parser_debug.out","w");
    }
    yyparse();
    if(MODE_DEBUG == 1){
        //close(stdout);
    }
    stdout = fstream;
    if(MODE_DEBUG == 1){
        printf("\n\nParsing done (debugging info: parser_debug.out).\n\n");
        stdout=fopen("symtable.out","w");
        printAllSymbolTable();
        close(stdout);
        stdout = fstream;
        printAllQuadTable();
        printf("\n\n\n");
        printAllQuadTableAsCommand();
        printf("Done, symbole table: symtable.out\n\n");
    }
    else {
        stdout = fopen("a.txt", "w");
        printAllQuadTableAsCommand();
        close(stdout);
        stdout = fstream;
        printf("Done, intermediatecode: a.txt\n\n");
        printf("\n\nParsing done\n\n");
    }
    return 0;
}
