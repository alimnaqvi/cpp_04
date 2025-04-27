#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

#define BOLDUNDERLINE "\033[1m\033[4m"
#define MAGENTA       "\033[35m"
#define BLUE          "\033[34m"
#define CYAN          "\033[36m"
#define RED           "\033[31m"
#define GREEN         "\033[32m"
#define RESET         "\033[0m"

class Animal {
  public:
    Animal();
    Animal( const std::string& initType );
    Animal( const Animal& animal );
    Animal& operator=( const Animal& animal );
    virtual ~Animal();

    virtual void              makeSound() const = 0;
    virtual const std::string getFirstThought() const = 0;
    const std::string&        getType() const;

  protected:
    std::string type;
};

#endif /* ANIMAL_H */
