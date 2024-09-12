#include <iostream>


int main(void)
{
    std::string example = "HI THIS IS BRAIN";
    std::string *stringPTR = &example;
    std::string &stringREF = example;

    std::cout << "This is from the main string: " << example << std::endl;
    std::cout << "This is from the pointer: " << *stringPTR << std::endl;
    std::cout << "This is from the reference: " << stringREF<< std::endl;

    return (0);
}