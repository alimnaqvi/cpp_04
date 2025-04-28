#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.h"
#include "AMateria.h"
#include <string>
#include <iostream>

class Character : public ICharacter {
  public:
    // Orthodox canonical form
    Character();
    Character( const Character& other );
    Character& operator=( const Character& other );
    ~Character() override;

    // Constructor taking Character name as parameter
    Character( const std::string& initName );

    // Required member functions
    std::string const& getName() const override;
    void               equip( AMateria* m ) override;
    void               unequip( int idx ) override;
    void               use( int idx, ICharacter& target ) override;

    // Additional functionality (memory management)
    bool      inventoryIsFull();
    AMateria* getAddressAtIdx( int idx );

  private:
    std::string mName;
    AMateria*   mInventory[4];
};

#endif /* CHARACTER_H */
