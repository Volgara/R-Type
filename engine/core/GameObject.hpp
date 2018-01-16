//
//-----------------------------------------------------------------------------
//Filename:    GameObject.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/10/18.
//-----------------------------------------------------------------------------
//

#include <vector>
#include <map>
#include "ID.hpp"
#include "Message.hpp"
#include "Component.hpp"
#include "Vector2D.hpp"

#ifndef RTYPE_GAMEOBJECT_HPP
#define RTYPE_GAMEOBJECT_HPP

namespace engine {
    namespace core {
        struct Scene;

        struct GameObject {
            Component *components[EComponentID_NUMBER];
            GameObjectID guid;
            Scene *scene;
            bool active;
            Vector2d pos;

            void AddComponent(Component *component);

            void RemoveComponent(Component *component);

            void RemoveComponent(ComponentID type);

            Component *GetComponent(ComponentID type);

            bool HasComponent(ComponentID type);

            void Update(float dt);

            void Init(void);

            template<typename T>
            T *GetComponent(ComponentID type);
        };
    }
}


#endif //RTYPE_GAMEOBJECT_HPP
