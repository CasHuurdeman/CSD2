#include <iostream>


int main(){
    std::string yourName;
    std::string yourAge;
    std::string yourHeight;

    std::cout << "Your name: ";
    std::cin >> yourName;

    std::cout << "Your age: ";
    std::cin >> yourAge; 

    std::cout << "Your height: ";
    std::cin >> yourHeight;

    std::cout << "Hello " << yourName 
    << "; " << yourAge << "; " << yourHeight << std::endl;
    
}