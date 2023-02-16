#include <iostream>
#include <string>
extern "C"{
    #include <stdio.h>
    #include <stdlib.h>
}
#include <algorithm>

using namespace std;

void revert_with_combination(char* array, unsigned int size, unsigned int combinWidth);


int main(int argc, char* argv[])
{
    FILE* fin = fopen(argv[1],"rb");
    cout<<argv[1]<<endl;
    
    string fout_name(argv[1]);
    fout_name += "x";
    
    FILE* fout = fopen(fout_name.c_str(),"wb+");

    char* tempSpace = (char*)malloc(1024*sizeof(char));
    fread(tempSpace, 1024, 1, fin);
    for(unsigned int i=0;i<8;i++)
        printf("##%x\n",0xff&tempSpace[i]);
    
    //revert_with_combination(tempSpace, 1024, 4);
    for(unsigned int i=0;i<8;i++)
        printf("###%x\n",0xff&tempSpace[i]);
    fwrite(tempSpace, 1, 32, fout);
    fclose(fin);
    fclose(fout);
}

void revert_with_combination(char* array, unsigned int size, unsigned int combinWidth)
{
    for(unsigned int i=0;i<size-combinWidth;i++)
        reverse(array+i*combinWidth,array+(i+1)*combinWidth);
}

class BChecker{
};
class BReader{
public:
    BReader():_bufferSize(4096){};
    inline BReader(FILE* fin, char* buffer, unsigned int size = 4096){
        _fin = fin;
        _buffer = buffer;
        _bufferSize = size;
    };
    inline void flash_buffer(){};

private:
    FILE* _fin;
    char *_buffer;  
    unsigned int _bufferSize;
};

class BReverser{
public:
    inline BReverser(char* array){
        _array = array;
    };
    inline void work(){
        //
    };
private:
    char* _array;
};

class BWriter{
public:
    inline BWriter(FILE* fout, char* array){};
private:
    FILE* _fout;
    char* _array;
};

class BReorder{
    BReorder();
    inline void run(){
        //phaser

        //checker

        //deal loop
            //reverser
            //writer
        //deal loop end

    };

private:

    BChecker _checker;
    BReader _reader;
    BReverser _reverser;
    BWriter _writer;
    
    string _finPath;
    string _foutPath;
    unsigned int _combinationWidth;

};