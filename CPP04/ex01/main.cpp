#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

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

/* int main()
{
  int SIZE = 4;

  Animal *animals[SIZE];

    for (int i = 0; i < SIZE / 2; ++i)
        animals[i] = new Dog(); 
    for (int i = SIZE / 2; i < SIZE; ++i)
        animals[i] = new Cat();
    for (int i = 0; i < SIZE; ++i)
        animals[i]->makeSound();

    for (int i = 0; i < 4; ++i)
        delete animals[i];
    return (0);
} */

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;
    return 0;
}