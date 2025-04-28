#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.h"

class MateriaSource : public IMateriaSource {
  public:
    // Orthodox canonical form
    MateriaSource();
    MateriaSource( const MateriaSource& other );
    MateriaSource& operator=( const MateriaSource& other );
    ~MateriaSource();

    // Required member functions
    void      learnMateria( AMateria* materia ) override;
    AMateria* createMateria( std::string const& type ) override;

    // Additional functionality (memory management)
    bool slotsAreFull();

  private:
    AMateria* mLearnedMateria[4];
};

#endif /* MATERIASOURCE_H */
