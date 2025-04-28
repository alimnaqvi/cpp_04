#include "Cure.h"

Cure::Cure() : AMateria{ "cure" } {
    std::cout << "Cure class default constructor called" << '\n';
}

Cure::Cure( const Cure& other ) : AMateria{ other.mType } {
    std::cout << "Cure class copy constructor called" << '\n';
}

Cure& Cure::operator=( const Cure& other ) {
    std::cout << "Cure class copy assignment operator called" << '\n';

    if ( this != &other )
        mType = other.mType;

    return *this;
}

Cure::~Cure() {
    std::cout << "Cure class destructor called" << '\n';
}

Cure::Cure( std::string const& type ) : AMateria{ type } {
    std::cout << "Cure class string constructor called" << '\n';
}

AMateria* Cure::clone() const {
    return new Cure{ mType };
}

void Cure::use( ICharacter& target ) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << '\n';
}
