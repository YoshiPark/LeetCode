// Exercise 10.10 Solution: DeckOfCards.cpp
// Member-function definitions for class DeckOfCards that simulates
// the shuffling and dealing of a deck of playing cards.
#include <cstdlib>
#include "DeckOfCards.h"  // DeckOfCards class definition
 
// DeckOfCards default constructor initializes deck
DeckOfCards::DeckOfCards() {
    currentCard = 0;  // set currentCard so first Card dealt is deck[ 0 ]
 
    // populate deck with Card objects
    for (int i = 0; i < Card::totalFaces * Card::totalSuits; ++i) {
        Card card(i % Card::totalFaces, i / Card::totalFaces);
        deck.push_back(card);  // adds copy of card to the end of the deck
    }  // end for
 
}  // end DeckOfCards default constructor
 
// deal cards in deck
Card DeckOfCards::dealCard() {
    return deck[currentCard++];  // return current Card in vector
}  // end function dealCard
 
// Check if there are more cards in the deck
bool DeckOfCards::moreCards() const {
    return currentCard < deck.size();
}  // end function moreCards
