#include "../include/pmt.h"

PMT::PMT(char* data):
    PMT_data(data),
    table_id(PMT_data[0]),
    section_syntax_indicator((PMT_data[1]&0x80)>>7),
    section_length((PMT_data[1]&0x0F)<<8 | PMT_data[2]),
    program_number(PMT_data[3]<<8 | PMT_data[4]),
    version_number((PMT_data[5]&0x3E)>>1),
    current_or_next(PMT_data[5]&0x01),
    section_number(PMT_data[6]),
    last_section_number(PMT_data[7]),
    PCR_PID((PMT_data[8]&0x1F)<<8 | PMT_data[9]),
    program_info_length((PMT_data[10]&0x0F)<<8 | PMT_data[11]){
        if(table_id != 0x02){
            /*   */
        }
    }

PMT::~PMT(){

}

void PMT::get_stream_types(std::vector<STREAM_TYPE*> &stream_types){
    unsigned int index = 12 + program_info_length;
    while(index < section_length + 3 - 4){
        STREAM_TYPE* stream_type = new STREAM_TYPE(PMT_data+index);
        stream_types.push_back(stream_type);
        index += 5+stream_type->ES_info_length;
    }
}

void PMT::get_CRC_32(){

}

void PMT::check_type(unsigned int type){

}
