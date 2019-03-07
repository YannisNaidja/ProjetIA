#ifndef DEF_OUVERT_FILE
#define DEF_OUVERT_FILE
#include "ouvert.h"
#include <deque>



class ouvert_queue : public ouvert{

    bool Isempty();
    etat get_tete();
    void remove();
    void ajout(etat e);
    bool etatdansouvert(etat e);

    deque<etat> Ouvert;


};
#endif