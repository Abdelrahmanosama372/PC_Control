#include "../include/script.hpp"
#include <cstdlib>


script::script(std::string name, std::string path, std::string type)
    :name(name),path(path),type(type) {   
}

script::script(script &&expired_script) {
    this->name = expired_script.get_name();
    this->path = expired_script.get_path();
    this->type = expired_script.get_type();
    expired_script.clear_script();
}

std::string script::get_name()const {
    return name;
}

std::string script::get_path()const {
    return path;
}

std::string script::get_type()const {
    return type;
}

void script::clear_script() {
    name.clear();
    path.clear();
    type.clear();
}

int script::execute(std::string &&script_executer)const {
    return system((script_executer + " " + path + "/" + name).c_str());
}