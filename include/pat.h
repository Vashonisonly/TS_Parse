#ifndef _PAT_H
#define _PAT_H

#include "section.h"
#include <vector>

class PAT{
public:
    PAT(char* data);
    ~PAT();

    void get_program_info(std::vector<PROGRAM_INFO*> &program_infos);
    void get_CRC32();
public:
    char* PAT_data;            //用来存储传入的数据

    unsigned int table_id;            //8b PAT表的值，固定0x47
    unsigned int section_syntax_indicator; //1b
    //unsigned int zero;                //1b 固定为0
    //unsigned int reserved1;           //2b
    unsigned int section_length;      //12b
    unsigned int transport_stream_id; //16b
    //unsigned int reserved2;           //2b
    unsigned int version_number;      //5b
    unsigned int current_next_indicator; //1b
    unsigned int section_number;      //8b
    unsigned int last_section_number; //8b
    /* 节目信息  */
    unsigned int CRC32;               //32b
};
#endif
