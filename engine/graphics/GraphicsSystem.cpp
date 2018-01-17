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
    auto *eg = engine::core::Engine::GetInstance();

    //engine::graphics::SpriteSheet shipSheet = engine::graphics::SpriteSheet("assets/ship.png", 192, 16, 6, 1);
    engine::graphics::SpriteSheet shipSheet = engine::graphics::SpriteSheet("assets/mummy.png", 185, 225, 5, 5);

    // Create an animation based on the spritesheet
    engine::graphics::Animation *shipAnimIdle = new engine::graphics::Animation("idle", &shipSheet);
    shipAnimIdle->addFrame(0, 2); // image in the middle

    engine::graphics::Animation *shipAnimGoDown = new engine::graphics::Animation("down", &shipSheet);
    shipAnimGoDown->addFrame(0, 0);
    shipAnimGoDown->addFrame(0, 1);
    shipAnimGoDown->setLoop(true);
    shipAnimGoDown->setCurrentFrame(0);
    shipAnimGoDown->setReverse(true);

    engine::graphics::Animation *shipAnimGoUp = new engine::graphics::Animation("up", &shipSheet);
    shipAnimGoUp->addFrame(0, 3);
    shipAnimGoUp->addFrame(0, 4);
    shipAnimGoUp->setLoop(true);
    shipAnimGoUp->setCurrentFrame(0);

    engine::graphics::Animation *mommy = new engine::graphics::Animation("mommy", &shipSheet);
    mommy->addFrame(0, 0);
    mommy->addFrame(0, 1);
    mommy->addFrame(0, 2);
    mommy->addFrame(0, 3);
    mommy->addFrame(0, 4);

    mommy->addFrame(1, 0);
    mommy->addFrame(1, 1);
    mommy->addFrame(1, 2);
    mommy->addFrame(1, 3);
    mommy->addFrame(1, 4);

    mommy->addFrame(2, 0);
    mommy->addFrame(2, 1);
    mommy->addFrame(2, 2);
    mommy->addFrame(2, 3);
    mommy->addFrame(2, 4);

    mommy->addFrame(3, 0);
    mommy->addFrame(3, 1);
    mommy->addFrame(3, 2);

    mommy->setLoop(true);
    mommy->setPingPong(true);

    for (auto &sprite : *eg->getScene()->GetComponents<GraphicsComponent>(core::ComponentID::GRA_SPRITE)) {
        sprite->addAnimation(shipAnimIdle);
        sprite->addAnimation(shipAnimGoDown);
        sprite->addAnimation(shipAnimGoUp);
        sprite->addAnimation(mommy);

        sprite->play("mommy");
    }
}

void engine::graphics::GraphicSystem::Update(float dt) {
    auto *eg = engine::core::Engine::GetInstance();

    for (auto &gc : *eg->getScene()->GetComponents<GraphicsComponent>(core::ComponentID::GRA_SPRITE)) {
        eg->getWindow().draw(gc->getDrawable());

        gc->update(dt);

        //update position, should be in the game logic
        gc->getDrawable().setPosition(static_cast<float>(gc->getDrawable().getPosition().x + 0.1), gc->getDrawable().getPosition().y);
    }
}

engine::graphics::GraphicSystem::GraphicSystem() {

}

void engine::graphics::GraphicSystem::onNotify(engine::core::Message msg) {
    auto *eg = engine::core::Engine::GetInstance();
    for (auto sprite : *eg->getScene()->GetComponents<GraphicsComponent>(core::ComponentID::GRA_SPRITE)) {
        sprite->SendMessage(&msg);
    }
}

