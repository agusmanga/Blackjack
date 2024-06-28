#include "../include/Deck.h"

Deck::Deck() {
    
    std::string palos[4] = {"Corazones", "Diamantes", "Treboles", "Picas"};
    for (int i = 0; i < 1; i++) {
        for (int j = 1; j < 13; j++) {
            Card* card = new Card(j,palos[i]);
            cards.push_back(card);
            
        }
    }
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
    Card* carta = this->getCards()[getCards().size()-1];
    cards.pop_back();
    return carta;
}
