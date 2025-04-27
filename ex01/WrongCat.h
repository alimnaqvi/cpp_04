#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.h"
#include <iostream>
#include <string>

class WrongCat : public WrongAnimal {
  public:
    WrongCat();
    WrongCat( const WrongCat& other );
    WrongCat& operator=( const WrongCat& other );
    ~WrongCat() override;
    void makeSound() const;
};

#endif /* WRONGCAT_H */
