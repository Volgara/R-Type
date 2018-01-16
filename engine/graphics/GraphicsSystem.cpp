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

    engine::graphics::SpriteSheet shipSheet = engine::graphics::SpriteSheet("assets/ship.png", 192, 16, 6, 1);

    // Create an animation based on the spritesheet
    /*engine::graphics::Animation shipAnimIdle = engine::graphics::Animation("idle", &shipSheet);
    shipAnimIdle.addFrame(0, 2); // image in the middle*/

    /*    sf::Sprite s;
    s.setTexture(shipAnimIdle.getFrames()[0]);*/

    engine::graphics::Animation *shipAnimGoDown = new engine::graphics::Animation("down", &shipSheet);
    shipAnimGoDown->addFrame(0, 1);
    shipAnimGoDown->addFrame(0, 0);
    shipAnimGoDown->setLoop(true);
    shipAnimGoDown->setCurrentFrame(0);
    shipAnimGoDown->setReverse(true);

    //eg->getWindow().draw(shipAnimGoDown.getFrames()[1]);

    /*engine::graphics::Animation shipAnimGoUp = engine::graphics::Animation("up", shipSheet);
    shipAnimGoUp.addFrame(0, 2);
    shipAnimGoUp.addFrame(0, 3);
    shipAnimGoDown.setLoop(true);
    shipAnimGoDown.setCurrentFrame(0);*/

    for (auto &sprite : *eg->getScene()->GetComponents<GraphicsComponent>(core::ComponentID::GRA_SPRITE)) {
        //sprite->addAnimation(shipAnimIdle);
        sprite->addAnimation(shipAnimGoDown);
        //sprite->addAnimation(shipAnimGoUp);

        sprite->play("down");
    }
}

void engine::graphics::GraphicSystem::SendMessage(Message *msg) {

}

void engine::graphics::GraphicSystem::Update(float) {
    auto *eg = engine::core::Engine::GetInstance();

    for (auto &gc : *eg->getScene()->GetComponents<GraphicsComponent>(core::ComponentID::GRA_SPRITE)) {

/*        sf::Sprite s;
        s.setTexture(gc->getAnimations()[0].getSpriteSheet()->getTexture());
        eg->getWindow().draw(s);*/



        //gc->setPosition(20, 20);

        //eg->getWindow().draw(gc->getDrawable());
        gc->update();
    }
}

