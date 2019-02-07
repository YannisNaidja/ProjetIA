 #include "etat.h"

etat::etat(){}
 
etat::etat(int taille){

    list.reserve(taille);    
}



int etat::getX_bloc(int bloc,int nb_ligne,int nb_colonne){
    for(int i=0;i<nb_ligne;i++){
        for(int j=0;j<nb_colonne;j++){
            if (etat::list[i][j]==bloc)
                return i;
        }
    }
    return -1;
}

int etat::getY_bloc(int bloc,int nb_ligne,int nb_colonne){
    for(int i=0;i<nb_ligne;i++){
        for(int j=0;j<nb_colonne;j++){
            if (etat::list[i][j]==bloc)
                return j;
        }
    }
    return -1;
}

 void etat::deplacer_bas(int bloc,int nb_ligne,int nb_colonne){
     int bloc_x=getX_bloc(bloc,nb_ligne,nb_colonne);
     int bloc_y=getY_bloc(bloc,nb_ligne,nb_colonne);

        if(((bloc_x)+1<= nb_ligne) && (bloc_x+1==case_vide_x) && (bloc_y=case_vide_y)){

            list[case_vide_x][case_vide_y]=list[bloc_x][bloc_y];
            case_vide_x=bloc_x;
            case_vide_y=bloc_y;
            list[case_vide_x][case_vide_y]=' ';
        }
 }

 void etat::deplacer_haut(int bloc,int nb_ligne,int nb_colonne){
     int bloc_x=getX_bloc(bloc,nb_ligne,nb_colonne);
     int bloc_y=getY_bloc(bloc,nb_ligne,nb_colonne);

        if(((bloc_x)-1>=0) && (bloc_x-1==case_vide_x) && (bloc_y=case_vide_y)){

            list[case_vide_x][case_vide_y]=list[bloc_x][bloc_y];
            case_vide_x=bloc_x;
            case_vide_y=bloc_y;
            list[case_vide_x][case_vide_y]=' ';
        }
 }


 void etat::deplacer_gauche(int bloc,int nb_ligne,int nb_colonne){
     int bloc_x=getX_bloc(bloc,nb_ligne,nb_colonne);
     int bloc_y=getY_bloc(bloc,nb_ligne,nb_colonne);

        if(((bloc_y)-1>=0) && (bloc_y-1==case_vide_y) && (bloc_x=case_vide_x)){

            list[case_vide_x][case_vide_y]=list[bloc_x][bloc_y];
            case_vide_x=bloc_x;
            case_vide_y=bloc_y;
            list[case_vide_x][case_vide_y]=' ';
        }
 }

 void etat::deplacer_droite(int bloc,int nb_ligne,int nb_colonne){
     int bloc_x=getX_bloc(bloc,nb_ligne,nb_colonne);
     int bloc_y=getY_bloc(bloc,nb_ligne,nb_colonne);

        if(((bloc_y)+1>=nb_colonne) && (bloc_y+1==case_vide_y) && (bloc_x=case_vide_x)){

            list[case_vide_x][case_vide_y]=list[bloc_x][bloc_y];
            case_vide_x=bloc_x;
            case_vide_y=bloc_y;
            list[case_vide_x][case_vide_y]=' ';
        }
 }