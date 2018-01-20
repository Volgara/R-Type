//
// Created by Hamza Hammouche on 20/01/2018.
//

#ifndef RTYPE_PLAYER_HPP
#define RTYPE_PLAYER_HPP

#include <core/Component.hpp>
#include <core/GameObject.hpp>
#include <physics/RigidBodyComponent.hpp>
#include "SpaceShip.hpp"

namespace game {
    class Player : public engine::core::Component, public SpaceShip {
    private:
        int _life;
    public:
        Player();

        void SendMessage(engine::core::Message *message) override;

        void Update(float dt) override;

        void Init() override;

        void ShutDown() override;
    };
}


#endif //RTYPE_PLAYER_HPP
