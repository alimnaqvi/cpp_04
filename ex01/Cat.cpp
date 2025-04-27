#include "Cat.h"

Cat::Cat() : Animal{ "Cat" }, mBrain{ new Brain } {
    std::cout << "Cat class default constructor called (type: " << type << ").\n";
}

Cat::Cat( const std::string& initIdea ) : Animal{ "Cat" }, mBrain{ new Brain{ initIdea } } {
    std::cout << "Cat class string constructor called (type: " << type << ").\n";
}

Cat::Cat( const std::string initIdeas[100] ) : Animal{ "Cat" }, mBrain{ new Brain{ initIdeas } } {
    std::cout << "Cat class array constructor called (type: " << type << ").\n";
}

Cat::Cat( const Cat& other ) : Animal{ other.type } {
    std::cout << "Cat class copy constructor called (type: " << type << ").\n";

    // allocate new Brain only if it is not a null pointer
    if ( other.mBrain )
        mBrain = new Brain{ *( other.mBrain ) };
    else
        mBrain = other.mBrain;
}

Cat& Cat::operator=( const Cat& other ) {
    std::cout << "Cat class copy assignment operator called (type: " << type << ").\n";

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

Cat::~Cat() {
    std::cout << "Cat class destructor called (type: " << type << ").\n";

    delete mBrain;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << '\n';
}

const std::string Cat::getFirstThought() const {
    return mBrain->getIdeas()[0];
}
