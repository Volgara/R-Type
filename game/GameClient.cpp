//
// Created by Hamza Hammouche on 21/01/2018.
//

#include <projectile/BulletSystem.hpp>
#include "GameClient.hpp"

game::GameClient::GameClient() {}

game::GameClient::~GameClient() {

}

void onKeyPressed(sf::Event &event) {
    if (event.KeyPressed && event.key.code == sf::Keyboard::Escape) {
        auto *ge = engine::core::Engine::GetInstance();
        ge->Shutdown();
    }
}

void game::GameClient::startGamePlayer() {
    auto *eg = engine::core::Engine::GetInstance();
    //engine::Network::Socket *udp = this->initSocketSystem();
    engine::physics::PhysicsSystem *physicsSystem = new engine::physics::PhysicsSystem(800, 800);
    game::GameLogicClientSystem *gameLogicClientSystem = new GameLogicClientSystem(800, 800);
    engine::projectile::BulletSystem *bulletSystem = new engine::projectile::BulletSystem(800, 800);
    auto *input = new engine::input::InputSystem();
    auto *graphics =  new engine::graphics::GraphicSystem();

    eg->addSystem("physics", physicsSystem);
    eg->addSystem("gameLogic", gameLogicClientSystem);
    eg->addSystem("bullets", bulletSystem);
    eg->addSystem("graphics",graphics);
    eg->addSystem("input", input);

    eg->setScene(new core::Scene());
    this->createPlayer(eg->getScene(), input);

    eg->Init();
    eg->MainLoop();
    eg->Shutdown();
}

void game::GameClient::createPlayer(engine::core::Scene *scene, engine::input::InputSystem *input) {
    engine::core::Vector2d pos(10, 10);

    engine::core::GameObject *player = scene->CreateEmptyObject();
    player->pos.setX(pos.getX());
    player->pos.setY(pos.getY());
    pos.setY(pos.getY() + 10);
    PlayerComponent *playerComponent = static_cast<PlayerComponent *>(scene->CreateComponent(engine::core::ComponentID::GAME_PLAYER));
    engine::physics::RigidBodyComponent *rigidBodyComponent = static_cast<engine::physics::RigidBodyComponent *>(scene->CreateComponent(engine::core::ComponentID::PHY_RIGIDBODY));
    engine::core::Component *spriteComponent = scene->CreateComponent(engine::core::GRA_SPRITE);
    auto *inputComponent = static_cast<engine::input::InputComponent *>(scene->CreateComponent(engine::core::INPUT_GENERATE));
    inputComponent->attachState(sf::Keyboard::Z, new engine::input::StateSendMessage(new game::PlayerActionMessage(game::PlayerActionMessage::GO_UP)));
    inputComponent->attachState(sf::Keyboard::Q, new engine::input::StateSendMessage(new game::PlayerActionMessage(game::PlayerActionMessage::GO_LEFT)));
    inputComponent->attachState(sf::Keyboard::S, new engine::input::StateSendMessage(new game::PlayerActionMessage(game::PlayerActionMessage::GO_DOWN)));
    inputComponent->attachState(sf::Keyboard::D, new engine::input::StateSendMessage(new game::PlayerActionMessage(game::PlayerActionMessage::GO_RIGHT)));
    inputComponent->attachState(sf::Keyboard::Space, new engine::input::StateSendMessage(new game::PlayerActionMessage(game::PlayerActionMessage::SHOOT)));
    input->addKeyCallback(onKeyPressed);
    rigidBodyComponent->setVelocity(engine::core::Vector2d(0, 0));
    rigidBodyComponent->setSize(playerComponent->getSize());
    rigidBodyComponent->Init();
    player->attachComponent(playerComponent);
    player->attachComponent(rigidBodyComponent);
    player->attachComponent(spriteComponent);
    player->attachComponent(inputComponent);
}

engine::Network::Socket *game::GameClient::initSocketSystem() {
    return nullptr;
}
