//
//  typecmp.h
//  compiler-debugging
//
//  Created by Yaxing Chen on 11/20/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_debugging_typecmp_h
#define compiler_debugging_typecmp_h

//compare two type descriptors
int typeDescCmp(typedescriptor *typedesc, typedescriptor *typedesc2) {
    if(typedesc == typedesc2) {
        return 0;
    }
    return -1;
}


//compare two array type attributes
int arrayCmp(struct ArrayInfo arrayAttr1, struct ArrayInfo arrayAttr2) {
    entry *entry1;
    entry *entry2;
    if(arrayAttr1.boundLow != arrayAttr2.boundLow
       || arrayAttr1.boundUp != arrayAttr2.boundUp
       || arrayAttr1.typeEntry != arrayAttr2.typeEntry
       || arrayAttr1.typeDefScopeId != arrayAttr2.typeDefScopeId) {
        entry1 = getSymbolbyEntryId(find_scope(arrayAttr1.typeDefScopeId)->symboltable, arrayAttr1.typeEntry);
        entry2 = getSymbolbyEntryId(find_scope(arrayAttr2.typeDefScopeId)->symboltable, arrayAttr2.typeEntry);
        if(typeDescCmp(entry1->typedesc, entry2->typedesc) != 0) {
            return -1;
        }
    }
    return 0;
}

// compare two record type attributes
int recordCmp(struct RecordInfo recordAttr1, struct RecordInfo recordAttr2) {
    scope *recordTmpScope1;
    scope *recordTmpScope2;
    if(recordAttr1.scopeHashCode == recordAttr2.scopeHashCode) {
        return 0;
    }
    else {
        recordTmpScope1 = find_scope(recordAttr1.scopeHashCode);
        recordTmpScope2 = find_scope(recordAttr2.scopeHashCode);
        if(recordTmpScope1 == recordTmpScope2) {
            return 0;
        }
        else if(recordTmpScope1 == NULL || recordTmpScope2 == NULL) {
            return -1;
        }
        return symboltableCmp(recordTmpScope1->symboltable, recordTmpScope2->symboltable);
    }
}


// compare type constructors array, record
int typeConstructorCmp(union SymbolEntryAttr attr1, union SymbolEntryAttr attr2, int typeAddr) {
    if(typeAddr == getPredefType("array")) {
        return arrayCmp(attr1.arrayInfo, attr2.arrayInfo);
    }
    else if(typeAddr == getPredefType("record")) {
        return recordCmp(attr1.recordInfo, attr2.recordInfo);
    }
    return 0;
}

// compare two func's return type attrs
int funcRetTypeAttrCmp(struct FuncInfo funcAttr1, struct FuncInfo funcAttr2, int typeAddr) {
    if(typeAddr == getPredefType("array")) {
        return arrayCmp(funcAttr1.retTypeAttr.retArrayAttr, funcAttr2.retTypeAttr.retArrayAttr);
    }
    else if(typeAddr == getPredefType("record")) {
        return recordCmp(funcAttr1.retTypeAttr.retRecordAttr, funcAttr2.retTypeAttr.retRecordAttr);
    }
    return 0;
}

//compare two func return 0 if equal
int funcCmp(struct FuncInfo attr1, struct FuncInfo attr2) {
    int res = -1;
    if(attr1.paramQty != attr2.paramQty
       || attr1.retTypeEntry != attr2.retTypeEntry) {
           return -1;
    }
    res = funcRetTypeAttrCmp(attr1, attr2, attr1.retTypeEntry);
    return res;
}

//compare two proc
int procCmp(struct FuncInfo attr1, struct FuncInfo attr2) {
    if(attr1.paramQty != attr2.paramQty) {
        return -1;
    }
    return 0;
}

//compare two type attrs 0 eq
int typeAttrCmp(union SymbolEntryAttr attr1, union SymbolEntryAttr attr2, int typeAddr) {
    if(typeAddr == getPredefType("function")
       || typeAddr == getPredefType("procedure")) {
        return funcCmp(attr1.funcInfo, attr2.funcInfo);
    }
    if(typeAddr == getPredefType("array")
       || typeAddr == getPredefType("record")) {
        return typeConstructorCmp(attr1, attr2, typeAddr);
    }
    return 0;
}

//compare a predef type with an array
int typeArrayCmp(int typeEntry, struct ArrayInfo arrayInfo) {
    return typeEntry == arrayInfo.typeEntry ? 0 : -1;
}

//compare a predef type with a func
int typeFuncCmp(int typeEntry, struct FuncInfo funcInfo) {
    return typeEntry == funcInfo.retTypeEntry ? 0 : -1;
}

//compare a func with a type constructor
int funcTypeConstructorCmp(struct FuncInfo funcInfo, union SymbolEntryAttr constructorInfo, int typeAddr) {
    if(funcInfo.retTypeEntry != typeAddr) {
        return -1;
    }
    else if(typeAddr == getPredefType("array")) {
        return arrayCmp(constructorInfo.arrayInfo, funcInfo.retTypeAttr.retArrayAttr);
    }
    else if(typeAddr == getPredefType("record")) {
        return recordCmp(constructorInfo.recordInfo, funcInfo.retTypeAttr.retRecordAttr);
    }
    return -1;
}

#endif
