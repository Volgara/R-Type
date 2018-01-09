#include <iostream>

int main() {
#ifdef _WIN32
    std::cout << "Hello, World windows!" << std::endl;
    return 0;
#elif linux
    std::cout << "Hello, World linux!" << std::endl;
    return 0;
#elif __APPLE__
    std::cout << "Hello, World Mac!" << std::endl;
    return 0;
#endif
}