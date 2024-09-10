#include "PhoneBook.hpp"

int isNumber(std::string argument)
{
    int i;

    i = 0;
    if (argument[i] >= '0' && argument[i] <= '8' && argument.length() == 1)
        return (0);
    return (1);
}
void    printInstructions(int i)
{
    if (i == 0)
    {
        std::cout << "Possible commands: ADD | SEARCH | EXIT\n\n";
        std::cout << "Enter the command: ";
    }
}
void    addCommand(PhoneBook &PhoneBook, int i, std::string line)
{
    if (line == "ADD")
        PhoneBook.setContact(i + 1);
}

int searchCommand(PhoneBook &PhoneBook, std::string line)
{
    PhoneBook.printAllPerson();
    std::cout << "Enter the index: ";
    if (!std::getline(std::cin, line))
    {
        std::cout << "\nEOF detected\n\n";
        return (1);
    }
    while (isNumber(line) == 1)
    {
        std::cout << "Enter a valid index: ";
        if (!std::getline(std::cin, line))
        {
            std::cout << "\nEOF detected\n\n";
            return (1);
        }
    }
    std::cout << "We are searching . . ." << std::endl;
    PhoneBook.printDeatils(line);
    std::cout << "\nEnter the command: ";
    return (0);
}


int main(void)
{  
    PhoneBook PhoneBook;
    std::string line;
  
    bool book = true;
    int i = 0;
    
    printInstructions(i);
    PhoneBook.validation();  
    while (book)
    {
        if (!std::getline(std::cin, line))
            break;
        if (line == "ADD")
        {
            if (i == 8)
                i = 0;
            addCommand(PhoneBook, i, line);
            i++;
        }
        else if (line == "SEARCH")
        {
           if  (searchCommand(PhoneBook, line) == 1)
                continue;
        }
        else if (line == "EXIT")
            return (0);
        else
        {
            std::cout << "Valid inputs are: ADD, SEARCH, EXIT\n\n";
            std::cout << "\nEnter the command: ";
        }
    }
        return (0);
}