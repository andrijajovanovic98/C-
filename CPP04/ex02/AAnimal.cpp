#include "AAnimal.hpp"

// Orthodox

AAnimal::AAnimal()
{
    std::cout << "AAnimal is beeing created";
    std::cout << std::endl;
    this->type = "stillNotDeceided";
}

AAnimal::AAnimal(const AAnimal &other)
{   
    std::cout << "One AAnimal is created, but the type in still unknown";
    this->type = other.type;
    this->type = "stillNotDeceided";

}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
   std::cout << "The copy assigment construtor is callad" << std::endl;
   if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal is destructed.." << std::endl;
}
// Another member functions

std::string AAnimal::getType() const
{
    return (this->type);
}
