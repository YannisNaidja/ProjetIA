#ifndef DEF_OUVERT
#define DEF_OUVERT
#include "etat.h"

class ouvert{


public:

    bool Isempty();
    etat tete();
    void remove();
    void add_ferme(etat e);
    void add_ouvert(etat e);
    void generer_voisins();


    




};

#endif
