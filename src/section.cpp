#include "../include/section.h"

PROGRAM_INFO::PROGRAM_INFO(char* data):
    program_number(data[0]<<8 | data[1]),
    PMT_PID((data[2] & 0x1F)<<8 | data[3]){

    }
PROGRAM_INFO::~PROGRAM_INFO(){

}

STREAM_TYPE::STREAM_TYPE(char* data):
    stream_type(data[0]),
    elementry_PID((data[1] &0x1F)<<8 | data[2]),
    ES_info_length((data[3]&0x0F)<<8 | data[4]){

    }
STREAM_TYPE::~STREAM_TYPE(){

}
