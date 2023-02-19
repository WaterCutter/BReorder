#ifndef _BREADER_H
#define _BREADER_H

extern "C"{
    #include <stdio.h>
    #include <stdlib.h>
}

#include <iostream>

class BReader{
public:
    //BReader():_bufferSize(4096){};
    inline BReader(FILE* fin, char* buffer, unsigned int buffersize){
        _fin = fin;
        _buffer = buffer;
        _bufferSize = buffersize;
    };
    inline size_t flash_buffer(){
        size_t nRead = fread(_buffer, 1, _bufferSize, _fin);
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

#endif