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
#include <iostream>

void onKeyPressed(sf::Event &) {
    std::cout << "KeyPressed" << std::endl;
}

int main(int argc, char *argv[]) {
    auto *ge = engine::core::Engine::GetInstance();

    auto *input = new engine::core::InputSystem();
    auto *graphics =  new engine::graphics::GraphicSystem();

    input->addEventListener(sf::Event::EventType::KeyPressed, std::bind(onKeyPressed, std::placeholders::_1));

    ge->addSystem("graphics",graphics);
    ge->addSystem("input", input);
    ge->Init();

    ge->MainLoop();

    ge->Shutdown();

    return (0);
}