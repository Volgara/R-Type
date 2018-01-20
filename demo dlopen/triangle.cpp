//
// Created by macdoy on 20/01/18.
//

#include "polygon.hpp"
#include <cmath>

class triangle : public polygon {
public:
    virtual double area() const {
        return side_length_ * side_length_ * sqrt(3) / 2;
    }
};

extern "C" polygon *create() {
    return new triangle;
}

extern "C" void destroy(polygon* p) {
    delete p;
}