#ifndef AMATERIA_H
#define AMATERIA_H

#include "ICharacter.h"
#include <string>
#include <iostream>

class ICharacter;

class AMateria {
  protected:
    std::string mType;
    //[...]

  public:
    AMateria();
    AMateria( const AMateria& other );
    AMateria& operator=( const AMateria& other );
    virtual ~AMateria();

    AMateria( std::string const& type );

    //[...]

    std::string const& getType() const;  // Returns the materia type

    virtual AMateria*  clone() const = 0;
    virtual void       use( ICharacter& target );
};

#endif /* AMATERIA_H */
