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
        class GameObject {
        protected:
            unsigned int _id;

        public:
            GameObject();

            virtual ~GameObject();

            unsigned int getId() const;

            void setId(unsigned int id);
        };
    }
}


#endif //RTYPE_GAMEOBJECT_HPP
