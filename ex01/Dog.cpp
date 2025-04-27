#include "Dog.h"

Dog::Dog() : Animal{ "Dog" }, mBrain{ new Brain } {
    std::cout << "Dog class default constructor called (type: " << type << ").\n";
}

Dog::Dog( const std::string& initIdea ) : Animal{ "Dog" }, mBrain{ new Brain{ initIdea } } {
    std::cout << "Dog class string constructor called (type: " << type << ").\n";
}

Dog::Dog( const std::string initIdeas[100] ) : Animal{ "Dog" }, mBrain{ new Brain{ initIdeas } } {
    std::cout << "Dog class array constructor called (type: " << type << ").\n";
}

Dog::Dog( const Dog& other ) : Animal{ other.type } {
    std::cout << "Dog class copy constructor called (type: " << type << ").\n";

    // allocate new Brain only if it is not a null pointer
    if ( other.mBrain )
        mBrain = new Brain{ *( other.mBrain ) };
    else
        mBrain = other.mBrain;
}

Dog& Dog::operator=( const Dog& other ) {
    std::cout << "Dog class copy assignment operator called (type: " << type << ").\n";

    if ( this != &other ) {
        type = other.type;

        // delete current Brain first
        delete mBrain;

        // allocate new Brain only if it is not a null pointer
        if ( other.mBrain )
            mBrain = new Brain{ *( other.mBrain ) };
        else
            mBrain = other.mBrain;
    }

    return *this;
}

Dog::~Dog() {
    std::cout << "Dog class destructor called (type: " << type << ").\n";

    delete mBrain;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << '\n';
}

const std::string Dog::getFirstThought() const {
    return mBrain->getIdeas()[0];
}
