 #include "etat.h"

etat::etat(){}
 
etat::etat(int taille){

    list.reserve(taille);    
}
etat::etat(etat e){

    this.list=e.list;    
}



 void etat::deplacer_bas(int bloc_x,int bloc_y,int nb_ligne,int nb_colonne){
     

        if(((bloc_x)+1<= nb_ligne) && (bloc_x+1==case_vide_x) && (bloc_y=case_vide_y)){

            list[case_vide_x][case_vide_y]=list[bloc_x][bloc_y];
            case_vide_x=bloc_x;
            case_vide_y=bloc_y;
            list[case_vide_x][case_vide_y]=' ';
        }
 }

 void etat::deplacer_haut(int bloc_x,int bloc_y,int nb_ligne,int nb_colonne){
     

        if(((bloc_x)-1>=0) && (bloc_x-1==case_vide_x) && (bloc_y=case_vide_y)){

            list[case_vide_x][case_vide_y]=list[bloc_x][bloc_y];
            case_vide_x=bloc_x;
            case_vide_y=bloc_y;
            list[case_vide_x][case_vide_y]=' ';
        }
 }


 void etat::deplacer_gauche(int bloc_x,int bloc_y,int nb_ligne,int nb_colonne){
     

        if(((bloc_y)-1>=0) && (bloc_y-1==case_vide_y) && (bloc_x=case_vide_x)){

            list[case_vide_x][case_vide_y]=list[bloc_x][bloc_y];
            case_vide_x=bloc_x;
            case_vide_y=bloc_y;
            list[case_vide_x][case_vide_y]=' ';
        }
 }

 void etat::deplacer_droite(int bloc_x,int bloc_y,int nb_ligne,int nb_colonne){
     

        if(((bloc_y)+1>=nb_colonne) && (bloc_y+1==case_vide_y) && (bloc_x=case_vide_x)){

            list[case_vide_x][case_vide_y]=list[bloc_x][bloc_y];
            case_vide_x=bloc_x;
            case_vide_y=bloc_y;
            list[case_vide_x][case_vide_y]=' ';
        }
 }

 void etat::generer_voisins(){
     
 }