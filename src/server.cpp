#include "../include/server.hpp"
#include <cstring>
#include <iterator>
#include <stdexcept>
#include <unistd.h>

Server::Server(int port): socket_fdes(-1) {
    // create socket
    socket_fdes = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(socket_fdes == -1){
        std::string error = std::string("Error opening the socket -> ") + std::strerror(errno);
        throw std::runtime_error(error);
    }
    // socket options
    int options = 1;
    if(setsockopt(socket_fdes, SOL_SOCKET, SO_REUSEADDR | SO_KEEPALIVE | SO_REUSEPORT, 
        &options, sizeof(options))){
        std::string error = std::string("Error setting socket options -> ") + std::strerror(errno);
        throw std::runtime_error(error);
    }

    // bind to socket 
    ServerAddress.sin_addr.s_addr = INADDR_ANY;
    ServerAddress.sin_port = htons(port);
    ServerAddress.sin_family = AF_INET;

    if(bind(socket_fdes,reinterpret_cast<sockaddr*>(&ServerAddress),sizeof(ServerAddress))){
        std::string error = std::string("Error in socket binding -> ") + std::strerror(errno);
        throw std::runtime_error(error);
    }

    // listen to socket
    if(listen(socket_fdes, MAX_CLIENTS)){
        std::string error = std::string("Error in listening -> ") + std::strerror(errno);
        throw std::runtime_error(error);
    }
}

void Server::accept_client(){
    socklen_t clientAddress_size =  sizeof(clientAddress);
    client_fdes = accept(socket_fdes, reinterpret_cast<sockaddr*>(&clientAddress), &clientAddress_size);
    if(client_fdes < 0){
        close(socket_fdes);
        std::string error = std::string("Error in accepting client -> ") + std::strerror(errno);
        throw std::runtime_error(error);
    }   
}

void Server::send(const std::string& data){
    if(write(client_fdes, data.c_str(), data.size()+1) == -1){
        std::string error = std::string("Error in writing to client -> ") + std::strerror(errno);
        throw std::runtime_error(error);
    }   
}   


std::string Server::recieve(){
    char buffer[1024];
    int data_num = read(client_fdes, buffer, sizeof(buffer));
    if(data_num == -1){
        std::string error = std::string("Error in reading from client -> ") + std::strerror(errno);
        throw std::runtime_error(error);
    }  
    return std::string(buffer,data_num);
}

Server::~Server(){
    close(client_fdes);
    close(socket_fdes);
}

