#include <iostream>
#include <string>
extern "C"{
    #include <stdio.h>
    #include <stdlib.h>
}
#include <algorithm>

using namespace std;

// void revert_with_combination(char* array, unsigned int size, unsigned int combinWidth);


// int main(int argc, char* argv[])
// {
//     FILE* fin = fopen(argv[1],"rb");
//     cout<<argv[1]<<endl;
    
//     string fout_name(argv[1]);
//     fout_name += "x";
    
//     FILE* fout = fopen(fout_name.c_str(),"wb+");

//     char* tempSpace = (char*)malloc(1024*sizeof(char));
//     fread(tempSpace, 1024, 1, fin);
//     for(unsigned int i=0;i<8;i++)
//         printf("##%x\n",0xff&tempSpace[i]);
    
//     //revert_with_combination(tempSpace, 1024, 4);
//     for(unsigned int i=0;i<8;i++)
//         printf("###%x\n",0xff&tempSpace[i]);
//     fwrite(tempSpace, 1, 32, fout);
//     fclose(fin);
//     fclose(fout);
// }

// void revert_with_combination(char* array, unsigned int size, unsigned int combinWidth)
// {
//     for(unsigned int i=0;i<size-combinWidth;i++)
//         reverse(array+i*combinWidth,array+(i+1)*combinWidth);
// }

class BPhaser{
public:
    BPhaser(){
        //ctor
    }
    inline void doPhase(int argn, char* argv[]){

    };
    inline string fPath(){ return _fPath; };
    inline unsigned int combinWidth(){ return _combinWidth; };
    
private:
    string _fPath;
    unsigned int _combinWidth; 
};

class BChecker{
public:
    BChecker(FILE* fp, unsigned int alignN):_fp(fp),_align(alignN){
        //ctor
    };
    //return 0 means everything fine
    inline unsigned int doCheck(){
        int alignRes = checkNotAlign(getFileSize(_fp), _align);
        _checkRes = alignRes<<0;
        return _checkRes;
    };

private:
    inline unsigned int getFileSize(FILE* fp){
        fseek(fp, 0L, SEEK_END);
        int fSize=ftell(fp);
        fclose(fp);
        return fSize;
    }
    inline int checkNotAlign(int fileSize, unsigned int n){
        return (fileSize % n != 0)?1:0;
    }
    //  [31:1]          [0]
    //  Reserved        align
    unsigned int _checkRes;
    FILE* _fp;
    unsigned int _align;
};

class BReader{
public:
    //BReader():_bufferSize(4096){};
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
    inline void reverse_with_combination(unsigned int size, unsigned int combinWidth)
    {
        for(unsigned int i=0;i<size-combinWidth;i++)
            reverse(_array+i*combinWidth,_array+(i+1)*combinWidth);
    }
private:
    char* _array;
};

class BWriter{
public:
    inline BWriter(FILE* fout, char* array, size_t len):
    _fout(fout), _array(array), _len(len){
        //ctor
    };
    inline void doWrite(){
        //writing array to fout (with binary format)
        fwrite(_array, _len, 1, _fout);
    };

private:
    FILE* _fout;
    char* _array;
    size_t _len;
};

class BReorder{
public:
    BReorder(int argn, char* argv[]):
    _argn(argn), _argv(argv){

    };
    inline void run(){
        //phaser
        // BPhaser phaser;
        // phaser.doPhase(_argn, _argv);
        // _finPath = phaser.fPath();
        // _combinationWidth = phaser.combinWidth();
        _finPath = _argv[1];
        _combinationWidth = 4;
        
        FILE* fin = fopen(_finPath.c_str(), "rb");
        FILE* fout = fopen(fin_2_fout(_finPath).c_str(), "wb+");
        //checker
        BChecker checker(fin, _combinationWidth);
        int res = checker.doCheck();
        if(res !=0 ){ 
            cout<<"check failed: res == "<< res << endl;
            return;
        };
        
        //dealing loop
        size_t bufferSize = 1024*_combinationWidth;
        _buffer = (char*) malloc(bufferSize*sizeof(char));
        BReader reader(fin, _buffer);
        BReverser reverser(_buffer);
        BWriter writer(fout, _buffer, bufferSize);
        //reader
        while(reader.flash_buffer() != 0){
            //reverser
            reverser.reverse_with_combination(bufferSize,_combinationWidth);
            //writer
            writer.doWrite();
        }
        //dealing loop end
    };

private:
    //function
    inline string fin_2_fout(string& finPath){
        string foutPath;
        
        //making
        
        return foutPath; 
    }
    //buf
    char* _buffer;
    //pahsed
    string _finPath;
    string _foutPath;
    unsigned int _combinationWidth;
    
    //param list
    int _argn;
    char** _argv;  

};

int main(int argn, char* argv[])
{
    BReorder reorder(argn, argv);
    reorder.run();
}
