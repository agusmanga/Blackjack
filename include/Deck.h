#include "Card.h"
#include "utils.h"

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