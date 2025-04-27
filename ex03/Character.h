#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.h"
#include <string>
#include <iostream>

class Character : public ICharacter {
  public:
    Character();
    Character( const Character& other );
    Character& operator=( const Character& other );
    ~Character();

    Character( const std::string& initName );

    std::string const& getName() const;
    void               equip( AMateria* m );
    void               unequip( int idx );
    void               use( int idx, ICharacter& target );

  private:
    // inventory logic
};

#endif /* CHARACTER_H */
