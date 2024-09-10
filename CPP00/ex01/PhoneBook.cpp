#include "PhoneBook.hpp"

std::string formatColumn(const std::string &text)
{
    if (text.length() > 10)
        return text.substr(0, 9) + ".";
    return std::string(10 - text.length(), ' ') + text;
}

int argumentCheck(std::string input, int mode)
{
    int i;

    if (mode == 6)
    {
        for (i = 0; input[i] ; i++)
        {
            if (!isdigit(input[i]))
                return (0);
        }
    }
    if (mode == 5)
    {
        for (i = 0; input[i] ; i++)
        {
            if (!isalpha(input[i]))
                return (0);
        }
    }
    return (1);
}

int    ssafeADD(std::string text, std::string *input, int mode)
{
    int check;

    check = -1;
    while (true)
    {
        std::cout << text;
        
        if (!std::getline(std::cin, *input))
        {
            std::cout << "\nEOF detected\n\n";
            return (1);
        }
        check = argumentCheck(*input, mode);
        if (!input->empty() && check == 1)
            break;
    }
    return (0);
}
int stringToInt(const std::string &str)
{
    return std::atoi(str.c_str());
}

void PhoneBook::validation()
{
    int i;

    for (i = 0; i <= 7; i++)
        contacts[i].setToValid(init);
}   
void    PhoneBook::setContact(int index)
{
    index--;
    contacts[index].setIndex(index);
    contacts[index].setToValid(1);
    if (ssafeADD("Enter the firstname: ", &input, isalphacheck) == 1)
        return ;
    contacts[index].setFirstName(input);
    if (ssafeADD("Enter the last name: ", &input, isalphacheck) == 1)
        return ;
    contacts[index].setLastName(input);
    if (ssafeADD("Enter the nickname: ", &input, isalphacheck) == 1)
        return ;
    contacts[index].setNickName(input);
    if (ssafeADD("Enter the telefon number: ", &input, isnumchek) == 1)
        return ; 
    contacts[index].setTelefonNumber(input);
    if (ssafeADD("Enter your darkest secret: ", &input , isalphacheck) == 1)
        return ;
    contacts[index].setDarkestSecret(input);
    std::cout << "\nEnter the command: ";    
}
void PhoneBook::printDeatils(std::string idx)
{
    int index = stringToInt(idx);
    index--;
    if (contacts[index].valid == 1)
    {
        std::cout << "\nThe first name is ";
        std::cout << contacts[index].getFirstName() << "\n";
        std::cout << "The last name is ";
        std::cout << contacts[index].getLastName() << "\n";
        std::cout << "The nick name is ";
        std::cout << contacts[index].getNickName() << "\n";
        std::cout << "The telefonnumber is ";
        std::cout << contacts[index].getTelefonNumber() << "\n";
        std::cout << "The darkest secret is ";
        std::cout << contacts[index].getDarkestSecret() << "\n";
    }
    else 
        std::cout << "\nNot avilable index!\n\n";
}

 void    PhoneBook::printAllPerson()
{            
    std::stringstream ss;
    int index = 0;

    while (contacts[index].valid == 1)
    {
        ss << index + 1;
        std::string num = ss.str();
        std::string firstName = contacts[index].getFirstName();
        std::string lastName = contacts[index].getLastName();
        std::string nickName = contacts[index].getNickName();
        std::cout << "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n|\n";
        std::cout << "| " << formatColumn("index") << "| ";
        std::cout << formatColumn("firstname") << "| " << formatColumn("lastname");
        std::cout << "| " << formatColumn("nickname") << "|" << "\n" ;
        std::cout << "_______________________________________________________\n|\n";         
        std::cout << "| " << formatColumn(num) << "| ";
        std::cout << formatColumn(firstName) << "| " << formatColumn(lastName);
        std::cout << "| " << formatColumn(nickName) << "|" << "\n" ;
        std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _";
        index++;
        ss.str("");
    }
    std::cout << "\n\n";
}

