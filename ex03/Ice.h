#ifndef ICE_H
#define ICE_H

#include "AMateria.h"
#include <iostream>

class Ice : public AMateria {
  public:
    Ice();
    Ice( const Ice& other );
    Ice& operator=( const Ice& other );
    ~Ice() override;

    AMateria* clone() const override;
    void      use( ICharacter& target ) override;
};

#endif /* ICE_H */
