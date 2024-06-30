#include "utils.h"
#include "Dealer.h"
#include "User.h"
#include "Deck.h"

class ControladorJuego{
    User* usuario;
    Dealer* dealer;
    Deck* deck;
    std::vector <Card*> cartasusuario;
     std::vector <Card*> cartasdealer;

    public:
    ControladorJuego();

    void crearUsuario();
    void crearDealer();
    void crearDeck();

    User* getUsuario();
    Dealer* getDealer();
    std::vector <Card*>getCartasDealer();
    std::vector <Card*>getCartasUsuario();

    void iniciarJuego();
    void repartirCartasInicial();
    void repartirCarta();
    void nuevaRonda();
    
    void imprimirCartas();

    bool igualar();

};