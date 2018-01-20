//
// Created by Hamza Hammouche on 14/01/2018.
//

#ifndef RTYPE_PHYSICSSYSTEM_HPP
#define RTYPE_PHYSICSSYSTEM_HPP

#include <vector>
#include <map>
#include "core/ASystem.hpp"
#include "core/Engine.hpp"
#include "core/Message.hpp"
#include "RigidBodyComponent.hpp"
#define CELL_SIZE 20

namespace engine {
    namespace physics {
        class PhysicsSystem : public core::ASystem {
        private:
            std::map<int, std::vector<RigidBodyComponent *>> _listState;
            std::vector<std::pair<RigidBodyComponent *, RigidBodyComponent *>> _currentCollision;
            std::vector<RigidBodyComponent *> _listDebug;
            int _wCell;
            int _sizeTab;
        private:
            int _debugNbCollision;
            int _debugCheck;

        private:
            bool addCollision(RigidBodyComponent *, RigidBodyComponent *);
            void addComponentInMap(RigidBodyComponent *);
            void createHasheMap();
            void clearMap();
            void checkCellCollision(std::vector<RigidBodyComponent *>);
            void createHasheMapDebug();

        protected:
            void onNotify(core::Message message) override;

        public:
            PhysicsSystem(int width, int height);

            void Update(float dt) override;

            void Init() override;
        public:

            void debugAddComponent(RigidBodyComponent *);

            int get_debugNbColision() const;

            int get_debugCheck() const;
        };
    }
}


#endif //RTYPE_PHYSICSSYSTEM_HPP
