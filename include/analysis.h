#ifndef _ANALYSIS_H
#define _ANALYSIS_H
#include "pat.h"
#include "pmt.h"
#include "tsheader.h"
#include "section.h"
#include "stdio.h"

#include <vector>
#include <map>
#include <string.h>

using namespace std;

#define PACKET_LENGTH_188 188
#define PACKET_LENGTH_204 204
#define MAX_TS_LENGTH 65536

class ANALYSIS{
public:
    ANALYSIS(char* file);
    ~ANALYSIS();
    //判断TS包长是否是188字节
    uint32_t get_packet_length(FILE* fp);
    //获取节目信息到map里面
    void get_infos(map<uint32_t, vector<STREAM_TYPE*>> &infos);
    //获取pes文件，es文件
    void get_pes_es(uint32_t pid);

private:
    PAT* pat;
    PMT* pmt;
    TSHEADER* tsheader;
    int8_t* ts_path;

    uint32_t packet_length = 0;
    uint32_t packet_start_position = 0;
    //存储PAT表中的节目信息。
    vector<PROGRAM_INFO*> program_infos;
    //将节目信息中的PID值与PMT表分别匹配
    map<uint32_t, vector<STREAM_TYPE*>> infos;

};
#endif


