#include "../include/User.h"

User::User():cartas(),suma(0){};

std::vector<Card*> User::getCartas(){
    return cartas;
}

int User::getSuma(){
    return suma;
}

void User::setSuma(int numero){
    suma = suma + numero;
}

void User::sumaReset(){
    suma = 0;
}