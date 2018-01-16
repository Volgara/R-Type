//
// Created by Hamza Hammouche on 12/01/2018.
//

#ifndef RTYPE_VECTOR2D_HPP
#define RTYPE_VECTOR2D_HPP

namespace engine {
    namespace core {
        class Vector2d {
        private:
            int _x;
            int _y;
        public:
            Vector2d(int x = 0, int y = 0);

            virtual ~Vector2d();

            int getX() const;

            void setX(int x);

            int getY() const;

            void setY(int y);
        };
    }
}


#endif //RTYPE_VECTOR2D_HPP
