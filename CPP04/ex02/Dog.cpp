#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
    this->type = "Dog";
    brain = new Brain();
    std::cout << "The type of the AAnimal is " << this->type << "." << std::endl;

}
Dog::Dog(const Dog& other) : AAnimal(other)
{ 
    brain = new Brain(*other.brain);
    this->type = other.type;
    std::cout << "Dog copy constructed" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        AAnimal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
        this->type = other.type;
    }
    std::cout << "Dog copy assigned constructor" << std::endl;
    return (*this);

}

Dog::~Dog()
{
    delete brain;
    std::cout << "The dog is destructed" << std::endl;
}
void Dog::makeSound() const
{
    std::cout << "Barkkk" << std::endl;
}
