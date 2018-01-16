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

int main(int argc, char *argv[]) {
    auto *ge = engine::core::Engine::GetInstance();

    ge->addSystem("graphics", new engine::graphics::GraphicSystem());
    ge->Init();

    while (ge->isRunning()) {
        ge->getWindow().clear();
        ge->Update(1.0f);
        ge->getWindow().display();
    }

    ge->Shutdown();

    return (0);
}