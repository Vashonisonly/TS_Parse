#ifndef _PMT_H
#define _PMT_H

#include "section.h"
#include <vector>

class PMT{
public:
    PMT(uint8_t* data);
    ~PMT();

    void get_stream_types(std::vector<STREAM_TYPE*> &stream_types);
    void get_CRC_32();
    void check_type(uint32_t type);

private:
    uint8_t* PMT_data;

public:
    uint32_t table_id;                  //8b
    uint32_t section_syntax_indicator;  //1b
    // uint32_t zero;                      //1b
    // uint32_t reserved1;                 //2b
    uint32_t section_length;            //12b
    uint32_t program_number;            //16b
    // uint32_t reserved2;                 //2b
    uint32_t version_number;            //5b
    uint32_t current_or_next;           //1b
    uint32_t section_number;            //8b
    uint32_t last_section_number;       //8b
    // uint32_t reserved3;                 //3b
    uint32_t PCR_PID;                   //13b
    // uint32_t reserved4;                 //4b
    uint32_t program_info_length;       //12b
    /*stream info */
    uint32_t CRC32;                     //32b
};
#endif
