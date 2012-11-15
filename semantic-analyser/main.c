//
//  main.c
//  compiler-debugging
//
//  Created by Yaxing Chen on 11/14/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#include <stdio.h>
#include "header.h"

int main() {
    
    initPredefinedSymboltable();
    printSymbolTable(predefinedIdTable);
    
    entryAttr attr;
    initScope();
    scope *curScope = getCurScope();
    registerSymbol(curScope->symboltable, "a", NULL, attr);
    
    printf("scopeid: %d \n", curScope->scopeId);
    printSymbolTable(curScope->symboltable);
    printf("\n");
    
    int addr = getSymbolEntry(curScope->symboltable, "a");
    if(getType("integer") >= 0) {
        setSymbolTypeAttrDirec(curScope->symboltable, addr, "integer", attr);
    }
    printf("scopeid: %d \n", curScope->scopeId);
    printSymbolTable(curScope->symboltable);
    
    printf("%d\n", getType("a"));
    
    attr.arrayInfo.bound = 10;
    attr.arrayInfo.typeEntry = 23;
    registerSymbol(curScope->symboltable, "b", "array", attr);
    
    printSymbolTable(curScope->symboltable);
    return 0;
}