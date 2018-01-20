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

            GameObject();

            void attachComponent(Component *component);

            void detachComponent(Component *component);

            void detachComponent(ComponentID type);

            void detachComponents();

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
