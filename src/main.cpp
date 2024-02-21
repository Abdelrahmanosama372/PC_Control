#include "../include/server.hpp"
#include "../include/script_manager.hpp"
#include <chrono>
#include <stdexcept>
#include <string>
#include <thread>

#define port 8070

int main()
{
    std::string path(getenv("HOME"));
    path.append("/.scripts");
    script_manager &sm = script_manager::get_script_manager(std::move(path));
    if(sm.load_scripts() == LOAD_FAILED){
        throw std::runtime_error("Error in loading scripts");
    }

    Server server(port);
    server.accept_client();
    std::cout << "server running on port -> " << port << std::endl;

    while(true){
        server.send(">send a command or script name\n");
        
        std::string data = server.recieve();
        int exec_status = sm.execute_script(data.substr(0,data.length()-1));

        if(exec_status == SCRIPT_NOT_EXSISTS){
            server.send("this script doesn't exists\n");
            continue;
        }
       
        if(exec_status == 0){
            server.send("script is executed successfully\n");
        }else{
            server.send("Execution error in script "+ data);
        }
    }
    server.shutdoown();
    return 0;
}