//
// Created by Hamza Hammouche on 13/01/2018.
//

#include <gtest/gtest.h>
#include <core/GameObject.hpp>
#include "physics/RigidBodyComponent.hpp"
#include "core/ID.hpp"

namespace engine {
    namespace physics {
        TEST(RigidBodyTest, moveTest) {
            core::Vector2d pos(20, 20);
            core::Vector2d velocity(2, 3);
            core::Vector2d size(30, 12);
            core::GameObject *game = new core::GameObject();
            game->pos = pos;
            RigidBodyComponent *component = new RigidBodyComponent();
            component->ownerRef = game;
            component->setVelocity(velocity);
            component->setSize(size);
            component->Init();

            component->move();
            ASSERT_EQ(22, component->ownerRef->pos.getX());
            ASSERT_EQ(23, component->ownerRef->pos.getY());
            component->move();
            ASSERT_EQ(24, component->ownerRef->pos.getX());
            ASSERT_EQ(26, component->ownerRef->pos.getY());
        }

        TEST(RigidBodyTest, updatePositionTest) {
            core::Vector2d pos(20, 20);
            core::Vector2d velocity(2, 3);
            core::Vector2d size(30, 12);
            core::GameObject *game = new core::GameObject();
            game->pos = pos;
            RigidBodyComponent *component = new RigidBodyComponent();
            component->ownerRef = game;
            component->setVelocity(velocity);
            component->setSize(size);
            component->Init();

            ASSERT_EQ(20, component->ownerRef->pos.getX());
            ASSERT_EQ(20, component->ownerRef->pos.getY());
            game->pos = core::Vector2d(12, 2);
            ASSERT_EQ(12, component->ownerRef->pos.getX());
            ASSERT_EQ(2, component->ownerRef->pos.getY());
            component->setVelocity(core::Vector2d(120, -23));
            ASSERT_EQ(120, component->getVelocity().getX());
            ASSERT_EQ(-23, component->getVelocity().getY());
            component->move();
            ASSERT_EQ(132, component->ownerRef->pos.getX());
            ASSERT_EQ(-21, component->ownerRef->pos.getY());
        }

        TEST(RigidBodyTest, updateBoxTest) {
            core::Vector2d pos(20, 18);
            core::Vector2d velocity(2, 3);
            core::Vector2d size(30, 12);
            core::GameObject *game = new core::GameObject();
            game->pos = pos;
            RigidBodyComponent *component = new RigidBodyComponent();
            component->ownerRef = game;
            component->setVelocity(velocity);
            component->setSize(size);
            component->Init();

            Box *box;
            box = component->getBox();
            ASSERT_EQ(18, box->getTop());
            ASSERT_EQ(20, box->getLeft());
            ASSERT_EQ(30, box->getBottom());
            ASSERT_EQ(50, box->getRight());
            game->pos = core::Vector2d(12, 2);
            component->setVelocity(core::Vector2d(120, -23));
            component->move();
            ASSERT_EQ(-21, component->ownerRef->pos.getY());
            ASSERT_EQ(132, component->ownerRef->pos.getX());
            ASSERT_EQ(-21, box->getTop());
            ASSERT_EQ(132, box->getLeft());
            ASSERT_EQ(-9, box->getBottom());
            ASSERT_EQ(162, box->getRight());
        }

        TEST(BoxTest, intersectTest) {
            core::Vector2d pos(20, 18);
            core::Vector2d velocity(2, 3);
            core::Vector2d size(30, 12);
            core::GameObject *game = new core::GameObject();
            game->pos = pos;
            RigidBodyComponent *component = new RigidBodyComponent();
            component->ownerRef = game;
            component->setVelocity(velocity);
            component->setSize(size);
            component->Init();
            core::Vector2d pos2(30, 18);
            core::Vector2d velocity2(2, 0);
            core::Vector2d size2(30, 12);
            core::GameObject *game2 = new core::GameObject();
            game2->pos = pos2;
            RigidBodyComponent *component2 = new RigidBodyComponent();
            component2->ownerRef = game2;
            component2->setVelocity(velocity2);
            component2->setSize(size2);
            component2->Init();

            for (int i = 0; i < 11; ++i) {
                component2->move();
                if (i < 10) {
                    ASSERT_TRUE(component->checkIntersect(component2));
                }
            }
            ASSERT_EQ(52, component2->ownerRef->pos.getX());
            ASSERT_EQ(50, component->getBox()->getRight());
            ASSERT_FALSE(component->checkIntersect(component2));
            component->move();
            ASSERT_TRUE(component->checkIntersect(component2));
        }

        TEST(BoxTest, intersectTestLeft) {
            core::Vector2d pos(20, 18);
            core::Vector2d velocity(-4, 3);
            core::Vector2d size(30, 12);
            core::GameObject *game = new core::GameObject();
            game->pos = pos;
            RigidBodyComponent *component = new RigidBodyComponent();
            component->ownerRef = game;
            component->setVelocity(velocity);
            component->setSize(size);
            component->Init();
            core::Vector2d pos2(30, 18);
            core::Vector2d velocity2(-4, 0);
            core::Vector2d size2(30, 12);
            core::GameObject *game2 = new core::GameObject();
            game2->pos = pos2;
            RigidBodyComponent *component2 = new RigidBodyComponent();
            component2->ownerRef = game2;
            component2->setVelocity(velocity2);
            component2->setSize(size2);
            component2->Init();

            for (int i = 0; i < 11; ++i) {
                component2->move();
                if (i < 10) {
                    ASSERT_TRUE(component->checkIntersect(component2));
                }
            }
            ASSERT_EQ(-14, component2->ownerRef->pos.getX());
            ASSERT_EQ(50, component->getBox()->getRight());
            ASSERT_FALSE(component->checkIntersect(component2));
            component->move();
            ASSERT_TRUE(component->checkIntersect(component2));
        }

        TEST(BoxTest, intersectTestTop) {
            core::Vector2d pos(20, 18);
            core::Vector2d velocity(0, -7);
            core::Vector2d size(30, 12);
            core::GameObject *game = new core::GameObject();
            game->pos = pos;
            RigidBodyComponent *component = new RigidBodyComponent();
            component->ownerRef = game;
            component->setVelocity(velocity);
            component->setSize(size);
            component->Init();
            core::Vector2d pos2(30, 18);
            core::Vector2d velocity2(0, -3);
            core::Vector2d size2(30, 12);
            core::GameObject *game2 = new core::GameObject();
            game2->pos = pos2;
            RigidBodyComponent *component2 = new RigidBodyComponent();
            component2->ownerRef = game2;
            component2->setVelocity(velocity2);
            component2->setSize(size2);
            component2->Init();

            for (int i = 0; i < 11; ++i) {
                component2->move();
                if (i < 4) {
                    ASSERT_TRUE(component->checkIntersect(component2));
                }
            }
            ASSERT_EQ(-15, component2->ownerRef->pos.getY());
            ASSERT_EQ(-3, component2->getBox()->getBottom());
            ASSERT_FALSE(component->checkIntersect(component2));
            for (int j = 0; j < 3; ++j) {
                component->move();
                if (j < 2) {
                    ASSERT_FALSE(component->checkIntersect(component2));
                }
            }
            ASSERT_TRUE(component->checkIntersect(component2));
        }
    }
}