#include "Fixed.hpp"

Fixed::Fixed()
{
    toStore = 0;
}

Fixed::~Fixed()
{
}
Fixed::Fixed(const int numb)
{
    this->toStore = numb << this->fractionalBits; 
}

Fixed::Fixed(const float numb)
{
    
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
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    if (this != &copy)
        this->toStore = copy.getRawBits();
    return (*this);
}

int Fixed::getRawBits() const
{
    return (this->toStore);
}

// Comparison Operators

bool Fixed::operator>(const Fixed& other) const
{
    return this->toStore > other.toStore;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->toStore < other.toStore;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->toStore >= other.toStore;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->toStore <= other.toStore;
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->toStore == other.toStore;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->toStore != other.toStore;
}

// Arithmetic Operators

Fixed Fixed::operator+(const Fixed& other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

// Incrementation

Fixed& Fixed::operator++()
{
    this->toStore++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(*this);
    return (temp);
}

Fixed& Fixed::operator--()
{
    this->toStore--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --(*this);
    return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

