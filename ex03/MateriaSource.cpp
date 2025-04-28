#include "MateriaSource.h"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource class default constructor called" << '\n';

    for ( int i = 0; i < 4; ++i ) {
        mLearnedMateria[i] = nullptr;
    }
}

MateriaSource::MateriaSource( const MateriaSource& other ) {
    std::cout << "MateriaSource class copy constructor called" << '\n';

    for ( int i = 0; i < 4; ++i ) {
        // clone the other's inventory (check for NULL before dereferencing)
        if ( other.mLearnedMateria[i] )
            mLearnedMateria[i] = other.mLearnedMateria[i]->clone();
    }
}

MateriaSource& MateriaSource::operator=( const MateriaSource& other ) {
    std::cout << "MateriaSource class copy assignment operator called" << '\n';

    if ( this != &other ) {
        for ( int i = 0; i < 4; ++i ) {
            // delete own inventory first
            delete mLearnedMateria[i];
            // clone the other's inventory (check for NULL before dereferencing)
            if ( other.mLearnedMateria[i] )
                mLearnedMateria[i] = other.mLearnedMateria[i]->clone();
        }
    }

    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource class destructor called" << '\n';

    for ( int i = 0; i < 4; ++i ) {
        // delete own inventory at destruction
        delete mLearnedMateria[i];
    }
}

void MateriaSource::learnMateria( AMateria* materia ) {
    // First check if argument is not NULL
    if ( materia ) {
        // Look for an empty slot to learn the Materia
        for ( int i = 0; i < 4; ++i ) {
            if ( !mLearnedMateria[i] ) {
                mLearnedMateria[i] = materia;
                break;
            }
        }
    }
}

AMateria* MateriaSource::createMateria( std::string const& type ) {
    for ( int i = 0; i < 4; ++i ) {
        if ( mLearnedMateria[i] && type == mLearnedMateria[i]->getType() )
            return mLearnedMateria[i]->clone();
    }
    return 0;
}

bool MateriaSource::slotsAreFull() {
    for ( int i = 0; i < 4; ++i ) {
        if ( !mLearnedMateria[i] ) {
            return false;
        }
    }
    return true;
}
