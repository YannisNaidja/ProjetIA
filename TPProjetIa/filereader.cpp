#include "filereader.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


filereader::filereader(){}

int filereader::getnblignes(string nom_fic){

    ifstream input(nom_fic);

    char cnb_lignes = input.get();
    int nb_lignes = cnb_lignes -48;

    input.close();

    return nb_lignes;

}


int filereader::getnbcolonnes(string nom_fic,int nb_lignes){

    ifstream input(nom_fic);
    input.seekg(1,ios::beg);

     int lignes_lues=0;
    int nb_colonne=0;
    string ligne;
        while((getline(input,ligne))&&(lignes_lues<nb_lignes)){
            lignes_lues++;
            if(ligne.size()>nb_colonne)
                nb_colonne=ligne.size();
        }

     input.close();
     return nb_colonne;   

}

void filereader::remplir_etat_initial(string nom_fic,etat ei){

         int nb_lignes = getnblignes(nom_fic);
         int nb_colonne = getnbcolonnes(nom_fic,nb_lignes);

        ifstream input(nom_fic);
        input.seekg(1,ios::beg);   
        etat ei(nb_lignes);
        string mot;
        mot.resize(nb_colonne);
        int lignes_lues=0;
        bool casevidetrouve = false;
        
            while ((input >> mot)&& lignes_lues<nb_lignes) {
                if(!casevidetrouve){
                    for(int i=0;i<nb_colonne;i++)
                    {
                        if(mot.at(i) ==' ')
                        {
                            ei.case_vide_x=lignes_lues;
                            ei.case_vide_y=i;
                            casevidetrouve = true;
                        }
                    }
                }
        ei.list.push_back(mot);
        lignes_lues++;
        }
        input.close();
}

void filereader::remplir_etat_final(string nom_fic,etat ef){
            int nb_lignes = getnblignes(nom_fic);
            int nb_colonne = getnbcolonnes(nom_fic,nb_lignes);

        ifstream input(nom_fic);
        input.seekg(nb_lignes+1,ios::beg);   
        etat ef(nb_lignes);
        string mot;
        mot.resize(nb_colonne);
        int lignes_lues=0;
        bool casevidetrouve = false;
        
            while ((input >> mot)&& lignes_lues<nb_lignes) {
                if(!casevidetrouve){
                    for(int i=0;i<nb_colonne;i++)
                    {
                        if(mot.at(i) ==' ')
                        {
                            ef.case_vide_x=lignes_lues;
                            ef.case_vide_y=i;
                            casevidetrouve = true;
                        }
                    }
                }
        ef.list.push_back(mot);
        lignes_lues++;
        }
        input.close();
}

