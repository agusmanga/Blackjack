#ifndef DEALER_H
#define DEALER_H

#include "utils.h"

#include "Card.h"

class Dealer{
    std::vector<Card*> cartas;
    int suma;

    public:
    Dealer();

    std::vector<Card*> getCartas();
    int getSuma();
    void setSuma(int numero);

};

#endif // DEALER_h 