//
//  symboltable.h
//  compiler-lexer
//
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#pragma once
#ifndef compiler_lexer_symboltable_h
#define compiler_lexer_symboltable_h
#include "symboltabledef.h"

symboltable *createSymbolTable() {
    symboltable *table = (symboltable *)malloc(sizeof(symboltable));
    table->size = sizeof(table->entries) / sizeof(entry);
    table->maxId = -1;
    return table;
}

int checkIndex(symboltable *table, int i) {
    if (i >= 0 && i <= table->maxId) {
        return 1;
    }
    return 0;
}

entry *getSymbolbyName(symboltable *table, char *name) {
    int i = 0;
    entry *res = NULL;
    while(i <= table->maxId && i < table->size) {
        if(strcmp(table->entries[i].symbolVal, name) == 0) {
            res = &table->entries[i];
            return res;
        }
        i ++;
    }
    return res;
}

entry *getSymbolbyEntryId(symboltable *table, int addr) {
    entry *res = NULL;
    if(checkIndex(table, addr) == 1) {
        res = (entry *)malloc(sizeof(entry));
        *res = table->entries[addr];
        return res;
    }
    return res;
}

//get a symbol table entry by symbol value and attribute
//@return entry pointer
//
int getSymbolEntry(symboltable *table, char *symbolVal) {
    int i = 0;
    while(i <= table->maxId && i < table->size) {
        if(strcmp(table->entries[i].symbolVal, symbolVal) == 0) {
            return i;
        }
        i ++;
    }
    return -1;
}

//get symbol name
char *getIDName(symboltable *table, int entry) {
    if(entry > table->maxId) {
        return NULL;
    }
    return table->entries[entry].symbolVal;
}

int extendTable() {
    return 0;
}

void printArrayInfo(union SymbolEntryAttr info) {
    char *type;
    if(attrIsEmpty(info, "array")) {
        return;
    }
    type = getIDName(predefinedIdTable, info.arrayInfo.typeEntry);
    printf("ArrayType: %-10s BoundLow: %d BoundUp: %d",
           type, info.arrayInfo.boundLow, info.arrayInfo.boundUp);
}

void printFuncInfo(union SymbolEntryAttr info) {
    if(attrIsEmpty(info, "function")) {
        return;
    }
    char *retType = getIDName(predefinedIdTable, info.funcInfo.retTypeEntry);
    printf("ParamQty: %d ReturnType: %-10s", info.funcInfo.paramQty, retType);
}

void printProcInfo(union SymbolEntryAttr info) {
    if(attrIsEmpty(info, "procedure")) {
        return;
    }
    printf("ParamQty: %d", info.funcInfo.paramQty);
}

void printSymbolTable(symboltable *table) {
    int i = 0;
    int j = 0;
    char *curType = NULL;
    entryAttr curAttr;
    while(i <= table->maxId) {
        curType = NULL;
        if(table->entries[i].typedesc != NULL) {
            curType = table->entries[i].typedesc->type;
            curAttr = table->entries[i].typedesc->attribute;
        }
        printf("Address: %-3d ID: %-15s Type: %-10s ", table->entries[i].address, table->entries[i].symbolVal, curType);
        if(curType != NULL) {
            if(strcmp(curType, "array") == 0) {
                printArrayInfo(curAttr);
            }
            else if(strcmp(curType, "record") == 0) {
                printf("MemberAddrs: ");
                for(j = 0; j < curAttr.recordInfo.qty; j ++) {
                    printf("%d ", curAttr.recordInfo.recordMembers[j]);
                }
            }
            else if(strcmp(curType, "function") == 0) {
                printFuncInfo(curAttr);
            }
            else if(strcmp(curType, "procedure") == 0) {
                printProcInfo(curAttr);
            }
        }
        printf("\n");
        i ++;
    }
    printf("\n\n");
}

char *getIdType(symboltable *table, int entry) {
    if(!checkIndex(table, entry)
       || table->entries[entry].typedesc == NULL) {
        return NULL;
    }
    return table->entries[entry].typedesc->type;
}

//set id attribute based on it's type
void setTypeAttribute(symboltable *table, int idAddr, char *type, entryAttr attribute) {
    table->entries[idAddr].typedesc = getDescriptor(attribute, type);
}

