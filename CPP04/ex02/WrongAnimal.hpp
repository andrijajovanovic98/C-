#ifndef WRONGAAnimalL_HPP
# define WRONGAAnimalL_HPP

#include <iostream>

class WrongAAnimal {
protected:

    std::string type;

public:

    WrongAAnimal();
    ~WrongAAnimal();

    WrongAAnimal(const WrongAAnimal &other);
    std::string getType() const;
    void makeSound() const;
    WrongAAnimal& operator=(const WrongAAnimal& other);

} ;

#endif