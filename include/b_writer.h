#ifndef _PHASER_H
#define _PHASER_h

#include <stdio.h>

class BWriter{
public:
    inline BWriter(FILE* fout, char* array, size_t len):
    _fout(fout), _array(array), _len(len){
        //ctor
    };
    inline void doWrite(){
        //writing array to fout (with binary format)
        fwrite(_array, 1, _len, _fout);
    };

private:
    FILE* _fout;
    char* _array;
    size_t _len;
};

#endif
