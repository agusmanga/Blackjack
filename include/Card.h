#ifndef CARD_H
#define CARD_H

#include "utils.h"



class Card {
    int numero;
    std::string palo;

    public:

    Card(int numero, std::string palo);

    int getNumero();
    std::string getPalo();
};

#endif // CARD_H