#ifndef DEF_ETAT
#define DEF_ETAT
#include <string>
#include <vector>
#include "case_vide.h"

class etat{

    public:

        void deplacer_gauche(int bloc,int nb_ligne,int nb_colonne);
        void deplacer_droite(int bloc,int nb_ligne,int nb_colonne);
        void deplacer_haut(int bloc,int nb_ligne,int nb_colonne);
        void deplacer_bas(int bloc,int nb_ligne,int nb_colonne);
        bool Isfinal();//teste si l etat est final
        int getX_bloc(int bloc,int nb_ligne,int nb_colonne);
        int getY_bloc(int bloc,int nb_ligne,int nb_colonne);
        
        etat(int nb_ligne,int nb_colonne);
        etat(int taille);

        char **grille;
        vector <string> list;

        struct casevide *ptrcasevide;
        
        int case_vide_x;
        int case_vide_y;
        int num_etat;
        
};
#endif