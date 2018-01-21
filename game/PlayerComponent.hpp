//
// Created by Hamza Hammouche on 20/01/2018.
//

#ifndef GAME_PLAYER_COMPONENT_HPP
# define GAME_PLAYER_COMPONENT_HPP

#include <core/Engine.hpp>
#include "../engine/core/Component.hpp"
#include "SpaceShip.hpp"

namespace game {
    class PlayerComponent : public engine::core::Component, public SpaceShip {
    public:
        PlayerComponent();

        void SendMessage(engine::core::Message *message) override ;

        void Update(float dt) override;

        void Init() override;

        void ShutDown() override;
    };
}


#endif //GAME_PLAYER_COMPONENT_HPP
