#include "AMateria.h"
#include "Cure.h"
#include "Ice.h"
#include "ICharacter.h"
#include "Character.h"
#include "IMateriaSource.h"
#include "MateriaSource.h"
#include <iostream>
#include <iterator>

#define BOLDUNDERLINE "\033[1m\033[4m"
#define MAGENTA       "\033[35m"
#define BLUE          "\033[34m"
#define CYAN          "\033[36m"
#define RED           "\033[31m"
#define GREEN         "\033[32m"
#define RESET         "\033[0m"

// Array to keep track of Materia left unequipped
AMateria* unequippedMateria[50]{};

void addToUnequippedMateria( AMateria* materia ) {
    for ( unsigned int i = 0; i < std::size( unequippedMateria ); ++i ) {
        if ( !unequippedMateria[i] ) {
            unequippedMateria[i] = materia;
            return;
        }
    }
}

void learnIfFreeSlot( MateriaSource& source, AMateria* materia ) {
    if ( !source.slotsAreFull() )
        source.learnMateria( materia );
    else
        addToUnequippedMateria( materia );
}

void equipIfFreeSlot( Character& character, AMateria* materia ) {
    if ( !character.inventoryIsFull() )
        character.equip( materia );
    else
        addToUnequippedMateria( materia );
}

AMateria* pickUnequipped() {
    for ( unsigned int i = 0; i < std::size( unequippedMateria ); ++i ) {
        if ( unequippedMateria[i] ) {
            AMateria* result     = unequippedMateria[i];
            unequippedMateria[i] = nullptr;
            return result;
        }
    }

    return nullptr;
}

int main() {
    Ice*      ice1{ new Ice };
    AMateria* cure1{ new Cure{} };
    Cure*     cure2{ new Cure() };
    Ice*      ice2( new Ice() );
    AMateria* ice3 = new Ice;

    // Source learns Materia if it has empty slots
    MateriaSource source;
    learnIfFreeSlot( source, ice1 );
    learnIfFreeSlot( source, cure1 );
    learnIfFreeSlot( source, cure2 );
    learnIfFreeSlot( source, ice2 );
    learnIfFreeSlot( source, ice3 );

    // Create 5 players with different initialization methods
    Character   player1{ "Player 1" };
    Character*  player2{ new Character( "Player 2" ) };
    ICharacter* player3( new Character( "Player 3" ) );
    Character*  player4 = new Character( "Player 4" );
    Character   noName;

    // Player 1 equips Materia if slot is available
    equipIfFreeSlot( player1, source.createMateria( "ice" ) );
    equipIfFreeSlot( player1, source.createMateria( "cure" ) );
    equipIfFreeSlot( player1, source.createMateria( "ice" ) );
    equipIfFreeSlot( player1, source.createMateria( "ice" ) );
    equipIfFreeSlot( player1, source.createMateria( "ice" ) );

    // Player 2 equips Materia if slot is available
    equipIfFreeSlot( *player2, source.createMateria( "fire" ) );
    equipIfFreeSlot( *player2, source.createMateria( "cure" ) );
    equipIfFreeSlot( *player2, source.createMateria( "ice" ) );
    equipIfFreeSlot( *player2, source.createMateria( "ice" ) );
    equipIfFreeSlot( *player2, source.createMateria( "cure" ) );

    // Player 3 equips any Materia left on the floor
    player3->equip( pickUnequipped() );
    player3->equip( pickUnequipped() );
    player3->equip( pickUnequipped() );

    // Player 4's inventory remains empty (does not pick anything)

    // noName player equips ice and attempts to equip unknown Materia
    noName.equip( source.createMateria( "ice" ) );
    noName.equip( source.createMateria( "fire" ) );
    noName.equip( source.createMateria( "wind" ) );
    noName.equip( source.createMateria( "" ) );

    std::cout << "--------------------------------\n" << MAGENTA;
    // Players use materia on each other (and on themselves)
    player1.use( 1, *player2 );
    player1.use( 2, *player2 );
    player1.use( 0, *player3 );
    player2->use( 4, *player2 );
    player3->use( 42, player1 );
    player1.use( 2, player1 );
    player3->use( 1, *player4 );
    player4->use( 3, *player4 );
    player4->use( 0, player1 );
    player2->use( 0, player1 );
    player2->use( -1, player1 );
    noName.use( 0, player1 );
    noName.use( 1, *player2 );
    player1.use( 3, noName );
    std::cout << RESET << "--------------------------------\n";

    // Player 1 unequips its materia at slot 1
    addToUnequippedMateria( player1.getAddressAtIdx( 1 ) );
    player1.unequip( 1 );

    // Player 2 unequips its materia at slot 3
    addToUnequippedMateria( player2->getAddressAtIdx( 3 ) );
    player2->unequip( 3 );

    // Player 4 attempts to unequip from an empty slot
    addToUnequippedMateria( player4->getAddressAtIdx( 0 ) );
    player4->unequip( 0 );

    // Player 1 attempts to unequip from an empty slot (previously unequipped)
    addToUnequippedMateria( player1.getAddressAtIdx( 1 ) );
    player1.unequip( 1 );

    // noName player unequips its materia at slot 0
    addToUnequippedMateria( noName.getAddressAtIdx( 0 ) );
    noName.unequip( 0 );

    // noName player attempts to unequip from an empty slot ("fire")
    addToUnequippedMateria( noName.getAddressAtIdx( 1 ) );
    noName.unequip( 1 );

    // Player 4 attempts to unequip from an invalid index
    addToUnequippedMateria( player4->getAddressAtIdx( 200 ) );
    player4->unequip( 200 );

    // Deep copy tests for Character class
    *player2 = player1;

    ICharacter* deepPlayer1 {new Character{*player2}};
    ICharacter* deepPlayer2 {new Character{player1}};
    Character* deepPlayer3 {new Character{}};
    Character deepPlayer4;
    deepPlayer4 = *deepPlayer3;

    // Deep copy tests for Materia class
    Ice*      deepTest1{ new Ice };
    AMateria* deepCopy1{ new Ice{ *deepTest1 } };

    AMateria* deepTest2{ new Cure{} };
    AMateria*     deepCopy2{ new Cure() };
    deepCopy2 = deepTest2;

    Ice* deepTest3{ new Ice };
    Ice*     deepCopy3{ new Ice };
    *deepCopy3 = *deepTest3;

    // Clean up
    for ( unsigned int i = 0; i < std::size( unequippedMateria ); ++i )
        delete unequippedMateria[i];
    delete player2;
    delete player3;
    delete player4;
    delete deepTest1;
    delete deepCopy1;
    delete deepTest2;
    delete deepCopy2;
    delete deepTest3;
    delete deepCopy3;
    delete deepPlayer1;
    delete deepPlayer2;
    delete deepPlayer3;

    return 0;
}

// int main() {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria( new Ice() );
//     src->learnMateria( new Cure() );

//     ICharacter* me = new Character( "me" );

//     AMateria* tmp;
//     tmp = src->createMateria( "ice" );
//     me->equip( tmp );
//     tmp = src->createMateria( "cure" );
//     me->equip( tmp );

//     ICharacter* bob = new Character( "bob" );

//     me->use( 0, *bob );
//     me->use( 1, *bob );

//     delete bob;
//     delete me;
//     delete src;

//     return 0;
// }
