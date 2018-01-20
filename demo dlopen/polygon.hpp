//
// Created by macdoy on 20/01/18.
//

#ifndef RTYPE_POLYGON_HPP
#define RTYPE_POLYGON_HPP

class polygon {
protected:
    double side_length_;
public:
    polygon()
            : side_length_(0) {}
    virtual ~polygon() {}

    void set_side_length(double side_length) {
        side_length_ = side_length;
    }

    virtual double area() const = 0;
};

typedef polygon *create_t();
typedef void destroy_t(polygon*);

#endif //RTYPE_POLYGON_HPP
