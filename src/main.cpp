#include <iostream>
#include <string>
#include <limits>
#include <random>
#include <cstdlib>
#include <ctime>
#include "../include/Deck.h"
#include "../include/Card.h"
#include "../include/User.h"
#include "../include/ControladorJuego.h"

#include <limits>

std::string ltrim(const std::string &s) {
    const size_t start = s.find_first_not_of(" \t\n\r\f\v");
    return start == std::string::npos ? "" : s.substr(start);
}

std::string rtrim(const std::string &s) {
    const size_t end = s.find_last_not_of(" \t\n\r\f\v");
    return end == std::string::npos ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string &s) {
    return rtrim(ltrim(s));
}

std::string inputStr(const std::string &prompt) {
    std::cout << prompt << " ";
    std::string s;
    getline(std::cin, s);
    return trim(s);
}

void inputEnter(const std::string &prompt) {
    std::cout << prompt;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int inputInt(const std::string &prompt) {
    try {
        std::string input = inputStr(prompt);

        size_t pos;
        int i = std::stoi(input, &pos);
        if (pos != input.length()) {
            throw std::exception();
        }

        return i;
    } catch (std::exception const &e) {
        throw std::invalid_argument("entero inválido");
    }
}

void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}






int main() {
    ControladorJuego* controladorJuego = new ControladorJuego();
    controladorJuego->iniciarJuego();
    clearScreen();
    std::cout << "---- BLACKJACK ----\n";

    inputEnter("Presione Enter para comenzar");
    

while (true){
    clearScreen();
    controladorJuego->repartirCartasInicial();

    if (controladorJuego->getUsuario()->getSuma() < 21){
        int pregunta = inputInt("Desea sacar Otra carta? (1-si, 0-no)");
        if (pregunta == 1){
            while (pregunta == 1 && controladorJuego->getUsuario()->getSuma()<21){
                controladorJuego->repartirCarta();
                if (controladorJuego->getUsuario()->getSuma()<21){
                    pregunta = inputInt("Desea sacar Otra carta? (1-si, 0-no)");
                    
                }
                else {
                    break;
                }
            }
        }
        
    }

    if (controladorJuego->getUsuario()->getSuma()<=21){
        bool retorno = controladorJuego->igualar();
        if (retorno){
            std::cout << std::endl;
            std::cout << std::right << std::setw(50) << "||¡¡GANA EL DEALER !!||"<<std::endl;
        }
        else {
            if (controladorJuego->getUsuario()->getSuma() == controladorJuego->getDealer()->getSuma()){
                std::cout << std::endl;
                std::cout <<std::left << std::setw(40) << std::left << std::setw(20) << "||EMPATE -_-||"<<std::endl;
            }
            else{
                std::cout << std::endl;
                std::cout <<"||¡¡TU GANAS!!||"<<std::endl;
            }
        }

    }
    else {
        std::cout << std::endl;
        std::cout << std::right << std::setw(50) << "||¡¡GANA EL DEALER !!||"<<std::endl;
    }
    std::cout << std::endl;
    std::string suma = "Tu suma: " + std::to_string(controladorJuego->getUsuario()->getSuma());
    std::cout <<std::left << std::setw(20) << suma;
    std::cout << "|" ;
    std::cout <<std::right << std::setw(20) <<  "la suma del dealer: " << controladorJuego->getDealer()->getSuma() << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    int otra = inputInt("Pulse 1 para jugar otra ronda:");
    if (otra != 1){
        break;
    }
    controladorJuego->nuevaRonda();
    
}
    
    return 0;
}