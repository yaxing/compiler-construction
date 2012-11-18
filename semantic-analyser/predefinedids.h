//
//  predefinedids.h
//  compiler-debugging
//
//  Created by Yaxing Chen on 11/14/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_debugging_predefinedids_h
#define compiler_debugging_predefinedids_h
int keywordsSize = 23;
int typeSize = 7;

char *keywords[] = {
    "and",
    "if",
    "begin",
    "forward",
    "div",
    "do",
    "else",
    "end",
    "for",
    "function",
    "array",
    "mod",
    "not",
    "of",
    "or",
    "procedure",
    "program",
    "record",
    "then",
    "to",
    "type",
    "var",
    "while"
};

char *types[] = {
    "integer",
    "real",
    "boolean",
    "char",
    "string",
    "array",
    "record"
};

char *booleans[] = {
    "true",
    "false"
};

char *null[] = {
    "NIL"
};

#endif
