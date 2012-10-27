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
     LT = 258,
     EQ = 259,
     NE = 260,
     GT = 261,
     GE = 262,
     LE = 263,
     RELOP = 264,
     PLUS = 265,
     MINUS = 266,
     MULTI = 267,
     ARIOP = 268,
     DOT = 269,
     COMMA = 270,
     COLON = 271,
     SEMICOLON = 272,
     ASSIGN = 273,
     DDOT = 274,
     L_BRACE = 275,
     R_BRACE = 276,
     L_BRACKET = 277,
     R_BRACKET = 278,
     OTHEROP = 279,
     ANDSYM = 280,
     BEGINSYM = 281,
     FORWARDSYM = 282,
     DIVSYM = 283,
     DOSYM = 284,
     ELSESYM = 285,
     ENDSYM = 286,
     FORSYM = 287,
     FUNCTIONSYM = 288,
     IFSYM = 289,
     ARRAYSYM = 290,
     MODSYM = 291,
     NOTSYM = 292,
     OFSYM = 293,
     ORSYM = 294,
     PROCEDURESYM = 295,
     PROGRAMSYM = 296,
     RECORDSYM = 297,
     THENSYM = 298,
     TOSYM = 299,
     TYPESYM = 300,
     VARSYM = 301,
     WHILESYM = 302,
     ID = 303,
     NUMBER = 304,
     STRING = 305,
     UNREC = 306
   };
#endif
/* Tokens.  */
#define LT 258
#define EQ 259
#define NE 260
#define GT 261
#define GE 262
#define LE 263
#define RELOP 264
#define PLUS 265
#define MINUS 266
#define MULTI 267
#define ARIOP 268
#define DOT 269
#define COMMA 270
#define COLON 271
#define SEMICOLON 272
#define ASSIGN 273
#define DDOT 274
#define L_BRACE 275
#define R_BRACE 276
#define L_BRACKET 277
#define R_BRACKET 278
#define OTHEROP 279
#define ANDSYM 280
#define BEGINSYM 281
#define FORWARDSYM 282
#define DIVSYM 283
#define DOSYM 284
#define ELSESYM 285
#define ENDSYM 286
#define FORSYM 287
#define FUNCTIONSYM 288
#define IFSYM 289
#define ARRAYSYM 290
#define MODSYM 291
#define NOTSYM 292
#define OFSYM 293
#define ORSYM 294
#define PROCEDURESYM 295
#define PROGRAMSYM 296
#define RECORDSYM 297
#define THENSYM 298
#define TOSYM 299
#define TYPESYM 300
#define VARSYM 301
#define WHILESYM 302
#define ID 303
#define NUMBER 304
#define STRING 305
#define UNREC 306




/* Copy the first part of user declarations.  */
#line 1 "test.y"

#include "header.h"

extern FILE *yyin;
extern int count;
extern char* yytext;

/*Symbol Table*/
extern struct token entity[1000];

