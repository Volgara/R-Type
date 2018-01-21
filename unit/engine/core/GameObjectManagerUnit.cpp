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
#include "core/GameObject.hpp"
#include "core/Scene.hpp"

using namespace engine::core;

TEST(EngineInstance, CreateInstance) {
    auto *ge = Engine::GetInstance();
    ASSERT_NE(ge, nullptr);
}

TEST(EngineInstance, InitInstance) {
    auto *gameEngine = Engine::GetInstance();

    gameEngine->Init();
}

GameObject *g_empty = nullptr;

TEST(Scene, AddScene) {
    auto *gameEngine = Engine::GetInstance();
    gameEngine->setScene(new Scene());
    ASSERT_NE(gameEngine->getScene(), nullptr);
}

TEST(Scene, AddObject) {
    auto *gameEngine = Engine::GetInstance();
    auto *scene = gameEngine->getScene();
    ASSERT_NE(gameEngine->getScene(), nullptr);
    g_empty = gameEngine->getScene()->CreateEmptyObject();
    Component *component = scene->CreateComponent(PHY_RIGIDBODY);
    ASSERT_NE(g_empty, nullptr);
    ASSERT_NE(component, nullptr);
    g_empty->attachComponent(component);
    ASSERT_EQ(component, g_empty->GetComponent(PHY_RIGIDBODY));
}

// TODO : Remove Object test
//TEST(Scene, RemoveObject) {
//    auto *gameEngine = Engine::GetInstance();
//    auto *scene = gameEngine->getScene();
//    scene->RemoveGameObject(g_empty);
//    scene->cleanUp();
//    ASSERT_EQ(scene->GetComponents<Component>(PHY_RIGIDBODY)->size(), 0);
//}
//
//TEST(Scene, AddObject2) {
//    auto *gameEngine = Engine::GetInstance();
//    auto *scene = gameEngine->getScene();
//
//    ASSERT_NE(gameEngine->getScene(), nullptr);
//    g_empty = gameEngine->getScene()->CreateEmptyObject();
//    Component *component = scene->CreateComponent(PHY_RIGIDBODY);
//    ASSERT_NE(g_empty, nullptr);
//    ASSERT_NE(component, nullptr);
//    g_empty->attachComponent(component);
//    ASSERT_EQ(component, g_empty->GetComponent(PHY_RIGIDBODY));
//}
//
//TEST(Scene, RemoveObject2) {
//    auto *gameEngine = Engine::GetInstance();
//    auto *scene = gameEngine->getScene();
//    scene->RemoveGameObject(g_empty->guid);
//    scene->cleanUp();
//    ASSERT_EQ(scene->GetComponents<Component>(PHY_RIGIDBODY)->size(), 0);
//}

