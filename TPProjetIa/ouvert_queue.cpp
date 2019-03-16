
#include "ouvert_queue.h"
using namespace std;


ouvert_queue::ouvert_queue(){

}

 bool ouvert_queue::Isempty(){
     if (Ouvert.empty())
        return true;
    return false;

 }

etat ouvert_queue::get_tete(){
    return Ouvert.front();
}

void ouvert_queue::remove(){
    Ouvert.pop_front();

}

void ouvert_queue::ajout(etat *e,etat *fin){
    Ouvert.push_back(*e);
} 

bool ouvert_queue::etatdansouvert(etat *e){
    for(int i=0;i<Ouvert.size();i++){
        if(e->list==Ouvert[i].list){
            return true;
        }
    }
    return false;
}
