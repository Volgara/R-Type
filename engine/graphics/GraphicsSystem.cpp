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
#include "SpriteComponent.hpp"

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
        /**
         * Bad way ( because, all objects is in this list... the component can be unavailable...
         */
        auto *sprite = static_cast<SpriteComponent *>(obj.second->getComponent(1)); // TODO : check is Sprite
        if (sprite->Active()) {
            // TODO : texture implementation
            // Simple draw circle
            auto const &x = sprite->getX();
            auto const &y = sprite->getY();
            sf::CircleShape shape(50);
            shape.setFillColor(sf::Color(100, 250, 50));
            shape.setPosition(x, y);
            // DANGER : Bad way !
            sprite->setX(x + 1);
            sprite->setY(y + 1);
            eg->getWindow().draw(shape);
        }
    }
}
