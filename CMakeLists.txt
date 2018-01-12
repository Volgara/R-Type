cmake_minimum_required(VERSION 3.8)
project(RType)

set(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(server/include)

set(SOURCE_FILES
        main.cpp
        server/src/Socket.cpp
        server/include/Socket.hpp
        server/src/WindowsSocket.cpp
        server/include/WindowsSocket.hpp
        server/src/UnixSocket.cpp
        server/include/UnixSocket.hpp
        server/include/ISocket.hpp
        server/include/Server.hpp
        server/include/GameManager.hpp
        server/src/Player.cpp
        server/include/Player.hpp
        server/src/Server.cpp
        server/src/GameManager.cpp server/include/Exception.hpp server/src/Room.cpp server/include/Room.hpp)

add_executable(RType ${SOURCE_FILES})