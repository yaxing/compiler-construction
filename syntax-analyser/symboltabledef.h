//
//  symboltabledef.h
//  compiler-debugging
//
//  Created by Yaxing Chen on 11/15/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_debugging_symboltabledef_h
#define compiler_debugging_symboltabledef_h
#include "typedescriptor.h"

typedef struct SymbolEntry {
    int address;
    char *symbolVal;
    struct TypeDescriptor *typedesc;
} entry;

typedef struct SymbolTable {
    int size;
    int maxId;
    entry entries[500];
} symboltable;

symboltable *predefinedIdTable;

#endif
