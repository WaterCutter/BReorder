#ifndef _BPHASER_H
#define _BPHASER_H

#include "cmdline.h"
#include <string>

using std::string;

class BPhaser{
public:
    BPhaser():
    _combinWidth(4),_elementWidth(1){
        arg.add<unsigned int>("elementWidth", 'E', "element width",false);
        arg.add<unsigned int>("combinationWidth",'C',"group width",false);
        arg.add<string>("filePath",'i',"file path",true);
        arg.add("t",'\0',"add an output with .txt format");
        arg.add<unsigned int>("forced", 'f', "without checking", false);
    }
    inline void doPhase(int argn, char* argv[]){
        arg.parse_check(argn,argv);
        _fPath=arg.get<string>("filePath");
        _elementWidth = arg.exist("elementWidth") ? arg.get<unsigned int>("elementWidth"):_combinWidth;
        _combinWidth = arg.exist("combinationWidth") ? arg.get<unsigned int>("combinationWidth"):_combinWidth; 
    };
    inline string fPath(){ return _fPath; };
    inline unsigned int combinWidth(){ return _combinWidth; };
    inline unsigned int elementWidth(){ return _elementWidth; };
    inline bool isForced(){ return (arg.exist("forced")?true:false); };

private:
    string _fPath;
    unsigned int _combinWidth = 4;
    unsigned int _elementWidth = 1;
    cmdline::parser arg;

};

#endif