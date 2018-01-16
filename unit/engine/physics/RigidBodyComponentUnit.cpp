//
// Created by Hamza Hammouche on 13/01/2018.
//

#include <gtest/gtest.h>
#include "physics/RigidBodyComponent.hpp"
#include "core/ID.hpp"

namespace engine {
    namespace physics {
        TEST(RigidBodyTest, moveTest) {
            core::Vector2d pos(20, 20);
            core::Vector2d velocity(2, 3);
            core::Vector2d size(30, 12);
            RigidBodyComponent *component = new RigidBodyComponent(engine::core::ComponentID::PHY_RIGIDBODY);
            component->setPosition(pos);
            component->setVelocity(velocity);
            component->setSize(size);

            component->move();
            ASSERT_EQ(22, component->getPosition().getX());
            ASSERT_EQ(23, component->getPosition().getY());
            component->move();
            ASSERT_EQ(24, component->getPosition().getX());
            ASSERT_EQ(26, component->getPosition().getY());
        }

        TEST(RigidBodyTest, updatePositionTest) {
            core::Vector2d pos(20, 20);
            core::Vector2d velocity(2, 3);
            core::Vector2d size(30, 12);
            RigidBodyComponent *component = new RigidBodyComponent(engine::core::ComponentID::PHY_RIGIDBODY);
            component->setPosition(pos);
            component->setVelocity(velocity);
            component->setSize(size);

            ASSERT_EQ(20, component->getPosition().getX());
            ASSERT_EQ(20, component->getPosition().getY());
            component->setPosition(core::Vector2d(12, 2));
            ASSERT_EQ(12, component->getPosition().getX());
            ASSERT_EQ(2, component->getPosition().getY());
            component->setVelocity(core::Vector2d(120, -23));
            ASSERT_EQ(120, component->getVelocity().getX());
            ASSERT_EQ(-23, component->getVelocity().getY());
            component->move();
            ASSERT_EQ(132, component->getPosition().getX());
            ASSERT_EQ(-21, component->getPosition().getY());
        }

        TEST(RigidBodyTest, updateBoxTest) {
            core::Vector2d pos(20, 18);
            core::Vector2d velocity(2, 3);
            core::Vector2d size(30, 12);
            RigidBodyComponent *component = new RigidBodyComponent(engine::core::ComponentID::PHY_RIGIDBODY);
            component->setPosition(pos);
            component->setVelocity(velocity);
            component->setSize(size);

            Box *box;
            box = component->getBox();
            ASSERT_EQ(18, box->getTop());
            ASSERT_EQ(20, box->getLeft());
            ASSERT_EQ(30, box->getBottom());
            ASSERT_EQ(50, box->getRight());
            component->setPosition(core::Vector2d(12, 2));
            component->setVelocity(core::Vector2d(120, -23));
            component->move();
            ASSERT_EQ(-21, component->getPosition().getY());
            ASSERT_EQ(132, component->getPosition().getX());
            ASSERT_EQ(-21, box->getTop());
            ASSERT_EQ(132, box->getLeft());
            ASSERT_EQ(-9, box->getBottom());
            ASSERT_EQ(162, box->getRight());
        }

        TEST(BoxTest, intersectTest) {
            core::Vector2d pos(20, 18);
            core::Vector2d velocity(2, 3);
            core::Vector2d size(30, 12);
            RigidBodyComponent *component = new RigidBodyComponent(engine::core::ComponentID::PHY_RIGIDBODY);
            component->setPosition(pos);
            component->setVelocity(velocity);
            component->setSize(size);
            core::Vector2d pos2(30, 18);
            core::Vector2d velocity2(2, 0);
            core::Vector2d size2(30, 12);
            RigidBodyComponent *component2 = new RigidBodyComponent(engine::core::ComponentID::PHY_RIGIDBODY);
            component2->setPosition(pos2);
            component2->setVelocity(velocity2);
            component2->setSize(size2);

            for (int i = 0; i < 11; ++i) {
                component2->move();
                if (i < 10)
                    ASSERT_TRUE(component->checkIntersect(component2));
            }
            ASSERT_EQ(52, component2->getPosition().getX());
            ASSERT_EQ(50, component->getBox()->getRight());
            ASSERT_FALSE(component->checkIntersect(component2));
            component->move();
            ASSERT_TRUE(component->checkIntersect(component2));
        }

        TEST(BoxTest, intersectTestLeft) {
            core::Vector2d pos(20, 18);
            core::Vector2d velocity(-4, 3);
            core::Vector2d size(30, 12);
            RigidBodyComponent *component = new RigidBodyComponent(engine::core::ComponentID::PHY_RIGIDBODY);
            component->setPosition(pos);
            component->setVelocity(velocity);
            component->setSize(size);
            core::Vector2d pos2(30, 18);
            core::Vector2d velocity2(-4, 0);
            core::Vector2d size2(30, 12);
            RigidBodyComponent *component2 = new RigidBodyComponent(engine::core::ComponentID::PHY_RIGIDBODY);
            component2->setPosition(pos2);
            component2->setVelocity(velocity2);
            component2->setSize(size2);

            for (int i = 0; i < 11; ++i) {
                component2->move();
                if (i < 10)
                    ASSERT_TRUE(component->checkIntersect(component2));
            }
            ASSERT_EQ(-14, component2->getPosition().getX());
            ASSERT_EQ(50, component->getBox()->getRight());
            ASSERT_FALSE(component->checkIntersect(component2));
            component->move();
            ASSERT_TRUE(component->checkIntersect(component2));
        }

        TEST(BoxTest, intersectTestTop) {
            core::Vector2d pos(20, 18);
            core::Vector2d velocity(0, -7);
            core::Vector2d size(30, 12);
            RigidBodyComponent *component = new RigidBodyComponent(engine::core::ComponentID::PHY_RIGIDBODY);
            component->setPosition(pos);
            component->setVelocity(velocity);
            component->setSize(size);
            core::Vector2d pos2(30, 18);
            core::Vector2d velocity2(0, -3);
            core::Vector2d size2(30, 12);
            RigidBodyComponent *component2 = new RigidBodyComponent(engine::core::ComponentID::PHY_RIGIDBODY);
            component2->setPosition(pos2);
            component2->setVelocity(velocity2);
            component2->setSize(size2);

            for (int i = 0; i < 11; ++i) {
                component2->move();
                if (i < 4)
                    ASSERT_TRUE(component->checkIntersect(component2));
            }
            ASSERT_EQ(-15, component2->getPosition().getY());
            ASSERT_EQ(-3, component2->getBox()->getBottom());
            ASSERT_FALSE(component->checkIntersect(component2));
            for (int j = 0; j < 3; ++j) {
                component->move();
                if (j < 2)
                    ASSERT_FALSE(component->checkIntersect(component2));
            }
            ASSERT_TRUE(component->checkIntersect(component2));
        }
    }
}