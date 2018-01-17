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

namespace engine {
    namespace game {
        class GameLogicSystem : public core::ASystem {
        private:
          //  std::vector<ILogicRule *> _rules;

        public:
            void Update(float d) override;

            void Init(void) override;

            ~GameLogicSystem() override = default;

        private:
            void Update(core::Scene *scene);

        protected:
            void onNotify(core::Message message) override;
        };
    }
}


#endif //RTYPE_GAMELOGICSYSTEM_HPP