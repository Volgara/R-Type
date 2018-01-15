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

void engine::graphics::GraphicSystem::Update(float dt) {
    auto *eg = engine::core::Engine::GetInstance();
    const auto &gom = engine::core::GameObjectManager::GetInstance()->getObjects();
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
}
