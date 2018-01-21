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

        void GameObject::attachComponent(Component *component) {
            component->attachGameObject(this);
            components[component->id] = component;
        }

        void GameObject::detachComponent(Component *component) {
            component->detachGameObject();
            components[component->id] = nullptr;
        }

        void GameObject::detachComponent(ComponentID type) {
            auto *component = components[type];
            component->detachGameObject();
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

        void GameObject::detachComponents() {
            for (auto *component : components) {
                if (component == nullptr) continue;
                component->detachGameObject();
            }
        }

        GameObject::GameObject() {
            for (int i = 0; i < EComponentID_NUMBER; ++i) {
                components[i] = nullptr;
            }
        }
    }
}