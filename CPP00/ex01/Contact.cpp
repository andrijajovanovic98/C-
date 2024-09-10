#include "Contact.hpp"

void    Contact::setFirstName(std::string first_n)
{
    first_name = first_n;
}

 void Contact::setLastName(std::string last_n)
{
    last_name = last_n;
}
 void Contact::setTelefonNumber(std::string telefonNumber)
{
    telefon_number = telefonNumber;
}

 void Contact::setDarkestSecret(std::string DarkestSecret)
{
    darkest_secret = DarkestSecret;
    std::cout << "| Succesfully added to the PhoneBook |\n";

}

 void Contact::setNickName(std::string nick_n)
{
    nick_name = nick_n;
}

 std::string  Contact::getFirstName()
{
    return (first_name);
}

std::string  Contact::getLastName()
{
    return (last_name);
}

std::string  Contact::getNickName()
{
    return (nick_name);
}

std::string  Contact::getTelefonNumber()
{
    return (telefon_number);
}

std::string  Contact::getDarkestSecret()
{
    return (darkest_secret);
}

void Contact::setIndex(int idx)
{
    index = idx;
}

int Contact::getIndex()
{
    return (index);
}

int Contact::setToValid(int setter)
{
    valid = setter;
    return (valid);
}

bool Contact::isEmpty()
{
    return first_name.empty();
}