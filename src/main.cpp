#include <iostream>
#include <string>
#include <limits>
#include <random>
#include <cstdlib>
#include <ctime>
#include "../include/Deck.h"
#include "../include/Card.h"
#include "../include/User.h"

int input(){
    int numero;
    std::cin >> numero;

    return numero;
}

void igualar(Dealer* &dealer,User* user,Deck* &deck){
    Card* carta;
    while (dealer->getSuma()<21 && dealer->getSuma()<= user->getSuma()){
        carta = deck->dealCard();
        dealer->getCartas().push_back(carta);
        dealer->setSuma(carta->getNumero());
        std::cout << carta->getNumero() << "de" << carta->getPalo() << "\n";
    }

}



int main() {
    Dealer* dealer = new Dealer();
    User* user = new User();
    Deck* deck = new Deck();

    std::cout << deck->getSize() << std::endl;
    for (auto carta : deck->getCards()){
        std::cout << carta->getNumero() << " de " << carta->getPalo() << std::endl;
    }

    std::cout << "Desea Comenzar un juego de cartas? \n (1 = Si, 0 = No)" << std::endl;
    int respuesta = input();
    if (respuesta == 1){
        std::cout << "Comenzando juego de cartas..." << std::endl;
        deck->shuffle();
        }
        Card* carta;
       // while (true){
       // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            carta = deck->dealCard();
            user->getCartas().push_back(carta);
            std::cout << carta->getNumero() << " de " <<  carta->getPalo()<< "\n";
            user->setSuma(carta->getNumero());

            carta = deck->dealCard();
            dealer->getCartas().push_back(carta);
            dealer->setSuma(carta->getNumero());
            std::cout << carta->getNumero() << " de " <<  carta->getPalo()<< "\n";
        
            carta = deck->dealCard();
            user->getCartas().push_back(carta );
            user->setSuma(carta ->getNumero());
            std::cout << carta ->getNumero() << " de " <<  carta ->getPalo()<<user->getSuma()<<"\n";

            if (user->getSuma() < 21){
                if (deck->getCards().size() != 0){
                    std::cout << "Desea sacar otra carta?\n  (1 = Si, 0 = No)" << std::endl;
                    int respuesta = input();
                    if (respuesta == 0){
                        igualar(dealer,user,deck);
                        if (dealer->getSuma() <= 21 && dealer->getSuma() > user->getSuma()){
                            std::cout << "gana la mano el dealer\n";
                        }
                        else {
                           std::cout << "ganas la mano\n"; 
                        }
                    }
                    else{
                        while (respuesta == 1){
                            carta = deck->dealCard();
                            user->getCartas().push_back(carta);
                            user->setSuma(carta->getNumero());
                            std::cout << carta->getNumero() << "de" << carta->getPalo() << "\n";
                            if (user->getSuma() < 21){
                                std::cout << "Desea sacar otra carta?\n  (1 = Si, 0 = No)" << std::endl;
                                int respuesta = input();
                                if (respuesta == 0){
                                    igualar(dealer,user,deck);
                                }
                            }
                            else{
                                if (user->getSuma() == 21){
                                    igualar(dealer,user,deck);
                                    if (dealer->getSuma() == 21){
                                        std::cout << "empate\n";
                                        break;
                                    }
                                    else {
                                        std::cout << "ganas la mano\n"; 
                                        break;
                                    }
                                    
                                }
                                else {
                                    std::cout<< "perdiste";
                                    break;
                                }
                            }
                        }
                    }
                }
            }

        if (respuesta == 0 && user->getSuma() > dealer->getSuma() && user->getSuma() <= 21){
            std::cout << "ganas";
        }
        else {
            if (dealer ->getSuma()<=21 && dealer->getSuma() > user->getSuma()){
                std::cout << "perdes";
            }
        }

       // }


    std::cout  << user->getSuma() << " , " << dealer->getSuma();
    return 0;
}