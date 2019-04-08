#include <iostream>
#include <cstdlib>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

void dealHand(Deck &d, Player &p, int numCards);

int main() {
    std::cout << "Hello, World!" << std::endl;

    Card c1;
    cout << c1.toString() << endl;

    Card c2(4, Card::clubs);
    cout << c2.toString() << endl;

    Card c3(4, Card::clubs);
    cout << c2.toString() << endl;

    cout << "Are card c2 and c3 the same? (want 1): " << (c2 == c3) << endl;
    cout << "Are card c1 and c3 the same? (want 0): " << (c1 == c3) << endl;

    cout << "Brand new deck: " <<endl;
    Deck testDeck = Deck();
    for(int i=0; i<52; i++){
        Card tempCard = testDeck.dealCard();
        cout << tempCard.toString() <<endl;
    }
    cout<<endl<<endl <<"Shuffled Deck: " <<endl;
    Deck testDeck2 = Deck();
    testDeck2.shuffle();
    for(int i=0; i<54; i++) {
        Card tempCard = testDeck2.dealCard();
        cout << tempCard.toString() << endl;
        cout << "Cards left: " << testDeck2.size() <<endl;
    }



    int numCards = 7;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    //d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);


    cout << p1.getHandSize() << endl << p2.getHandSize() <<endl;

    cout << p1.getName() <<" has : " <<endl << p1.showHand() << endl;
    cout << p2.getName() <<" has : " <<endl << p2.showHand() << endl;

    Card c5(3, Card::spades);
    p1.removeCardFromHand(c5);
    cout << p1.showHand() <<endl;

    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
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