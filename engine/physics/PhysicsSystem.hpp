//
// Created by Hamza Hammouche on 14/01/2018.
//

#ifndef RTYPE_PHYSICSSYSTEM_HPP
#define RTYPE_PHYSICSSYSTEM_HPP

#include <vector>
#include <map>
#include "core/ASystem.hpp"
#include "core/Engine.hpp"
#include "RigidBodyComponent.hpp"
#define CELL_SIZE 20

namespace engine {
    namespace physics {
        class PhysicsSystem : public core::ASystem {
        private:
            std::map<int, std::vector<RigidBodyComponent *>> _listState;
            std::vector<std::pair<RigidBodyComponent *, RigidBodyComponent *>> _currentCollision;
            std::vector<RigidBodyComponent *> _listDebug;
            int _width;
        private:
            int _debugNbAdd;
            int _debugNbCollision;
            int _debugNb;
            int _debugCheck;

        private:
            bool addCollision(RigidBodyComponent *, RigidBodyComponent *);
            void addComponentInMap(RigidBodyComponent *);
            void createHasheMap();
            void clearMap();
            void checkCellColision(std::vector<RigidBodyComponent *>);
            void createHasheMapDebug();
        public:
            PhysicsSystem(int width, int height);

            void Update(float dt) override;

            void Init() override;

            void SendMessage(engine::core::Message *msg) override;

        public:

            void debugAddComponent(RigidBodyComponent *);

            int get_debugNbAdd() const;

            int get_debugNbColision() const;

            int get_debugNb() const;

            int get_debugCheck() const;
        };
    }
}


#endif //RTYPE_PHYSICSSYSTEM_HPP
