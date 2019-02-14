#include "ouvert.h"
using namespace std;

 void ouvert::parcours(ouvert *Ouvert, ferme *Ferme, etat initial,etat fin){

    Ouvert->ajout(initial);
    while(!Ouvert->Isempty() && Ouvert->get_tete().list != fin.list){
        etat *e = new etat(Ouvert->get_tete());
        Ferme->ajout(*e);
        
        
    }

}