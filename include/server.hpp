#ifndef SERVER_HPP      
#define SERVER_HPP

#include <asm-generic/socket.h>
#include <cerrno>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <memory>
#include <netinet/in.h>
#include <stdexcept>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <thread>
#include <unistd.h>
#include <memory.h>
#include <iterator>

#define MAX_CLIENTS 5


class Server
{   private:
        sockaddr_in ServerAddress;
        sockaddr_in clientAddress;
        int socket_fdes;
        int client_fdes;
        char Buffer[1024];
    public:

        Server(int port);
        void accept_client();
        void send(const std::string& data);
        std::string recieve();
        ~Server();

        void shutdoown(){
            // shutdown(client_fdes,SHUT_RDWR);
            if(close(client_fdes) == -1)
                std::cout << "cclose failed" << std::endl;
            if(close(socket_fdes) == -1)
                std::cout << "cclose failed" << std::endl;
        }
};


#endif // SERVER_HPP