#include "utils.h"
#include "Dealer.h"
#include "User.h"
#include "Deck.h"

class ControladorJuego{
    User* usuario;
    Dealer* dealer;
    Deck* deck;

    public:
    ControladorJuego();

    void crearUsuario();
    void crearDealer();
    void crearDeck();

    User* getUsuario();
    Dealer* getDealer();

    void iniciarJuego();
    void repartirCartasInicial();
    void repartirCarta();
    void nuevaRonda();
    

    bool igualar();

};