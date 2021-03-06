//
// Created by macdoy on 21/01/18.
//

#ifndef GAME_GAME_LOGIC_CLIENT_SYSTEM_HPP
#define GAME_GAME_LOGIC_CLIENT_SYSTEM_HPP

#include <core/ASystem.hpp>
#include <core/Scene.hpp>
#include <core/Engine.hpp>
#include <core/GameObject.hpp>
#include "PlayerComponent.hpp"
#include <graphics/GraphicsComponent.hpp>
#include <projectile/BulletComponent.hpp>
#include "Message.hpp"

namespace game {
    class GameLogicClientSystem : public engine::core::ASystem {
    private:
        float _currentDt;
        int _width;
        int _height;
        int _shoot = 0;
    private:
        void playAction(engine::core::GameObject *, game::PlayerActionMessage::Action action);

        void move(engine::core::GameObject *, int x, int y);

        void playerShoot(engine::core::GameObject *);
    public:
        GameLogicClientSystem(int, int);

        void Update(float d) override;

        void Init() override;

        ~GameLogicClientSystem() override = default;

        void onNotify(engine::core::Message *message) override;
    };
}

class GameLogicServerSystem {

};


#endif //GAME_GAME_LOGIC_CLIENT_SYSTEM_HPP
