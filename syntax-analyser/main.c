//
//  main.c
//  compiler-lexer
//
//  Created by Yaxing Chen on 10/7/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#include <stdio.h>
#include "header.h"
int main(int argc, const char * argv[])
{
    int a = 5;
    char * buf = (char *)malloc(sizeof(a) + 1);
    sprintf(buf, "%d", a);
    printf("%s\n", buf);
//    char *keywords[] = {
//        "and",
//        "if",
//        "begin",
//        "forward",
//        "div",
//        "do",
//        "else",
//        "end",
//        "for",
//        "function",
//        "array",
//        "mod",
//        "not",
//        "of",
//        "or",
//        "procedure",
//        "program",
//        "record",
//        "then",
//        "to",
//        "type",
//        "var",
//        "while"
//    };
    //int i;
//    registerKeywords(keywords, 23);
//    entry * e = registerSymbol("x", "STRING", "test");
//    e = registerSymbol("y", "INT", "100");
//    e = registerSymbol("a", NULL, NULL);
//    appendToIdList(e);
//    e = registerSymbol("b", NULL, NULL);
//    appendToIdList(e);
//    e = registerSymbol("c", NULL, NULL);
//    appendToIdList(e);
//    
//    setIdListTypeAttr("STRING", NULL);
//    setSymbolTypeAttr("c", NULL, "c");
    
    //    initTable();
    //    long addr = 0;
    //    addr = registerSymbol("add", "");
    //    printf("%ld\n", addr);
    //    addr = registerSymbol("min", "");
    //    printf("%ld\n", addr);
    //    addr = registerSymbol("mul", "");
    //    printf("%ld\n", addr);
    //    addr = registerSymbol("div", "");
    //    printf("%ld\n", addr);
    //    addr = registerSymbol("add", "");
    //    printf("%ld\n", addr);
    //    addr = registerSymbol("add", "");
    //    printf("%ld\n", addr);
//    printSymbolTable();
    
    return 0;
}



