#include "b_reorder.h"

void BReorder::run(){
    //phaser
    BPhaser phaser;
    phaser.doPhase(_argn, _argv);
    _finPath = phaser.fPath();
    _combinationWidth = phaser.combinWidth();
    _elementWidth = phaser.elementWidth();

    size_t combinBytesNum = _elementWidth*_combinationWidth;
    
    FILE* fin = fopen(_finPath.c_str(), "rb");
    FILE* fout = fopen(fin_2_fout(_finPath).c_str(), "wb+");
    //checker
    if(!phaser.isForced()){
        BChecker checker(fin, combinBytesNum);
        int res = checker.doCheck();
        if(res !=0 ){ 
            cout<<"alignment check failed: res == "<< res << endl;
            return;
        };
    }
    
    //dealing loop
    size_t bufferSize = combinBytesNum;
    _buffer = (char*) malloc(bufferSize*sizeof(char));
    BReader reader(fin, _buffer, bufferSize);
    BReverser reverser(_buffer, _elementWidth, _combinationWidth);
    BWriter writer(fout, _buffer, bufferSize);
    //reader
    while(reader.flash_buffer() != 0){
        //reverser
        reverser.doReverse();
        //writer
        writer.doWrite();
    }
    //dealing loop end
    free(_buffer);
};
