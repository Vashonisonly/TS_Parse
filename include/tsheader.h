#ifndef _TSHEADER_H
#define _TSHEADER_H


class TSHEADER{
public:
    TSHEADER(char* data);
    ~TSHEADER();
private:
    char* TSHEADER_data;
    
public:
    unsigned int syntax_indicator;                //8b
    unsigned int transport_error_indicator;       //1b
    unsigned int payload_uint_start_indicator;    //1b
    unsigned int transport_pritxy;                //1b
    unsigned int PID;                             //13b
    unsigned int scrmling_control;                //2b
    unsigned int adapation_field_control;         //2b
    unsigned int continue_counter;                //4b
};
#endif
