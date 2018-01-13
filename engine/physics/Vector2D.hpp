//
// Created by Hamza Hammouche on 12/01/2018.
//

#ifndef RTYPE_VECTOR2D_HPP
#define RTYPE_VECTOR2D_HPP

namespace engine {
    namespace physics {
        class Vector2d {
        private:
            int x;
            int y;
        public:
            Vector2d(int x, int y);

            virtual ~Vector2d();

            int getX() const;

            void setX(int x);

            int getY() const;

            void setY(int y);
        };
    }
}


#endif //RTYPE_VECTOR2D_HPP
