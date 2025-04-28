#ifndef AMATERIA_H
#define AMATERIA_H

#include "ICharacter.h"
#include <string>
#include <iostream>

class ICharacter;

class AMateria {
  protected:
    std::string mType;

  public:
    // Orthodox canonical form
    AMateria();
    AMateria( const AMateria& other );
    AMateria& operator=( const AMateria& other );
    virtual ~AMateria();

    // String constructor as required by subject
    AMateria( std::string const& type );

    std::string const& getType() const;  // Returns the materia type

    virtual AMateria* clone() const = 0;
    virtual void      use( ICharacter& target );
};

#endif /* AMATERIA_H */
