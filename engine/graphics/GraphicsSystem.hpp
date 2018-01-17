//
//-----------------------------------------------------------------------------
//Filename:    GraphicSystem.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/15/18.
//-----------------------------------------------------------------------------
//

#ifndef RTYPE_GRAPHICSYSTEM_HPP
#define RTYPE_GRAPHICSYSTEM_HPP


#include <core/ASystem.hpp>

namespace engine {
    namespace graphics {
        class GraphicSystem : public engine::core::ASystem {
        public:
            void Init(void) override;

            void SendMessage(engine::core::Message *msg) override;

            void Update(float dt) override;

        protected:
            void onNotify(core::Message message) override;
        };
    }
}

#endif //RTYPE_GRAPHICSYSTEM_HPP
