//
//-----------------------------------------------------------------------------
//Filename:    AScene.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/15/18.
//-----------------------------------------------------------------------------
//

#ifndef RTYPE_SCENE_HPP
#define RTYPE_SCENE_HPP

#include <map>
#include <vector>
#include "ID.hpp"
#include "NonCopyable.hpp"
#include "AutoList.hpp"
#include "MessageBus.hpp"

namespace engine {
    namespace core {

        struct GameObject;
        struct Component;

        struct Scene : public AutoList<Scene> {
            std::map<GameObjectID, GameObject *> objectsMap;
            std::vector<Component *> handlesComponents[EComponentID_NUMBER];
            unsigned guid = 0;

            Component *CreateComponent(ComponentID type);

            void RemoveComponent(Component *c);

            void RemoveComponent(GameObjectID handle);

            GameObject *CreateEmptyObject(void);

            void RemoveGameObject(GameObject *o);

            void RemoveGameObject(GameObjectID handle);

            template <typename T>
            std::vector<T *> *GetComponents(ComponentID type);

            Component *GetComponent(ComponentID type, GameObjectID owner);
        };

        template<typename T>
        std::vector<T *> *engine::core::Scene::GetComponents(engine::core::ComponentID type) {
            return reinterpret_cast<std::vector<T *> *>(&handlesComponents[type]);
        }
    }
}


#endif //RTYPE_SCENE_HPP
