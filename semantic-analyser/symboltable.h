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
    entry *res = (entry *)malloc(sizeof(entry));
    while(i <= table->maxId && i < table->size) {
        if(strcmp(table->entries[i].symbolVal, name) == 0) {
*res = table->entries[i];
return res;
        }
        i ++;
    }
    return res;
}

entry *getSymbolbyEntryId(symboltable *table, int addr) {
    entry *res = NULL;
    if(checkIndex(table, addr) == 1) {
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
char * getIDName(symboltable *table, int entry) {
    if(entry > table->maxId) {
        return NULL;
    }
    return table->entries[entry].symbolVal;
}

char *getIdType(symboltable *table, int entry) {
    if(entry > table->maxId) {
        return NULL;
    }
    return table->entries[entry].type;
}

int extendTable() {
    return 0;
}

void printSymbolTable(symboltable *table) {
    int i = 0;
    int j = 0;
    char *type;
    while(i <= table->maxId) {
        printf("Address: %-3d ID: %-15s Type: %-10s ", table->entries[i].address, table->entries[i].symbolVal, table->entries[i].type);
        if(type != NULL) {
            if(strcmp(table->entries[i].type, "array") == 0) {
                type = getIDName(predefinedIdTable, table->entries[i].attribute.arrayInfo.typeEntry);
                printf("ArrayType: %s Bound: %d", type, table->entries[i].attribute.arrayInfo.bound);
            }
            else if(strcmp(table->entries[i].type, "record") == 0) {
                printf("MemberAddrs: ");
                for(j = 0; j < table->entries[i].attribute.recordInfo.qty; j ++) {
                    printf("%d ", table->entries[i].attribute.recordInfo.recordMembers[j]);
                }
            }

        }
        printf("\n");
        i ++;
    }
}

//set id attribute based on it's type
void setAttribute(symboltable *table, int idAddr, char *type, entryAttr attribute) {
    int i = 0;
    if(type != NULL) {
        if(strcmp(type, "function") == 0) {
            table->entries[idAddr].attribute.funcInfo.paramQty = attribute.funcInfo.paramQty;
            table->entries[idAddr].attribute.funcInfo.returnTypeEntry
                = attribute.funcInfo.returnTypeEntry;
        }
        else if(strcmp(type, "array") == 0) {
            table->entries[idAddr].attribute.arrayInfo.boundLow = attribute.arrayInfo.boundLow;
            table->entries[idAddr].attribute.arrayInfo.boundUp = attribute.arrayInfo.boundUp;
            table->entries[idAddr].attribute.arrayInfo.typeEntry
                = attribute.arrayInfo.typeEntry;
        }
        else if(strcmp(type, "record") == 0) {
            table->entries[idAddr].attribute.recordInfo.qty = attribute.recordInfo.qty;
            for(i = 0; i < attribute.recordInfo.qty; i ++) {
                table->entries[idAddr].attribute.recordInfo.recordMembers[i]
                    = attribute.recordInfo.recordMembers[i];
            }
        }
    }
    else {
        table->entries[idAddr].attribute.attr = attribute.attr;
    }
}


//register a symbol into symbol table
//@return long the address of registered entry
int registerSymbol(symboltable *table, char *symbolVal, char *type, entryAttr attribute) {
    int addr = getSymbolEntry(table, symbolVal);
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
        table->entries[table->maxId].type = (char *)malloc(sizeof(type));
        strcpy(table->entries[table->maxId].type, type);
    }
    else {
        table->entries[table->maxId].type = NULL;
    }
    setAttribute(table, table->maxId, type, attribute);
    return table->maxId;
}

void registerPredefinedIds(symboltable *table, char *ids[], char * type, int size) {
    int i = 0;
    entryAttr atr;
    atr.attr = NULL;
    for(i = 0; i < size; i ++) {
        registerSymbol(table, ids[i], type, atr);
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
        return -3;
    }
    else if(table->entries[address].type != NULL) {
        if(strcmp(type, table->entries[address].type) == 0) {
            return 0;
        }
        return -1; //re-definition
    }
    
    table->entries[address].type = (char *)malloc(sizeof(type));
    strcpy(table->entries[address].type, type);
    
    setAttribute(table, address, type, attribute);
    return 0;
}

//set symbol entry type & attr using type addr
int setSymbolEntyTypeAttr(symboltable *table, int idAddr, int typeAddr, entryAttr attribute) {
    char * type = NULL;
    if(checkIndex(table, idAddr) != 1) {
        return -2; //invalie id addr
    }
    if(checkIndex(table, typeAddr) == 1) {
        type = table->entries[typeAddr].symbolVal;
    }
    
    if(type == NULL) {
        return -2; //invalid type
    }
    else if(table->entries[idAddr].type != NULL) {
        if(strcmp(type, table->entries[idAddr].type) == 0) {
            return 0;
        }
        return -1; //re-definition
    }
    
    setSymbolTypeAttrDirec(table, idAddr, type, attribute);
    return 0;
}

/**
 *get the entry id of a predefined keyword
 *@return int  >=0: entry index, -1: entry doesn't exist
 */
int getKeyword(char *name) {
    struct SymbolEntry *symbol = getSymbolbyName(predefinedIdTable, name);
    if(strcmp(symbol->type, "KEYWORD") == 0) {
        return symbol->address;
    }
    return -1;
}

/**
 *get the entry id of a predefined variable
 *@return int  >=0: entry index, -1: entry doesn't exist
 */
int getPredefineVar(char *name) {
    struct SymbolEntry *symbol = getSymbolbyName(predefinedIdTable, name);
    if(symbol == NULL || symbol->type == NULL || strcmp(symbol->type, "KEYWORD") == 0
       || strcmp(symbol->type, "TYPE") == 0) {
        return -1;
    }
    return symbol->address;
}

#endif