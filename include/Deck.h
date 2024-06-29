#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "utils.h"
#include "Dealer.h"

class Deck{
    std::vector<Card*> cards;
    int size;

    public:
    Deck();

    std::vector <Card*> getCards();
    int getSize();


    void shuffle();

    Card* dealCard();

};

#endif //DECH_H