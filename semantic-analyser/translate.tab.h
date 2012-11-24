/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 46 "translate.y"
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
/* Line 1529 of yacc.c.  */
#line 162 "translate.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

