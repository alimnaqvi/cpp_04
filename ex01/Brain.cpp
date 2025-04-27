#include "Brain.h"

Brain::Brain() {
    std::cout << "Brain class default constructor called" << '\n';

    for ( int i = 0; i < 100; ++i )
        ideas[i] = "";
}

Brain::Brain( const std::string& initIdea ) {
    std::cout << "Brain class string constructor called" << '\n';

    for ( int i = 0; i < 100; ++i )
        ideas[i] = initIdea;
}

Brain::Brain( const std::string initIdeas[100] ) {
    std::cout << "Brain class array constructor called" << '\n';

    for ( int i = 0; i < 100; ++i )
        ideas[i] = initIdeas[i];
}

Brain::Brain( const Brain& brain ) {
    std::cout << "Brain class copy constructor called" << '\n';

    for ( int i = 0; i < 100; ++i )
        ideas[i] = brain.ideas[i];
}

Brain& Brain::operator=( const Brain& brain ) {
    std::cout << "Brain class copy assignment operator called" << '\n';

    if ( this != &brain ) {
        for ( int i = 0; i < 100; ++i )
            ideas[i] = brain.ideas[i];
    }

    return *this;
}

Brain::~Brain() {
    std::cout << "Brain class destructor called" << '\n';
}

void Brain::setIdeas( const std::string newIdeas[100] ) {
    for ( int i = 0; i < 100; ++i )
        ideas[i] = newIdeas[i];
}

const std::string* Brain::getIdeas() {
    return ideas;
}
