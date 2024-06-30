#include "../include/controladorJuego.h"

ControladorJuego::ControladorJuego():usuario(),dealer(),deck(),cartasusuario(),cartasdealer(){}


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

std::vector <Card*> ControladorJuego::getCartasUsuario(){
    return cartasusuario;
}

std::vector <Card*> ControladorJuego::getCartasDealer(){
    return cartasdealer;
}

void ControladorJuego::repartirCartasInicial(){
    Card* carta;
    
    //primera usuario
    carta = deck->dealCard();
    usuario->getCartas().push_back(carta);
    usuario->setSuma(carta->getNumero());
    cartasusuario.push_back(carta);
    imprimirCartas();
    std::this_thread::sleep_for(std::chrono::milliseconds(700));

    //primera dealer
    carta = deck->dealCard();
    dealer->getCartas().push_back(carta);
    dealer->setSuma(carta->getNumero());
    cartasdealer.push_back(carta);
    imprimirCartas();
    std::this_thread::sleep_for(std::chrono::milliseconds(700));

    // Línea divisoria vertical
    

    //primera usuario
    carta = deck->dealCard();
    usuario->getCartas().push_back(carta);
    usuario->setSuma(carta->getNumero());
    cartasusuario.push_back(carta);
    imprimirCartas();
    

    
    
}

void ControladorJuego::repartirCarta(){
    Card* carta;

    carta = deck->dealCard();
    usuario->getCartas().push_back(carta);
    usuario->setSuma(carta->getNumero());
    cartasusuario.push_back(carta);
    imprimirCartas();
}

bool ControladorJuego::igualar(){
    Card* carta;
    while (dealer->getSuma()<21 && dealer->getSuma()<= usuario->getSuma()){
        carta = deck->dealCard();
        dealer->getCartas().push_back(carta);
        dealer->setSuma(carta->getNumero());
        cartasdealer.push_back(carta);
        imprimirCartas();
        if (dealer->getSuma()<21 && dealer->getSuma()<= usuario->getSuma()){
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
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
    cartasdealer.clear();
    cartasusuario.clear();
    std::cout << deck->getSize();
}

void ControladorJuego::imprimirCartas(){
    std::cout << "\033[2J\033[1;1H";
    size_t max_size = std::max(getCartasUsuario().size(),getCartasDealer().size());

    for (size_t i = 0; i < max_size; ++i){
        if (i < cartasusuario.size()){
            std::cout << std::left << std::setw(20) << (std::to_string(cartasusuario[i]->getNumero()) + " de " + cartasusuario[i]->getPalo());
        }
        else{
            std::cout << std::left <<std::setw(20) << "";
        }

        std::cout << "|";

        if (i < cartasdealer.size()){
            std::cout << std::right << std::setw(20) << (std::to_string(cartasdealer[i]->getNumero()) + " de " + cartasdealer[i]->getPalo());
        }

        std::cout << std::endl;
    }

    std::cout << std::left << std::setw(20) << "(" + std::to_string(usuario->getSuma()) + ")";
    std::cout << "|";
    std::cout << std::right << std::setw(20) << "(" + std::to_string(dealer->getSuma()) + ")";
    std::cout << std::endl;
}
