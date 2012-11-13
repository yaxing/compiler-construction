//
//  header.h
//  compiler-debugging
//
//  Created by Yaxing Chen on 10/27/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_debugging_header_h
#define compiler_debugging_header_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "symboltable.h"
#include "bisonheader.h"

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

#endif
