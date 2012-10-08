//
//  main.c
//  compiler-lexer
//
//  Created by Yaxing Chen on 10/7/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    enum TokenType {
        AND,
        BEGIN,
        FORWARD,
        DIV,
        DO,
        ELSE,
        END,
        FOR,
        FUNCTION,
        IF,
        ARRAY,
        MOD,
        NOT,
        OF,
        OR,
        PROCEDURE,
        PROGRAM,
        RECORD,
        THEN,
        TO,
        TYPE,
        VAR,
        WHILE,
        OP_ADD,
        OP_MUL,
        OP_MIN,
        OP_EQ,
        OP_LESS,
        OP_LESS_EQ,
        OP_GREATER,
        OP_GREATER_EQ,
        OP_NOT_EQ,
        DOT,
        COMMA,
        COLON,
        SEMICOLON,
        ASSIGN,
        DOUBLE_DOT,
        BRACE_L,
        BRACE_R,
        BRACKET_L,
        BRACKET_R,
        NUM,
        ID,
        STRING,
        UNK
    };
    char *symbols[] = {
        "AND",
        "BEGIN",
        "FORWARD",
        "DIV",
        "DO",
        "ELSE",
        "END",
        "FOR",
        "FUNCTION",
        "IF",
        "ARRAY",
        "MOD",
        "NOT",
        "OF",
        "OR",
        "PROCEDURE",
        "PROGRAM",
        "RECORD",
        "THEN",
        "TO",
        "TYPE",
        "VAR",
        "WHILE",
        "OP-ADD",
        "OP-MUL",
        "OP-MIN",
        "OP-EQ",
        "OP-LESS",
        "OP-LESS-EQ",
        "OP-GREATER",
        "OP-GREATER-EQ",
        "OP-NOT-EQ",
        "DOT",
        "COMMA",
        "COLON",
        "SEMICOLON",
        "ASSIGN",
        "DOUBLE-DOT",
        "BRACE-L",
        "BRACE-R",
        "BRACKET-L",
        "BRACKET-R",
        "NUM",
        "ID",
        "STRING",
        "UNK"
    };
    enum TEST{
        test,
        ttt,
        t
    };
    enum TokenType interesting = AND;
    char *names[] = {"ss", "s1", "s2"};
    printf("%d", AND);
    return 0;
}

