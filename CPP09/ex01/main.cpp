#include "RPN.hpp"

int main(int argc, char **argv)
{
    try {
        RPN(argc, argv);
    }
    catch (const std::string &e) {
        std::cout << e << std::endl;
    }
    return 0;
}
