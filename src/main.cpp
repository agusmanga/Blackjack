#include <iostream>
#include <string>
#include <limits>
#include <random>
#include <cstdlib>
#include <ctime>
#include "../include/Deck.h"
#include "../include/Card.h"

int input(){
    int numero;
    std::cin >> numero;

    return numero;
}




int main() {
   

    Deck* deck = new Deck();
    std::cout << deck->getSize() << std::endl;
    for (auto carta : deck->getCards()){
        std::cout << carta->getNumero() << " de " << carta->getPalo() << std::endl;
    }

    std::cout << "Desea Comenzar un juego de cartas? (1 = Si, 0 = No)" << std::endl;
    int respuesta = input();
    if (respuesta == 1){
        std::cout << "Comenzando juego de cartas..." << std::endl;
        deck->shuffle();
        }
        Card* carta;
        while (true){
       // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        
        
        carta = deck->dealCard();

        std::cout << "La carta seleccionada es: " << carta->getNumero() << " de " << carta->getPalo() << std::endl;
        for (auto carta: deck->getCards()){
        std::cout << carta->getNumero() << " de " << carta->getPalo() << std::endl;
    }
        if (deck->getCards().size() != 0){
        std::cout << "Desea sacar otra carta? (1 = Si, 0 = No)" << std::endl;
        int respuesta = input();
        if (respuesta == 0){
            std::cout << "Fin del juego" << std::endl;
            break;
        }
        }

        else{
            std::cout << "Fin del juego" << std::endl;
        }


        }





    return 0;
}