//
//  main.c
//  compiler-lexer
//
//  Created by Yaxing Chen on 10/7/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#include <stdio.h>
#include "symboltable.h"

int main(int argc, const char * argv[])
{
    initTable();
    long addr = 0;
    addr = registerSymbol("add", "");
    printf("%ld\n", addr);
    addr = registerSymbol("min", "");
    printf("%ld\n", addr);
    addr = registerSymbol("mul", "");
    printf("%ld\n", addr);
    addr = registerSymbol("div", "");
    printf("%ld\n", addr);
    addr = registerSymbol("add", "");
    printf("%ld\n", addr);
    addr = registerSymbol("add", "");
    printf("%ld\n", addr);
    entry *cursor = getSymbolTableHead();
    while(cursor != NULL) {
        printf("%s\n", cursor->symbolVal);
        cursor = cursor->next;
    }
    return 0;
}

