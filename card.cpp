//
// Created by caleb on 4/7/19.
//

#include "card.h"
#include <iostream>
#include <cstdlib>

    Card::Card(){
        myRank = 1;
        mySuit = spades;
    }

    Card::Card(int rank, Suit s) {
        myRank = rank;
        mySuit = s;
    }

    string Card::toString() const{
        string both;
        both = rankString(getRank()) + suitString(mySuit);
        return both;

    } // return string version e.g. Ac 4h Js

    //Card::Suit Card::getSuit() const {
    //    return(mySuit);
    //}

    bool Card::sameSuitAs(const Card& c) const{
        return( c.mySuit == mySuit);
    }  // true if suit same as c

    int  Card::getRank() const{
        return myRank;
    }// return rank, 1..13

    string Card::suitString(Suit s) const{
        switch(s){
            case spades: return "s";
            case hearts: return "h";
            case diamonds: return "d";
            case clubs: return "c";
            default: break;
        }


    } // return "s", "h",...

    string Card::rankString(int r) const{

        if(r == 1){
            return "A";
        }
        else if( (r == 2) || (r == 3) || (r == 4) || (r == 5) || (r == 6) || (r == 7) || (r == 8) || (r == 9) || (r == 10) ){
            return to_string(r);
        }
        else if(r == 11){
            return "J";
        }
        else if(r == 12){
            return "Q";
        }
        else if(r == 13){
            return "K";
        }
        else{
            return "-1";
        }
    } // return "A", "2", ..."Q"


    bool Card::operator == (const Card& rhs) const{
        return( sameSuitAs(rhs) && myRank == rhs.myRank);
    }
    bool Card::operator != (const Card& rhs) const{
        return( mySuit != rhs.mySuit && myRank != rhs.myRank);
    }



