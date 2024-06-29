#ifndef USER_H
#define USER_H

#include "utils.h"
#include "Card.h"

class User{
    std::vector <Card*> cartas;
    int suma;

    public:
    User();
    std::vector<Card*> getCartas();
    int getSuma();
    void setSuma(int numero);
    void sumaReset();
};

#endif //USER_H