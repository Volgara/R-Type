//
// Created by Volgar on 12/01/2018.
// Contact: volgar.dev@gmail.com
//

#ifndef RTYPE_EXCEPTION_HPP
#define RTYPE_EXCEPTION_HPP


#include <string>
#include <exception>

namespace RType{

    class Exception: public std::exception
    {
    public:
        /** Constructor (C strings).
         *  @param message C-style string error message.
         *                 The string contents are copied upon construction.
         *                 Hence, responsibility for deleting the char* lies
         *                 with the caller.
         */
        explicit Exception(const char* message):
                msg_(message)
        {
        }

        /** Constructor (C++ STL strings).
         *  @param message The error message.
         */
        explicit Exception(const std::string& message):
                msg_(message)
        {}

        /** Destructor.
         * Virtual to allow for subclassing.
         */
        virtual ~Exception() throw (){}

        /** Returns a pointer to the (constant) error description.
         *  @return A pointer to a const char*. The underlying memory
         *          is in posession of the Exception object. Callers must
         *          not attempt to free the memory.
         */
        virtual const char* what() const throw (){
            return msg_.c_str();
        }

    protected:
        /** Error message.
         */
        std::string msg_;
    };

    class NetworkException: public  Exception
    {
    public:
        NetworkException(const char *message) : Exception(message) {};
        NetworkException(const std::string& message) : Exception(message) {};
    };
}

#endif //RTYPE_EXCEPTION_HPP
