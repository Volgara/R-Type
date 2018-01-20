//
// Created by macdoy on 20/01/18.
//

#include "NetworkComponent.hpp"

engine::network::NetworkComponent::NetworkComponent() : Component(engine::core::NET) {
}

engine::network::NetworkComponent::~NetworkComponent() {
}

void engine::network::NetworkComponent::setRoom(std::string roomName) {
    if (!_inRoom)
    {
        _inRoom = true;
        _roomName = roomName;
    }
}

void engine::network::NetworkComponent::cleanRoom() {
    _inRoom = false;
    _roomName = "";
    isReady = false;
}

void engine::network::NetworkComponent::SendMessage(engine::core::Message *message) {
    std::cout << "I get message in NetworkComponent : " << message->id << std::endl;
}

void engine::network::NetworkComponent::Update(float dt) {
    return;
}

void engine::network::NetworkComponent::Init() {
    _fd = -1;
    _id = -1;
    _inRoom = false;
    isReady = false;
    _roomName = "";
}

void engine::network::NetworkComponent::ShutDown() {
    return;
}

int engine::network::NetworkComponent::getFd() const {
    return _fd;
}

int engine::network::NetworkComponent::getId() const {
    return _id;
}

bool engine::network::NetworkComponent::getInRoom() const {
    return _inRoom;
}

std::string engine::network::NetworkComponent::getRoomName() const {
    return _roomName;
}

bool engine::network::NetworkComponent::getIsReady() const {
    return isReady;
}

void engine::network::NetworkComponent::setFd(const int &fd) {
    _fd = fd;
}

void engine::network::NetworkComponent::setId(const int &id) {
    _id = id;
}

void engine::network::NetworkComponent::setInRoom(const bool &b){
    _inRoom = b;
}

void engine::network::NetworkComponent::setRoomName(const std::string &m){
    _roomName = m;
}

void engine::network::NetworkComponent::setIsReady(const bool &b){
    isReady = b;
}
