#include "Character.h"

Character::Character() : mName{ "defaultName" } {
    std::cout << "Character class default constructor called" << '\n';

    for ( int i = 0; i < 4; ++i ) {
        mInventory[i] = nullptr;
    }
}

Character::Character( const Character& other ) : mName{ other.mName } {
    std::cout << "Character class copy constructor called" << '\n';

    for ( int i = 0; i < 4; ++i ) {
        // clone the other's inventory (check for NULL before dereferencing)
        if ( other.mInventory[i] )
            mInventory[i] = other.mInventory[i]->clone();
    }
}

Character& Character::operator=( const Character& other ) {
    std::cout << "Character class copy assignment operator called" << '\n';

    if ( this != &other ) {
        mName = other.mName;

        for ( int i = 0; i < 4; ++i ) {
            // delete own inventory first
            delete mInventory[i];
            // clone the other's inventory (check for NULL before dereferencing)
            if ( other.mInventory[i] )
                mInventory[i] = other.mInventory[i]->clone();
        }
    }

    return *this;
}

Character::~Character() {
    std::cout << "Character class destructor called" << '\n';

    for ( int i = 0; i < 4; ++i ) {
        // delete own inventory at destruction
        delete mInventory[i];
    }
}

Character::Character( const std::string& initName ) : mName{ initName } {
    std::cout << "Character class string constructor called" << '\n';

    for ( int i = 0; i < 4; ++i ) {
        mInventory[i] = nullptr;
    }
}

std::string const& Character::getName() const {
    return mName;
}

void Character::equip( AMateria* m ) {
    for ( int i = 0; i < 4; ++i ) {
        if ( !mInventory[i] ) {
            mInventory[i] = m;
            break;
        }
    }
}

void Character::unequip( int idx ) {
    mInventory[idx] = nullptr;
}

void Character::use( int idx, ICharacter& target ) {
    if ( mInventory[idx] )
        mInventory[idx]->use( target );
    else
        std::cout << "Slot " << idx << " is empty!" << '\n';
}

bool Character::inventoryIsFull() {
    for ( int i = 0; i < 4; ++i ) {
        if ( !mInventory[i] ) {
            return false;
        }
    }
    return true;
}

AMateria* Character::getAddressAtIdx( int idx ) {
    return mInventory[idx];
}
