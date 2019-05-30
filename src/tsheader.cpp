#include "../include/tsheader.h"

TSHEADER::TSHEADER(char* data):
    TSHEADER_data(data),
    syntax_indicator(TSHEADER_data[0]),
    transport_error_indicator((data[1]&0x80)>>7),
    payload_uint_start_indicator((data[1]&0x40)>>6),
    transport_pritxy((TSHEADER_data[1]&0x20)>>5),
    PID((TSHEADER_data[1]&0x1F)<<8 | data[2]),
    scrmling_control((TSHEADER_data[3]&0xC0)>>6),
    adapation_field_control((TSHEADER_data[3]&0x30)>>4),
    continue_counter(TSHEADER_data[3]&0x0F){
        if(syntax_indicator != 0x47){
            /*   */
        }
    }

TSHEADER::~TSHEADER(){

}

