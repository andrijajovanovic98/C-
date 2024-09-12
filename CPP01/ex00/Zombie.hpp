#include <iostream>
#include <new>


class Zombie {

private:
    std::string name;


public:
    void    announce(void);
    void    setname(std::string nameToSet);
    
    Zombie(const std::string &name);
    ~Zombie();

};


void    randomChump(std::string name);
Zombie* newZombie(const std::string &name);