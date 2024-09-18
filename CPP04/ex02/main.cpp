#include "AAnimal.hpp"
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
    const AAnimal* meta = new AAnimal();
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
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

  AAnimal *AAnimals[SIZE];

    for (int i = 0; i < SIZE / 2; ++i)
        AAnimals[i] = new Dog(); 
    for (int i = SIZE / 2; i < SIZE; ++i)
        AAnimals[i] = new Cat();
    for (int i = 0; i < SIZE; ++i)
        AAnimals[i]->makeSound();

    for (int i = 0; i < 4; ++i)
        delete AAnimals[i];
    return (0);
} */

/* int main()
{
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    delete j;
    delete i;
    return 0;
} */

int main()
{
    Dog dog;
    dog.makeSound();

    Cat cat;
    cat.makeSound();
    return (0);
}