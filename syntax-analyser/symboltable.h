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
entry symboltable[1000];

int getSymbolTableMaxId() {
    return maxId;
}

void initSymbolTable() {
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
        if(strcmp(symboltable[i].symbolVal, symbolVal) == 0) {
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
    return symboltable[entry].symbolVal;
}

int extendTable() {
    return 0;
}

void printSymbolTable() {
    int i = 0;
    while(i <= maxId) {
        printf("Address: %-3d ID: %-15s Type: %-10s Attr:%s\n",
               symboltable[i].address, symboltable[i].symbolVal, symboltable[i].type, symboltable[i].attribute);
        i ++;
    }
}

//register a symbol into symbol table
//@return long the address of registered entry
//
int registerSymbol(char *symbolVal, char *type, char *attribute) {
    int addr = getSymbolEntry(symbolVal);
    if(checkIndex(addr) == 1) {
        return addr;
    }
    if(maxId >= size - 1) {
        if(extendTable() == 0) {
            return -1;
        }
    }
    maxId ++;
    symboltable[maxId].address = maxId;
    symboltable[maxId].symbolVal = (char *)malloc(sizeof(symbolVal));
    strcpy(symboltable[maxId].symbolVal, symbolVal);
    if(type != NULL) {
        symboltable[maxId].type = (char *)malloc(sizeof(type));
        strcpy(symboltable[maxId].type, type);
    }
    else {
        symboltable[maxId].type = NULL;
    }
    if(attribute != NULL) {
        symboltable[maxId].attribute = (char *)malloc(sizeof(attribute));
        strcpy(symboltable[maxId].attribute, attribute);
    }
    else {
        symboltable[maxId].attribute = NULL;
    }
    return maxId;
}

int setSymbolEntyTypeAttr(int idAddr, int typeAddr, char *attribute) {
    char * type = NULL;
    if(checkIndex(idAddr) != 1) {
        return -2;
    }
    if(checkIndex(typeAddr) == 1) {
        type = symboltable[typeAddr].symbolVal;
    }
    
    if(type == NULL) {
        return -2;
    }
    else if(symboltable[idAddr].type != NULL) {
        if(strcmp(type, symboltable[idAddr].type) == 0) {
            return 0;
        }
        return -1;
    }
    
    symboltable[idAddr].type = (char *)malloc(sizeof(type));
    strcpy(symboltable[idAddr].type, type);

    if(attribute != NULL) {
        symboltable[idAddr].attribute = (char *)malloc(sizeof(attribute));
        strcpy(symboltable[idAddr].attribute, attribute);
    }
    return 0;
}

void setSymbolTypeAttrDirec(int address, char * type, char *attribute) {
    if(checkIndex(address) != 1) {
        return;
    }
    
    if(type != NULL) {
        symboltable[address].type = (char *)malloc(sizeof(type));
        strcpy(symboltable[address].type, type);
    }
    
    if(attribute != NULL) {
        symboltable[address].attribute = (char *)malloc(sizeof(attribute));
        strcpy(symboltable[address].attribute, attribute);
    }
}

void registerKeywords(char *keywords[], int size) {
    int i = 0;
    for(i = 0; i < size; i ++) {
        registerSymbol(keywords[i], "KEYWORD", NULL);
    }
}

#endif