#ifndef _PMT_H
#define _PMT_H

#include "section.h"
#include <vector>

class PMT{
public:
    PMT(char* data);
    ~PMT();

    void get_stream_types(std::vector<STREAM_TYPE*> &stream_types);
    void get_CRC_32();
    void check_type(unsigned int type);

private:
    char* PMT_data;

public:
    unsigned int table_id;                  //8b
    unsigned int section_syntax_indicator;  //1b
    // unsigned int zero;                      //1b
    // unsigned int reserved1;                 //2b
    unsigned int section_length;            //12b
    unsigned int program_number;            //16b
    // unsigned int reserved2;                 //2b
    unsigned int version_number;            //5b
    unsigned int current_or_next;           //1b
    unsigned int section_number;            //8b
    unsigned int last_section_number;       //8b
    // unsigned int reserved3;                 //3b
    unsigned int PCR_PID;                   //13b
    // unsigned int reserved4;                 //4b
    unsigned int program_info_length;       //12b
    /*stream info */
    unsigned int CRC32;                     //32b
};
#endif
