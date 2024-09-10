#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <cctype> 
#include "Contact.hpp"

#define isnumchek 6
#define isalphacheck 5
#define init 5

class PhoneBook
{
    private:
        Contact contacts[8];
        std::string input;

    public:
        void    setContact(int index);  
        void    printAllPerson();
        void    printDeatils(std::string idx);
        void     validation();
};

#endif