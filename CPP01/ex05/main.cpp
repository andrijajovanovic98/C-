#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl test;

    if (argc < 2)
    {
        std::cerr << "This program requires one argument to execute." << std::endl;
        std::cerr << "DEBUG, INFO, WARNING, ERROR arguments are allowed." << std::endl;
        return (1);
    }
    test.complain(argv[1]);
    return (0);
}