#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include "Brain.h"
#include <iostream>
#include <string>

class Dog : public Animal {
  public:
    Dog();
    Dog( const std::string& initIdea );       // pass one string to fill all 100 ideas
    Dog( const std::string initIdeas[100] );  // pass an array of 100 ideas
    Dog( const Dog& other );
    Dog& operator=( const Dog& other );
    ~Dog() override;

    void              makeSound() const override;
    const std::string getFirstThought() const override;

  private:
    Brain* mBrain;
};

#endif /* DOG_H */
