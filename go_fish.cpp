#include <iostream>
#include <cstdlib>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

/*

// FILE: card_demo.cpp

// PROTOTYPES for functions used by this demonstration program:


void dealHand(Deck &d, Player &p, int numCards);


int main( )
{
    int numCards = 5;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

*/