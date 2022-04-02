#pragma once

using std::string;

#include <filesystem>
#ifdef __APPLE__
        namespace fs = std::__fs::filesystem;
    #else
        namespace fs = std::filesystem;
#endif

namespace Nbk {
    
class Init{
    public:
        Init(){
            this->num = 1;
        }
        ~Init(){}
        
    private:
        int num;
};
    void init_dir(string dir);
    
    
    const string ROOT_DIR=".";
    const string FILES_DIR="files";
    const string SHARE_DIR="share";
    const string DATA_DIR="data";
    // No other directory can be made as DEFAULT_DIR
    const string DEFAULT_DIR =  "default";
    const string README_FILE = "readme";
}