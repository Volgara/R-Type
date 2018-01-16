//
// Created by Hamza Hammouche on 14/01/2018.
//

#ifndef RTYPE_PHYSICSSYSTEM_HPP
#define RTYPE_PHYSICSSYSTEM_HPP

#include <vector>
#include <map>
#include "core/ASystem.hpp"
#include "RigidBodyComponent.hpp"
#define CELL_SIZE 20

namespace engine {
    namespace physics {
        class PhysicsSystem : public core::ASystem {
        private:
            std::map<int, std::vector<RigidBodyComponent *>> _listState;
            std::vector<RigidBodyComponent *> _listDebug;
            std::vector<std::pair<RigidBodyComponent *, RigidBodyComponent *>> _currentCollision;
            int _width;
            int _height;
            int _debugNbAdd;
            int _debugNbCollision;
            int _debugNb;
            int _debugCheck;

            bool addCollision(RigidBodyComponent *, RigidBodyComponent *);
            void addComponentInMap(RigidBodyComponent *);
            void createHasheMap();
            void clearMap();
            void checkCellColision(std::vector<RigidBodyComponent *>);
        public:
            PhysicsSystem(int width, int height);

            void Update(float dt) override;

            void Init() override;

            void SendMessage(Message *msg) override;

            void debugAddComponent(RigidBodyComponent *);

            int get_debugNbAdd() const;

            int get_debugNbColision() const;

            int get_debugNb() const;

            int get_debugCheck() const;
        };
    }
}


#endif //RTYPE_PHYSICSSYSTEM_HPP
