//
//-----------------------------------------------------------------------------
//Filename:    Singleton.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/15/18.
//-----------------------------------------------------------------------------
//

#ifndef RTYPE_SINGLETON_HPP
#define RTYPE_SINGLETON_HPP

namespace engine {
    namespace core {
        template<typename T>
        class Singleton
        {
        public:
            static bool isBuilt();
            static T* GetInstance();
            virtual void constructor() {};

        protected:
            static T* _instance;
            static void buildInstance();

            Singleton(){}
            ~Singleton(){}
        };

        template<typename T>
        T* Singleton<T>::_instance = 0;

        template<typename T>
        void Singleton<T>::buildInstance()
        {
            if ( _instance )
                throw "Singleton already constructed";
            _instance = new T();
            _instance->constructor();
        }

        template<typename T>
        T* Singleton<T>::GetInstance() {
            if ( ! isBuilt() )
                buildInstance();
            return _instance;
        }

        template<typename T>
        bool Singleton<T>::isBuilt() {
            return (_instance != 0);
        }
    }
}

#endif //RTYPE_SINGLETON_HPP
