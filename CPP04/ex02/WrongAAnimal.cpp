#include "WrongAnimal.hpp"

// Orthodox

WrongAAnimal::WrongAAnimal()
{
    std::cout << "One WrongAAnimal is created, but the type in still unknown";
    std::cout << std::endl;
    this->type = "stillNotDeceided";
}


WrongAAnimal::WrongAAnimal(const WrongAAnimal &other)
{   
    std::cout << "One WrongAAnimal is created, but the type in still unknown";
    this->type = other.type;
    this->type = "stillNotDeceided";
}

WrongAAnimal& WrongAAnimal::operator=(const WrongAAnimal& other)
{
    std::cout << "The copy assigment construtor from WrongAAnimal is callad" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

WrongAAnimal::~WrongAAnimal()
{
    std::cout << "The WrongAAnimal is destroyed" << std::endl;
}
// Another member functions

std::string WrongAAnimal::getType() const
{
    return (this->type);
}

void WrongAAnimal::makeSound() const
{
    std::cout << "Wrong sound yet" << std::endl;
}
