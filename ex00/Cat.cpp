#include "Cat.h"

Cat::Cat() : Animal{ "Cat" } {
    std::cout << "Cat class default constructor called (type: " << type << ").\n";
}

Cat::Cat( const Cat& other ) : Animal{ other.type } {
    std::cout << "Cat class copy constructor called (type: " << type << ").\n";
}

Cat& Cat::operator=( const Cat& other ) {
    std::cout << "Cat class copy assignment operator called (type: " << type << ").\n";

    if ( this != &other )
        type = other.type;

    return *this;
}

Cat::~Cat() {
    std::cout << "Cat class destructor called (type: " << type << ").\n";
}

void Cat::makeSound() const {
    std::cout << "Meow!" << '\n';
}
