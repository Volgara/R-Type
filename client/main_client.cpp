//
//-----------------------------------------------------------------------------
//Filename:    main_client.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/9/18.
//-----------------------------------------------------------------------------
//

/*#include <core/Engine.hpp>
#include <core/Scene.hpp>
#include <input/InputSystem.hpp>
#include <input/InputComponent.hpp>
#include <graphics/GraphicsSystem.hpp>
#include <iostream>
#include "../game/Message.hpp"*/
#include "../game/GameClient.hpp"
/*void onKeyPressed(sf::Event &event) {
    if (event.KeyPressed && event.key.code == sf::Keyboard::Escape) {
        auto *ge = engine::core::Engine::GetInstance();
        ge->Shutdown();
    }
}*/

int main(int argc, char *argv[]) {
    std::cout << "argc = " << argc << std::endl;
    for(int i = 0; i < argc; i++)
        std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
    game::GameClient *gameClient = new game::GameClient();
    gameClient->startGamePlayer();
    return (0);
}