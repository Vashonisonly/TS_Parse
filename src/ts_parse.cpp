#include <iostream>
#include <vector>
#include <map>

#include "../include/analysis.h"

using namespace std;

int main(int argc,char* argv[])
{
//    if(argc == 1){
//        printf("please input the ts file as argument\n");
//    }
    char ts_file[] = "/home/vashon/clion/my_programs/src/test.ts";
    ANALYSIS* analysis = new ANALYSIS(ts_file);
}
