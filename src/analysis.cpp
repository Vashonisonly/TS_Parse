#include "../include/analysis.h"

ANALYSIS::ANALYSIS(char* file){
    strcpy(ts_path,file);
}

ANALYSIS::~ANALYSIS(){

}

uint32_t judge_packet_length(FILE* fp, uint32_t ts_position, uint32_t length){
    for(int i = 0; i != 10; ++i){
        if(fseek(fp, length, SEEK_CUR) == -1){
            perror("fssek error:");
            return -1;
        }
        if(feof(fp)){
            return -1;
        }
        if(fgetc(fp) != '0x47'){
            perror("fgetc is not the 0x47, error:");
            return -1;
        }
    }
    printf("---------------------------------------/n
           the transport stream packet length is %d/n",length);
    return length;
}

uint32_t ANALYSIS::get_packet_length(FILE* fp){

    //ts包前面可能有同步字节，我们循环跳过
    while(feof(fp)){
        if(getc(fp) == '0x47'){
            if(judge_packet_length(fp,packet_start_position,PACKET_LENGTH_188) == PACKET_LENGTH_188){
                return PACKET_LENGTH_188;
            }      
            fseek(fp, ts_position, SEEK_SET);
            if(judge_packet_length(fp,packet_start_position,PACKET_LENGTH_204) == PACKET_LENGTH_204){
                return PACKET_LENGTH_204;
            }
            return -1;
        }
        packet_start_position++;
        if((fseek(fp, packet_start_position, SEEK_SET)) == -1){
            perror("seek the file lose:");
            return -1;
        }
    }
}

void ANALYSIS::get_infos(map<uint32_t, vector<STREAM_TYPE*>> &infos){
    //获取ts包的长度
    FILE* fp = fopen(ts_path, "rb");
    uint32_t ts_position = 0;
    packet_length = get_packet_length(fp, ts_position);
    printf("packet_length: %d",packet_length);
    
    uint32_t payload_position = 0;
    uint32_t pat_exit_flag = 0;
    uint8_t* buffer_data = new uint8_t[packet_length];
    //跳跃到第一个包的位置
    fseek(fp, ts_position, SEEK_SET);

    while(feof(fp)){
        //将当前包存入buffer_data
        if(fread(buffer_data, packet_length, 1, fp) == 0){
           perror("fread error:");
           return;
        }

        //跳跃到下一个包
        ts_position += packet_length;
        if(fseek(fp, ts_position, SEEK_SET) == -1){
          perror("get_infos fseek error:");
          return;
        }

        //通过包头tsheader判断payload位置
        tsheader = new TSHEADER(buffer_data);
        /*switch(tsheader->adapation_field_control){
        case 0:
            break;
        case 1:
        }*/
        if(tsheader->adapation_field_control == 0 || tsheader->adapation_field_control == 2){
            printf("no payload, continue the next packet");
            continue;
        }else if(tsheader->adapation_field_control == 1){
            payload_position = 4;
        }else{
            //pes header头部第一个字节代表剩下长度，再加上它本身
            payload_position = 4 + buffer_data[4] +1;
        }
        //对含有有效负载偏移的情况。当这个值为1，说明含有1个字节的FieldPointer，这个FieldPointer的值又代表了PSI，SI表在payload开头占据的字节数。
        if(tsheader->payload_uint_start_indicator/* == 1*/){
            payload_position += buffer_data[payload_position] + 1;
        }

        //分析PID值，PAT表只需要分析一次即可，以后不再分析。得到一个map，first代表pid值，second是pmt表中的stream_types信息，比如音频，食品。
        uint32_t program_infos_size = 0;
        uint32_t current_pids = 0;
        if(tsheader->PID == 0x00 && !pat_exit_flag){

            pat = new PAT(buffer_data + payload_position);
            pat->get_program_info(program_infos);
            pat_exit_flag = 1;
            program_infos_size = program_infos.size();
        }else{

            pmt = new PMT(buffer_data + payload_position);
            if(pmt->table_id == 0x02){

                for(auto program_it = program_infos.begin(); program_it != program_infos.end(); ++program_it){

                    if((*program_it)->program_number == pmt->program_number){

                        vector<STREAM_TYPE*> stream_types;
                        pmt->get_stream_types(stream_types);
                        infos.insert(make_pair((*program_it)->PMT_PID, stream_types));
                        if(++current_pids == program_infos_size){
                            
                            return;
                        }
                       // for(auto stream_it = stream_types.begin(); stream_it != stream_types.end(); ++stream_it){
                       //     infos.insert(make_pair((*stream_it)->elementry_PID, )
                       // }
                    }
                }
            }
        }
    }    
}

void ANALYSIS::get_pes_es(uint32_t pid){
    FILE* ts_fp = fopen(ts_path, "rb");
    FILE* pes_fp = fopen("test.pes", "wb");
    FILE* es_fp = fopen("test.es", "wb");
    uint32_t ts_position = 0;
    uint32_t read_size = 0;
    uint32_t payload_position = 0;
    uint8_t* buffer_data = new uint8_t[188*1024];
    uint8_t* current_p = NULL;

    

    if(ts_fp == NULL && pes_fp == NULL && es_fp == NULL){
        perror("open file lose:");
    }
    
    if(fseek(ts_fp, ts_position, SEEK_SET) == -1){
        perror("seek the file lose:");
    }

    while(feof(ts_fp)){
        read_size = fread(buffer_data, 1, sizeof(buffer_data), ts_fp);
        if(read_size == 0){
            perror("fread lose:");
        }

        current_p = buffer_data;
        //处理读到的数据
        while(current_p < buffer_data + read_size){
            tsheader = new TSHEADER(current_p);
            if(tsheader->PID = pid){
                
            }
        }
    }










}
