#ifndef _BREORDER_H
#define _BREORDER_H

#include <string>
#include "b_checker.h"
#include "b_phaser.h"
#include "b_reader.h"
#include "b_reverser.h"
#include "b_writer.h"
#include <iostream>
using std::string;
using std::endl;
using std::cout;

class BReorder{
public:
    BReorder(int argn, char* argv[]):
    _argn(argn), _argv(argv),
    _elementWidth(1), _combinationWidth(2){

    };

    void run();
    
private:
    //function
    inline string fin_2_fout(string& finPath){
        string foutPath;
        
        //making
        foutPath = finPath+"x";
        
        return foutPath; 
    }
    //buf
    char* _buffer;
    //pahsed
    string _finPath;
    string _foutPath;
    unsigned int _combinationWidth;
    unsigned int _elementWidth;
    
    //param list
    int _argn;
    char** _argv;  

};

#endif