#include "WrongAnimal.hpp"

// Orthodox

WrongAnimal::WrongAnimal()
{
    std::cout << "One WrongAnimal is created, but the type in still unknown";
    std::cout << std::endl;
    this->type = "stillNotDeceided";
}


WrongAnimal::WrongAnimal(const WrongAnimal &other)
{   
    std::cout << "One WrongAnimal is created, but the type in still unknown";
    this->type = other.type;
    this->type = "stillNotDeceided";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
   std::cout << "The copy assigment construtor is callad" << std::endl;
   if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "The animal is destroyed" << std::endl;
}

// Another member functions

std::string WrongAnimal::getType() const
{
    return (this->type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "No sound yet" << std::endl;
}
