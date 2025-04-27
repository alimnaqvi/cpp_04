#ifndef CURE_H
#define CURE_H

#include "AMateria.h"
#include <iostream>

class Cure : public AMateria {
  public:
    Cure();
    Cure( const Cure& other );
    Cure& operator=( const Cure& other );
    ~Cure();

    Cure( std::string const& type );

    AMateria* clone() const;
    void      use( ICharacter& target ) override;
};

#endif /* CURE_H */
