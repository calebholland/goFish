//
// Created by caleb on 4/7/19.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "deck.h"

using namespace std;

    Deck::Deck(){
        for(int i=0; i<4; i++){
            for(int j=0; j<13; j++){
                switch(i){
                    case 0: myCards[(i*13) + j] = Card(j+1, Card::spades); break;
                    case 1: myCards[(i*13) + j] = Card(j+1, Card::hearts); break;
                    case 2: myCards[(i*13) + j] = Card(j+1, Card::diamonds); break;
                    case 3: myCards[(i*13) + j] = Card(j+1, Card::clubs); break;
                }


                /*
                if(i == 0){
                    myCards[(i*13) + j] = Card(j+1, Card::spades);
                }
                else if(i == 1){
                    myCards[(i*13) + j] = Card(j+1, Card::hearts);
                }
                else if(i == 2){
                    myCards[(i*13) + j] = Card(j+1, Card::diamonds);
                }
                else if(i == 3){
                    myCards[(i*13) + j] = Card(j+1, Card::clubs);
                }
                 */
            }
        }
        myIndex = 0;
        unsigned int nowTime = (unsigned)time(0);
        srand(nowTime);
    }           // pristine, sorted deck

    void Deck::shuffle() {
        for(int i=0; i<SIZE * 8; i++){
            int idx1 = rand() % 52;
            int idx2 = rand() % 52;
            Card tempCard = myCards[idx1];
            myCards[idx1] = myCards[idx2];
            myCards[idx2] = tempCard;
        }
    }   // shuffle the deck, all 52 cards present

    Card Deck::dealCard(){
        if(myIndex <52){
            Card tempCard = myCards[myIndex];
            myIndex++;
            return tempCard;
        }
        else{
            cout << "Out of cards" <<endl;
            return Card();
        }
    }   // get a card, after 52 are dealt, fail

    int  Deck::size() const {
        return(SIZE - myIndex);
    }// # cards left in the deck
