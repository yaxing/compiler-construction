//
//  flex-bison-header.h
//  compiler-debugging
//
//  Created by Yaxing Chen on 11/17/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_debugging_flex_bison_header_h
#define compiler_debugging_flex_bison_header_h

typedef struct IdResp {
    int idEntry;
    char *idStr;
    int idRespStatus; //0 is normal, -1 is keyword, -2 is type
} idresp;

#endif
