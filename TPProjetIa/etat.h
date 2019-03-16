#ifndef DEF_ETAT
#define DEF_ETAT
#include <string>
#include <vector>
class ouvert;
#include "ferme.h"





class etat{

    public:
        
        void deplacer_gauche(int bloc_x,int bloc_y);
        void deplacer_droite(int bloc_x,int bloc_y);
        void deplacer_haut(int bloc_x,int bloc_y);
        void deplacer_bas(int bloc_x,int bloc_y);
        bool Isfinal();//teste si l etat est final
        void generer_voisins(ouvert *Ouvert, ferme Ferme,etat *fin);
        void nombre_voisins();
        void affiche_etat();
        
       
        etat(int taille);
        etat(const etat &e);
        etat();

        std::vector <std::string> list;
        
        int case_vide_x;
        int case_vide_y;
        int nb_ligne;
        int nb_colonne;
        bool voisin_gauche=false;
        bool voisin_droite=false;
        bool voisin_haut=false;
        bool voisin_bas=false;
        
        

    
        
};
#endif