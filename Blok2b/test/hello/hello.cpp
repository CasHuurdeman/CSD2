
#include <iostream>

int main() {
    std::cout << "Hello there, what's your name?" << std::endl;

    std::string yourName;
    std::cin >> yourName;

    std::cout << "Hi " << yourName << std::endl;
}