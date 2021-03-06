//
//-----------------------------------------------------------------------------
//Filename:    ID.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/15/18.
//-----------------------------------------------------------------------------
//

#ifndef RTYPE_ID_HPP
#define RTYPE_ID_HPP

#define EComponentID_NUMBER 6

namespace engine {
    namespace core {

        enum ComponentID {
            GRA_SPRITE = 0,
            PHY_RIGIDBODY, // TODO : use RIGID Body
            PRO_BULLET,
            GAME_PLAYER,
            INPUT_GENERATE,
            NET
        };

        typedef unsigned GameObjectID;
    }
}


#endif //RTYPE_ID_HPP