/*Function declaration*/
void set_ID_type(int,char*);
void set_Function_type(int,struct ids* idptr);
void set_VarIds_type(struct ids*,char*);
char* toStr(int);


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
#line 18 "test.y"
{
  struct ids* idtype;
  int num;
  char* strtype;
}
/* Line 193 of yacc.c.  */
#line 221 "test.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 234 "test.tab.c"

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
#define YYLAST   197

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNRULES -- Number of states.  */
#define YYNSTATES  193

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
      63,    66,    69,    73,    76,    79,    83,    85,    87,    90,
      93,    96,    99,   103,   107,   115,   123,   133,   143,   144,
     146,   150,   156,   159,   161,   165,   167,   171,   173,   175,
     176,   178,   180,   184,   189,   191,   196,   203,   208,   217,
     219,   228,   232,   234,   235,   237,   241,   247,   250,   252,
     254,   258,   260,   262,   264,   266,   268,   270,   273,   275,
     277,   281,   283,   285,   287,   289,   293,   295,   297,   299,
     301,   303,   305,   307,   309,   312,   316,   321,   324,   325,
     329,   334,   335,   337,   339,   343,   345,   349,   351
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    41,    48,    17,    68,    14,    -1,    41,
      48,    17,    54,    68,    14,    -1,    41,    48,    17,    56,
      68,    14,    -1,    41,    48,    17,    58,    68,    14,    -1,
      41,    48,    17,    54,    56,    68,    14,    -1,    41,    48,
      17,    56,    58,    68,    14,    -1,    41,    48,    17,    54,
      58,    68,    14,    -1,    41,    48,    17,    54,    56,    58,
      68,    14,    -1,    45,    55,    -1,    61,    17,    -1,    61,
      17,    55,    -1,    46,    57,    -1,    62,    17,    -1,    62,
      17,    57,    -1,    59,    -1,    60,    -1,    63,    17,    -1,
      59,    58,    -1,    64,    17,    -1,    60,    58,    -1,    48,
       4,    75,    -1,    93,    16,    75,    -1,    40,    48,    20,
      65,    21,    17,    67,    -1,    40,    48,    20,    65,    21,
      17,    27,    -1,    33,    48,    20,    65,    21,    16,    76,
      17,    67,    -1,    33,    48,    20,    65,    21,    16,    76,
      17,    27,    -1,    -1,    66,    -1,    93,    16,    75,    -1,
      93,    16,    75,    17,    66,    -1,    56,    68,    -1,    68,
      -1,    26,    69,    31,    -1,    70,    -1,    70,    17,    69,
      -1,    71,    -1,    74,    -1,    -1,    72,    -1,    73,    -1,
      89,    18,    80,    -1,    48,    20,    91,    21,    -1,    68,
      -1,    34,    80,    43,    70,    -1,    34,    80,    43,    70,
      30,    70,    -1,    47,    80,    29,    70,    -1,    32,    48,
      18,    80,    44,    80,    29,    70,    -1,    48,    -1,    35,
      22,    79,    19,    79,    23,    38,    75,    -1,    42,    77,
      31,    -1,    48,    -1,    -1,    78,    -1,    93,    16,    75,
      -1,    93,    16,    75,    17,    78,    -1,    94,    49,    -1,
      49,    -1,    82,    -1,    82,    81,    82,    -1,     3,    -1,
       8,    -1,     6,    -1,     7,    -1,     5,    -1,     4,    -1,
      94,    83,    -1,    83,    -1,    85,    -1,    85,    84,    83,
      -1,    10,    -1,    11,    -1,    39,    -1,    87,    -1,    87,
      86,    85,    -1,    12,    -1,    28,    -1,    36,    -1,    25,
      -1,    49,    -1,    50,    -1,    89,    -1,    88,    -1,    37,
      87,    -1,    20,    80,    21,    -1,    48,    20,    91,    21,
      -1,    48,    90,    -1,    -1,    14,    48,    90,    -1,    22,
      80,    23,    90,    -1,    -1,    92,    -1,    80,    -1,    80,
      15,    92,    -1,    48,    -1,    48,    15,    93,    -1,    10,
      -1,    11,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    78,    78,    79,    80,    81,    82,    83,    84,    85,
      88,    91,    92,    95,    98,    99,   102,   103,   106,   107,
     110,   111,   114,   117,   120,   122,   126,   128,   132,   133,
     136,   137,   140,   141,   144,   147,   148,   151,   152,   155,
     156,   157,   160,   163,   166,   167,   168,   169,   170,   173,
     174,   175,   178,   181,   182,   185,   186,   189,   190,   193,
     194,   197,   198,   199,   200,   201,   202,   205,   206,   209,
     210,   213,   214,   215,   218,   219,   222,   223,   224,   225,
     228,   229,   230,   231,   232,   233,   236,   239,   242,   243,
     244,   247,   248,   251,   252,   255,   256,   259,   260
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LT", "EQ", "NE", "GT", "GE", "LE",
  "RELOP", "PLUS", "MINUS", "MULTI", "ARIOP", "DOT", "COMMA", "COLON",
  "SEMICOLON", "ASSIGN", "DDOT", "L_BRACE", "R_BRACE", "L_BRACKET",
  "R_BRACKET", "OTHEROP", "ANDSYM", "BEGINSYM", "FORWARDSYM", "DIVSYM",
  "DOSYM", "ELSESYM", "ENDSYM", "FORSYM", "FUNCTIONSYM", "IFSYM",
  "ARRAYSYM", "MODSYM", "NOTSYM", "OFSYM", "ORSYM", "PROCEDURESYM",
  "PROGRAMSYM", "RECORDSYM", "THENSYM", "TOSYM", "TYPESYM", "VARSYM",
  "WHILESYM", "ID", "NUMBER", "STRING", "UNREC", "$accept", "Program",
  "TypeDefinitions", "TypeDefinitionSub", "VariableDeclarations",
  "VariableDeclarationSub", "SubprogramDeclarations",
  "ProcedureDeclarationSub", "FunctionDeclarationSub", "TypeDefinition",
  "VariableDeclaration", "ProcedureDeclaration", "FunctionDeclaration",
  "FormalParameterList", "FormalParameterListSub", "Block",
  "CompoundStatement", "StatementSequence", "Statement", "SimpleStatement",
  "AssignmentStatement", "ProcedureStatement", "StructuredStatement",
  "Type", "ResultType", "Fieldlist", "FieldlistSub", "Constant",
  "Expression", "RelationalOp", "SimpleExpression", "SimpleExpressionSub",
  "AddOp", "Term", "MulOp", "Factor", "FunctionReference", "Variable",
  "ComponentSelection", "ActualParameterList", "ActualParameterListSub",
  "Identifierlist", "Sign", 0
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
      60,    60,    61,    62,    63,    63,    64,    64,    65,    65,
      66,    66,    67,    67,    68,    69,    69,    70,    70,    71,
      71,    71,    72,    73,    74,    74,    74,    74,    74,    75,
      75,    75,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    81,    81,    81,    81,    81,    81,    82,    82,    83,
      83,    84,    84,    84,    85,    85,    86,    86,    86,    86,
      87,    87,    87,    87,    87,    87,    88,    89,    90,    90,
      90,    91,    91,    92,    92,    93,    93,    94,    94
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     6,     6,     6,     7,     7,     7,     8,
       2,     2,     3,     2,     2,     3,     1,     1,     2,     2,
       2,     2,     3,     3,     7,     7,     9,     9,     0,     1,
       3,     5,     2,     1,     3,     1,     3,     1,     1,     0,
       1,     1,     3,     4,     1,     4,     6,     4,     8,     1,
       8,     3,     1,     0,     1,     3,     5,     2,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     4,     2,     0,     3,
       4,     0,     1,     1,     3,     1,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    39,     0,     0,     0,
       0,     0,     0,     0,    16,    17,     0,     0,     0,     0,
       0,     0,    88,    44,     0,    35,    37,    40,    41,    38,
       0,     0,     0,     0,    10,     0,    95,    13,     0,     0,
       0,     0,     0,     0,     0,     0,    19,    21,    18,    20,
       2,     0,    97,    98,     0,     0,    88,    80,    81,     0,
      59,    68,    69,    74,    83,    82,     0,     0,     0,    91,
       0,    87,    34,    39,     0,    28,    28,     0,    11,     0,
      14,     0,     0,     0,     0,     3,     0,     4,     5,     0,
       0,    84,    91,    39,    61,    66,    65,    63,    64,    62,
       0,    71,    72,    73,     0,    76,    79,    77,    78,     0,
      67,    39,    88,    93,     0,    92,     0,    36,    42,     0,
      29,     0,     0,     0,    53,    49,    22,    12,    96,    15,
      23,     0,     6,     8,     7,     0,    85,     0,    45,    60,
      70,    75,    47,    89,     0,    43,    88,     0,     0,     0,
       0,     0,    54,     0,     9,     0,    86,    39,    94,    90,
       0,    30,     0,    58,     0,     0,    51,     0,     0,    46,
      52,     0,     0,    25,     0,    24,    33,     0,    57,    55,
      39,     0,    31,    32,     0,     0,    48,    27,    26,     0,
      56,     0,    50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    11,    34,   174,    37,    13,    14,    15,    35,
      38,    16,    17,   119,   120,   175,    23,    24,    25,    26,
      27,    28,    29,   126,   171,   151,   152,   164,   113,   100,
      60,    61,   104,    62,   109,    63,    64,    65,    71,   114,
     115,   121,    66
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -109
static const yytype_int16 yypact[] =
{
     -23,   -29,    40,    24,  -109,    48,    52,   -11,     9,    18,
      32,    49,    30,    57,   -17,   -17,    41,    68,    77,    44,
       2,     2,    90,  -109,    72,    88,  -109,  -109,  -109,  -109,
      91,    86,    98,   104,  -109,   102,   105,  -109,   111,   113,
      30,    57,   116,    57,   117,   118,  -109,  -109,  -109,  -109,
    -109,   115,  -109,  -109,     2,    -3,    93,  -109,  -109,    92,
     119,  -109,    20,    37,  -109,  -109,    -3,   107,    89,     2,
       2,  -109,  -109,    52,     2,    32,    32,   -15,    18,    32,
      32,   -15,    57,   120,   124,  -109,   125,  -109,  -109,     2,
     121,  -109,     2,    52,  -109,  -109,  -109,  -109,  -109,  -109,
       2,  -109,  -109,  -109,    -3,  -109,  -109,  -109,  -109,    -3,
    -109,    52,    10,   126,   122,  -109,   123,  -109,  -109,   127,
    -109,   128,   129,   130,    32,  -109,  -109,  -109,  -109,  -109,
    -109,   133,  -109,  -109,  -109,    96,  -109,   132,   131,  -109,
    -109,  -109,  -109,  -109,     2,  -109,    10,   135,   -15,   137,
      -6,   134,  -109,   139,  -109,     2,  -109,    52,  -109,  -109,
     101,   141,    71,  -109,   140,   114,  -109,   -15,   138,  -109,
    -109,   145,    32,  -109,    57,  -109,  -109,    -6,  -109,   147,
      52,    75,  -109,  -109,   143,    32,  -109,  -109,  -109,   136,
    -109,   -15,  -109
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,  -109,    78,    50,    95,    14,  -109,  -109,  -109,
    -109,  -109,  -109,    94,    -4,    -9,    -5,   100,   -90,  -109,
    -109,  -109,  -109,   -80,  -109,  -109,   -14,     1,   -10,  -109,
      79,   -51,  -109,    73,  -109,   142,  -109,     3,   -98,    97,
      36,    -8,  -108
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      18,   130,    39,   138,    52,    53,    42,    44,    45,    30,
      59,    67,    52,    53,   143,   110,     7,    54,     1,     3,
     123,   142,    54,     8,    68,    41,    43,   124,    46,    47,
     101,   102,    70,   125,    55,    83,    84,    31,    86,    55,
       4,     5,   165,   163,    90,    56,    57,    58,   159,   105,
      56,    57,    58,   140,    82,    12,     6,    32,    48,   103,
     116,    40,   106,     7,   118,   107,    33,   169,   161,   165,
       8,   128,    39,   108,     6,     6,    30,   131,     6,   135,
      36,     7,     7,     6,    19,    49,    20,   179,     8,     8,
     186,    50,    51,     9,    10,    10,    30,     6,   173,    21,
      22,     6,   187,    72,    68,    73,    75,    68,    77,    74,
      69,   192,    70,    92,    30,    70,   153,    10,    76,    78,
      79,    10,    94,    95,    96,    97,    98,    99,    80,    81,
      85,    87,    88,    89,   132,    93,   111,   112,   133,   134,
     155,   144,   136,   145,   148,   168,   146,   154,   147,   170,
     149,   160,   150,   156,   162,   167,   127,   176,   172,   177,
      30,   157,   181,   178,   185,   166,   189,   180,   182,   183,
     122,   190,   188,   117,   191,   129,   176,   153,   184,   139,
     158,     0,   141,    30,     0,     0,     0,     0,     0,   137,
       0,     0,     0,     0,     0,     0,     0,    91
};

