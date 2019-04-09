#include <iostream>
#include <cstdlib>
#include "card.h"
#include "player.h"
#include "deck.h"

#define HAND_SIZE 7

using namespace std;

void dealHand(Deck &d, Player &p, int numCards);
void pl1Turn(Player &pl1, Player &pl2, Deck &deck);
void pl2Turn(Player &pl1, Player &pl2, Deck &deck);
void test2();

int main() {
    //test2();

    Player pl1("Amy");
    Player pl2("Ned");

    Deck deck;
    deck.shuffle();
    dealHand(deck, pl1, HAND_SIZE);
    dealHand(deck, pl2, HAND_SIZE);

    cout << pl1.getName() << ": " << pl1.showHand() << endl << pl2.getName() << ": " << pl2.showHand() << endl;

    //while(deck.size() != 0){
    while(pl1.getBookSize() + pl2.getBookSize() < 52){
        pl1Turn(pl1, pl2, deck);
        pl2Turn(pl1, pl2, deck);
    }

    cout << pl1.getName() << "book size: " << pl1.getBookSize() << endl  << pl1.showBooks() << endl;
    cout << pl2.getName() << "books size: " << pl2.getBookSize() << endl << pl2.showBooks() << endl;







    return EXIT_SUCCESS;
}

void pl1Turn(Player &pl1, Player &pl2, Deck &deck){
    Card book1;
    Card book2;
    Card roundCard;
    while(pl1.checkHandForBook(book1, book2)){
        pl1.bookCards(book1, book2);
    }
    while(pl2.checkHandForBook(book1, book2)){
        pl2.bookCards(book1, book2);
    }
    if(pl1.getHandSize() != 0) {
        cout << pl1.getName() << ": " << pl2.getName() << ", got any ";
        roundCard = pl1.chooseCardFromHand();
        cout << roundCard.rankString(roundCard.getRank()) << "s?" << endl;

        cout << pl2.getName() << ": ";
        if (pl2.rankInHand(roundCard)) {
            cout << "Yes. Here is ";
            Card takenCard = pl2.rankedRemove(roundCard);
            pl1.addCard(takenCard);
            cout << takenCard.toString() << endl;
            if(pl1.getBookSize() + pl2.getBookSize() < 52){
                pl1Turn(pl1, pl2, deck);
            }
            else{
                return;
            }
        }
        else {
            cout << "Go Fish" << endl;
            if(deck.size() != 0){
                pl1.addCard(deck.dealCard());
            }
        }
    }
    else{
        cout << pl1.getName() << ": I'm fishing" <<endl;
        if(deck.size() != 0){
            pl1.addCard(deck.dealCard());
        }
    }
}
void pl2Turn(Player &pl1, Player &pl2, Deck &deck){
    Card book1;
    Card book2;
    Card roundCard;
    while(pl1.checkHandForBook(book1, book2)){
        pl1.bookCards(book1, book2);
    }
    while(pl2.checkHandForBook(book1, book2)){
        pl2.bookCards(book1, book2);
    }
    if(pl2.getHandSize() != 0) {
        cout << pl2.getName() << ": " << pl1.getName() << ", got any ";
        roundCard = pl2.chooseCardFromHand();
        cout << roundCard.rankString(roundCard.getRank()) << "s?" << endl;

        cout << pl1.getName() << ": ";
        if (pl1.rankInHand(roundCard)) {
            cout << "Yes. Here is ";
            Card takenCard = pl1.rankedRemove(roundCard);
            pl2.addCard(takenCard);
            cout << takenCard.toString() << endl;
            if(pl1.getBookSize() + pl2.getBookSize() < 52){
                pl2Turn(pl1, pl2, deck);
            }
            else{
                return;
            }
        }
        else {
            cout << "Go Fish" << endl;
            if(deck.size() != 0){
                pl2.addCard(deck.dealCard());
            }
        }
    }
    else {
        cout << pl2.getName() << ": I'm fishing" << endl;
        if(deck.size() != 0){
            pl2.addCard(deck.dealCard());
        }
    }
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

void test2(){
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
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);


    cout << p1.getHandSize() << endl << p2.getHandSize() <<endl;

    cout << p1.getName() <<" has : " <<endl << p1.showHand() << endl;
    cout << p2.getName() <<" has : " <<endl << p2.showHand() << endl;

    Card c5(3, Card::spades);
    p1.removeCardFromHand(c5);
    cout << p1.showHand() <<endl;
}







