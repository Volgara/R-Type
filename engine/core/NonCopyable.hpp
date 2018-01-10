//
//-----------------------------------------------------------------------------
//Filename:    NonCopyable.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/10/18.
//-----------------------------------------------------------------------------
//

#ifndef RTYPE_NONCOPYABLE_HPP
#define RTYPE_NONCOPYABLE_HPP


namespace engine {
    namespace core {
        class NonCopyable {
        protected:
            NonCopyable() = default;

            ~NonCopyable() = default; /// Protected non-virtual destructor
        private:
            NonCopyable(const NonCopyable &) = delete;

            NonCopyable &operator=(const NonCopyable &) = delete;
        };
    }
}

#endif //RTYPE_NONCOPYABLE_HPP
