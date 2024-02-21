#include "../include/script_manager.hpp"

script_manager::script_manager(std::string &&path){
    scripts_path = std::move(path);

    Mtype_executer["py"] = "python3";
    Mtype_executer["js"] = "node";
    Mtype_executer["sh"] = "bash";
}

script_manager& script_manager::get_script_manager(std::string &&path){
    static script_manager sm(std::move(path));
    return sm;
}


bool script_manager::script_exist(const std::string &script_name){
    auto scr_it = std::find_if(scripts.begin(), scripts.end(),
                                    [&script_name](const script& scr){
                                        return scr.get_name() == script_name;
                                    });
    if(scr_it == scripts.end())
        return false;
    return true;
}

void script_manager::add_script(script &&other_script) noexcept{
    scripts.push_back(std::move(other_script));
}


int script_manager::load_scripts() {
    directory_reader dr(scripts_path);

    if(!dr.is_dir_opened())
        return LOAD_FAILED;

    std::vector<std::string> file_names = std::move(dr.read_scripts());

    if (file_names.empty())
        return LOAD_FAILED;

    for(const std::string& name: file_names){
        std::string file_type = std::move(get_fileType(name));
        if(file_type != ""){
            script scr(name,scripts_path,file_type);
            add_script(std::move(scr));
        }
    }

    return LOAD_SUCCESS;
}

int script_manager::execute_script(const std::string &script_name) const{
    auto scr_it = std::find_if(scripts.begin(), scripts.end(),
                                    [&script_name](const script& scr){
                                        return scr.get_name() == script_name;
                                    });
    if(scr_it == scripts.end())
        return SCRIPT_NOT_EXSISTS;  // error code script not exists

    auto pair = *Mtype_executer.find(scr_it->get_type());  // no check on pair as the scripts are of defined types

    return scr_it->execute(std::move(pair.second));
}

std::string script_manager::get_fileType(std::string file_name) const{
    auto index = file_name.find('.');
    if (index == std::string::npos)
        return "";
    return file_name.substr(index+1,file_name.length());

}
