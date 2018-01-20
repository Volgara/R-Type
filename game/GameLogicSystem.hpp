//
//-----------------------------------------------------------------------------
//Filename:    GameLogicSystem.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/16/18.
//-----------------------------------------------------------------------------
//

#ifndef RTYPE_GAMELOGICSYSTEM_HPP
#define RTYPE_GAMELOGICSYSTEM_HPP


#include <core/ASystem.hpp>
#include <core/Scene.hpp>
#include <core/Engine.hpp>
#include <core/GameObject.hpp>
#include "PlayerComponent.hpp"
#include <projectile/BulletComponent.hpp>
namespace game {
    class GameLogicSystem : public engine::core::ASystem {
        private:
            int _height;
            int _width;
            float _currentDt;
            std::map<engine::core::Direction, engine::core::Vector2d> _map;
        private:
            void checkColision(engine::core::GameObject *, engine::core::GameObject *);
            void addDamageToPlayer(PlayerComponent *, engine::projectile::BulletComponent *);
            void movePlayer(engine::core::GameObject *, engine::core::Direction dir);
        public:
            GameLogicSystem(int _height, int _width);

            void Update(float d) override;

            void Init() override;

            ~GameLogicSystem() override = default;

            void onNotify(engine::core::Message message) override;
    };
}


#endif //RTYPE_GAMELOGICSYSTEM_HPP
