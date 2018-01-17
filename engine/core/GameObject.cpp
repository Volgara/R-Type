//
//-----------------------------------------------------------------------------
//Filename:    GameObject.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/10/18.
//-----------------------------------------------------------------------------
//

#include "GameObject.hpp"
#include "Scene.hpp"

namespace engine {
    namespace core {
        template<typename T>
        T *GameObject::GetComponent(ComponentID type) {
            return (T *) GetComponent(type);
        }

        Component *GameObject::GetComponent(ComponentID type) {
            return components[type];
        }

        void GameObject::AddComponent(Component *component) {
            component->owner = guid;
            component->ownerRef = this;
            components[component->id] = component;
        }

        void GameObject::RemoveComponent(Component *component) {
            component->owner = static_cast<GameObjectID>(-1); // Debug
            component->ownerRef = nullptr;
            components[component->id] = nullptr;
        }

        void GameObject::RemoveComponent(ComponentID type) {
            auto *component = components[type];
            component->owner = static_cast<GameObjectID>(-1); // Debug
            component->ownerRef = nullptr;
            components[component->id] = nullptr;
        }

        bool GameObject::HasComponent(ComponentID type) {
            return components[type] != nullptr;
        }

        void GameObject::Update(float dt) {
            for (auto component : components) {
                component->Update(dt);
            }
        }

        void GameObject::Init(void) {
            for (auto component : components) {
                component->Init();
            }
        }
    }
}