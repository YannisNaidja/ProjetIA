#include "ouvert_pile.h"
using namespace std;

 
ouvert_pile::ouvert_pile(){
    
}

 bool ouvert_pile::Isempty(){
     if (Ouvert.empty())
        return true;
    return false;

 }

etat ouvert_pile::get_tete(){
    return Ouvert.back();
}

void ouvert_pile::remove(){
    Ouvert.pop_back();

}

void ouvert_pile::ajout(etat *e,etat *fin){
    Ouvert.push_back(*e);
} 

bool ouvert_pile::etatdansouvert(etat *e){
    for(int i=0;i<Ouvert.size();i++){
        if(e->list==Ouvert[i].list){
            return true;
        }
    }
    return false;
}

