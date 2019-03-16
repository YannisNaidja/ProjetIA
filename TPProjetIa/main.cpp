#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "filereader.h"
#include "ouvert.h"
#include "ouvert_pile.h"
#include "ouvert_queue.h"
#include "ouvert_meilleur.h"
#include "etat.h"
#include "ferme.h"


using namespace std;

int main(int argc,char *argv[]){


    if(argc<2)
        cout << "Usage : ./main nom_du_fichier type_parcous (profondeur/largeur/meilleur)" << endl;

    string nom_fic=argv[1];
    string type_parcour=argv[2];
    
    filereader filer;
    etat *ei = new etat();
    etat *ef = new etat();
    
     filer.remplir_etat_initial(nom_fic,ei);
    
     filer.remplir_etat_final(nom_fic,ef);

    cout << "l'etat initial est " << endl;
    cout << endl;
    ei->affiche_etat();
    cout<< " l'etat final est " << endl;
    cout << endl;
    ef->affiche_etat();

    ferme myferme;

    if(type_parcour.compare("meilleur")==0){
        ouvert *ouvert = new ouvert_meilleur();
        ouvert->parcours(ouvert,myferme,ei,ef);
    }
    else if(type_parcour.compare("profondeur")==0){
        ouvert *ouvert = new ouvert_pile();
        ouvert->parcours(ouvert,myferme,ei,ef);
    }
    else if(type_parcour.compare("largeur")==0){
        ouvert *ouvert = new ouvert_queue();
        ouvert->parcours(ouvert,myferme,ei,ef);
    }

    return 0;
}