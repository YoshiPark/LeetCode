// Exercise 10.10 Solution: Card.cpp
// Member-function definitions and array initializers for the Card class.
#include "Card.h"
#include <string>
// Card constructor initializes face and suit
Card::Card(int cardFace, int cardSuit) {
    face = (cardFace >= 0 && cardFace < totalFaces) ? cardFace : 0;
    suit = (cardSuit >= 0 && cardSuit < totalSuits) ? cardSuit : 0;
}  // end Card constructor
 
// returns a string representation of a Card
std::string Card::toString() const {
    // strings can be concatenated with +
    return std::string(faceNames[ face ]) +
    " of " + std::string(suitNames[ suit ]);
}  // end function toString
 
int Card::getFace() const {
     return face;
}
 
int Card::getSuit() const {
     return suit;
}
 
// contents of arrays to convert index into name
const char* Card::faceNames[ totalFaces ] =
        { "Ace", "Deuce", "Three", "Four", "Five", "Six",
          "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
const char* Card::suitNames[ totalSuits ] =
        { "Hearts", "Diamonds", "Clubs", "Spades" };
