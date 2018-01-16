cmake_minimum_required(VERSION 3.8)
project(RType)

set(CMAKE_CXX_STANDARD 14)

include(GTest.cmake)

# Engine
set(core_SOURCE_FILES
        engine/core/Engine.cpp
        engine/core/Engine.hpp
        engine/core/NonCopyable.hpp
        engine/core/ASystem.hpp
        engine/core/Message.cpp
        engine/core/Message.hpp
        engine/core/GameObject.cpp
        engine/core/GameObject.hpp engine/core/Component.cpp engine/core/Component.hpp engine/core/Singleton.hpp engine/core/Scene.cpp engine/core/Scene.hpp engine/core/AutoList.hpp engine/core/ComponentHandler.hpp engine/core/ID.hpp
        engine/core/Vector2D.hpp engine/core/Vector2D.cpp)

set(core_unit_SOURCE_FILES
        unit/engine/core/GameObjectUnit.cpp
        unit/engine/core/GameObjectManagerUnit.cpp)

# Engine : Game
set(game_SOURCE_FILES)
set(game_unit_SOURCE_FILES)

# Engine : Graphics
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/find/") #add FindSFML file

set(graphics_SOURCE_FILES
        engine/graphics/Animation.cpp
        engine/graphics/Animation.hpp
        engine/graphics/RTypeGraphics.hpp
        engine/graphics/SpriteSheet.cpp
        engine/graphics/SpriteSheet.hpp
        engine/graphics/Scene.cpp
        engine/graphics/Scene.hpp
        engine/graphics/Event.cpp
        engine/graphics/Event.hpp
        engine/graphics/Window.cpp
        engine/graphics/Window.hpp
        engine/graphics/GraphicsComponent.cpp
        engine/graphics/GraphicsComponent.hpp)
set(graphics_unit_SOURCE_FILES)

# Engine : Physics
set(physics_SOURCE_FILES engine/physics/RigidBodyComponent.cpp
        engine/physics/RigidBodyComponent.hpp
        engine/physics/Box.cpp
        engine/physics/Box.hpp
        engine/physics/PhysicsSystem.cpp
        engine/physics/PhysicsSystem.hpp)
set(physics_unit_SOURCE_FILES
        unit/engine/physics/RigidBodyComponentUnit.cpp
        unit/engine/physics/PhysicsSystemUnit.cpp)

# Engine : Network
set(network_SOURCE_FILES engine/network/Socket.cpp
        engine/network/Socket.hpp
        engine/network/WindowsSocket.cpp
        engine/network/WindowsSocket.hpp
        engine/network/UnixSocket.cpp
        engine/network/UnixSocket.hpp
        engine/network/ISocket.hpp)
set(network_unit_SOURCE_FILES)

# Link Module

set(client_MODULES
        ${core_SOURCE_FILES}
        ${game_SOURCE_FILES}
        ${graphics_SOURCE_FILES}
        ${network_SOURCE_FILES})

set(server_MODULES
        ${core_SOURCE_FILES}
        ${game_SOURCE_FILES}
        ${physics_SOURCE_FILES}
        ${network_SOURCE_FILES})

# Software : Client
set(client_SOURCE_FILES ${client_MODULES} client/main_client.cpp engine/graphics/GraphicsSystem.cpp engine/graphics/GraphicsSystem.hpp)

# Software : Server
set(server_SOURCE_FILES ${server_MODULES} server/main_server.cpp)

# include dir
include_directories(engine)

# client
add_executable(client ${client_SOURCE_FILES})
set_target_properties(client PROPERTIES COMPILE_DEFINITIONS GRAPHICS=1)
# server
add_executable(server ${server_SOURCE_FILES})
#add_executable(testGraphics ${graphics_SOURCE_FILES})

# init linkage variable
set(SFML_STATIC_LIBRARIES False)

# search libs
find_package(Threads)
find_package(SFML 2.4 REQUIRED audio graphics window system) # find SFML

message("SFML LIBS: " ${SFML_LIBRARIES})
message("SFML INCLUDES: " ${SFML_INCLUDE_DIR})

# link libs
target_link_libraries(client ${SFML_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(server ${SFML_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
#target_link_libraries(testGraphics ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

# includes dir libs
include_directories(${SFML_INCLUDE_DIR})

# unit test
add_executable(engine_core_unit ${core_SOURCE_FILES} ${core_unit_SOURCE_FILES})

add_executable(engine_physics_unit ${physics_SOURCE_FILES} ${physics_unit_SOURCE_FILES})

set(GOOGLE_TESTS_LIBS gtest gmock ${CMAKE_THREAD_LIBS_INIT})

if (MSVC)
    target_compile_options(engine_core_unit PRIVATE /std:c++14 /W4 /WX)
    target_compile_options(engine_physics_unit PRIVATE /std:c++14 /W4 /WX)

    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Ox")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Od")
    target_link_libraries(engine_core_unit ${GOOGLE_TESTS_LIBS})
    target_link_libraries(engine_physics_unit ${GOOGLE_TESTS_LIBS})
    # VS 2017 removed tr1
    add_definitions(-DGTEST_HAS_TR1_TUPLE=0)
else ()
    target_compile_options(engine_core_unit PRIVATE -g -Wall -Werror -Wextra -Wpedantic -Wconversion -Wswitch-default -Wswitch-enum -Wunreachable-code -Wwrite-strings -Wcast-align -Wshadow -Wundef)
    target_compile_options(engine_physics_unit PRIVATE -g -Wall -Werror -Wextra -Wpedantic -Wconversion -Wswitch-default -Wswitch-enum -Wunreachable-code -Wwrite-strings -Wcast-align -Wshadow -Wundef)
    if (COVERAGE)
        target_compile_options(engine_core_unit PRIVATE --coverage)
        target_link_libraries(engine_core_unit PRIVATE --coverage ${GOOGLE_TESTS_LIBS})
        target_compile_options(engine_physics_unit PRIVATE --coverage)
        target_link_libraries(engine_physics_unit PRIVATE --coverage ${GOOGLE_TESTS_LIBS})
    else ()
        target_link_libraries(engine_core_unit ${GOOGLE_TESTS_LIBS})
        target_link_libraries(engine_physics_unit ${GOOGLE_TESTS_LIBS})
    endif ()
endif ()
