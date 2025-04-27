#include "Animal.h"

Animal::Animal() : type{ "unknownType" } {
    std::cout << "Animal class default constructor called (type: " << type << ").\n";
}

Animal::Animal( const std::string& initType ) : type{ initType } {
    std::cout << "Animal class string constructor called (type: " << type << ").\n";
}

Animal::Animal( const Animal& animal ) : type{ animal.type } {
    std::cout << "Animal class copy constructor called (type: " << type << ").\n";
}

Animal& Animal::operator=( const Animal& animal ) {
    std::cout << "Animal class copy assignment operator called (type: " << type << ").\n";

    if ( this != &animal )
        type = animal.type;

    return *this;
}

Animal::~Animal() {
    std::cout << "Animal class destructor called (type: " << type << ").\n";
}

void Animal::makeSound() const {
    std::cout << "unknownSound" << '\n';
}

const std::string Animal::getFirstThought() const {
    return "unknownThought";
}

const std::string& Animal::getType() const {
    return type;
}
