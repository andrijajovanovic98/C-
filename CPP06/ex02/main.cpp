#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>

Base* generate(void)
{
    int randomValue = rand() % 3;
    std::cout << "Random value: " << randomValue << std::endl;
    if (randomValue == 0)
        return new A();
    else if (randomValue == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (...)
    {
        try
        {
            (void)dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch (...) 
        {
            try
            {
                (void)dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }
            catch (...)
            {        
                std::cout << "Unknown type" << std::endl;
            }
        }
    }

}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    Base* obj = generate();

    Base baseobj;

    std::cout << "Using pointer:" << std::endl;
    identify(obj);

    std::cout << "Using reference:" << std::endl;
    identify(*obj);

    delete obj; 
    return 0;
}
