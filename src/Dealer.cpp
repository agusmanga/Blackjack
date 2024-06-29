#include "../include/Dealer.h"

Dealer::Dealer():cartas(),suma(0){};

std::vector<Card*> Dealer::getCartas(){
    return cartas;
}

int Dealer::getSuma(){
    return suma;
}

void Dealer::setSuma(int numero){
    suma = suma + numero;
}

void Dealer::sumaReset(){
    suma = 0;
}