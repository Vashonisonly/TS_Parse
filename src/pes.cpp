#include "../include/pes.h"

const unsigned int PROGRAM_STREAM_MAP = 0xBC;
const unsigned int PADDING_STREAM = 0xBE;
const unsigned int PRIVATE_STREAM_2 = 0xBF;
const unsigned int ECM_STREAM = 0xF0;
const unsigned int EMM_STREAM = 0xF1;
const unsigned int PROGRAM_STREAM_DIRECTORY = 0xFF;
const unsigned int DSMCC_STREAM = 0xF2;
const unsigned int E_STREAM = 0xF8;

PES::PES(char* data){
    PES_data = data;
    packet_start_code_prefix = (PES_data[0]<<16)|(PES_data[1]<<8)|(PES_data[2]);
    stream_id = PES_data[3];
    PES_packet_length = (PES_data[4]<<8)|(PES_data[5]);
    if(stream_id != PROGRAM_STREAM_MAP &&
		stream_id != PADDING_STREAM &&
		stream_id != PRIVATE_STREAM_2 &&
		stream_id != ECM_STREAM &&
		stream_id != EMM_STREAM &&
		stream_id != PROGRAM_STREAM_DIRECTORY &&
		stream_id != DSMCC_STREAM && 
        stream_id != E_STREAM){
        PES_scrambling_control = (PES_data[6]>>4)&0x03;
        PES_priority = (PES_data[6]>>3)&0x1;
        data_alignment_indicator = (PES_data[6]>>2)&0x1;
        copyright = (PES_data[6]>>1)&0x1;
        original_or_copy = (PES_data[6])&0x1;
        /*  flags~~~~*/
        PES_header_data_length = (PES_data[8]);

        elementy_stream_position = PES_data +PES_header_data_length +9;

        PES_packet_data_length = elementy_stream_position - PES_data;
    }
}

PES::~PES(){

}

