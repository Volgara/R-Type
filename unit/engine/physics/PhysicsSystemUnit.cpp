//
// Created by Hamza Hammouche on 15/01/2018.
//

#include <gtest/gtest.h>
#include "core/Engine.hpp"
#include "core/Scene.hpp"
#include <core/GameObject.hpp>
#include "physics/PhysicsSystem.hpp"

namespace engine {
    namespace physics {
        TEST(PhysicsSystemTest, InitTest) {
            PhysicsSystem *physicsSystem = new PhysicsSystem(800, 600);

            core::Vector2d size(10, 10);

            for (int i = 0; i < 100; ++i) {
                core::Vector2d pos(i * 2, i * 2);

                core::GameObject *game = new core::GameObject();
                game->pos = pos;
                RigidBodyComponent *comp = new RigidBodyComponent();
                comp->ownerRef = game;
                comp->setSize(size);
                comp->setVelocity(core::Vector2d(2, 2));
                comp->Init();
                physicsSystem->debugAddComponent(comp);
            }
            std::cout << "Before update" << std::endl;
            physicsSystem->Update(-1);
            std::cout << "After update" << std::endl;
            ASSERT_EQ(460, physicsSystem->get_debugNbColision());
            std::cout << "Before update2" << std::endl;
            ASSERT_EQ(1155, physicsSystem->get_debugCheck());
            std::cout << "Before update3" << std::endl;
        }
    }
}