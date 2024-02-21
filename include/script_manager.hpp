#ifndef SCRIPT_MANAGER
#define SCRIPT_MANAGER

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "script.hpp"
#include "directory_reader.hpp"
#include <algorithm>
#include <string>
#include <vector>

#define LOAD_FAILED             -1
#define LOAD_SUCCESS             0
#define SCRIPT_NOT_EXSISTS     -10

class script_manager {
    private:
        std::string scripts_path;
        std::vector<script> scripts;
        std::map<std::string, std::string> Mtype_executer;

        script_manager() = delete;
        script_manager(std::string &&path);
    
    public:
        static script_manager& get_script_manager(std::string &&path);
        bool script_exist(const std::string &script_name);
        void add_script(script &&) noexcept;
        int execute_script(const std::string &script_name) const;
        int load_scripts();
        std::string get_fileType(std::string file_name) const;

        script_manager(const script_manager&) = delete;
        script_manager(script_manager &&) = delete;
        script_manager& operator=(const script_manager&) = delete;
        script_manager& operator=(script_manager &&) = delete;
    
        void print_scr(){
            for(const script& src: scripts)
                src.print_script();
        }
};


#endif // SCRIPT_MANAGER