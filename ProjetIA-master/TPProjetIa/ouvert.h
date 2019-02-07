#ifndef DEF_OUVERT
#define DEF_OUVERT
#include "etat.h"

class ouvert{


public:

    bool Isempty();
    etat tete();
    void remove();
    void add_ferme();
    void add_ouvert();
    void generer_voisins();



    char grille[][];




};

#endif
