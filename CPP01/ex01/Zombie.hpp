#include <iostream>
#include <new>
#include <sstream>


class Zombie {
private:

    std::string name;

public:
    Zombie();
    void setName(std::string name);
    void announce();

} ;

    Zombie* zombieHorde( int N, std::string name );