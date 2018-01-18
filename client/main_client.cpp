//
//-----------------------------------------------------------------------------
//Filename:    main_client.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/9/18.
//-----------------------------------------------------------------------------
//

#include <core/Engine.hpp>
#include <graphics/GraphicsSystem.hpp>
#include <core/InputSystem.hpp>
#include <core/GameObject.hpp>
#include "../game/BulletSystem.hpp"

void onKeyPressed(sf::Event &) {
    std::cout << "KeyPressed" << std::endl;
}

int main(int argc, char *argv[]) {
    auto *ge = engine::core::Engine::GetInstance();

    //auto *input = new engine::core::InputSystem();
    //auto *graphics =  new engine::graphics::GraphicSystem();
    auto *bullet = new game::BulletSystem();

    //input->addEventListener(sf::Event::EventType::KeyPressed, std::bind(onKeyPressed, std::placeholders::_1));

    //ge->addSystem("graphics",graphics);
    //ge->addSystem("input", input);
    ge->addSystem("bullet", bullet);

    ge->Init();

    engine::core::GameObject *game = ge->getScene()->CreateEmptyObject();

    auto *comp = ge->getScene()->CreateComponent(engine::core::BULLET);
    auto *comp2 = ge->getScene()->CreateComponent(engine::core::PHY_RIGIDBODY);

    game->AddComponent(comp);
    game->AddComponent(comp2);

    comp->Update(0.1);

    //ge->MainLoop();

    ge->Shutdown();

    return (0);
}