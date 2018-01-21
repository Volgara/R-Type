//
//-----------------------------------------------------------------------------
//Filename:    main_client.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/9/18.
//-----------------------------------------------------------------------------
//

#include <core/Engine.hpp>
#include <core/Scene.hpp>
#include <input/InputSystem.hpp>
#include <input/InputComponent.hpp>
#include <graphics/GraphicsSystem.hpp>
#include <iostream>
#include "../game/Message.hpp"

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

    ge->setScene(new engine::core::Scene());
    auto *scene = ge->getScene();

    engine::core::GameObject *object = scene->CreateEmptyObject();
    engine::core::Component *spriteComponent = scene->CreateComponent(engine::core::GRA_SPRITE);
    auto *inputComponent = static_cast<engine::input::InputComponent *>(scene->CreateComponent(engine::core::INPUT_GENERATE));
    inputComponent->attachState(sf::Keyboard::Z, new engine::input::StateSendMessage(new game::PlayerActionMessage(game::PlayerActionMessage::GO_UP)));
    inputComponent->attachState(sf::Keyboard::Q, new engine::input::StateSendMessage(new game::PlayerActionMessage(game::PlayerActionMessage::GO_LEFT)));
    inputComponent->attachState(sf::Keyboard::S, new engine::input::StateSendMessage(new game::PlayerActionMessage(game::PlayerActionMessage::GO_DOWN)));
    inputComponent->attachState(sf::Keyboard::D, new engine::input::StateSendMessage(new game::PlayerActionMessage(game::PlayerActionMessage::GO_RIGHT)));
    inputComponent->attachState(sf::Keyboard::Space, new engine::input::StateSendMessage(new game::PlayerActionMessage(game::PlayerActionMessage::SHOOT)));
    object->attachComponent(spriteComponent);
    object->attachComponent(inputComponent);

    input->addKeyCallback(onKeyPressed);

    ge->addSystem("graphics",graphics);
    ge->addSystem("input", input);
    ge->Init();



    ge->MainLoop();

    ge->Shutdown();

    return (0);
}