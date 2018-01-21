//
//-----------------------------------------------------------------------------
//Filename:    GraphicSystem.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/15/18.
//-----------------------------------------------------------------------------
//

#include <core/Engine.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include <core/GameObject.hpp>
#include "GraphicsSystem.hpp"
#include "GraphicsComponent.hpp"
#include "../physics/RigidBodyComponent.hpp"

/**
 * Init all texture
 */
void engine::graphics::GraphicSystem::Init(void) {
}

void engine::graphics::GraphicSystem::Update(float dt) {
    auto *eg = engine::core::Engine::GetInstance();

    for (auto &gc : *eg->getScene()->GetComponents<GraphicsComponent>(core::ComponentID::GRA_SPRITE)) {
        eg->getWindow().draw(gc->getDrawable());

        gc->update(dt);
    }
}

engine::graphics::GraphicSystem::GraphicSystem() {

}

void engine::graphics::GraphicSystem::onNotify(engine::core::Message *msg) {
    auto      *eg = engine::core::Engine::GetInstance();
    for (auto sprite : *eg->getScene()->GetComponents<GraphicsComponent>(core::ComponentID::GRA_SPRITE)) {
        sprite->SendMessage(msg);
    }
}

