//
//-----------------------------------------------------------------------------
//Filename:    AutoList.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/15/18.
//-----------------------------------------------------------------------------
//

#ifndef RTYPE_AUTOLIST_HPP
#define RTYPE_AUTOLIST_HPP

namespace engine {
    namespace core {
        /**
         * @class AutoList
         * @code
         class Object : public AutoList<Object> {};
         * @tparam T Object
         */
        template<typename T>
        class AutoList {
        public:
            AutoList() {
                next = Head();
                Head() = static_cast<const T *>(this);
            }

            const T *Next(void) const {
                return next;
            }

            static const T *&Head(void) {
                static const T *p = 0;
                return p;
            }

        private:
            const T *next;
        };
    }
}

#endif //RTYPE_AUTOLIST_HPP
