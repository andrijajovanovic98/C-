#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}

/* int main() {
    Fixed a(10); 
    Fixed b(2.5f);    

    std::cout << "Res (a * b): " << (a * b) << std::endl;
    std::cout << "Res (a / b): " << (a / b) << std::endl;
    std::cout << "Res (a + b): " << (a + b) << std::endl;
    std::cout << "Res (a - b): " << (a - b) << std::endl;

    return 0;
} */