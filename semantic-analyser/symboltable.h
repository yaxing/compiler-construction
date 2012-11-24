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

char *getIdType(symboltable *table, int entry) {
    if(!checkIndex(table, entry)
       || table->entries[entry].typedesc == NULL) {
        return NULL;
    }
    return table->entries[entry].typedesc->type;
}

//set id attribute based on it's type
void setTypeAttribute(symboltable *table, int idAddr, char *type, entryAttr attribute, int tag) {
    table->entries[idAddr].typedesc = getDescriptor(attribute, tag, type);
}

entryAttr getCleanAttr(char *type) {
    entryAttr attr;
    if(strcmp(type, "array") == 0) {
        attr.arrayInfo.boundLow = 0;
        attr.arrayInfo.boundUp = 0;
        attr.arrayInfo.typeEntry = 0;
        attr.arrayInfo.typeDefScopeId = 0;
    }
    else if(strcmp(type, "function") == 0
            || strcmp(type, "procedure") == 0) {
        attr.funcInfo.paramQty = 0;
        attr.funcInfo.retTypeEntry = 0;
    }
    else if(strcmp(type, "record") == 0) {
        attr.recordInfo.scopeHashCode = -1;
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
    int tag = ATTR_DEFAULT;
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
        attr = getCleanAttr(type);
    }
    table->entries[table->maxId].typedesc = getDescriptor(attr, tag, type);
    return table->maxId;
}

void registerPredefinedIds(symboltable *table, char *ids[], char * type, int size) {
    int i = 0;
    for(i = 0; i < size; i ++) {
        registerSymbol(table, ids[i], type);
    }
}

void registerKeywordsTypes(symboltable *table) {
    registerPredefinedIds(table, types, "TYPE", typeSize);
    registerPredefinedIds(table, booleans, "boolean", 2);
    registerPredefinedIds(table, null, "NIL", 1);
}

void initPredefinedSymboltable() {
    predefinedIdTable = createSymbolTable();
    registerKeywordsTypes(predefinedIdTable);
}

//set symbol entry type & attr using type name
int setSymbolTypeAttrDirec(symboltable *table, int address, char * type, entryAttr attribute, int tag) {
    int res = 0;
    if(checkIndex(table, address) != 1) {
        return -2; //invalid id addr
    }
    
    if(type == NULL) {
        type = "undefined";
    }
    else if(table->entries[address].typedesc->type != NULL) {
        res = -1; //re-definition
    }
    setTypeAttribute(table, address, type, attribute, tag);
    return res;
}

//set symbol entry type & attr using type addr
int setSymbolEntyTypeAttr(symboltable *table, int idAddr, int typeAddr, entryAttr attribute, int tag) {
    char *type;
    if(checkIndex(table, idAddr) != 1) {
        return -2; //invalie id addr
    }
    type = getIDName(predefinedIdTable, typeAddr);
    return setSymbolTypeAttrDirec(table, idAddr, type, attribute, tag);
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

int symbolTableEntryCmp(entry *entry1, entry *entry2) {
    if(entry1->address != entry2->address) {
        return -1;
    }
    if(entry1->symbolVal != entry2->symbolVal) {
        if(entry1->symbolVal == NULL
           || entry2->symbolVal == NULL
           || strcmp(entry1->symbolVal, entry2->symbolVal) != 0) {
            return -1;
        }
    }
    if(typeDescCmp(entry1->typedesc, entry2->typedesc) != 0) {
        return -1;
    }
    return 0;
}

int symboltableCmp(symboltable *table1, symboltable *table2) {
    int i = 0;
    entry *tableEntry1;
    entry *tableEntry2;
    if(table1 == table2) {
        return 0;
    }
    if(table1 == NULL || table2 == NULL) {
        return -1;
    }
    if(table1->size != table2->size
       || table1->maxId != table2->maxId) {
        return -1;
    }
    for(i = 0; i <= table1->maxId; i ++) {
        tableEntry1 = &(table1->entries[i]);
        tableEntry2 = &(table2->entries[i]);
        if(symbolTableEntryCmp(tableEntry1, tableEntry2) != 0) {
            return -1;
        }
    }
    return 0;
}

#endif