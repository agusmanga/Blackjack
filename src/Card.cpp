#include "../include/Card.h"

Card::Card(int numero, std::string palo) {
    this->numero = numero;
    this->palo = palo;
}

int Card::getNumero() {
    return numero;
}

std::string Card::getPalo() {
    return palo;
}