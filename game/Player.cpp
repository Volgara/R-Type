//
// Created by Hamza Hammouche on 20/01/2018.
//

#include "Player.hpp"

game::Player::Player() : SpaceShip(50, 10, 30), Component(engine::core::ComponentID::GAME_PLAYER) {}

void game::Player::SendMessage(engine::core::Message *) {}

void game::Player::Update(float) {}

void game::Player::Init() {}

void game::Player::ShutDown() {}