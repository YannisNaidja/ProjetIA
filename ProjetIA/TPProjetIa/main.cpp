#include <fstream>
#include <iostream>
#include <string>
#include "etat.h"
#include "ouvert.h"
#include <vector>
using namespace std;

int main(void){

    ifstream input("taquin_2x4.grid");

    char cnb_lignes = input.get();
    int nb_lignes = cnb_lignes -48;
    
    
    int lignes_lues=0;
    int nb_colonne=0;
    string ligne;
        while((getline(input,ligne))&&(lignes_lues<nb_lignes)){
            lignes_lues++;
            if(ligne.size()>nb_colonne)
                nb_colonne=ligne.size();
        }
    etat etatinitial(nb_lignes,nb_colonne);
        
        input.seekg(1,ios::beg); // replace le curseur aprés le 1er char

        vector<string> list(nb_lignes);
        string mot;
        mot.resize(nb_colonne);
        lignes_lues=0;
        
            while ((input >> mot)&& lignes_lues<nb_lignes) {
        list.push_back(mot);
        lignes_lues++;
        }


            
            
            
        }
    


}