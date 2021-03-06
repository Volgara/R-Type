//
// Created by Hamza Hammouche on 20/01/2018.
//

#include "PlayerComponent.hpp"

game::PlayerComponent::PlayerComponent() : Component(engine::core::ComponentID::GAME_PLAYER), SpaceShip(50,
                                                                                                        10,
                                                                                                        5,
                                                                                                        engine::core::Vector2d(10, 10)) {}

void game::PlayerComponent::SendMessage(engine::core::Message *) {}

void game::PlayerComponent::Update(float) {
}

void game::PlayerComponent::Init() {
}

void game::PlayerComponent::ShutDown() {}