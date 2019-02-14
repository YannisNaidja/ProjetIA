#ifndef DEF_ETAT
#define DEF_ETAT
#include <string>
#include <vector>


class etat{

    public:

        void deplacer_gauche(int bloc_x,int bloc_y,int nb_ligne,int nb_colonne);
        void deplacer_droite(int bloc_x,int bloc_y,int nb_ligne,int nb_colonne);
        void deplacer_haut(int bloc_x,int bloc_y,int nb_ligne,int nb_colonne);
        void deplacer_bas(int bloc_x,int bloc_y,int nb_ligne,int nb_colonne);
        bool Isfinal();//teste si l etat est final
        void generer_voisins();
        
       
        etat(int taille);
        etat();

        vector <string> list;
        
        int case_vide_x;
        int case_vide_y;
        int num_etat;

    
        
};
#endif