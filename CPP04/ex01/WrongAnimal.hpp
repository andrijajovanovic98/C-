#ifndef WRONGANIMALL_HPP
# define WRONGANIMALL_HPP

#include <iostream>

class WrongAnimal {
protected:

    std::string type;

public:

    WrongAnimal();
    ~WrongAnimal();

    WrongAnimal(const WrongAnimal &other);
    std::string getType() const;
    void makeSound() const;
    WrongAnimal& operator=(const WrongAnimal& other);

} ;

#endif