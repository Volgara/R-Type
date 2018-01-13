//
// Created by Hamza Hammouche on 13/01/2018.
//

#ifndef RTYPE_BOX_HPP
#define RTYPE_BOX_HPP

#include "Vector2D.hpp"

namespace engine {
    namespace physics {
        class Box {
        private:
            int _left;
            int _right;
            int _top;
            int _bottom;
        public:
            Box(Vector2d position, Vector2d size);

            void updatePosition(const engine::physics::Vector2d &position, const engine::physics::Vector2d &size);

            bool intersectBox(Box *box);

            int getLeft() const;

            int getRight() const;

            int getTop() const;

            int getBottom() const;
        };
    }
}


#endif //RTYPE_BOX_HPP
