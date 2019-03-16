#ifndef DEF_OUVERT_MEILLEUR
#define DEF_OUVERT_MEILLEUR
#include "ouvert.h"
#include <utility>
#include <vector>
#include "etat.h"


 // renvoyer le min de la fonction pour la paire

 class  ouvert_meilleur : public ouvert {

    public:

    bool Isempty();
    etat get_tete();
    void remove();
    void ajout(etat *e,etat *fin);// calculer l'heuristique pour chaque etat qu'on ajoute
    bool etatdansouvert(etat *e);
    
    int heuristique( etat *courant, etat *fin);//somme des distance de la postion actuelle à la position finale pour chaque case 
    ouvert_meilleur();
    

    std::vector<std::pair<etat,int>> Ouvert;
    

};
#endif