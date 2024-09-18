#include "Cat.hpp"

// Orthodox

Cat::Cat()
{
    brain = new Brain();
    this->type = "Cat";
    std::cout << "The type of the animal is " << this->type << "." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Cat is copied with copy construktor ! :)";
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        delete brain;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

Cat::~Cat()
{
    delete brain;
    std::cout << this->type << " is destructed" << std::endl;
}

// Another member functions

void Cat::makeSound() const
{
    std::cout << "Meeeeeeeeeeeow" << std::endl;
}
