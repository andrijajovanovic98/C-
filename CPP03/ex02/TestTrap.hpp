#ifndef TESTTRAP_HPP
#define TESTTRAP_HPP
#include "ClapTrap.hpp"


class TestTrap : public ClapTrap {
public:
    TestTrap()
    {
        std::cout << "TestTrap is executed" << std::endl;
    }
    int i;
} ;


#endif