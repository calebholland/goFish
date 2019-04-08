//
// Created by caleb on 4/7/19.
//

#include "deck.h"

    Deck::Deck(){
        for(int i=0; i<13; i++){
            for(int j=0; j<4; j++){
                if(j == 0){
                    myCards[(i*4) + j] = Card(i+1, Card::spades);
                }
                else if(j == 1){
                    myCards[(i*4) + j] = Card(i+1, Card::hearts);
                }
                else if(j == 2){
                    myCards[(i*4) + j] = Card(i+1, Card::diamonds);
                }
                else if(j == 3){
                    myCards[(i*4) + j] = Card(i+1, Card::clubs);
                }
            }
        }
        myIndex = 0;
    }           // pristine, sorted deck

    void Deck::shuffle() {

    }   // shuffle the deck, all 52 cards present

    Card Deck::dealCard(){
        Card tempCard = myCards[myIndex];
        myIndex++;
        return tempCard;
    }   // get a card, after 52 are dealt, fail

    int  Deck::size() const {

    }// # cards left in the deck
