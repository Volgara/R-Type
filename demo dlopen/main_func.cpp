//
// Created by macdoy on 20/01/18.
//

#include <iostream>
#include <dlfcn.h>

int main() {
    using std::cout;
    using std::cerr;

    cout << "C++ dlopen demo\n\n";

    cout << "Opening hello.so...\n";

    void *handle = dlopen("./hello.so", RTLD_LAZY);

    if (!handle) {
        cerr << "Cannot open library: " << dlerror() << '\n';
        return 1;
    }
    cout << "Loading symbol hello...\n";
    typedef  void (*hello_t)();
    dlerror();
    hello_t hello = (hello_t) dlsym(handle, "hello");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol 'hello': " << dlsym_error << '\n';
        dlclose(handle);
        return 1;
    }
    cout << "Calling hello...\n";
    hello();
    cout << "Closing library...\n";
    dlclose(handle);
    return 0;
}
