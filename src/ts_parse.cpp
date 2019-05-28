#include <iostream>
#include <vector>
#include <map>

#include "../include/analysis.h"

using namespace std;

int main(int argc,char* argv[])
{
    //存储我们想要的pes和es文件
    uint8_t pes_path[] = "test.pes";
    uint8_t es_path[] = "test.es";
    //存储每一个PMT表指示的流类型信息
    vector<STREAM_TYPE*> program_info; 
    vector<STREAM_TYPE*>::iterator program_info_iter;
    //存储各个不同的PMT表信息
    map<uint32_t, vector<STREAM_TYPE*>>program_infos;
    map<uint32_t, vector<STREAM_TYPE*>> program_infos_iter;
    ANALYSIS* analysis = new ANALYSIS(argv[0]);
    analysis->get_infos(program_infos);
    
}
