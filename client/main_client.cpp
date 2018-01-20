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
#include <input/InputSystem.hpp>
#include <iostream>

void onKeyPressed(sf::Event &event) {
    if (event.KeyPressed && event.key.code == sf::Keyboard::Escape) {
        auto *ge = engine::core::Engine::GetInstance();
        ge->Shutdown();
    }
}

int main(int argc, char *argv[]) {
    std::cout << "argc = " << argc << std::endl;
    for(int i = 0; i < argc; i++)
        std::cout << "argv[" << i << "] = " << argv[i] << std::endl;


    auto *ge = engine::core::Engine::GetInstance();

    auto *input = new engine::input::InputSystem();
    auto *graphics =  new engine::graphics::GraphicSystem();

    input->addKeyCallback(onKeyPressed);

    ge->addSystem("graphics",graphics);
    ge->addSystem("input", input);
    ge->Init();

    ge->MainLoop();

    ge->Shutdown();

    return (0);
}