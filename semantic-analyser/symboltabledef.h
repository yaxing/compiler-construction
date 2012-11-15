//
//  symboltabledef.h
//  compiler-debugging
//
//  Created by Yaxing Chen on 11/15/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_debugging_symboltabledef_h
#define compiler_debugging_symboltabledef_h

typedef union SymbolEntryAttr {
    char *attr;
    struct ArrayInfo {
        int boundLow;
        int boundUp;
        int typeEntry;
    } arrayInfo;
    
    struct RecordInfo {
        int recordMembers[100];
        int qty;
    } recordInfo;
    
    struct FuncInfo {
        int paramQty;
        int returnTypeEntry;
    } funcInfo;
} entryAttr;

typedef struct SymbolEntry {
    int address;
    char *symbolVal;
    char *type;
    entryAttr attribute;
} entry;

typedef struct SymbolTable {
    int size;
    int maxId;
    entry entries[500];
} symboltable;

symboltable *predefinedIdTable;

#endif
