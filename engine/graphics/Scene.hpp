/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 12/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_SCENE_HPP
#define RTYPE_SCENE_HPP


#include <string>

namespace RType {
    namespace Engine {
        class Scene {
        public:
            Scene(std::string name);

            ~Scene();

            std::string name;
        };
    }
}


#endif //RTYPE_SCENE_HPP
