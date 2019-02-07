#ifndef DEF_ETAT
#define DEF_ETAT

class etat{

    public:

        void deplacer_gauche();
        void deplacer_droite();
        void deplacer_haut();
        void deplacer_bas();

        char[][] grille;
        int case_vide_x;
        int case_vide_y;


};