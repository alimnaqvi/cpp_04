#include "WrongCat.h"

WrongCat::WrongCat() : WrongAnimal{ "WrongCat" } {
    std::cout << "WrongCat class default constructor called (type: " << type << ").\n";
}

WrongCat::WrongCat( const WrongCat& other ) : WrongAnimal{ other.type } {
    std::cout << "WrongCat class copy constructor called (type: " << type << ").\n";
}

WrongCat& WrongCat::operator=( const WrongCat& other ) {
    std::cout << "WrongCat class copy assignment operator called (type: " << type << ").\n";

    if ( this != &other )
        type = other.type;

    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat class destructor called (type: " << type << ").\n";
}

void WrongCat::makeSound() const {
    std::cout << "Meow!" << '\n';
}
