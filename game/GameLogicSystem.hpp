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

namespace game {
    class GameLogicSystem : public engine::core::ASystem {
        private:
            int _height;
            int _width;
        public:
            GameLogicSystem(int _height, int _width);

            void Update(float d) override;

            void Init(void) override;

            ~GameLogicSystem() override = default;

            void Update(engine::core::Scene *scene) override;

            void onNotify(engine::core::Message message) override;
    };
}


#endif //RTYPE_GAMELOGICSYSTEM_HPP
