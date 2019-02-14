#ifndef DEF_OUVERT
#define DEF_OUVERT
#include "etat.h"
#include "ferme.h"

class ouvert{


public:

    bool Isempty();
    etat get_tete();
    void remove();
    void ajout(etat e);
    void parcours(ouvert *Ouvert ,ferme *Ferme,etat initial,etat fin );


    




};

#endif
