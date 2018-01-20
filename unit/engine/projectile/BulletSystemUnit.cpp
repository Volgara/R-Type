//
// Created by Hamza Hammouche on 20/01/2018.
//

#include <gtest/gtest.h>
#include "core/Engine.hpp"
#include "core/Scene.hpp"
#include <core/GameObject.hpp>
#include "projectile/BulletSystem.hpp"


namespace engine {
    namespace projectile {
        TEST(BulletSystemTest, BasicTest) {
            BulletSystem *b = new BulletSystem(800, 800);
            auto *eg = core::Engine::GetInstance();

            eg->addSystem("BulletSystem", b);
            eg->Init();
            core::GameObject *game = eg->getScene()->CreateEmptyObject();
            core::Vector2d pos(10, 10);
            game->pos = pos;
            BulletComponent *bullet1 = static_cast<BulletComponent *>(eg->getScene()->CreateComponent(core::ComponentID::PRO_BULLET));
            physics::RigidBodyComponent *comp2 = static_cast<physics::RigidBodyComponent *>(eg->getScene()->CreateComponent(core::ComponentID::PHY_RIGIDBODY));
            game->attachComponent(bullet1);
            game->attachComponent(comp2);
            comp2->setVelocity(core::Vector2d(1, 3));
            comp2->setSize(core::Vector2d(10, 10));
            core::GameObject *game2 = eg->getScene()->CreateEmptyObject();
            game2->pos = pos;
            BulletComponent *bullet2 = static_cast<BulletComponent *>(eg->getScene()->CreateComponent(core::ComponentID::PRO_BULLET));
            game2->attachComponent(bullet2);
            comp2->Init();
            bullet1->Init();
            physics::RigidBodyComponent *comp = static_cast<physics::RigidBodyComponent *>(eg->getScene()->CreateComponent(core::ComponentID::PHY_RIGIDBODY));
            game2->attachComponent(comp);
            comp->setVelocity(core::Vector2d(1, 3));
            comp->setSize(core::Vector2d(10, 10));
            comp->Init();
            bullet2->Init();
            b->Update(1);
            ASSERT_EQ(13, game->pos.getY());
            ASSERT_EQ(11, game2->pos.getX());
            ASSERT_EQ(11, game->pos.getX());
            ASSERT_EQ(13, game2->pos.getY());
        }
    }
}