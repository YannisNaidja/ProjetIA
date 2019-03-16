#include "filereader.h"
#include <string>
#include <fstream>
#include <iostream>
#include <ctype.h>
#include "etat.h"
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

void filereader::remplir_etat_initial(string nom_fic,etat *ei){

         int nb_lignes = getnblignes(nom_fic);
         int nb_colonne = getnbcolonnes(nom_fic,nb_lignes);
         

        ifstream input(nom_fic);  
        ei->nb_ligne=nb_lignes;
        ei->list.reserve(nb_lignes);
        ei->nb_colonne=nb_colonne;

        string mot;
        getline(input,mot); // manger le premier char
        
        int lignes_lues=0;
        bool casevidetrouve = false;
        
            while ((getline(input,mot))&& lignes_lues<nb_lignes)
             {
    
                if(!casevidetrouve){
                    for(int i=0;i<nb_colonne;i++)
                    {
                        if(mot[i]== ' ' )
                        { 
                            ei->case_vide_x=lignes_lues;
                            ei->case_vide_y=i;
                            casevidetrouve = true;
                            cout << "la case vide de l etat initial se trouve en " << ei->case_vide_x << " " << ei->case_vide_y << endl;
                        }
                    }
                    
                }
        ei->list.push_back(mot);
        lignes_lues++;
        }
        input.close();
       
        
}

void filereader::remplir_etat_final(string nom_fic, etat *ef){
            int nb_lignes = getnblignes(nom_fic);
            int nb_colonne = getnbcolonnes(nom_fic,nb_lignes);

        ifstream input(nom_fic);
        input.seekg(1,ios::beg);
         
        ef->nb_ligne=nb_lignes;
        ef->list.reserve(nb_lignes);
        ef->nb_colonne=nb_colonne;

        string mot;
        string lol;

        int lignes_lues=0;
        
         while(lignes_lues<=nb_lignes){
             getline(input,lol); // retourner a la fin de la premiere grille pour lire la deuxieme
             lignes_lues++;
             cout << lol << endl;
         }
         lignes_lues=0;
        bool casevidetrouve = false;
        
            while ((getline(input,mot))&& lignes_lues<nb_lignes) {
                
                if(!casevidetrouve){
                    for(int i=0;i<nb_colonne;i++)
                    {
                        if(mot[i]== ' ')
                        {
                            ef->case_vide_x=lignes_lues;
                            ef->case_vide_y=i;
                            casevidetrouve = true;
                            cout << "la case vide de l etat final se trouve en " << ef->case_vide_x << " " << ef->case_vide_y << endl;
                        }
                    }
                    
                }
                
        ef->list.push_back(mot);
        lignes_lues++;
        }
        input.close();
        
        
}

