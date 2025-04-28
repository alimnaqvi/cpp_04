#include "AMateria.h"

AMateria::AMateria() : mType{ "unknown type" } {
    std::cout << "AMateria class default constructor called" << '\n';
}

AMateria::AMateria( const AMateria& other ) : mType{ other.mType } {
    std::cout << "AMateria class copy constructor called" << '\n';
}

AMateria& AMateria::operator=( const AMateria& other ) {
    std::cout << "AMateria class copy assignment operator called" << '\n';

    if ( this != &other )
        mType = other.mType;

    return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria class destructor called" << '\n';
}

AMateria::AMateria( std::string const& type ) : mType{ type } {
    std::cout << "AMateria class string constructor called" << '\n';
}

std::string const& AMateria::getType() const {
    return mType;
}

void AMateria::use( ICharacter& target ) {
    std::cout << "* uses unknown materia at " << target.getName() << " *" << '\n';
}
