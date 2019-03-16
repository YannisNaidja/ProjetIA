#ifndef DEF_OUVERT_PILE
#define DEF_OUVERT_PILE
#include <vector>
#include "etat.h"
#include "ouvert.h"



class ouvert_pile : public ouvert {

    public:

    bool Isempty();
    etat get_tete();
    void remove();
    void ajout(etat *e, etat *fin);
    bool etatdansouvert(etat *e);
    
    ouvert_pile();

    std::vector<etat> Ouvert;

};
#endif
