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
            std::map<unsigned int, GameObject *> _objectsMap;
            std::vector<GameObject *> _objects;

        public:
            GameObjectManager() = default;

            virtual ~GameObjectManager() {
                for (auto item : _objects) {
                    delete (item);
                }
            }

            GameObject *getObjectId(unsigned int id) {
                return _objectsMap[id];
            }

            void addObject(GameObject *obj) {
                obj->setId(_count);
                _objectsMap[_count++] = obj;
                _objects.push_back(obj);
            }
        };
    }
}

#endif //RTYPE_GAMEOBJECTMANAGER_HPP
