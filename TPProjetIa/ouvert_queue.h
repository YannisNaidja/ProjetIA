#ifndef DEF_OUVERT_QUEUE
#define DEF_OUVERT_QUEUE
#include "ouvert.h"
#include "etat.h"
#include <deque>




 class ouvert_queue : public ouvert {

    public:

    bool Isempty();
    etat get_tete();
    void remove();
    void ajout( etat *e, etat *fin);
    bool etatdansouvert(etat *e);

    ouvert_queue();
    

    std::deque<etat> Ouvert;


};
#endif