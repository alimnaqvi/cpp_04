#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include "Brain.h"
#include <iostream>
#include <string>

class Cat : public Animal {
  public:
    Cat();
    Cat( const std::string& initIdea );       // pass one string to fill all 100 ideas
    Cat( const std::string initIdeas[100] );  // pass an array of 100 ideas
    Cat( const Cat& other );
    Cat& operator=( const Cat& other );
    ~Cat() override;

    void              makeSound() const override;
    const std::string getFirstThought() const override;

  private:
    Brain* mBrain;
};

#endif /* CAT_H */
