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

    std::vector<Card*> inicializarDeck();
    void shuffle();

    Card* dealCard();
    void resetDeck();

};

#endif //DECH_H