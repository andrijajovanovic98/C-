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

    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);

    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
#endif