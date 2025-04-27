#ifndef ICE_H
#define ICE_H

#include "AMateria.h"
#include <iostream>

class Ice : public AMateria {
  public:
    Ice();
    Ice( const Ice& other );
    Ice& operator=( const Ice& other );
    ~Ice();

    Ice( std::string const& type );

    AMateria* clone() const;
    void      use( ICharacter& target ) override;
};

#endif /* ICE_H */
