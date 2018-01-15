//
//-----------------------------------------------------------------------------
//Filename:    GameObject.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/10/18.
//-----------------------------------------------------------------------------
//

#ifndef RTYPE_GAMEOBJECT_HPP
#define RTYPE_GAMEOBJECT_HPP


namespace engine {
    namespace core {
        class GameObject;

        typedef unsigned int GameObjectID;
    }
}

#include <vector>
#include <map>
#include "Message.hpp"
#include "Component.hpp"


namespace engine {
    namespace core {

        class GameObject {
        protected:
            GameObjectID _id;
            bool _active;
            std::map<ComponentID, Component *> _components;

        public:
            GameObject();

            ~GameObject();

            void SendMessage(Message *msg);

            bool active(void) const;

            GameObjectID getId() const;

            void setId(GameObjectID id);

            bool hasComponent(ComponentID id) const;

            Component *getComponent(ComponentID id);

            void addComponent(ComponentID id, Component *);

            void Update(float dt);
        };
    }
}


#endif //RTYPE_GAMEOBJECT_HPP
