//
//-----------------------------------------------------------------------------
//Filename:    ComponentHandler.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/15/18.
//-----------------------------------------------------------------------------
//

#ifndef RTYPE_COMPONENTHANDLER_HPP
#define RTYPE_COMPONENTHANDLER_HPP

#include "Component.hpp"
#include "Scene.hpp"

namespace engine {
    namespace core {
        struct ComponentHandler {
            ComponentHandler(ComponentID type, unsigned size)
                    : _type(type), _size(size) {
            }

            virtual Component *Create(Scene *scene) = 0;

            virtual void Remove(Scene *scene, Component *component) = 0;

            ComponentID _type;
            unsigned _size;
        };


        template<typename T>
        struct ComponentHandlerDerived : public ComponentHandler {
            explicit ComponentHandlerDerived(ComponentID type)
                    : ComponentHandler(type, sizeof(T)) {
            }

            Component *Create(Scene *scene) override {
                std::vector<Component *> *components = scene->GetComponents(_type);

                auto *component = new T();
                component->scene = scene;
                scene->handlesComponents->push_back(component);
                components->push_back(component);
                return component;
            }

            void Remove(Scene *scene, Component *component) override {
                std::vector<Component *> *components = scene->GetComponents(_type);
                component->~Component();

                //Component *moved = (Component *)components.Free( component );
                //scene->m_handles.Update( moved, moved->self );
            }
        };

    }
}

#endif //RTYPE_COMPONENTHANDLER_HPP
