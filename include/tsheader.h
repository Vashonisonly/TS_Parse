#ifndef _TSHEADER_H
#define _TSHEADER_H

#include "def.h"

class TSHEADER{
public:
    TSHEADER(uint8_t* data);
    ~TSHEADER();
private:
    uint8_t* TSHEADER_data;
    
public:
    uint32_t syntax_indicator;                //8b
    uint32_t transport_error_indicator;       //1b
    uint32_t payload_uint_start_indicator;    //1b
    uint32_t transport_pritxy;                //1b
    uint32_t PID;                             //13b
    uint32_t scrmling_control;                //2b
    uint32_t adapation_field_control;         //2b
    uint32_t continue_counter;                //4b
};
#endif
