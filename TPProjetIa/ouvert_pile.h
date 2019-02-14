#ifndef DEF_OUVERT_PILE
#define DEF_OUVERT_PILE
#include <stack>
#include "ouvert.h"



class ouvert_pile : public ouvert{

    bool Isempty();
    etat get_tete();
    void remove();
    void ajout(etat e);

    stack<etat> Ouvert;

};
#endif
