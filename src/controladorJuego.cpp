#include "../include/controladorJuego.h"

ControladorJuego::ControladorJuego():usuario(),dealer(),deck(){}


void ControladorJuego::crearUsuario(){
    usuario = new User();
}

void ControladorJuego::crearDealer(){
    dealer = new Dealer();
}

void ControladorJuego::crearDeck(){
    deck = new Deck();
}

void ControladorJuego::iniciarJuego(){
    crearDealer();
    crearUsuario();
    crearDeck();
    deck->shuffle();
}

User* ControladorJuego::getUsuario(){
    return usuario;
}

Dealer* ControladorJuego::getDealer(){
    return dealer;
}

void ControladorJuego::repartirCartasInicial(){
    Card* carta;
    
    //primera usuario
    carta = deck->dealCard();
    usuario->getCartas().push_back(carta);
    usuario->setSuma(carta->getNumero());
    std::cout << carta->getNumero() << "de" << carta->getPalo() << "\n";

    //primera dealer
    carta = deck->dealCard();
    dealer->getCartas().push_back(carta);
    dealer->setSuma(carta->getNumero());
    std::cout << carta->getNumero() << "de" << carta->getPalo() << "\n";

    //primera usuario
    carta = deck->dealCard();
    usuario->getCartas().push_back(carta);
    usuario->setSuma(carta->getNumero());
    std::cout << carta->getNumero() << "de" << carta->getPalo() << "\n";

}

void ControladorJuego::repartirCarta(){
    Card* carta;

    carta = deck->dealCard();
    usuario->getCartas().push_back(carta);
    usuario->setSuma(carta->getNumero());
    std::cout << carta->getNumero() << "de" << carta->getPalo() << "\n";
}

bool ControladorJuego::igualar(){
    Card* carta;
    while (dealer->getSuma()<21 && dealer->getSuma()<= usuario->getSuma()){
        carta = deck->dealCard();
        dealer->getCartas().push_back(carta);
        dealer->setSuma(carta->getNumero());
        std::cout << carta->getNumero() << "de" << carta->getPalo() << "\n";
    }
    if (dealer->getSuma()<=21 && dealer->getSuma() > usuario->getSuma()){
        return true;
    }
    else {
        return false;
    }
}

void ControladorJuego::nuevaRonda(){
    usuario->sumaReset();
    dealer->sumaReset();
    std::cout << deck->getSize();
}

