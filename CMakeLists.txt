cmake_minimum_required(VERSION 3.8)
project(RType)

set(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(server/include)

# Core
set(core_SOURCE_FILES )

# Engine : Game
set(game_SOURCE_FILES )

# Engine : Graphics
set(graphics_SOURCE_FILES )

# Engine : Physics
set(physics_SOURCE_FILES )

# Engine : Network
set(network_SOURCE_FILES engine/network/Socket.cpp
        engine/network/Socket.hpp
        engine/network/WindowsSocket.cpp
        engine/network/WindowsSocket.hpp
        engine/network/UnixSocket.cpp
        engine/network/UnixSocket.hpp
        engine/network/ISocket.hpp)

# Link Module

set(client_MODULES ${core_SOURCE_FILES}
        ${game_SOURCE_FILES}
        ${graphics_SOURCE_FILES}
        ${network_SOURCE_FILES})

set(server_MODULES ${core_SOURCE_FILES}
        ${game_SOURCE_FILES}
        ${physics_SOURCE_FILES}
        ${network_SOURCE_FILES})

# Software : Client
set(client_SOURCE_FILES ${client_MODULES} client/main_client.cpp)

# Software : Server
set(server_SOURCE_FILES ${server_MODULES} server/main_server.cpp)

add_executable(client ${client_SOURCE_FILES})
add_executable(server ${server_SOURCE_FILES})