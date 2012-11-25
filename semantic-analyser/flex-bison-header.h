//
//  flex-bison-header.h
//  compiler-debugging
//
//  Created by Yaxing Chen on 11/17/12.
//  Copyright (c) 2012 Yaxing Chen. All rights reserved.
//

#ifndef compiler_debugging_flex_bison_header_h
#define compiler_debugging_flex_bison_header_h

#ifndef IDRESP_PREDEF_TYPE
#define IDRESP_PREDEF_TYPE -1
#endif

#ifndef IDRESP_PREDEF_KEYW
#define IDRESP_PREDEF_KEYW -2
#endif

#ifndef IDRESP_DEF_IN_PARENT
#define IDRESP_DEF_IN_PARENT -3
#endif

#ifndef IDRESP_UNDEF
#define IDRESP_UNDEF -5
#endif

#ifndef IDRESP_NORMAL
#define IDRESP_NORMAL 0
#endif

// a shared struct for id entities between bison & flex
typedef struct IdResp {
    int idEntry;
    char *idStr;
    int idRespStatus; //0 is normal, -1 is keyword, -2 is type
} idresp;

#endif
