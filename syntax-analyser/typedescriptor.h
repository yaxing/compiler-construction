//
//  typedescriptor.h
//  compiler-debugging
//
//  Created by Yaxing Chen on 11/18/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_debugging_typedescriptor_h
#define compiler_debugging_typedescriptor_h

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
        int retTypeEntry;
        union RetTypeAttr {
            struct ArrayInfo retArrayAttr;
            struct RecordInfo retRecordAttr;
        } retTypeAttr;
    } funcInfo;
} entryAttr;


typedef struct TypeDescriptor {
    char *type;
    entryAttr attribute;
    struct TypeDescriptor *next;
} typedescriptor;

typedescriptor *typedescripterlisthead;
typedescriptor *typedescripterlisttail;

void initTypeDescList() {
    entryAttr attr;
    typedescripterlisthead = (typedescriptor *)malloc(sizeof(typedescriptor));
    typedescripterlisthead->type = "TYPE_LIST_HEAD";
    typedescripterlisthead->attribute = attr;
    typedescripterlisttail = typedescripterlisthead;
}

int attrIsEmpty(union SymbolEntryAttr attr, char *type) {
    if(type == NULL) {
        return 1;
    }
    if(strcmp(type, "array") == 0) {
        if(attr.arrayInfo.typeEntry == 0
           && attr.arrayInfo.boundLow == 0
           && attr.arrayInfo.boundUp == 0) {
            return 1;
        }
    }
    else if(strcmp(type, "record") == 0) {
        if(attr.recordInfo.qty == 0) {
            return 1;
        }
    }
    else if(strcmp(type, "function") == 0 || strcmp(type, "procedure") == 0) {
        if(attr.funcInfo.paramQty == 0
           || attr.funcInfo.retTypeEntry == 0) {
            return 1;
        }
    }
    else {
        if(attr.attr == NULL) {
            return 1;
        }
    }
    return 0;
}

int typeDescCmp(typedescriptor *typedesc, typedescriptor *typedesc2) {
    if(typedesc == typedesc2) {
        return 0;
    }
    return -1;
}

int typeAttrCmp(union SymbolEntryAttr attr1, union SymbolEntryAttr attr2, char *type) {
    int i = 0;
    if(strcmp(type, "array") == 0) {
        if(attr1.arrayInfo.typeEntry != attr2.arrayInfo.typeEntry
           || attr1.arrayInfo.boundLow != attr2.arrayInfo.boundLow
           || attr1.arrayInfo.boundUp != attr2.arrayInfo.boundUp) {
            return -1;
        }
    }
    else if(strcmp(type, "record") == 0) {
        if(attr1.recordInfo.qty != attr2.recordInfo.qty) {
            return -1;
        }
        for(i = 0; i < attr1.recordInfo.qty; i ++) {
            if(attr1.recordInfo.recordMembers[i] != attr2.recordInfo.recordMembers[i]) {
                return -1;
            }
        }
    }
    else if(strcmp(type, "function") == 0 || strcmp(type, "procedure") == 0) {
        if(attr1.funcInfo.paramQty != attr2.funcInfo.paramQty
           || attr1.funcInfo.retTypeEntry != attr2.funcInfo.retTypeEntry) {
            return -1;
        }
    }
    else {
        if((attr1.attr == NULL && attr2.attr != NULL)
           || (attr1.attr != NULL && attr2.attr == NULL)) {
            return -1;
        }
    }
    return 0;
}

/**
 *try to find an identical type desc in list, if no, insert
 */
typedescriptor *getDescriptor(union SymbolEntryAttr attr, char *type) {
    typedescriptor *cursor = typedescripterlisthead;
    if(type == NULL) {
        return NULL;
    }
    while(cursor != NULL) {
        if(strcmp(cursor->type, type) == 0
           && typeAttrCmp(cursor->attribute, attr, type) == 0) {
            return cursor;
        }
        cursor = cursor->next;
    }
    cursor = (typedescriptor *)malloc(sizeof(typedescriptor));
    cursor->type = (char *)malloc(sizeof(type));
    strcpy(cursor->type, type);
    cursor->attribute = attr;
    cursor->next = NULL;
    typedescripterlisttail->next = cursor;
    typedescripterlisttail = cursor;
    return typedescripterlisttail;
}
#endif
