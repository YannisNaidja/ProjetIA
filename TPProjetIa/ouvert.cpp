#include "ouvert.h"
#include <iostream>
#include "etat.h"

using namespace std;

 void ouvert::parcours(ouvert *Ouvert,ferme Ferme , etat *initial , etat *fin){

    
    Ouvert->ajout(initial,fin);

    while(!Ouvert->Isempty() && Ouvert->get_tete().list != fin->list){
        etat *e = new etat(Ouvert->get_tete());
        cout << "l etat courant est"<< endl;
        cout << endl;
        e->affiche_etat();
        cout << " " << endl; 
        Ouvert->remove();
        Ferme.ajoute(e);
        e->generer_voisins( Ouvert , Ferme, fin);
        

    }
    if(Ouvert->Isempty()){
        cout << "Il n'existe pas de but accessible" << endl;    
    }
    else{
        cout << "l element en tete de ouvert est un but" << endl;
    }

}
