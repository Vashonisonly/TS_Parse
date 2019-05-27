#ifndef _SECTION_H
#define _SECTION_H

#include "def.h"

class PROGRAM_INFO{

public:
    PROGRAM_INFO(uint8_t* data);
    ~PROGRAM_INFO();

public:
    uint32_t program_number;             //16b
    // uint32_t reserved;                   //3b
    uint32_t PMT_PID;                   //13b
};

class STREAM_TYPE{
public:
    STREAM_TYPE(uint8_t* data);
    ~STREAM_TYPE();

public:
    uint32_t stream_type;              //8b
    uint32_t reserved1;                //3b
    uint32_t elementry_PID;            //13b
    uint32_t reserved2;                //4b
    uint32_t ES_info_length;           //12b
};
#endif


