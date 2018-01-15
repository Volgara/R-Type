//
//-----------------------------------------------------------------------------
//Filename:    GameObjectManager.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/10/18.
//-----------------------------------------------------------------------------
//

#include <map>
#include <vector>
#include "GameObject.hpp"
#include "Singleton.hpp"

#ifndef RTYPE_GAMEOBJECTMANAGER_HPP
#define RTYPE_GAMEOBJECTMANAGER_HPP

namespace engine {
    namespace core {

        class GameObjectManager : public Singleton<GameObjectManager> {
        private:
            std::map<GameObjectID, GameObject *> _objects;

        public:
            GameObject *getObjectId(GameObjectID id) {
                return _objects[id];
            }

            void addObject(GameObjectID id, GameObject *obj) {
                _objects.insert(_objects.begin(), std::pair<GameObjectID, GameObject *>(id, obj));
            }

            const std::map<GameObjectID, GameObject *> &getObjects() const {
                return _objects;
            }
        };
    }
}

#endif //RTYPE_GAMEOBJECTMANAGER_HPP
