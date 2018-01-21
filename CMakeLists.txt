cmake_minimum_required(VERSION 3.8)
project(RType)

set(CMAKE_CXX_STANDARD 14)

#set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG")

include(GTest.cmake)

# Engine
set(core_SOURCE_FILES
        engine/core/Engine.cpp
        engine/core/Engine.hpp
        engine/core/NonCopyable.hpp
        engine/core/ASystem.hpp
        engine/core/Message.hpp
        engine/core/GameObject.cpp
        engine/core/GameObject.hpp
        engine/core/Component.cpp
        engine/core/Component.hpp
        engine/core/Singleton.hpp
        engine/core/Scene.cpp
        engine/core/Scene.hpp
        engine/core/AutoList.hpp
        engine/core/ComponentHandler.hpp
        engine/core/ID.hpp
        engine/core/Vector2D.hpp
        engine/core/Vector2D.cpp
        engine/core/MessageBus.hpp
        engine/core/MessageBus.cpp
        engine/core/BusNode.hpp
        engine/core/BusNode.cpp)


set(core_unit_SOURCE_FILES
        unit/engine/core/GameObjectUnit.cpp
        unit/engine/core/GameObjectManagerUnit.cpp)

# Engine : Game

set(game_server_SOURCE_FILES
        game/GameLogicSystem.cpp
        game/GameLogicSystem.hpp
        game/GameServer.hpp
        game/GameServer.cpp)

set(game_SOURCE_FILES
        game/PlayerComponent.cpp
        game/PlayerComponent.hpp
        game/UserType.hpp
        game/Message.hpp
        game/SpaceShip.hpp
        game/SpaceShip.cpp)

set(game_unit_SOURCE_FILES
        ${game_server_SOURCE_FILES}
        unit/game/GamePlayerUnit.cpp)

set(game_client_SOURCE_FILES
        ${game_SOURCE_FILE}
        game/GameLogicClientSystem.cpp
        game/GameLogicClientSystem.hpp
        game/GameClient.hpp
        game/GameClient.cpp)

# Engine : Projectile
set(projectile_SOURCE_FILES
        engine/projectile/BulletComponent.hpp
        engine/projectile/BulletComponent.cpp
        engine/projectile/BulletSystem.hpp
        engine/projectile/BulletSystem.cpp)
set(projectile_unit_SOURCE_FILES
        unit/engine/projectile/BulletSystemUnit.cpp)

# Engine : Graphics
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/find/") #add FindSFML file

set(graphics_SOURCE_FILES
        engine/graphics/Animation.cpp
        engine/graphics/Animation.hpp
        engine/graphics/RTypeGraphics.hpp
        engine/graphics/SpriteSheet.cpp
        engine/graphics/SpriteSheet.hpp
        engine/graphics/Event.cpp
        engine/graphics/Event.hpp
        engine/graphics/Window.cpp
        engine/graphics/Window.hpp
        engine/graphics/GraphicsComponent.cpp
        engine/graphics/GraphicsComponent.hpp
        engine/graphics/GraphicsSystem.cpp
        engine/graphics/GraphicsSystem.hpp)
set(graphics_unit_SOURCE_FILES
        unit/engine/graphics/GraphicsComponentUnit.cpp
        unit/engine/graphics/GraphicsSystemUnit.cpp)

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
        engine/network/NetworkComponent.cpp
        engine/network/NetworkComponent.hpp
        engine/network/ISocket.hpp)
set(network_unit_SOURCE_FILES)

# Engine : input
set(input_SOURCE_FILES
        engine/input/InputSystem.cpp
        engine/input/InputSystem.hpp
        engine/input/Command.hpp engine/input/InputComponent.cpp engine/input/InputComponent.hpp)
set(input_unit_SOURCE_FILES)

