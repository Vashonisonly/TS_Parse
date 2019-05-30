#include <iostream>
#include <vector>
#include <map>

#include "../include/analysis.h"

using namespace std;

int main(int argc,char* argv[])
{
//    if(argc == 1){
//        printf("please input the ts file as argument\n");
//        return -1;
//    }
//
//    ANALYSIS* analysis = new ANALYSIS(argv[1]);

    char ts_file[] = "../src/test.ts";
    ANALYSIS* analysis = new ANALYSIS(ts_file);
}