static const yytype_int16 yycheck[] =
{
       5,    81,    10,    93,    10,    11,    11,    12,    13,     6,
      20,    21,    10,    11,   112,    66,    33,    20,    41,    48,
      35,   111,    20,    40,    14,    11,    12,    42,    14,    15,
      10,    11,    22,    48,    37,    40,    41,    48,    43,    37,
       0,    17,   150,    49,    54,    48,    49,    50,   146,    12,
      48,    49,    50,   104,    40,     5,    26,    48,    17,    39,
      70,    11,    25,    33,    74,    28,    48,   157,   148,   177,
      40,    79,    80,    36,    26,    26,    73,    82,    26,    89,
      48,    33,    33,    26,    32,    17,    34,   167,    40,    40,
     180,    14,    48,    45,    46,    46,    93,    26,    27,    47,
      48,    26,    27,    31,    14,    17,    20,    14,     4,    18,
      20,   191,    22,    20,   111,    22,   124,    46,    20,    17,
      15,    46,     3,     4,     5,     6,     7,     8,    17,    16,
      14,    14,    14,    18,    14,    43,    29,    48,    14,    14,
      44,    15,    21,    21,    16,   155,    23,    14,    21,    48,
      21,    16,    22,    21,    17,    16,    78,   162,    17,    19,
     157,    30,    17,    49,    17,    31,    23,    29,   172,   174,
      76,   185,   181,    73,    38,    80,   181,   185,   177,   100,
     144,    -1,   109,   180,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    53,    48,     0,    17,    26,    33,    40,    45,
      46,    54,    56,    58,    59,    60,    63,    64,    68,    32,
      34,    47,    48,    68,    69,    70,    71,    72,    73,    74,
      89,    48,    48,    48,    55,    61,    48,    57,    62,    93,
      56,    58,    68,    58,    68,    68,    58,    58,    17,    17,
      14,    48,    10,    11,    20,    37,    48,    49,    50,    80,
      82,    83,    85,    87,    88,    89,    94,    80,    14,    20,
      22,    90,    31,    17,    18,    20,    20,     4,    17,    15,
      17,    16,    58,    68,    68,    14,    68,    14,    14,    18,
      80,    87,    20,    43,     3,     4,     5,     6,     7,     8,
      81,    10,    11,    39,    84,    12,    25,    28,    36,    86,
      83,    29,    48,    80,    91,    92,    80,    69,    80,    65,
      66,    93,    65,    35,    42,    48,    75,    55,    93,    57,
      75,    68,    14,    14,    14,    80,    21,    91,    70,    82,
      83,    85,    70,    90,    15,    21,    23,    21,    16,    21,
      22,    77,    78,    93,    14,    44,    21,    30,    92,    90,
      16,    75,    17,    49,    79,    94,    31,    16,    80,    70,
      48,    76,    17,    27,    56,    67,    68,    19,    49,    75,
      29,    17,    66,    68,    79,    17,    70,    27,    67,    23,
      78,    38,    75
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
#line 78 "test.y"
    {printf("Program\n");;}
    break;

  case 3:
#line 79 "test.y"
    {printf("Program\n");;}
    break;

  case 4:
#line 80 "test.y"
    {printf("Program\n");;}
    break;

  case 5:
#line 81 "test.y"
    {printf("Program\n");;}
    break;

  case 6:
#line 82 "test.y"
    {printf("Program\n");;}
    break;

  case 7:
#line 83 "test.y"
    {printf("Program\n");;}
    break;

  case 8:
#line 84 "test.y"
    {printf("Program\n");;}
    break;

  case 9:
#line 85 "test.y"
    {printf("Program\n");;}
    break;

  case 10:
#line 88 "test.y"
    {printf("TypeDefinitions\n");;}
    break;

  case 13:
#line 95 "test.y"
    {printf("VariableDeclaration\n");;}
    break;

  case 16:
#line 102 "test.y"
    {printf("SubprogramDeclarations\n");;}
    break;

  case 17:
#line 103 "test.y"
    {printf("SubprogramDeclarations\n");;}
    break;

  case 22:
#line 114 "test.y"
    {printf("TypeDefinition\n");set_ID_type((yyvsp[(1) - (3)].num),(yyvsp[(3) - (3)].strtype));;}
    break;

  case 23:
#line 117 "test.y"
    {printf("VariableDeclaration\n");set_VarIds_type((yyvsp[(1) - (3)].idtype),(yyvsp[(3) - (3)].strtype));;}
    break;

  case 24:
#line 121 "test.y"
    {printf("ProcedureDeclaration\n");set_Function_type((yyvsp[(2) - (7)].num), (yyvsp[(4) - (7)].idtype));;}
    break;

  case 25:
#line 123 "test.y"
    {printf("ProcedureDeclaration\n");set_Function_type((yyvsp[(2) - (7)].num), (yyvsp[(4) - (7)].idtype));;}
    break;

  case 26:
#line 127 "test.y"
    {printf("FunctionDeclaration\n");set_Function_type((yyvsp[(2) - (9)].num), (yyvsp[(4) - (9)].idtype));;}
    break;

  case 27:
#line 129 "test.y"
    {printf("FunctionDeclaration\n");set_Function_type((yyvsp[(2) - (9)].num), (yyvsp[(4) - (9)].idtype));;}
    break;

  case 28:
#line 132 "test.y"
    {printf("FormalParameterList\n");;}
    break;

  case 29:
#line 133 "test.y"
    {printf("FormalParameterList\n");;}
    break;

  case 30:
#line 136 "test.y"
    { (yyval.idtype)->depth = (yyvsp[(1) - (3)].idtype)->depth; ;}
    break;

  case 31:
#line 137 "test.y"
    { (yyval.idtype)->depth = (yyvsp[(1) - (5)].idtype)->depth + (yyvsp[(5) - (5)].idtype)->depth; ;}
    break;

  case 32:
#line 140 "test.y"
    {printf("Block\n");;}
    break;

  case 33:
#line 141 "test.y"
    {printf("Block");;}
    break;

  case 34:
#line 144 "test.y"
    {printf("CompoundStatement\n");;}
    break;

  case 35:
#line 147 "test.y"
    {printf("StatementSequence\n");;}
    break;

  case 36:
#line 148 "test.y"
    {printf("StatementSequence\n");;}
    break;

  case 37:
#line 151 "test.y"
    {printf("Statement\n");;}
    break;

  case 38:
#line 152 "test.y"
    {printf("Statement\n");;}
    break;

  case 39:
#line 155 "test.y"
    {printf("SimpleStatement\n");;}
    break;

  case 40:
#line 156 "test.y"
    {printf("SimpleStatement\n");;}
    break;

  case 41:
#line 157 "test.y"
    {printf("SimpleStatement\n");;}
    break;

  case 42:
#line 160 "test.y"
    {printf("AssignmentStatement\n");;}
    break;

  case 43:
#line 163 "test.y"
    {printf("ProcedureStatement\n");;}
    break;

  case 44:
#line 166 "test.y"
    {printf("StructuredStatement\n");;}
    break;

  case 45:
#line 167 "test.y"
    {printf("StructuredStatement\n");;}
    break;

  case 46:
#line 168 "test.y"
    {printf("StructuredStatement\n");;}
    break;

  case 47:
#line 169 "test.y"
    {printf("StructuredStatement\n");;}
    break;

  case 48:
#line 170 "test.y"
    {printf("StructuredStatement\n");;}
    break;

  case 49:
#line 173 "test.y"
    {printf("Type\n"); (yyval.strtype) = toStr((yyvsp[(1) - (1)].num));;}
    break;

  case 50:
#line 174 "test.y"
    {printf("Type\n"); (yyval.strtype) = "array";;}
    break;

  case 51:
#line 175 "test.y"
    {printf("Type\n"); (yyval.strtype) ="record";;}
    break;

  case 52:
#line 178 "test.y"
    {printf("ResultType\n");;}
    break;

  case 53:
#line 181 "test.y"
    {printf("Fieldlist\n");;}
    break;

  case 54:
#line 182 "test.y"
    {printf("Fieldlist\n");;}
    break;

  case 55:
#line 185 "test.y"
    {set_VarIds_type((yyvsp[(1) - (3)].idtype),(yyvsp[(3) - (3)].strtype));;}
    break;

  case 56:
#line 186 "test.y"
    {set_VarIds_type((yyvsp[(1) - (5)].idtype),(yyvsp[(3) - (5)].strtype));;}
    break;

  case 57:
#line 189 "test.y"
    {printf("Constant\n");;}
    break;

  case 58:
#line 190 "test.y"
    {printf("Constant\n");;}
    break;

  case 59:
#line 193 "test.y"
    {printf("Expression\n");;}
    break;

  case 60:
#line 194 "test.y"
    {printf("Expression\n");;}
    break;

  case 61:
#line 197 "test.y"
    {printf("RelationalOp\n");;}
    break;

  case 62:
#line 198 "test.y"
    {printf("RelationalOp\n");;}
    break;

  case 63:
#line 199 "test.y"
    {printf("RelationalOp\n");;}
    break;

  case 64:
#line 200 "test.y"
    {printf("RelationalOp\n");;}
    break;

  case 65:
#line 201 "test.y"
    {printf("RelationalOp\n");;}
    break;

  case 66:
#line 202 "test.y"
    {printf("RelationalOp\n");;}
    break;

  case 67:
#line 205 "test.y"
    {printf("SimpleExpression\n");;}
    break;

  case 68:
#line 206 "test.y"
    {printf("SimpleExpression\n");;}
    break;

  case 71:
#line 213 "test.y"
    {printf("AddOp\n");;}
    break;

  case 72:
#line 214 "test.y"
    {printf("AddOp\n");;}
    break;

  case 73:
#line 215 "test.y"
    {printf("AddOp\n");;}
    break;

  case 74:
#line 218 "test.y"
    {printf("Factor\n");;}
    break;

  case 75:
#line 219 "test.y"
    {printf("Factor\n");;}
    break;

  case 76:
#line 222 "test.y"
    {printf("MulOp\n");;}
    break;

  case 77:
#line 223 "test.y"
    {printf("MulOp\n");;}
    break;

  case 78:
#line 224 "test.y"
    {printf("MulOp\n");;}
    break;

  case 79:
#line 225 "test.y"
    {printf("MulOp\n");;}
    break;

  case 80:
#line 228 "test.y"
    {printf("Factor\n");;}
    break;

  case 81:
#line 229 "test.y"
    {printf("Factor\n");;}
    break;

  case 82:
#line 230 "test.y"
    {printf("Factor\n");;}
    break;

  case 83:
#line 231 "test.y"
    {printf("Factor\n");;}
    break;

  case 84:
#line 232 "test.y"
    {printf("Factor\n");;}
    break;

  case 85:
#line 233 "test.y"
    {printf("Factor\n");;}
    break;

  case 86:
#line 236 "test.y"
    {printf("FunctionReference\n");;}
    break;

  case 87:
#line 239 "test.y"
    {printf("Variable\n");;}
    break;

  case 88:
#line 242 "test.y"
    {printf("ComponentSelection\n");;}
    break;

  case 89:
#line 243 "test.y"
    {printf("ComponentSelection\n");;}
    break;

  case 90:
#line 244 "test.y"
    {printf("ComponentSelection\n");;}
    break;

  case 91:
#line 247 "test.y"
    {printf("ActualParameterList\n");;}
    break;

  case 92:
#line 248 "test.y"
    {printf("ActualParameterList\n");;}
    break;

  case 95:
#line 255 "test.y"
    { (yyval.idtype) = newid((yyvsp[(1) - (1)].num),NULL); printf("Identifierlist\n");;}
    break;

  case 96:
#line 256 "test.y"
    { (yyval.idtype) = newid((yyvsp[(1) - (3)].num),(yyvsp[(3) - (3)].idtype)); printf("Identifierlist\n");;}
    break;

  case 97:
#line 259 "test.y"
    {printf("Sign\n");;}
    break;

  case 98:
#line 260 "test.y"
    {printf("Sign\n");;}
    break;


/* Line 1267 of yacc.c.  */
#line 2040 "test.tab.c"
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


#line 262 "test.y"

int main(int argc, char *argv[])
{
    ++argv, --argc;    /* skip argv[0] */
    if (argc > 0) {
        yyin = fopen(argv[0], "r");
    } else {
        yyin = stdin;
    }
    printf("\n\nStart parsing...:\n\n");
    freopen("rule.out","w",stdout);
    yyparse();

    freopen("symtable.out","w",stdout);
    printf("\n\nSymbol Table:\n");
    int i;
    for(i=0;i<count;i++){
      printf("entry: %3d, symbol: %12s, property: %3s, type: %4s \n",i,entity[i].value,entity[i].property,entity[i].type);
    }
    return 0;
};

yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
};

void set_ID_type(int id, char* type){
  //char* str = strdup(yytext);
  entity[id].type = strdup(type);
}

void set_Function_type(int id, struct ids* idptr){
  char buffer[10];
  //printf("------sdfsfd----%d--=====",idptr->depth);
  sprintf(buffer,"%d",idptr->depth);
  entity[id].type = strdup(buffer);
}

void set_VarIds_type(struct ids* ids,char* type){
  //printf("-------------ids--%d---type---%d\n",ids->index,type);
  while(ids != NULL){
    entity[ids->index].type = strdup(type);
    ids = ids->next;
  }
}

struct ids* newid(int id,struct ids* next){
  struct ids* i = malloc(sizeof(struct ids));
  //printf("----------%d--=====",id);
  i->index = id;
  i->next = next;
  if(next == NULL){
    i->depth = 1;
  }else{
    i->depth = 1 + (next->depth);
  }
  return i;
}

char* toStr(int id){
  return entity[id].value;
}


