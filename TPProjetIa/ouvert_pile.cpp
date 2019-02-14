#include "ouvert_pile.h"
using namespace std;


 bool ouvert_pile::Isempty(){
     if (Ouvert.empty())
        return true;
    return false;

 }

etat ouvert_pile::get_tete(){
    return Ouvert.top();
}

void ouvert_pile::remove(){
    Ouvert.pop();

}

void ouvert_pile::ajout(etat e){
    Ouvert.push(e);
} 

