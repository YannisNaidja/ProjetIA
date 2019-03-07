#ifndef DEF_OUVERT_MEILLEUR
#define DEF_OUVERT_MEILLEUR
#include "ouvert.h"
#include <utility>
#include <vector>


 // renvoyer le min de la fonction pour la paire

class ouvert_meilleur : public ouvert{

    bool Isempty();
    std::pair<etat,int> get_tete();
    void remove();
    void ajout(etat e, int i);
    bool etatdansouvert(etat e);

    std::vector<std::pair<etat,int>> Ouvert;
    

};
#endif