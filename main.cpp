#include <iostream>
#include <string>
extern "C"{
    #include <stdio.h>
    #include <stdlib.h>
}
using namespace std;

void array_revert(char* array, unsigned int size);
void revert_with_combination(char* array, unsigned int size, unsigned int combinWidth);


int main(int argc, char* argv[])
{
    FILE* fin = fopen(argv[1],"rb");
    cout<<argv[1]<<endl;
    
    string fout_name(argv[1]);
    fout_name += "x";
    
    FILE* fout = fopen(fout_name.c_str(),"wb+");

    char* tempSpace = (char*)malloc(1024*sizeof(char));
    for(unsigned int i=0;i<8;i++)
        printf("#%x\n",0xff&tempSpace[i]);
    fread(tempSpace, 1024, 1, fin);
    for(unsigned int i=0;i<8;i++)
        printf("##%x\n",0xff&tempSpace[i]);
    
    revert_with_combination(tempSpace, 1024, 4);
    for(unsigned int i=0;i<8;i++)
        printf("###%x\n",0xff&tempSpace[i]);
    fwrite(tempSpace, 1024, 1, fout);
}

void array_revert(char* array, unsigned int size)
{
    char tmpVar;
    for(unsigned int i=0; i<size; i++){
        tmpVar = array[i];
        array[i] = array[size-1-i];
        array[size-1-i] = tmpVar;
    }
}

void revert_with_combination(char* array, unsigned int size, unsigned int combinWidth)
{
    // char tmpArray[combinWidth] = {0};
    // for(unsigned int i=0; i<size; i+=combinWidth){
    //     for(unsigned int j=0; j<combinWidth; j++){
    //         tmpArray[i] = array[i+j];
    //     }
    //     //array_revert(tmpArray, combinWidth);
    // }
}