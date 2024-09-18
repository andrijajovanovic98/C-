#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/* int main(void)
{
    Cat meow;
    Dog bark;

    bark.makeSound();
    meow.makeSound();
    return (0);
} */

/* int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    return 0;
} */

int main(void)
{
    WrongAnimal* wrongAnimal = new WrongAnimal();
    WrongAnimal* wrongCat = new WrongCat();

    std::cout << "WrongAnimal sound: ";
    wrongAnimal->makeSound();
    std::cout << "WrongCat sound: ";
    wrongCat->makeSound();
    return (0);

}