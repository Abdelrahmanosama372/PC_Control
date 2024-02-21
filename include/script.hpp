#ifndef SCRIPT
#define SCRIPT

#include <string.h>
#include <iostream>
#include <stdlib.h>

class script {
    private:
        std::string name;
        std::string path;
        std::string type;

    public:
        script() = delete;
        script(std::string name, std::string path, std::string type);
        script(script &&);

        script(const script&) = delete;
        script& operator=(script &&) = delete;
        script& operator=(const script &) = delete;

        std::string get_name() const;
        std::string get_path() const;
        std::string get_type() const;
        void clear_script();
        int execute(std::string &&) const;

        void print_script() const{
            std::cout << "==============" << std::endl;
            std::cout << name << std::endl;
            std::cout << path << std::endl;
            std::cout << type << std::endl;
            std::cout << "==============" << std::endl;
        }
};


#endif // !SCRIPT