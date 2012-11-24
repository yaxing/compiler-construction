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
    symboltable *table;
    initTypeDescList();
    initPredefinedSymboltable();
    initScope();
    printSymbolTable(predefinedIdTable, 0);
    
    printf("type %d\n", getType("integer"));
    
    entryAttr attr;
    scope *curScope = getCurScope();
    table = getCurSymboltable();
    registerSymbol(table, "a", NULL);
    registerSymbol(table, "test", NULL);
    
    printf("scopeid: %d \n", curScope->scopeId);
    printSymbolTable(getCurSymboltable(), 0);
    printf("\n");
    
    int addr = getSymbolEntry(getCurSymboltable(), "a");
    if(getType("integer") >= 0) {
        setSymbolTypeAttrDirec(getCurSymboltable(), addr, "integer", attr, ATTR_VAR);
    }
    printf("scopeid: %d \n", curScope->scopeId);
    printSymbolTable(getCurSymboltable(), 0);

    
    attr.arrayInfo.boundLow = 1;
    attr.arrayInfo.boundUp = 10;
    attr.arrayInfo.typeEntry = getType("integer");
    registerSymbol(getCurSymboltable(), "b", NULL);
    printSymbolTable(getCurSymboltable(), 0);
    setSymbolTypeAttrDirec(getCurSymboltable(), getSymbolEntry(getCurSymboltable(), "b"), "array", attr, ATTR_VAR);
    
    printSymbolTable(getCurSymboltable(), 0);
    
    attr.funcInfo.paramQty = 2;
    attr.funcInfo.retTypeEntry = getType("integer");
    registerSymbol(getCurSymboltable(), "func1", NULL);
    setSymbolTypeAttrDirec(getCurSymboltable(), getSymbolEntry(getCurSymboltable(), "func1"), "function", attr, ATTR_DEFAULT);
    
    newScopeAndPush(getSymbolEntry(getCurSymboltable(), "func1"));
    
    registerSymbol(getCurSymboltable(), "a", "integer");
    
    popScopeStack();
    
    registerSymbol(getCurSymboltable(), "var1", "string");
    
    registerSymbol(getCurSymboltable(), "rec1", NULL);
    attr.recordInfo.scopeHashCode = recordIdHashCode();
    printf("hash: %d\n", attr.recordInfo.scopeHashCode);
    setSymbolTypeAttrDirec(getCurSymboltable(), getSymbolEntry(getCurSymboltable(), "rec1"), "record", attr, ATTR_VAR);
    
    newScopeAndPush(attr.recordInfo.scopeHashCode);
    registerSymbol(getCurSymboltable(), "a", "integer");
    popScopeStack();
    
    registerSymbol(getCurSymboltable(), "rec2", NULL);
    attr.recordInfo.scopeHashCode = recordIdHashCode();
    printf("hash: %d\n", attr.recordInfo.scopeHashCode);
    setSymbolTypeAttrDirec(getCurSymboltable(), getSymbolEntry(getCurSymboltable(), "rec2"), "record", attr, ATTR_VAR);
    
    newScopeAndPush(attr.recordInfo.scopeHashCode);
    registerSymbol(getCurSymboltable(), "a", "integer");
//    registerSymbol(getCurSymboltable(), "b", "integer");
    popScopeStack();
    
    printf("\n");
    printAllSymbolTable();
    return 0;
}