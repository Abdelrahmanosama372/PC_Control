cmake_minimum_required(VERSION 3.16.3)
project(PC-Control)
add_executable(${PROJECT_NAME} 
    src/main.cpp 
    src/server.cpp
    src/script.cpp
    src/script_manager.cpp 
    src/directory_reader.cpp)