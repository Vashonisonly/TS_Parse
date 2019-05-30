#ifndef _SECTION_H
#define _SECTION_H


class PROGRAM_INFO{

public:
    PROGRAM_INFO(char* data);
    ~PROGRAM_INFO();

public:
    unsigned int program_number;             //16b
    // unsigned int reserved;                   //3b
    unsigned int PMT_PID;                   //13b
};

class STREAM_TYPE{
public:
    STREAM_TYPE(char* data);
    ~STREAM_TYPE();

public:
    unsigned int stream_type;              //8b
    // unsigned int reserved1;                //3b
    unsigned int elementry_PID;            //13b
    // unsigned int reserved2;                //4b
    unsigned int ES_info_length;           //12b
};
#endif


