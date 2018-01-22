//
//-----------------------------------------------------------------------------
//Filename:    main_client.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/9/18.
//-----------------------------------------------------------------------------
//

#include "../game/GameClient.hpp"

int main(int argc, char *argv[]) {
    std::cout << "argc = " << argc << std::endl;
    for(int i = 0; i < argc; i++)
        std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
    game::GameClient *gameClient = new game::GameClient(4243, "127.0.0.1");
    gameClient->startGamePlayer();
    return (0);
}