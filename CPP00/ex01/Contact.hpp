#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <cctype> 

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string telefon_number;
        std::string darkest_secret;
        int         index;

    public:
    int         valid;
    void    setFirstName(std::string first_n);
    void    setLastName(std::string last_n);
    void    setNickName(std::string nick_n);
    void    setTelefonNumber(std::string telefonNumber);
    void    setDarkestSecret(std::string DarkestSecret);

    std::string  getFirstName();
    std::string  getLastName();
    std::string  getNickName();
    std::string  getTelefonNumber();
    std::string  getDarkestSecret();

    int     getIndex();
    void    setIndex(int idx);
    int     setToValid(int setter);
    bool    isEmpty();
};

#endif