#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <string>

class Brain {
  public:
    Brain();
    Brain( const std::string& initIdea );       // pass one string to fill all 100 ideas
    Brain( const std::string initIdeas[100] );  // pass an array of 100 ideas
    Brain( const Brain& brain );
    Brain& operator=( const Brain& brain );
    ~Brain();

    void               setIdeas( const std::string newIdeas[100] );
    const std::string* getIdeas();

  private:
    std::string ideas[100];
};

#endif /* BRAIN_H */
