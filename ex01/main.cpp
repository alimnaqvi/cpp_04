#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include <new>
#include <iostream>

int main() {
    int exitStatus{ 0 };

    // Allocate an array of 20 pointers to animals on the stack
    Animal* animalArray[20]{};

    try {
        // Loop through the array to dynamically allocate cats and dogs
        for ( int i = 0; i < 20; ++i ) {
            // 5 cats with their Brain filled with "sleep" array
            if ( i < 5 )
                animalArray[i] = new Cat{ "sleep" };
            // 5 cats with their Brain filled with "food" array
            else if ( i < 10 )
                animalArray[i] = new Cat{ "food" };
            // 5 dogs with their Brain filled with "hooman" array
            else if ( i < 15 )
                animalArray[i] = new Dog{ "hooman" };
            // 5 dogs with their Brain filled with "boops" array
            else if ( i < 20 )
                animalArray[i] = new Dog{ "boops" };
        }

        // makeSound and getFirstThought tests
        std::cout << "-----------------------" << '\n';
        std::cout << BOLDUNDERLINE << "makeSound and getFirstThought tests:" << RESET << '\n';

        std::cout << MAGENTA;
        std::cout << animalArray[4]->getType() << " is thinking of " << animalArray[4]->getFirstThought()
                  << " and says: ";
        animalArray[4]->makeSound();
        std::cout << animalArray[8]->getType() << " is thinking of " << animalArray[8]->getFirstThought()
                  << " and says: ";
        animalArray[8]->makeSound();
        std::cout << animalArray[12]->getType() << " is thinking of " << animalArray[12]->getFirstThought()
                  << " and says: ";
        animalArray[12]->makeSound();
        std::cout << animalArray[16]->getType() << " is thinking of " << animalArray[16]->getFirstThought()
                  << " and says: ";
        animalArray[16]->makeSound();

        std::cout << RESET << "-----------------------" << '\n';

        // Deep copy tests
        std::cout << BOLDUNDERLINE << "Deep copy tests:" << RESET << '\n';
        Dog* deepDog{ new Dog{ "boops" } };
        std::cout << "-----------------------" << '\n';

        std::cout << BLUE;
        std::cout << "Before copying, dog was thinking of " << deepDog->getFirstThought() << " and said: ";
        deepDog->makeSound();

        std::cout << RESET << "-----------------------" << '\n';
        Dog const copyDog{ "food" };
        *deepDog = copyDog;

        std::cout << "-----------------------" << '\n';
        std::cout << BLUE;
        std::cout << "After copying, dog is thinking of " << deepDog->getFirstThought() << " and says: ";
        deepDog->makeSound();

        std::cout << RESET << "-----------------------" << '\n';
        delete deepDog;

        Cat*      copyCat{ new Cat{ "laser pointer" } };
        const Cat deepCat{ *copyCat };

        std::cout << "-----------------------" << '\n';
        std::cout << GREEN << "Both copyCat and deepCat say: " << '\n';
        copyCat->makeSound();
        deepCat.makeSound();
        std::cout << "copyCat is thinking of " << copyCat->getFirstThought() << '\n';
        std::cout << RESET << "-----------------------" << '\n';
        delete copyCat;
        std::cout << "-----------------------" << '\n';
        // Should not crash / segmentation fault
        std::cout << GREEN << "deepCat is also thinking of " << deepCat.getFirstThought() << '\n';

        // WrongAnimal tests
        std::cout << RESET << "-----------------------" << '\n';

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

    } catch ( const std::bad_alloc& e ) {
        std::cerr << "Memory allocation failed: " << e.what() << '\n';
        exitStatus = 1;
    }

    for ( int i = 0; i < 20; ++i ) {
        delete animalArray[i];
    }

    return exitStatus;
}

// // Generic tests without custom functions (only subject requirements)
// int main() {
//     // Allocate an array of 20 pointers to animals on the stack
//     Animal* animalArray[20]{};

//     // Loop through the array to dynamically allocate cats and dogs
//     for ( int i = 0; i < 20; ++i ) {
//         if ( i < 10 )
//             animalArray[i] = new Cat;
//         else
//             animalArray[i] = new Dog;
//     }

//     // makeSound tests
//     std::cout << "-----------------------" << '\n';
//     std::cout << "\033[1m\033[4m" << "makeSound tests:" << "\033[0m" << '\n';

//     std::cout << "\033[35m";
//     std::cout << animalArray[4]->getType() << " says: ";
//     animalArray[4]->makeSound();
//     std::cout << animalArray[8]->getType() << " says: ";
//     animalArray[8]->makeSound();
//     std::cout << animalArray[12]->getType() << " says: ";
//     animalArray[12]->makeSound();
//     std::cout << animalArray[16]->getType() << " says: ";
//     animalArray[16]->makeSound();

//     std::cout << "\033[0m" << "-----------------------" << '\n';
//     // should not create memory leaks
//     for ( int i = 0; i < 20; ++i ) {
//         delete animalArray[i];
//     }

//     // deep copy tests
//     Dog* deepDog{ new Dog };
//     std::cout << "-----------------------" << '\n';

//     std::cout << "\033[34m";
//     std::cout << "Before copying, dog said: ";
//     deepDog->makeSound();

//     std::cout << "\033[0m" << "-----------------------" << '\n';
//     Dog const copyDog;
//     // should not create leak
//     *deepDog = copyDog;

//     std::cout << "-----------------------" << '\n';
//     std::cout << "\033[34m";
//     std::cout << "After copying, dog says: ";
//     deepDog->makeSound();

//     std::cout << "\033[0m" << "-----------------------" << '\n';
//     delete deepDog;
//     Cat*      copyCat{ new Cat };
//     const Cat deepCat{ *copyCat };

//     std::cout << "-----------------------" << '\n';
//     std::cout << "\033[32m" << "Both deepCat and copyCat say: " << '\n';
//     copyCat->makeSound();
//     deepCat.makeSound();

//     std::cout << "\033[0m" << "-----------------------" << '\n';

//     delete copyCat;
//     // if we access the Brain contents of deepCat here, there should be no crash / segmentation fault

//     return 0;
// }
