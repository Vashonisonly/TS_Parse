#include <iostream>
#include <vector>
#include <map>

#include "../include/analysis.h"

using namespace std;

int main(int argc,char* argv[])
{
    if(argc == 1){
        printf("please input the ts file as argument\n");
    }
    ANALYSIS* analysis = new ANALYSIS(argv[1]);
    delete analysis;
}
