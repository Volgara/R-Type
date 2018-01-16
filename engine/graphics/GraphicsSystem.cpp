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
#include "GraphicsSystem.hpp"
#include "GraphicsComponent.hpp"
#include "../physics/RigidBodyComponent.hpp"

/**
 * Init all texture
 */
void engine::graphics::GraphicSystem::Init(void) {

}

void engine::graphics::GraphicSystem::SendMessage(Message *msg) {

}

void engine::graphics::GraphicSystem::Update(float) {
    /*auto *eg = engine::core::Engine::GetInstance();

    for (auto sprite : *eg->getScene()->GetComponents<SpriteComponent>(core::ComponentID::GRA_SPRITE)) {
        auto const &x = sprite->getX();
        auto const &y = sprite->getY();
        sf::CircleShape shape(50);
        shape.setFillColor(sf::Color(100, 250, 50));
        shape.setPosition(x, y);
        sprite->setX(x + 1);
        sprite->setY(y + 1);
        eg->getWindow().draw(shape);
    }

    for (auto obj : gom) {

        /*auto *sprite = static_cast<engine::physics::RigidBodyComponent *>(obj.second->getComponent(1)); // TODO : check is Sprite
        if (sprite->Active()) {
            engine::physics::Vector2d position = sprite->getPosition();

            sf::CircleShape shape(50);
            shape.setFillColor(sf::Color(100, 250, 50));
            shape.setPosition(position.getX(), position.getY());

            position.setX(sprite->getPosition().getX() + 1);
            position.setY(sprite->getPosition().getY() + 1);

            sprite->setPosition(position);
            eg->getWindow().draw(shape);
        }*/
    }
    */
}
