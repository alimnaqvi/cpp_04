#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() : type{ "unknownType" } {
    std::cout << "WrongAnimal class default constructor called (type: " << type << ").\n";
}

WrongAnimal::WrongAnimal( const std::string& initType ) : type{ initType } {
    std::cout << "WrongAnimal class string constructor called (type: " << type << ").\n";
}

WrongAnimal::WrongAnimal( const WrongAnimal& animal ) : type{ animal.type } {
    std::cout << "WrongAnimal class copy constructor called (type: " << type << ").\n";
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& animal ) {
    std::cout << "WrongAnimal class copy assignment operator called (type: " << type << ").\n";

    if ( this != &animal )
        type = animal.type;

    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal class destructor called (type: " << type << ").\n";
}

void WrongAnimal::makeSound() const {
    std::cout << "unknownSound" << '\n';
}

const std::string& WrongAnimal::getType() const {
    return type;
}
