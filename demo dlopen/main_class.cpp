//
// Created by macdoy on 20/01/18.
//

#include "polygon.hpp"
#include <iostream>
#include <dlfcn.h>

int main() {
    using std::cout;
    using std::cerr;

    void *triangle = dlopen("./triangle.so", RTLD_LAZY);
    if (!triangle) {
        cerr << "Cannot load library: " << dlerror() << '\n';
        return 1;
    }

    dlerror();

    create_t *create_triangle = (create_t *)dlsym(triangle, "create");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol create: " << dlsym_error << '\n';
        return 1;
    }

    destroy_t *destroy_triangle = (destroy_t *)dlsym(triangle, "destroy");
    dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol destroy: " << dlsym_error << '\n';
        return 1;
    }

    polygon *poly = create_triangle();

    poly->set_side_length(7);
    cout << "The area is: " << poly->area() << '\n';

    dlclose(triangle);
}