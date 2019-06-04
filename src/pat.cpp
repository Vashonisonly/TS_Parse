#include "../include/pat.h"

PAT::PAT(char* data):
    PAT_data(data),
    table_id(data[0]),
    //也可以(data[1]>>7)&0x01,不再赘述
    section_syntax_indicator((data[1]&0x80)>>7),
    section_length((data[1]&0x0F)<<8 | data[2]),
    transport_stream_id(data[3]<<8 | data[4]),
    version_number((data[5]&0x3E)>>1),
    current_next_indicator(data[5]&0x01),
    section_number(data[6]),
    last_section_number(data[7]){
        if(table_id != 0x00){
            /* */
        }
    }
PAT::~PAT(){

}

void PAT::get_program_info(std::vector<PROGRAM_INFO*> &program_infos){
    int size =(section_length - 9)/4;
    int index = 8;
    for(int i=0; i<size; ++i){
        PROGRAM_INFO* program_info = new PROGRAM_INFO(PAT_data+index);
        index+=4;
        if(program_info->program_number) {
            program_infos.push_back(program_info);
        }
    }
}

void PAT::get_CRC32(){
    int index = section_length+3;
    CRC32 = PAT_data[index-1]<<24 | PAT_data[index-2]<<16
          | PAT_data[index-3]<<8 | PAT_data[index-4];
}

