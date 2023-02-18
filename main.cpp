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

class BPhaser{

};

class BChecker{
public:
    BChecker(FILE* fp, unsigned int alignN):_fp(fp),_align(alignN){
        //ctor
    };
    inline unsigned int doCheck(){
        int alignRes = checkAlign(getFileSize(_fp), _align);
        _checkRes = alignRes<<0;
        return _checkRes;
    };

private:
    inline unsigned int getFileSize(FILE* fp){
        fseek(fp,0L,SEEK_END);
        int fSize=ftell(fp);
        fclose(fp);
        return fSize;
    }
    inline int checkAlign(int fileSize, unsigned int n){
        return (fileSize % n == 0)?1:0;
    }
    //  [31:1]          [0]
    //  Reserved        align
    unsigned int _checkRes;
    FILE* _fp;
    unsigned int _align;
};

class BReader{
public:
    BReader():_bufferSize(4096){};
    inline BReader(FILE* fin, char* buffer, unsigned int buffersize = 4096){
        _fin = fin;
        _buffer = buffer;
        _bufferSize = buffersize;
    };
    inline size_t flash_buffer(){
        size_t nRead = fread(_buffer, _bufferSize, 1, _fin);
        if(nRead != _bufferSize){
            std::fill(_buffer+nRead, _buffer+_bufferSize, 0xFF);
        };
        return nRead;
    };

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
    inline void reverse_with_combination(char* array, unsigned int size, unsigned int combinWidth)
    {
        for(unsigned int i=0;i<size-combinWidth;i++)
            reverse(array+i*combinWidth,array+(i+1)*combinWidth);
    }
private:
    char* _array;
};

class BWriter{
public:
    inline BWriter(FILE* fout, char* array){
        //ctor
    };
    inline void doWrite(){
        //writing array to fout (with binary format)
    };

private:
    FILE* _fout;
    char* _array;
};

class BReorder{
    BReorder(int argn, char* argv[]);
    inline void run(){
        //phaser

        //checker

        //deal loop
            //reader
            //reverser
            //writer
        //deal loop end

    };

private:
    //pahsed
    string _finPath;
    string _foutPath;
    unsigned int _combinationWidth;
    
    //param list
    

};