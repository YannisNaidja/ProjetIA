#ifndef DEF_FERME
#define DEF_FERME
#include <vector>
class etat;


 class ferme {
    
    public:
    

    std::vector<etat> tferme;
    void ajoute( etat *e);
    bool etatdansferme(etat *e);
    ferme();

};
#endif