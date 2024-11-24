#include "cat.h"

//constructor and destructor

Cat::Cat(std::string name) : Pet(name)
{
  std::cout << "Cat::Cat - constructor, name: "
    << name << "\n";
}
Cat::~Cat()
{
  std::cout << "Cat::~Cat - destructor, name: "
    << name << "\n";
}

void Cat::climb(){
    std::cout << name << " is sitting in  tree\n";
}