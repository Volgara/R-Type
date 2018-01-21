//
//-----------------------------------------------------------------------------
//Filename:    GameLogicSystem.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/16/18.
//-----------------------------------------------------------------------------
//

#ifndef GAME_GAMELOGICSYSTEM_HPP
#define GAME_GAMELOGICSYSTEM_HPP

#include "PlayerComponent.hpp"
#include "Message.hpp"

namespace game {
    class GameLogicSystem : public engine::core::ASystem {
        private:
            int _height;
            int _width;
            float _currentDt;
            std::map<game::PlayerActionMessage::Action, engine::core::Vector2d> _map;
        private:
            void checkColision(engine::core::GameObject *, engine::core::GameObject *);
            void addDamageToPlayer(game::PlayerComponent *, engine::projectile::BulletComponent *);
            void playAction(engine::core::GameObject *, game::PlayerActionMessage::Action action);
        public:
            GameLogicSystem(int _height, int _width);

            void Update(float d) override;

            void Init() override;

            ~GameLogicSystem() override = default;

            void onNotify(engine::core::Message message) override;
    };
}


#endif //GAME_GAMELOGICSYSTEM_HPP
