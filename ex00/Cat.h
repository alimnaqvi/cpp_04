#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include <iostream>
#include <string>

class Cat : public Animal {
  public:
    Cat();
    Cat( const Cat& other );
    Cat& operator=( const Cat& other );
    ~Cat() override;
    void makeSound() const override;
};

#endif /* CAT_H */
