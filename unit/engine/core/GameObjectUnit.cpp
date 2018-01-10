//
//-----------------------------------------------------------------------------
//Filename:    GameObjectUnit.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/10/18.
//-----------------------------------------------------------------------------
//

#include <gtest/gtest.h>
#include "core/GameObject.hpp"

using namespace engine::core;

TEST(GameObjectTest, Instance) {
    auto *gameObject = new GameObject();

    ASSERT_NE(gameObject, nullptr);
}

TEST(GameObjectTest, Id) {
    auto *gameObject = new GameObject();

    gameObject->setId(1);
    ASSERT_EQ(gameObject->getId(), 1);
}