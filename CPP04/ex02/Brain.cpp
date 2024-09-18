#include "Brain.hpp"

// Orthodox

Brain::Brain()
{
    std::cout << "Brain is constructed" << std::endl;
    for (int i = 0; i < 100; ++i)
        this->ideas[i] = "food";
}
Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructe" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
}
Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain assigned" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain is destructed" << std::endl;
}