//
// Created by Hamza Hammouche on 21/01/2018.
//

#ifndef RTYPE_GAMECLIENT_HPP
#define RTYPE_GAMECLIENT_HPP

#include <network/Socket.hpp>

#include <core/Engine.hpp>
#include <core/Scene.hpp>
#include <input/InputSystem.hpp>
#include <input/InputComponent.hpp>
#include <graphics/GraphicsSystem.hpp>
#include <physics/PhysicsSystem.hpp>
#include "Message.hpp"
#include "GameLogicClientSystem.hpp"

namespace game {
    class GameClient {
    private:
        engine::Network::Socket *initSocketSystem();

        void createPlayer(engine::core::Scene *, engine::input::InputSystem *);
    public:
        GameClient();

        virtual ~GameClient();

        void startGamePlayer();
    };
}


#endif //RTYPE_GAMECLIENT_HPP
