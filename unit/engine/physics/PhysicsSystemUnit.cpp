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
            physicsSystem->Update(-1);
            ASSERT_EQ(485, physicsSystem->get_debugNbColision());
            ASSERT_EQ(1200, physicsSystem->get_debugCheck());
        }
        TEST(MessageBusTest, SimpleMessage) {
            std::cout << "I'm in test" << std::endl;
            PhysicsSystem *physicsSystem = new PhysicsSystem(800, 600);
            std::cout << "I create system" << std::endl;
            auto *ge = engine::core::Engine::GetInstance();

            std::cout << "I add instance" << std::endl;
            ge->addSystem("physics", physicsSystem);
            std::cout << "I add system" << std::endl;
            ge->Init();
            std::cout << "I init" << std::endl;
            ge->getScene()->CreateComponent(core::ComponentID::PHY_RIGIDBODY);
            std::cout << "I add component" << std::endl;
            ge->MainLoop();
            std::cout << "I run mainLoop" << std::endl;
            ASSERT_EQ(0, physicsSystem->get_debugNbColision());
            std::cout << "I add test debug" << std::endl;
        }
    }
}