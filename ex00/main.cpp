#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include <iostream>

int main() {
    // Subject tests
    std::cout << "-----------------------" << '\n';

    const Animal* meta = new Animal();
    const Animal* j    = new Dog();
    const Animal* i    = new Cat();

    std::cout << "-----------------------" << '\n';
    std::cout << BOLDUNDERLINE << "Subject tests:" << RESET << '\n';

    std::cout << MAGENTA << meta->getType() << " says: ";
    meta->makeSound();
    std::cout << i->getType() << " says: ";
    i->makeSound();  // will output the cat sound!
    std::cout << j->getType() << " says: ";
    j->makeSound();

    std::cout << RESET << "-----------------------" << '\n';

    delete meta;
    delete i;
    delete j;

    // WrongAnimal tests
    std::cout << "-----------------------" << '\n';

    const WrongAnimal* metaWrong = new WrongAnimal();
    const WrongAnimal* iWrong    = new WrongCat();

    std::cout << "-----------------------" << '\n';
    std::cout << BOLDUNDERLINE << "WrongAnimal tests:" << RESET << '\n';

    std::cout << CYAN << metaWrong->getType() << " says: ";
    metaWrong->makeSound();
    std::cout << iWrong->getType() << " says: ";
    iWrong->makeSound();  // will not output the cat sound!

    std::cout << RESET << "-----------------------" << '\n';

    delete metaWrong;
    delete iWrong;

    // Additional tests:
    std::cout << "-----------------------" << '\n';
    std::cout << BOLDUNDERLINE << "Additional tests:" << RESET << '\n';

    const Animal animal{"An animal"};
    Dog const dog;
    Cat cat;

    std::cout << "-----------------------" << '\n';

    std::cout << GREEN << animal.getType() << " says: ";
    animal.makeSound();
    std::cout << dog.getType() << " says: ";
    dog.makeSound();
    std::cout << cat.getType() << " says: ";
    cat.makeSound();

    std::cout << RESET << "-----------------------" << '\n';

    return 0;
}
