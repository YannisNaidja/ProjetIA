 #include "etat.h"


 
etat::etat(int taille){

    list.reserve(taille); 
    nb_ligne=taille;

}
etat::etat(const etat &e){

    //copy constructor
    list = e.list;
    nb_ligne=e.nb_ligne;
    nb_colonne=e.nb_colonne;
    voisin_bas=e.voisin_bas;
    voisin_droite=e.voisin_droite;
    voisin_gauche=e.voisin_gauche;
    voisin_haut=e.voisin_haut;
    case_vide_x=e.case_vide_x;
    case_vide_y=e.case_vide_y;

}




 void etat::deplacer_bas(int bloc_x,int bloc_y){
     

        if(((bloc_x)+1<= nb_ligne) && (bloc_x+1==case_vide_x) && (bloc_y=case_vide_y)){

            list[case_vide_x][case_vide_y]=list[bloc_x][bloc_y];
            case_vide_x=bloc_x;
            case_vide_y=bloc_y;
            list[case_vide_x][case_vide_y]=' ';
        }
 }

 void etat::deplacer_haut(int bloc_x,int bloc_y){
     

        if(((bloc_x)-1>=0) && (bloc_x-1==case_vide_x) && (bloc_y=case_vide_y)){

            list[case_vide_x][case_vide_y]=list[bloc_x][bloc_y];
            case_vide_x=bloc_x;
            case_vide_y=bloc_y;
            list[case_vide_x][case_vide_y]=' ';
        }
 }


 void etat::deplacer_gauche(int bloc_x,int bloc_y){
     

        if(((bloc_y)-1>=0) && (bloc_y-1==case_vide_y) && (bloc_x=case_vide_x)){

            list[case_vide_x][case_vide_y]=list[bloc_x][bloc_y];
            case_vide_x=bloc_x;
            case_vide_y=bloc_y;
            list[case_vide_x][case_vide_y]=' ';
        }
 }

 void etat::deplacer_droite(int bloc_x,int bloc_y){
     

        if(((bloc_y)+1< nb_colonne) && (bloc_y+1==case_vide_y) && (bloc_x=case_vide_x)){

            list[case_vide_x][case_vide_y]=list[bloc_x][bloc_y];
            case_vide_x=bloc_x;
            case_vide_y=bloc_y;
            list[case_vide_x][case_vide_y]=' ';
        }
 }

    int etat::nombre_voisins(){

        int c = 0;
        if(list[case_vide_x][case_vide_y+1]!=' ' && case_vide_y < nb_colonne){
                c++;
                voisin_droite=true;
        } // voisin a droite
            
        if ((list[case_vide_x][case_vide_y-1]!= ' ') && ( case_vide_y>0)){ //voisin gauche
            c++;
            voisin_gauche=true;
        }
        if((list[case_vide_x-1][case_vide_y]!= ' ') && (case_vide_x > 0)){ //voisin haut 
            c++; 
            voisin_haut=true;
        }
        if((list[case_vide_x+1][case_vide_y]!= ' ') && (case_vide_x < nb_ligne)){
            c++;
            voisin_bas=true;
        }

        return c;        


    }

 void etat::generer_voisins(ouvert *Ouvert,ferme *Ferme){

     if(voisin_bas){
        etat case_bas_deplacer = etat(*this);
        case_bas_deplacer.deplacer_haut(case_vide_x+1,case_vide_y);
        if(!Ouvert->etatdansouvert(case_bas_deplacer) && !Ferme->etatdansferme(case_bas_deplacer)){
            Ouvert->ajout(case_bas_deplacer);
        }
     }

     if(voisin_haut){
         etat case_haut_deplacer = etat(*this);
         case_haut_deplacer.deplacer_bas(case_vide_x-1,case_vide_y);
         if(!Ouvert->etatdansouvert(case_haut_deplacer) && !Ferme->etatdansferme(case_haut_deplacer)){
            Ouvert->ajout(case_haut_deplacer);
        }
     }

     if(voisin_droite){
         etat case_droite_deplacer = etat(*this);
         case_droite_deplacer.deplacer_gauche(case_vide_x,case_vide_y+1);
         if(!Ouvert->etatdansouvert(case_droite_deplacer) && !Ferme->etatdansferme(case_droite_deplacer)){
            Ouvert->ajout(case_droite_deplacer);
        }
     }
     if(voisin_gauche){
         etat case_gauche_deplacer = etat(*this);
         case_gauche_deplacer.deplacer_droite(case_vide_x,case_vide_y-1);
         if(!Ouvert->etatdansouvert(case_gauche_deplacer) && !Ferme->etatdansferme(case_gauche_deplacer)){
            Ouvert->ajout(case_gauche_deplacer);
        }
     }   
 }