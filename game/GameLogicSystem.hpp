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

namespace game {
    class GameLogicSystem : public engine::core::ASystem {
        private:
            int _height;
            int _width;
            float _currentDt;
            std::map<engine::core::Direction, engine::core::Vector2d> _map;
        private:
            void checkColision(engine::core::GameObject *, engine::core::GameObject *);
            void addDamageToPlayer(game::PlayerComponent *, engine::projectile::BulletComponent *);
            void movePlayer(engine::core::GameObject *, engine::core::Direction dir);
        public:
            GameLogicSystem(int _height, int _width);

            void Update(float d) override;

            void Init() override;

            ~GameLogicSystem() override = default;

            void onNotify(engine::core::Message message) override;
    };
}


#endif //GAME_GAMELOGICSYSTEM_HPP
