//
//-----------------------------------------------------------------------------
//Filename:    GameObjectManagerUnit.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/10/18.
//-----------------------------------------------------------------------------
//

#include <gtest/gtest.h>
#include "core/GameObjectManager.hpp"

using namespace engine::core;

TEST(GameObjectManagerTest, Instance) {
    auto *gm = new GameObjectManager();
    ASSERT_NE(gm, nullptr);
}