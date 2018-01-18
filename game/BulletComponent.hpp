//
// Created by macdoy on 18/01/18.
//

#ifndef RTYPE_BULLETCOMPONENT_HPP
#define RTYPE_BULLETCOMPONENT_HPP

#include "../engine/core/Component.hpp"
#include "Type.hpp"

namespace game {
    class BulletComponent : public engine::core::Component {
    private:
        Type _type;
    public:
        BulletComponent();

        ~BulletComponent();

        void SendMessage(engine::core::Message *message) override;

        void Update(float dt) override;

        void Init(void) override;

        void ShutDown(void) override;
    };
}

#endif //RTYPE_BULLETCOMPONENT_HPP
