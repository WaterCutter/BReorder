#ifndef _BREVERSER_H
#define _BREVERSER_H

#include<iostream>

class BReverser{
public:
    inline BReverser(char* array, size_t elemWidth, size_t combinWidth){
        _array = array;
        _elemWidth = elemWidth;
        _combinWidth = combinWidth;
    };
    inline void doReverse()
    {
        char tmpArray[_elemWidth] = {0};
        for(int i=0;i<(_combinWidth-1);i++){
            memcpy(tmpArray, (char*)&_array[i*_elemWidth], _elemWidth);
            memcpy((char*)&_array[i*_elemWidth], (char*)&_array[(_combinWidth-1-i)*_elemWidth], _elemWidth);
            memcpy((char*)&_array[(_combinWidth-1-i)*_elemWidth], tmpArray, _elemWidth);
        }
           
    }
private:
    char* _array;
    size_t _elemWidth;
    size_t _combinWidth;
};

#endif