//
// Created by Hamza Hammouche on 13/01/2018.
//

#ifndef RTYPE_BOX_HPP
#define RTYPE_BOX_HPP

#include "core/Vector2D.hpp"

namespace engine {
    namespace physics {
        class Box {
        private:
            core::Vector2d *_pos;
            core::Vector2d *_size;
        public:
            Box(engine::core::Vector2d *position, engine::core::Vector2d *size);

            bool intersectBox(Box *box);

            int getLeft() const;

            int getRight() const;

            int getTop() const;

            int getBottom() const;
        };
    }
}


#endif //RTYPE_BOX_HPP
