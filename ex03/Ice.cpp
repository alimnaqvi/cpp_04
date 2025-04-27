#include "Ice.h"

Ice::Ice() : AMateria{ "ice" } {
    std::cout << "Ice class default constructor called" << '\n';
}

Ice::Ice( const Ice& other ) : AMateria{ other.mType } {
    std::cout << "Ice class copy constructor called" << '\n';
}

Ice& Ice::operator=( const Ice& other ) {
    std::cout << "Ice class copy assignment operator called" << '\n';

    if ( this != &other )
        mType = other.mType;

    return *this;
}

Ice::~Ice() {
    std::cout << "Ice class destructor called" << '\n';
}

Ice::Ice( std::string const& type ) : AMateria{ type } {
    std::cout << "Ice class string constructor called" << '\n';
}

AMateria* Ice::clone() const {
    return new Ice{ mType };
}

void Ice::use( ICharacter& target ) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << '\n';
}
