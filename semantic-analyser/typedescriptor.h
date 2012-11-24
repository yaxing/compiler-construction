//
//  typedescriptor.h
//  compiler-debugging
//
//  Created by Yaxing Chen on 11/18/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_debugging_typedescriptor_h
#define compiler_debugging_typedescriptor_h

struct ArrayInfo {
    int boundLow;
    int boundUp;
    int typeEntry;
    int typeDefScopeId;
} arrayInfo;

struct RecordInfo {
    int scopeHashCode;
} recordInfo;

struct FuncInfo {
    int paramQty;
    int retTypeEntry;
    union RetTypeAttr {
        struct ArrayInfo retArrayAttr;
        struct RecordInfo retRecordAttr;
    } retTypeAttr;
} funcInfo;

typedef union SymbolEntryAttr {
    struct ArrayInfo arrayInfo;
    struct RecordInfo recordInfo;
    struct FuncInfo funcInfo;
} entryAttr;


typedef struct TypeDescriptor {
    char *type;
    int tag;// indicate type or var
    entryAttr attribute;
    struct TypeDescriptor *next;
    struct TypeDescriptor *prev;
} typedescriptor;

typedescriptor *typedescripterlisthead;
typedescriptor *typedescripterlisttail;

int attrIsEmpty(union SymbolEntryAttr attr, char *type);

int typeDescCmp(typedescriptor *typedesc, typedescriptor *typedesc2);

int typeAttrCmp(union SymbolEntryAttr attr1, union SymbolEntryAttr attr2, int typeAddr);

int getPredefType(char *name);

void initTypeDescList() {
    entryAttr attr;
    typedescripterlisthead = (typedescriptor *)malloc(sizeof(typedescriptor));
    typedescripterlisthead->type = "TYPE_LIST_HEAD";
    typedescripterlisthead->attribute = attr;
    typedescripterlisttail = typedescripterlisthead;
    typedescripterlisthead->next = NULL;
    typedescripterlisttail->next = NULL;
}

/**
 *try to find an identical type desc in list, if no, insert
 */
typedescriptor *getDescriptor(union SymbolEntryAttr attr, int tag, char *type) {
    typedescriptor *cursor = typedescripterlisttail;
    while(cursor != NULL) {
        if(type == NULL) {
            if(cursor->type == NULL) {
                return cursor;
            }
        }
        else if(cursor->type != NULL
           && strcmp(cursor->type, type) == 0
           && tag == cursor->tag
           && typeAttrCmp(cursor->attribute, attr, getPredefType(type)) == 0) {
            return cursor;
        }
        cursor = cursor->prev;
    }
    cursor = (typedescriptor *)malloc(sizeof(typedescriptor));
    if(type == NULL) {
        cursor->type = NULL;
    }
    else {
        cursor->type = (char *)malloc(sizeof(type));
        strcpy(cursor->type, type);
    }
    cursor->attribute = attr;
    cursor->tag = tag;
    cursor->prev = typedescripterlisttail;
    cursor->next = NULL;
    typedescripterlisttail->next = cursor;
    typedescripterlisttail = cursor;
    return typedescripterlisttail;
}

#endif
