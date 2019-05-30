#ifndef _PES_H
#define _PES_H

class PES{
public:
    PES(char* data);
    ~PES();

public:
    char* PES_data;
    //存储es包的起始位置
    char* elementy_stream_position;
    //存储pes包的长度
    unsigned int PES_packet_data_length;

    unsigned int packet_start_code_prefix;        //24b
    unsigned int stream_id;                       //8b
    unsigned int PES_packet_length;               //16b

    // '10';                                  //2b
    unsigned int PES_scrambling_control;          //2b
    unsigned int PES_priority;                    //1b
    unsigned int data_alignment_indicator;        //1b
    unsigned int copyright;                       //1b
    unsigned int original_or_copy;                //1b
    unsigned int PTS_DTS_flags;                   //2b
    unsigned int ESCR_flag;                       //1b
    unsigned int ES_rate_flag;                    //1b
    unsigned int DSM_trick_mode_flag;             //1b
    unsigned int additional_copy_info_flag;       //1b
    unsigned int PES_CRC_flag;                    //1b
    unsigned int PES_extension_flag;              //1b
    unsigned int PES_header_data_length;          //8b

    //各个flag标志了之后的字段是否存在
    //有空再详细的补全吧。
    //unsigned int PTS;                             //40b
    //unsigned int DTS;                             //40b

    //unsigned int ESCR;                            //48b

    //ES rate;
    //unsigned int marker_bit1;                      //1b
    //unsigned int ES_rate;                         //22b
    //unsigned int marker_bit2;                      //1b

    //unsigned int DSM_trick_mode;                  //8b

    //unsigned int additional_copy_info;            //8b

    //unsigned int PES_CRC;                         //16b

    //unsigned int PES_extension;


};
#endif
