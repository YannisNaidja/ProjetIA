#include "ouvert.h"
#include <iostream>

using namespace std;

 void ouvert::parcours(ouvert *Ouvert, ferme *Ferme, etat initial,etat fin){

    Ouvert->ajout(initial);
    while(!Ouvert->Isempty() && Ouvert->get_tete().list != fin.list){
        etat *e = new etat(Ouvert->get_tete());
        Ouvert->remove();
        Ferme->ajout(*e);
        e->generer_voisins(Ouvert,Ferme);
    }
    if(Ouvert->Isempty()){
        cout << "Il n'existe pas de but accessible" << endl;    
    }
    else{
        cout << "l element en tete de ouvert est un but" << endl;
    }

}
