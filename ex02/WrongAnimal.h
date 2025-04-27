#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>
#include <string>

class WrongAnimal {
  public:
    WrongAnimal();
    WrongAnimal( const std::string& initType );
    WrongAnimal( const WrongAnimal& animal );
    WrongAnimal& operator=( const WrongAnimal& animal );
    virtual ~WrongAnimal();

    void               makeSound() const;
    const std::string& getType() const;

  protected:
    std::string type;
};

#endif /* WRONGANIMAL_H */
