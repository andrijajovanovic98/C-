#ifndef ANIMALL_HPP
# define ANIMALL_HPP

#include <iostream>

class Animal {
protected:

    std::string type;

public:

    Animal();
    Animal(const Animal &other);
    Animal& operator=(const Animal& other);
    ~Animal();

    std::string getType() const;
    virtual void makeSound() const;

} ;

#endif