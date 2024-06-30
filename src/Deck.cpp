#include "../include/Deck.h"

Deck::Deck() {
    
    cards = inicializarDeck();
    size = cards.size();
}

std::vector <Card*> Deck::getCards() {
    return cards;
}

int Deck::getSize() {
    return size;
}


void Deck::shuffle(){
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

Card* Deck::dealCard(){
    if (this->getCards().size() >= 1){
        Card* carta = this->getCards()[getCards().size()-1];
        cards.pop_back();
        size = size-1;
        return carta;
    }
    else{
        resetDeck();
        Card* carta = this->getCards()[getCards().size()-1];
        cards.pop_back();
        size = size-1;
        return carta;
    }
}

void Deck::resetDeck(){
    cards.clear();
    std::cout<<"reiniciando Deck...\n";
    cards = inicializarDeck();
    size = cards.size();
    shuffle();
    
}

std::vector<Card*> Deck::inicializarDeck(){
    std::vector <Card*> retorno;
    std::string palos[4] = {"Corazones", "Diamantes", "Treboles ", "Espadas "};

    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 13; j++) {
            Card* card = new Card(j,palos[i]);
            retorno.push_back(card);
            
        }
    }
    return retorno;
}