#ifndef AAnimalL_HPP
# define AAnimalL_HPP

#include <iostream>

class AAnimal {
protected:

    std::string type;

public:

    AAnimal();
    AAnimal(const AAnimal &other);
    AAnimal& operator=(const AAnimal& other);
    virtual ~AAnimal();

    std::string getType() const;
    virtual void makeSound() const = 0;

} ;

#endif