# Launcher
set(launcher_SOURCE_FILES
        launcher/main.cpp
        launcher/Connection.cpp
        launcher/Connection.hpp
        launcher/Scene.cpp
        launcher/Scene.hpp
        launcher/SceneManager.cpp
        launcher/SceneManager.hpp
        launcher/Menu.cpp
        launcher/Menu.hpp
        launcher/Settings.cpp
        launcher/Settings.hpp
        launcher/ServerList.cpp
        launcher/ServerList.hpp
        launcher/Lobby.cpp
        launcher/Lobby.hpp
        launcher/Helper.cpp
        launcher/Helper.hpp
        launcher/Room.cpp launcher/Room.hpp launcher/GraphicalRoom.cpp launcher/GraphicalRoom.hpp)

set(launcher_unit_SOURCE_FILES)

# Link Module

set(client_MODULES
        ${core_SOURCE_FILES}
        ${input_SOURCE_FILES}
        ${game_SOURCE_FILES}
        ${graphics_SOURCE_FILES}
        ${physics_SOURCE_FILES}
        ${network_SOURCE_FILES}
        ${projectile_SOURCE_FILES})

set(server_MODULES
        ${core_SOURCE_FILES}
        ${game_SOURCE_FILES}
        ${physics_SOURCE_FILES}
        ${network_SOURCE_FILES}
        ${projectile_SOURCE_FILES})

# Software : Client
set(client_SOURCE_FILES ${client_MODULES}
        client/main_client.cpp)

set(file_server engine/network/networkException.hpp
        server/GameManager.cpp
        server/GameManager.hpp
        server/Player.cpp
        server/Player.hpp
        server/Room.cpp
        server/Room.hpp
        server/Server.cpp
        server/Server.hpp)

# Software : Server
set(server_SOURCE_FILES ${server_MODULES}
        ${file_server}
        server/main_server.cpp)

# include dir
include_directories(engine)

# client
add_executable(client ${client_SOURCE_FILES} ${game_client_SOURCE_FILES})
set_target_properties(client PROPERTIES COMPILE_DEFINITIONS GRAPHICS=1)

# server
add_executable(server ${server_SOURCE_FILES} ${game_SOURCE_FILES} ${game_server_SOURCE_FILES})

#launcher
add_executable(launcher ${launcher_SOURCE_FILES} ${client_MODULES})
set_target_properties(launcher PROPERTIES COMPILE_DEFINITIONS GRAPHICS=1)

# init linkage variable
set(SFML_STATIC_LIBRARIES False)

# search libs
find_package(Threads)
find_package(SFML 2.4 COMPONENTS audio graphics window system) # find SFML

