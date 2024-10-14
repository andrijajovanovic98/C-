#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const int numb)
{
    std::cout << "Int constructor called" << std::endl;
    this->toStore = numb << this->fractionalBits; 
}

Fixed::Fixed(const float numb)
{
    std::cout << "Float constructor called" << std::endl;
    
    this->toStore = roundf(numb * (1 << fractionalBits));
}
float Fixed::toFloat() const
{
    return static_cast<float>(toStore) / (1 << fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

int Fixed::toInt( void ) const
{
    return toStore >> this->fractionalBits;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}


Fixed& Fixed::operator=(const Fixed& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->toStore = copy.getRawBits();
    return (*this);
}

int Fixed::getRawBits() const
{
    return (this->toStore);
}
