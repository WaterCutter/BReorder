#ifndef _BCHECKER_H
#define _BCHECKER_H

extern "C"{
    #include <stdio.h>
    #include <stdlib.h>
}

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
        fseek(fp, 0L, SEEK_SET);
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

#endif