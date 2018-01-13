//
// Created by Hamza Hammouche on 13/01/2018.
//

#include <gtest/gtest.h>
#include "physics/RigidBodyComponent.hpp"

namespace engine {
    namespace physics {
        TEST(RigidBodyTest, moveTest) {
            Vector2d pos(20, 20);
            Vector2d velocity(2, 3);
            Vector2d size(30, 12);
            RigidBodyComponent *component = new RigidBodyComponent(pos, velocity, size);

            component->move();
            ASSERT_EQ(22, component->getPosition().getX());
            ASSERT_EQ(23, component->getPosition().getY());
            component->move();
            ASSERT_EQ(24, component->getPosition().getX());
            ASSERT_EQ(26, component->getPosition().getY());
        }

        TEST(RigidBodyTest, updatePositionTest) {
            Vector2d pos(20, 20);
            Vector2d velocity(2, 3);
            Vector2d size(30, 12);
            RigidBodyComponent *component = new RigidBodyComponent(pos, velocity, size);

            ASSERT_EQ(20, component->getPosition().getX());
            ASSERT_EQ(20, component->getPosition().getY());
            component->setPosition(Vector2d(12, 2));
            ASSERT_EQ(12, component->getPosition().getX());
            ASSERT_EQ(2, component->getPosition().getY());
            component->setVelocity(Vector2d(120, -23));
            ASSERT_EQ(120, component->getVelocity().getX());
            ASSERT_EQ(-23, component->getVelocity().getY());
            component->move();
            ASSERT_EQ(142, component->getPosition().getX());
            ASSERT_EQ(-21, component->getPosition().getY());
        }

        TEST(RigidBodyTest, updateBoxTest) {
            Vector2d pos(20, 18);
            Vector2d velocity(2, 3);
            Vector2d size(30, 12);
            RigidBodyComponent *component = new RigidBodyComponent(pos, velocity, size);

            Box *box;
            box = component->getBox();
            ASSERT_EQ(18, box->getTop());
            ASSERT_EQ(20, box->getLeft());
            ASSERT_EQ(30, box->getBottom());
            ASSERT_EQ(50, box->getRight());
            component->setPosition(Vector2d(12, 2));
            component->setVelocity(Vector2d(120, -23));
            component->move();
            ASSERT_EQ(-21, box->getTop());
            ASSERT_EQ(142, box->getLeft());
            ASSERT_EQ(-9, box->getBottom());
            ASSERT_EQ(172, box->getRight());
        }
    }
}