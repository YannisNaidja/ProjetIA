 #include "etat.h"

etat::etat(int taille){

    list.reserve(taille);    
}
etat::etat(int nb_ligne,int nb_colonne){
        grille = (char**) calloc(nb_ligne, sizeof(char*));

for ( int i = 0; i < nb_ligne; i++ )
{
    grille[i] = (char*) calloc(nb_colonne, sizeof(char));
}
}

int etat::getX_bloc(int bloc,int nb_ligne,int nb_colonne){
    for(int i=0;i<nb_ligne;i++){
        for(int j=0;j<nb_colonne;j++){
            if (etat::grille[i][j]==bloc)
                return i;
        }
    }
    return -1;
}

int etat::getY_bloc(int bloc,int nb_ligne,int nb_colonne){
    for(int i=0;i<nb_ligne;i++){
        for(int j=0;j<nb_colonne;j++){
            if (etat::grille[i][j]==bloc)
                return j;
        }
    }
    return -1;
}

 void etat::deplacer_bas(int bloc,int nb_ligne,int nb_colonne){
     int bloc_x=getX_bloc(bloc,nb_ligne,nb_colonne);
     int bloc_y=getY_bloc(bloc,nb_ligne,nb_colonne);

        if(((bloc_x)+1<= nb_ligne) && (bloc_x+1==case_vide_x) && (bloc_y=case_vide_y)){

            grille[case_vide_x][case_vide_y]=grille[bloc_x][bloc_y];
            case_vide_x=bloc_x;
            case_vide_y=bloc_y;
            grille[case_vide_x][case_vide_y]='v';
        }
 }

 void etat::deplacer_haut(int bloc,int nb_ligne,int nb_colonne){
     int bloc_x=getX_bloc(bloc,nb_ligne,nb_colonne);
     int bloc_y=getY_bloc(bloc,nb_ligne,nb_colonne);

        if(((bloc_x)-1>=0) && (bloc_x-1==case_vide_x) && (bloc_y=case_vide_y)){

            grille[case_vide_x][case_vide_y]=grille[bloc_x][bloc_y];
            case_vide_x=bloc_x;
            case_vide_y=bloc_y;
            grille[case_vide_x][case_vide_y]='v';
        }
 }


 void etat::deplacer_gauche(int bloc,int nb_ligne,int nb_colonne){
     int bloc_x=getX_bloc(bloc,nb_ligne,nb_colonne);
     int bloc_y=getY_bloc(bloc,nb_ligne,nb_colonne);

        if(((bloc_y)-1>=0) && (bloc_y-1==case_vide_y) && (bloc_x=case_vide_x)){

            grille[case_vide_x][case_vide_y]=grille[bloc_x][bloc_y];
            case_vide_x=bloc_x;
            case_vide_y=bloc_y;
            grille[case_vide_x][case_vide_y]='v';
        }
 }

 void etat::deplacer_droite(int bloc,int nb_ligne,int nb_colonne){
     int bloc_x=getX_bloc(bloc,nb_ligne,nb_colonne);
     int bloc_y=getY_bloc(bloc,nb_ligne,nb_colonne);

        if(((bloc_y)+1>=nb_colonne) && (bloc_y+1==case_vide_y) && (bloc_x=case_vide_x)){

            grille[case_vide_x][case_vide_y]=grille[bloc_x][bloc_y];
            case_vide_x=bloc_x;
            case_vide_y=bloc_y;
            grille[case_vide_x][case_vide_y]='v';
        }
 }