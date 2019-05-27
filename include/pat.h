#ifndef _PAT_H
#define _PAT_H

#include "def.h"
#include "section.h"

class PAT{
public:
    PAT(uint8_t* data);
    ~PAT();

    void get_program_info(std::vector<PROGRAM_INFO*> &program_infos);
    void get_CRC32();
public:
    uint8_t* PAT_data;            //用来存储传入的数据

    uint32_t table_id;            //8b PAT表的值，固定0x47
    uint32_t section_syntax_indicator; //1b
    //uint32_t zero;                //1b 固定为0
    //uint32_t reserved1;           //2b
    uint32_t section_length;      //12b
    uint32_t transport_stream_id; //16b
    //uint32_t reserved2;           //2b
    uint32_t version_number;      //5b
    uint32_t current_next_indicator; //1b
    uint32_t section_number;      //8b
    uint32_t last_section_number; //8b
    /* 节目信息  */
    uint32_t CRC32;               //32b
};
#endif
