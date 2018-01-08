#include <iostream>

int main() {
#ifdef _WIN32
    std::cout << "Hello, World windows!" << std::endl;
    return 0;
#endif

#ifdef linux
    std::cout << "Hello, World linux!" << std::endl;
    return 0;
#endif
}