#include "Cat.hpp"

// Orthodox

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "The type of the animal is " << this->type << "." << std::endl;
}
Cat::Cat(const Cat& other)
{
    this->type = other.type;
    std::cout << "Cat copy constructor is used";
}
Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assign constructor is used" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Our " << this->type << "is dead ;()" << std::endl;
}

// Another member functions

void Cat::makeSound() const
{
    std::cout << "Meeeeeeeeeeeow" << std::endl;
}
