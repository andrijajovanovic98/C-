#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

private:

    int toStore;
    static const int fractionalBits = 8;

public:

    Fixed();
    ~Fixed();
    Fixed(const Fixed& copy);
    Fixed& operator=(const Fixed& copy);

    Fixed(const int number);
    Fixed(const float number);

    int getRawBits ( void ) const;
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
#endif