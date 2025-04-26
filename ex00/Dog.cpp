#include "Dog.h"

Dog::Dog() : Animal{ "Dog" } {
    std::cout << "Dog class default constructor called (type: " << type << ").\n";
}

Dog::Dog( const Dog& other ) : Animal{ other.type } {
    std::cout << "Dog class copy constructor called (type: " << type << ").\n";
}

Dog& Dog::operator=( const Dog& other ) {
    std::cout << "Dog class copy assignment operator called (type: " << type << ").\n";

    if ( this != &other )
        type = other.type;

    return *this;
}

Dog::~Dog() {
    std::cout << "Dog class destructor called (type: " << type << ").\n";
}

void Dog::makeSound() const {
    std::cout << "Woof!" << '\n';
}
