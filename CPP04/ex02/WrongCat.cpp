#include "WrongCat.hpp"

// Orthodox

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "The type of the AAnimal is " << this->type << "." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
    std::cout << "WrongCat copy constructor" << std::endl;
    this->type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat copy assign consturcotr" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "Our " << this->type << "is dead ;()" << std::endl;
}

// Another member functions

void WrongCat::makeSound() const
{
    std::cout << "Meeeeeeeeeeeow" << std::endl;
}