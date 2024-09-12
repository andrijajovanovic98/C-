#include "Harl.hpp"

void Harl::debug( void )
{
    std::cerr << \
    "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" \
    << std::endl;
}
void Harl::info( void )
{
     std::cout << \
     "I cannot believe adding extra bacon costs more money." << std::endl;
     std::cout << " You didn't put \
    enough bacon in my burger! If you did, I wouldn't be asking for more!" \
    << std::endl;

}
void Harl::warning( void )
{
     std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
     std::cout << "I've been coming for years whereas you started working here since last month" << std::endl;
}
void Harl::error( void )
{
     std::cout << \
     "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{   
    int i;
    
    std::string commands[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; level != commands[i]; i++)
        if (i == 5)
        {
            std::cout << "DEBUG, INFO, WARNING, ERROR commands are allowed." << std::endl;
            return ;
        }

    void(Harl::*funcPtr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    
    while (i <= 3)
    {
        (this->*funcPtr[i])();
        std::cout << std::endl;
        i++;
    }
}