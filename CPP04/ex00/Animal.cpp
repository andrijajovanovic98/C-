#include "Animal.hpp"

// Orthodox

Animal::Animal()
{
    std::cout << "One animal is created, but the type in still unknown";
    std::cout << std::endl;
    this->type = "stillNotDeceided";
}


Animal::Animal(const Animal &other)
{   
    std::cout << "One animal is created, but the type in still unknown";
    this->type = other.type;
    this->type = "stillNotDeceided";

}

Animal& Animal::operator=(const Animal& other)
{
   std::cout << "The copy assigment construtor is called" << std::endl;
   if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructed" << std::endl;
}

// Another member functions

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::makeSound() const
{
    std::cout << "No sound yet" << std::endl;
}