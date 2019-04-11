//
// Created by caleb on 4/7/19.
//

#include <iostream>
#include <string>
#include <vector>

#include "player.h"
using namespace std;

    Player::Player(){

    }


    void Player::addCard(Card c){
        myHand.push_back(c);
    }  //adds a card to the hand

    void Player::bookCards(Card c1, Card c2){
        myBook.push_back(c1);
        myBook.push_back(c2);

        removeCardFromHand(c1);
        removeCardFromHand(c2);
    }

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards that make the pair.

    bool Player::checkHandForBook(Card &c1, Card &c2){
        for(vector<Card>::iterator it = myHand.begin(); it != myHand.end(); it++) {
            for (vector<Card>::iterator it2 = myHand.begin(); it2 != myHand.end(); it2++) {
                if (((*it).getRank() == (*it2).getRank()) && (it != it2)) {
                    c1 = (*it);
                    c2 = (*it2);
                    return true;
                }
            }
        }

    }

    //OPTIONAL
    // comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    bool Player::rankInHand(Card c) const{
        for(int i = 0; i < myHand.size(); i++){
            if(myHand[i].getRank() == c.getRank()){
                return true;
            }
        }
        return false;
        //for(vector<Card>::const::iterator it = myHand.begin(); it != myHand.end; it++){
    }

    //uses some strategy to choose one card from the player's
    //hand so they can say "Do you have a 4?"
    Card Player::chooseCardFromHand() const{
        if(myHand.begin() != myHand.end()){
            int r = rand() % myHand.size();
            return myHand[r];
        }
    }

    //Does the player have the card c in her hand?
    bool Player::cardInHand(Card c) const{
        for(vector<Card>::const_iterator it = myHand.begin(); it < myHand.end(); it++) {
            if( (*it) == c){
                return true;
            }
        }
        return false;
    }

    //Remove the card c from the hand and return it to the caller
    Card Player::removeCardFromHand(Card c) {
        for (vector<Card>::const_iterator it = myHand.begin(); it < myHand.end(); it++) {
            if ((*it) == c) {
                myHand.erase(it);
            }
        }
        return c;
    }

    string Player::showHand() const{
        string sHand;
        for(vector<Card>::const_iterator it = myHand.begin(); it < myHand.end(); it++) {
            sHand += (*it).toString() + " ";
        }
        return sHand;

    }

    string Player::showBooks() const{
        string sHand;
        for(vector<Card>::const_iterator it = myBook.begin(); it < myBook.end(); it++) {
            sHand += (*it).toString() + " ";
        }
        return sHand;
    }

    int Player::getHandSize() const{
        return myHand.size();
    }
    int Player::getBookSize() const{
        return myBook.size()/2;
    }

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    //bool Player::checkHandForPair(Card &c1, Card &c2){

    //}

    //OPTIONAL
    // comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c
    //
    bool Player::sameRankInHand(Card c) const{
        for(vector<Card>::const_iterator it = myHand.begin(); it < myHand.end(); it++) {
            if( (*it).getRank() == c.getRank()){
                return true;
            }
        }
        return false;
    }


    //Remove a card of c's rank from the hand and return it to the caller
    Card Player::rankedRemove(Card c) {
        Card rankMatch;
        for (vector<Card>::const_iterator it = myHand.begin(); it < myHand.end(); it++) {
            if ((*it).getRank() == c.getRank()) {
                rankMatch = (*it);
                myHand.erase(it);
            }
        }
        return rankMatch;
}