# link libs
#set(SFML_INCLUDE_DIR /usr/local/SFML)
if (SFML_FOUND)
    message("SFML LIBS: " ${SFML_LIBRARIES})
    message("SFML INCLUDES: " ${SFML_INCLUDE_DIR})

    target_link_libraries(client ${SFML_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
    target_link_libraries(launcher ${SFML_LIBRARIES})

    # includes dir libs
    include_directories(${SFML_INCLUDE_DIR})
else ()
    message("||||||||| SFML NOT FOUND ||||||||||")
endif (SFML_FOUND)

target_link_libraries(server ${SFML_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
# includes dir libs
include_directories(${SFML_INCLUDE_DIR})
# unit test
add_executable(engine_core_unit ${server_MODULES} ${core_unit_SOURCE_FILES})

add_executable(engine_physics_unit ${server_MODULES} ${physics_unit_SOURCE_FILES})

add_executable(engine_projectile_unit ${server_MODULES} ${projectile_unit_SOURCE_FILES})

add_executable(game_unit ${game_unit_SOURCE_FILES} ${server_MODULES} ${file_server})

add_executable(engine_graphics_unit ${client_MODULES} ${graphics_unit_SOURCE_FILES})

set_target_properties(engine_graphics_unit PROPERTIES COMPILE_DEFINITIONS GRAPHICS=1)

set(GOOGLE_TESTS_LIBS gtest gmock ${CMAKE_THREAD_LIBS_INIT})

if (MSVC)
    target_compile_options(engine_core_unit PRIVATE /std:c++14 /W4 /WX)
    target_compile_options(engine_physics_unit PRIVATE /std:c++14 /W4 /WX)
    target_compile_options(engine_projectile_unit PRIVATE /std:c++14 /W4 /WX)
    target_compile_options(game_unit PRIVATE /std:c++14 /W4 /WX)
    target_compile_options(engine_graphics_unit PRIVATE /std:c++14 /W4 /WX)

    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Ox")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Od")
    target_link_libraries(engine_core_unit ${GOOGLE_TESTS_LIBS})
    target_link_libraries(engine_physics_unit ${GOOGLE_TESTS_LIBS})
    target_link_libraries(engine_projectile_unit ${GOOGLE_TESTS_LIBS})
    target_link_libraries(game_unit ${GOOGLE_TESTS_LIBS})
    target_link_libraries(engine_graphics_unit ${GOOGLE_TESTS_LIBS} ${SFML_LIBRARIES})
    # VS 2017 removed tr1
    add_definitions(-DGTEST_HAS_TR1_TUPLE=0)
else ()
    target_compile_options(engine_core_unit PRIVATE -g -Wall -Wextra -Wpedantic -Wconversion -Wswitch-default -Wswitch-enum -Wunreachable-code -Wwrite-strings -Wcast-align -Wshadow -Wundef)
    target_compile_options(engine_physics_unit PRIVATE -g -Wall -Wextra -Wpedantic -Wconversion -Wswitch-default -Wswitch-enum -Wunreachable-code -Wwrite-strings -Wcast-align -Wshadow -Wundef)
    target_compile_options(engine_projectile_unit PRIVATE -g -Wall -Wextra -Wpedantic -Wconversion -Wswitch-default -Wswitch-enum -Wunreachable-code -Wwrite-strings -Wcast-align -Wshadow -Wundef)
    target_compile_options(game_unit PRIVATE -g -Wall -Wextra -Wpedantic -Wconversion -Wswitch-default -Wswitch-enum -Wunreachable-code -Wwrite-strings -Wcast-align -Wshadow -Wundef)
    target_compile_options(engine_graphics_unit PRIVATE -g -Wall -Wextra -Wpedantic -Wconversion -Wswitch-default -Wswitch-enum -Wunreachable-code -Wwrite-strings -Wcast-align -Wshadow -Wundef)
    if (COVERAGE)
        # Travis-CI
        target_compile_options(engine_core_unit PRIVATE --coverage)
        target_link_libraries(engine_core_unit PRIVATE --coverage ${GOOGLE_TESTS_LIBS})
        target_compile_options(engine_physics_unit PRIVATE --coverage)
        target_link_libraries(engine_physics_unit PRIVATE --coverage ${GOOGLE_TESTS_LIBS})
        target_compile_options(engine_projectile_unit PRIVATE --coverage)
        target_compile_options(game_unit PRIVATE --coverage)
        target_link_libraries(engine_projectile_unit PRIVATE --coverage ${GOOGLE_TESTS_LIBS})
        #target_compile_options(engine_graphics_unit PRIVATE --coverage)
        #target_link_libraries(engine_graphics_unit PRIVATE --coverage ${GOOGLE_TESTS_LIBS})
    else ()
        target_link_libraries(engine_core_unit ${GOOGLE_TESTS_LIBS})
        target_link_libraries(engine_physics_unit ${GOOGLE_TESTS_LIBS})
        target_link_libraries(engine_projectile_unit ${GOOGLE_TESTS_LIBS})
        target_link_libraries(game_unit ${GOOGLE_TESTS_LIBS})
        target_link_libraries(engine_graphics_unit ${GOOGLE_TESTS_LIBS} ${SFML_LIBRARIES})
    endif ()
endif ()

# Copy full directories
macro(resource_dirs dirs)
    foreach (dir ${dirs})
        # Replace / at the end of the path (copy dir content VS copy dir)
        string(REGEX REPLACE "/+$" "" dirclean "${dir}")
        message(STATUS "Copying resource ${dirclean}")
        file(COPY ${dirclean} DESTINATION ${CMAKE_BINARY_DIR})
    endforeach ()
endmacro()

resource_dirs(game/assets)
resource_dirs(launcher/assets)
