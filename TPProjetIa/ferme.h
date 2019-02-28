#ifndef DEF_FERME
#define DEF_FERME
#include <list>
#include "etat.h"

class ferme {

    public :
        list<etat> ferme;
         void ajout(etat e);
         bool etatdansferme(etat e);

};
#endif