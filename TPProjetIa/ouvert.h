#ifndef DEF_OUVERT
#define DEF_OUVERT
#include "ferme.h"
class etat;



class ouvert{


    public:

    virtual bool Isempty() = 0;
    virtual etat get_tete() = 0;
    virtual void remove()= 0;
    virtual void ajout(etat *e,etat *fin)= 0;
    void parcours(ouvert *Ouvert , ferme Ferme, etat *initial,etat *fin );
    virtual bool etatdansouvert(etat *e)= 0;
    



};

#endif
