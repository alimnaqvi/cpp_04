#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include <iostream>
#include <string>

class Dog : public Animal {
  public:
    Dog();
    Dog( const Dog& other );
    Dog& operator=( const Dog& other );
    ~Dog() override;
    void makeSound() const override;
};

#endif /* DOG_H */
