#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->toStore = 0;
}
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    this->toStore = 0;
}
Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->toStore = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->toStore = copy.getRawBits();
    return (*this);
}
void Fixed::setRawBits( int const raw )
{
    this->toStore = raw;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->toStore);
}


