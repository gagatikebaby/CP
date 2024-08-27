#include"cat.h"

Cat::Cat(std::string name) : name(name)
{
    std::cout << "Constructor of cat : "<<name <<std::endl;
}

Cat::~Cat()
{
    std :: cout <<"Destructor of cat : "<<name <<std::endl;
}
