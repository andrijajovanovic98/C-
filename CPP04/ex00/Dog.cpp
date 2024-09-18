#include "Dog.hpp"

// Orthodox

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "The type of the animal is " << this->type << "." << std::endl;
}
Dog::Dog(const Dog& other)
{
    this->type = other.type;
    std::cout << "Dog copy counstructor is used";
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assign constructor is used" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Out dog is gone ;(" << std::endl;
}

// Another member functions

void Dog::makeSound() const
{
    std::cout << "Barkkk" << std::endl;
}
