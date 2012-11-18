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
    registerSymbol(getCurSymboltable(), "a", NULL);
    
    printf("scopeid: %d \n", curScope->scopeId);
    printSymbolTable(getCurSymboltable());
    printf("\n");
    
    int addr = getSymbolEntry(getCurSymboltable(), "a");
    if(getType("integer") >= 0) {
        setSymbolTypeAttrDirec(getCurSymboltable(), addr, "integer", attr);
    }
    printf("scopeid: %d \n", curScope->scopeId);
    printSymbolTable(getCurSymboltable());
    
    printf("%d\n", getType("a"));
    
    attr.arrayInfo.boundLow = 1;
    attr.arrayInfo.boundUp = 10;
    attr.arrayInfo.typeEntry = 23;
    registerSymbol(getCurSymboltable(), "b", "array");
    printSymbolTable(getCurSymboltable());
    setSymbolTypeAttrDirec(getCurSymboltable(), getSymbolEntry(getCurSymboltable(), "b"), "array", attr);
    
    printSymbolTable(getCurSymboltable());
    
    attr.funcInfo.paramQty = 2;
    attr.funcInfo.retTypeEntry = 23;
    registerSymbol(getCurSymboltable(), "func1", "function");
    setSymbolTypeAttrDirec(getCurSymboltable(), getSymbolEntry(getCurSymboltable(), "func1"), "function", attr);
    
    newScopeAndPush(getSymbolEntry(getCurSymboltable(), "func1"));
    
    registerSymbol(getCurSymboltable(), "a", "integer");
    
    popScopeStack();
    
    registerSymbol(getCurSymboltable(), "var1", "string");
    
    printf("\n");
    printAllSymbolTable();
    return 0;
}