#include "../include/directory_reader.hpp"
#include <cstddef>
#include <dirent.h>
#include <string>

directory_reader::directory_reader(std::string dir_path):dirp(nullptr){
    dirp = opendir(dir_path.c_str());
    if(dirp == nullptr){
        return;
    }
}

std::vector<std::string> directory_reader::read_scripts(){
    std::vector<std::string> files_names;
    for(dp = readdir(dirp); dp != nullptr; dp = readdir(dirp)) {
        if(dp->d_type == DT_REG)
            files_names.push_back(dp->d_name);
    }
    
    // close dir
    closedir(dirp);
    return files_names;
}

bool directory_reader::is_dir_opened() const{
    return dirp != nullptr;
}