entryAttr getCleanAttr(char *type) {
    entryAttr attr;
    if(strcmp(type, "array") == 0) {
        attr.arrayInfo.boundLow = 0;
        attr.arrayInfo.boundUp = 0;
        attr.arrayInfo.typeEntry = 0;
    }
    else if(strcmp(type, "function") == 0
            || strcmp(type, "procedure") == 0) {
        attr.funcInfo.paramQty = 0;
        attr.funcInfo.retTypeEntry = 0;
    }
    else if(strcmp(type, "record") == 0) {
        attr.recordInfo.qty = 0;
    }
    return attr;
}

void removeTailSymbol(symboltable *table) {
    table->entries[table->maxId].symbolVal = NULL;
    table->entries[table->maxId].typedesc = NULL;
    table->maxId --;
}

//register a symbol into symbol table
//@return long the address of registered entry
int registerSymbol(symboltable *table, char *symbolVal, char *type) {
    int addr = getSymbolEntry(table, symbolVal);
    entryAttr attr;
    if(checkIndex(table, addr) == 1) {
        return addr;
    }
    if(table->maxId >= table->size - 1) {
        if(extendTable() == 0) {
            return -10;
        }
    }
    table->maxId ++;
    table->entries[table->maxId].address = table->maxId;
    table->entries[table->maxId].symbolVal = (char *)malloc(sizeof(symbolVal));
    strcpy(table->entries[table->maxId].symbolVal, symbolVal);
    if(type != NULL) {
        table->entries[table->maxId].typedesc = getDescriptor(attr, type);
        table->entries[table->maxId].typedesc->attribute = getCleanAttr(type);
    }
    else {
        table->entries[table->maxId].typedesc = NULL;
    }
    return table->maxId;
}

void registerPredefinedIds(symboltable *table, char *ids[], char * type, int size) {
    int i = 0;
    for(i = 0; i < size; i ++) {
        registerSymbol(table, ids[i], type);
    }
}

void registerKeywordsTypes(symboltable *table) {
    registerPredefinedIds(table, keywords, "KEYWORD", keywordsSize);
    registerPredefinedIds(table, types, "TYPE", typeSize);
    registerPredefinedIds(table, booleans, "boolean", 2);
    registerPredefinedIds(table, null, "NIL", 1);
}

void initPredefinedSymboltable() {
    predefinedIdTable = createSymbolTable();
    registerKeywordsTypes(predefinedIdTable);
}

//set symbol entry type & attr using type name
int setSymbolTypeAttrDirec(symboltable *table, int address, char * type, entryAttr attribute) {
    if(checkIndex(table, address) != 1) {
        return -2; //invalid id addr
    }
    
    if(type == NULL) {
        type = "NIL";
    }
    else if(table->entries[address].typedesc != NULL
            && table->entries[address].typedesc->type != NULL) {
        if(strcmp(type, table->entries[address].typedesc->type) == 0
           && typeAttrCmp(attribute, table->entries[address].typedesc->attribute, type) == 0) {
            return 0;
        }
        return -1; //re-definition
    }
    setTypeAttribute(table, address, type, attribute);
    return 0;
}

//set symbol entry type & attr using type addr
int setSymbolEntyTypeAttr(symboltable *table, int idAddr, int typeAddr, entryAttr attribute) {
    char *type;
    if(checkIndex(table, idAddr) != 1) {
        return -2; //invalie id addr
    }
    type = getIDName(predefinedIdTable, typeAddr);
    return setSymbolTypeAttrDirec(table, idAddr, type, attribute);
}

/**
 *get the entry id of a predefined keyword
 *@return int  >=0: entry index, -1: entry doesn't exist
 */
int getKeyword(char *name) {
    entry *symbol = getSymbolbyName(predefinedIdTable, name);
    if(symbol!= NULL && strcmp(symbol->typedesc->type, "KEYWORD") == 0) {
        return symbol->address;
    }
    return -1;
}

/**
 *get the entry id of a predefined variable
 *@return int  >=0: entry index, -1: entry doesn't exist
 */
int getPredefineVar(char *name) {
    entry *symbol = getSymbolbyName(predefinedIdTable, name);
    if(symbol == NULL
       || symbol->typedesc == NULL
       || symbol->typedesc->type == NULL
       || strcmp(symbol->typedesc->type, "KEYWORD") == 0
       || strcmp(symbol->typedesc->type, "TYPE") == 0) {
        return -1;
    }
    return symbol->address;
}

#endif