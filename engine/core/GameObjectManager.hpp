//
//-----------------------------------------------------------------------------
//Filename:    GameObjectManager.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/10/18.
//-----------------------------------------------------------------------------
//

#ifndef RTYPE_GAMEOBJECTMANAGER_HPP
#define RTYPE_GAMEOBJECTMANAGER_HPP

#include <map>
#include <vector>
#include "GameObject.hpp"

namespace engine {
    namespace core {
        class GameObjectManager {
        private:
            unsigned int _count;
            std::map<GameObjectID, GameObject *> _objects;

        public:
            GameObjectManager() = default;

            virtual ~GameObjectManager() {
                for (auto item : _objects) {
                    delete (item);
                }
            }

            GameObject *getObjectId(GameObjectID id) {
                return _objects[id];
            }

            void addObject(GameObjectID id, GameObject *obj) {
                _objects[id] = obj;
            }
        };
    }
}

#endif //RTYPE_GAMEOBJECTMANAGER_HPP
