#include <iostream>
#include <vector>
#include <map>

#include "../include/section.h"

using namespace std;

int main(int argc,char* argv[])
{
    //存储我们想要的pes和es文件
    uint8_t pes_path[] = "test.pes";
    uint8_t es_path[] = "test.es";
    //存储每一个PMT表指示的流类型信息
    vector<STREAM_TYPE*> stream_infos; 
    vector<STREAM_TYPE*>::iterator stream_infos_iter;
    //存储各个不同的PMT表信息
    map<uint32_t, vector<STREAM_TYPE*>> infos;
    map<uint32_t, vector<STREAM_TYPE*>> infos_iter;
    
}
