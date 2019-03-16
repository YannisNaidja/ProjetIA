#include <iostream>
#include "ouvert_meilleur.h"
using namespace std;


ouvert_meilleur::ouvert_meilleur(){

}

 bool ouvert_meilleur::Isempty(){
     if (Ouvert.empty())
        return true;
    return false;

 }

etat ouvert_meilleur::get_tete(){
    int min=Ouvert[0].second;
    int indice_min=0;
    for(int i=1;i<Ouvert.size();i++){
        if (Ouvert[i].second<min)
            min=Ouvert[i].second;
            indice_min=i;
    }
    return Ouvert[indice_min].first;
        
}

void ouvert_meilleur::remove(){
    Ouvert.pop_back();
    
}

void ouvert_meilleur::ajout(etat *e,etat *fin){
    
    int i=heuristique(e,fin);
    Ouvert.push_back(std::make_pair(*e,i));
} 

bool ouvert_meilleur::etatdansouvert(etat *e){
    for(int i=0;i<Ouvert.size();i++){
        if(e->list==Ouvert[i].first.list){
            return true;
        }
    }
    return false;
}


int recherche_diff(int num_ligne,int num_colonne, etat *courant, etat *fin){

    for(int i=0;i<fin->nb_ligne;i++){
        for(int j=0;i<fin->nb_colonne;j++){
            if(courant->list[num_ligne][num_colonne]==fin->list[i][j])
                return (i+j)-(num_ligne+num_colonne);
    
            }
                
        }
           
    }



int ouvert_meilleur::heuristique(etat *courant,etat *fin){ // somme des distances de la position actuelle à la distance de la position finale pour chaque case
    int h=0;
    for(int i=0;i<courant->nb_ligne;i++){
        for(int j=0;j<courant->nb_colonne;j++){
            h += recherche_diff(i , j, courant , fin);
        } 

    }
    return h;
}









