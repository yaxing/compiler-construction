//
//  symboltable.h
//  compiler-lexer
//
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#pragma once
#ifndef compiler_lexer_symboltable_h
#define compiler_lexer_symboltable_h

typedef struct SymbolEntry {
    int address;
    char *symbolVal;
    char *type;
    char *attribute;
} entry;

int size = 1000;
int maxId = -1;
entry * symboltable[1000] = {NULL};

int getSymbolTableMaxId() {
    return maxId;
}

int checkIndex(int i) {
    if (i >= 0 && i <= maxId) {
        return 1;
    }
    return 0;
}

//get a symbol table entry by symbol value and attribute
//@return entry pointer
//
int getSymbolEntry(char *symbolVal) {
    int i = 0;
    while(i <= maxId && i < size) {
        if(symboltable[i] != NULL
           && strcmp(symboltable[i]->symbolVal, symbolVal) == 0) {
            return i;
        }
        i ++;
    }
    return -1;
}

char * getIDName(int entry) {
    if(entry > maxId) {
        return NULL;
    }
    return symboltable[entry]->symbolVal;
}

void extendTable() {
}

void printSymbolTable() {
    int i = 0;
    entry * cursor = NULL;
    while(i <= maxId) {
        cursor = symboltable[i];
        printf("entryID: %d ID: %s Type: %s Attr: %s\n",
               cursor->address, cursor->symbolVal, cursor->type, cursor->attribute);
        i ++;
    }
}

//register a symbol into symbol table
//@return long the address of registered entry
//
int registerSymbol(char *symbolVal, char *type, char *attribute) {
    type = type == NULL ? "" : type;
    attribute = attribute == NULL ? "" : attribute;
    
    int addr = getSymbolEntry(symbolVal);
    if(checkIndex(addr) == 1) {
        return addr;
    }
    if(maxId >= size - 1) {
        extendTable();
    }
    maxId ++;
    entry * newEntry = (entry *)(malloc(sizeof(entry)));
    newEntry->address = maxId;
    newEntry->symbolVal = (char *)malloc(strlen(symbolVal) + 1);
    newEntry->type = (char *)malloc(strlen(type) + 1);
    newEntry->attribute = (char *)malloc(strlen(attribute) + 1);
    strcpy(newEntry->symbolVal, symbolVal);
    strcpy(newEntry->type, type);
    strcpy(newEntry->attribute, attribute);
    symboltable[maxId] = newEntry;
    newEntry = NULL;
    return maxId;
}

void setSymbolEntyTypeAttr(int idAddr, int typeAddr, char *attribute) {
    char * type = NULL;
    entry * typeEnty = NULL;
    entry * idEnty = NULL;
    if(checkIndex(idAddr) == 1) {
        idEnty = symboltable[idAddr];
    }
    else {
        return;
    }
    if(checkIndex(typeAddr) == 1) {
        typeEnty = symboltable[typeAddr];
        type = typeEnty->symbolVal;
    }
    type = type == NULL ? "" : type;
    attribute = attribute == NULL ? "" : attribute;
    if(idEnty->type == NULL || strlen(idEnty->type) == 0) {
        idEnty->type = (char *)malloc(strlen(type) + 1);
        strcpy(idEnty->type, type);
    }
    idEnty->attribute = (char *)malloc(strlen(attribute) + 1);
    strcpy(idEnty->attribute, attribute);}

void setSymbolTypeAttrDirec(int address, char * type, char *attribute) {
    if(checkIndex(address) != 1) {
        return;
    }
    entry * idEntry = symboltable[address];
    type = type == NULL ? "" : type;
    attribute = attribute == NULL ? "" : attribute;
    
    
    idEntry->type = (char *)malloc(strlen(type) + 1);
    idEntry->attribute = (char *)malloc(strlen(attribute) + 1);
    
    strcpy(idEntry->type, type);
    strcpy(idEntry->attribute, attribute);
}

void registerKeywords(char *keywords[], int size) {
    int i = 0;
    for(i = 0; i < size; i ++) {
        registerSymbol(keywords[i], "KEYWORD", NULL);
    }
}

#endif
