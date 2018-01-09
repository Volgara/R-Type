cmake_minimum_required(VERSION 3.8)
project(RType)

set(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(server/include)

# Game Engine
include(core/core.cmake)
include(engine/game/game.cmake)
include(engine/graphics/graphics.cmake)
include(engine/network/network.cmake)
include(engine/physics/physics.cmake)

# Software : Client
include(client/client.cmake)

# Sofware : Server
include(server/server.cmake)

set(SOURCE_FILES
        main.cpp
        server/src/Socket.cpp
        server/include/Socket.hpp
        server/src/WindowsSocket.cpp
        server/include/WindowsSocket.hpp
        server/src/UnixSocket.cpp
        server/include/UnixSocket.hpp
        server/include/ISocket.hpp)

add_executable(RType ${SOURCE_FILES})