using namespace std;
#include <iostream>
#include "etat.h"
#include "ouvert.h"

etat::etat(){
    
}
 
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




 void etat::deplacer_bas(int bloc_x,int bloc_y){ // bloc x et bloc y sont les coordoonee de la case a deplacer
     

        if((bloc_x+1 < nb_ligne) && (bloc_x+1==case_vide_x) && (bloc_y==case_vide_y)){
            
            
            list[case_vide_x][case_vide_y]=list[bloc_x][bloc_y];
            case_vide_x=bloc_x;
            case_vide_y=bloc_y;
            list[case_vide_x][case_vide_y]=' ';

            

            
        }
 }

 void etat::deplacer_haut(int bloc_x,int bloc_y){
     

        if(((bloc_x)-1>=0) && (bloc_x-1==case_vide_x) && (bloc_y==case_vide_y)){

            list[case_vide_x][case_vide_y]=list[bloc_x][bloc_y];
            case_vide_x=bloc_x;
            case_vide_y=bloc_y;
            list[case_vide_x][case_vide_y]=' ';
        }
 }


 void etat::deplacer_gauche(int bloc_x,int bloc_y){
     

        if(((bloc_y)-1>=0) && (bloc_y-1==case_vide_y) && (bloc_x==case_vide_x)){

            list[case_vide_x][case_vide_y]=list[bloc_x][bloc_y];
            case_vide_x=bloc_x;
            case_vide_y=bloc_y;
            list[case_vide_x][case_vide_y]=' ';
        }
 }

 void etat::deplacer_droite(int bloc_x,int bloc_y){
     

        if(((bloc_y)+1< nb_colonne) && (bloc_y+1==case_vide_y) && (bloc_x==case_vide_x)){

            list[case_vide_x][case_vide_y]=list[bloc_x][bloc_y];
            case_vide_x=bloc_x;
            case_vide_y=bloc_y;
            list[case_vide_x][case_vide_y]=' ';
        }
 }

    void etat::nombre_voisins(){

        int c = 0;
        

                if(case_vide_y < nb_colonne-1){
            if(list[case_vide_x][case_vide_y+1]!=' '){
                    c++;
                    this->voisin_droite=true;
            }
            
           }  // voisin a droite

            

             if(case_vide_y>0){  
            if (list[case_vide_x][case_vide_y-1]!= ' '){ //voisin gauche
                c++;
                this->voisin_gauche=true;
                
                }
                
                 
            }
         
            
                if(case_vide_x > 0){
            if(list[case_vide_x-1][case_vide_y]!= ' ') { //voisin haut 
                c++; 
                this->voisin_haut=true;
                }
             
               
            } 
            
            
                if(case_vide_x < nb_ligne-1){
            if(list[case_vide_x+1][case_vide_y]!= ' '){
            
                c++;
                this->voisin_bas=true;
            }
        } 
        
                


    }

 void etat::generer_voisins(ouvert *Ouvert,ferme Ferme,etat *fin){

     this->nombre_voisins();
    
    //cout << "case vide x : " << this->case_vide_x << endl;
    //cout << "case vide y : " << this->case_vide_y << endl;
     //cout << " voisin gauche : " << this->voisin_gauche << endl;
     //cout << " voisin droit  : " << this->voisin_droite << endl;
     //cout << " voisin haut : " << this->voisin_haut << endl;
     //cout << " voisin bas : " << this->voisin_bas << endl;


     if(this->voisin_bas){ // voisin en bas on déplace la case du bas vers le haut
        cout << "voisin bas" << endl; 
        cout << endl;
        etat *case_bas_deplacer = new etat(*this);

        case_bas_deplacer->deplacer_haut(case_vide_x+1,case_vide_y);
        case_bas_deplacer->voisin_bas=false;
        //this->voisin_bas=false;

        cout << "affichage de l etat produit"<<endl;
        cout << endl;
        case_bas_deplacer->affiche_etat();

        if(!Ouvert->etatdansouvert(case_bas_deplacer) && !Ferme.etatdansferme(case_bas_deplacer)){
            cout << " ajout de la production dans ouvert" << endl;
            cout << endl;
            Ouvert->ajout(case_bas_deplacer,fin);
        }
     }

     if(this->voisin_haut){
         cout << "voisin haut" << endl;
         cout << endl;
         etat *case_haut_deplacer = new etat(*this);
         case_haut_deplacer->deplacer_bas(case_vide_x-1,case_vide_y);
         case_haut_deplacer->voisin_haut=false;
         //this->voisin_haut=false;

         cout << "affichage de l etat produit"<<endl;
         cout << endl;
        case_haut_deplacer->affiche_etat();

         if(!Ouvert->etatdansouvert(case_haut_deplacer) && !Ferme.etatdansferme(case_haut_deplacer)){
            cout << " ajout de la production dans ouvert" << endl;
            cout << endl;
            Ouvert->ajout(case_haut_deplacer,fin);
        }
     }

     if(this->voisin_droite){
         cout << "voisin droite" << endl;
         cout << endl;
         etat *case_droite_deplacer = new etat(*this);
         case_droite_deplacer->deplacer_gauche(case_vide_x,case_vide_y+1);
         case_droite_deplacer->voisin_droite=false;
         //this->voisin_droite=false;

         cout << "affichage de l etat produit"<<endl;
         cout << endl;
        case_droite_deplacer->affiche_etat();

         if(!Ouvert->etatdansouvert(case_droite_deplacer) && !Ferme.etatdansferme(case_droite_deplacer)){
             cout << " ajout de la production dans ouvert" << endl;
             cout << endl;
            Ouvert->ajout(case_droite_deplacer,fin);
        }
     }
     if(this->voisin_gauche){
         cout << "voisin gauche" << endl;
         cout << endl;
         etat *case_gauche_deplacer = new etat(*this);
         case_gauche_deplacer->deplacer_droite(case_vide_x,case_vide_y-1);
         case_gauche_deplacer->voisin_gauche=false;
         //this->voisin_gauche=false;

         cout << "affichage de l etat produit"<<endl;
         cout << endl;
            case_gauche_deplacer->affiche_etat();

         if(!Ouvert->etatdansouvert(case_gauche_deplacer) && !Ferme.etatdansferme(case_gauche_deplacer)){
             cout << " ajout de la production dans ouvert" << endl;
            Ouvert->ajout(case_gauche_deplacer,fin);
        }
     } 


 }

 void etat::affiche_etat(){
     for(int i=0;i<list.size();i++){
         for(int j=0;j<list[i].size();j++){
             cout << list[i][j] ;
         }
         cout << endl;
     }

 }
 