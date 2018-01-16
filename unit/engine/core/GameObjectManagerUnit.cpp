//
//-----------------------------------------------------------------------------
//Filename:    GameObjectManagerUnit.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/10/18.
//-----------------------------------------------------------------------------
//

#include <gtest/gtest.h>
#include "core/Engine.hpp"

using namespace engine::core;

TEST(GameObjectManagerTest, Instance) {
    auto *ge = Engine::GetInstance();
    ASSERT_NE(ge, nullptr);
}