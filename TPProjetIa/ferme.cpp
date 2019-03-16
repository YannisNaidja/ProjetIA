#include "ferme.h"
#include "etat.h"
using namespace std;


ferme::ferme(){}

void ferme::ajoute(etat *e){
    tferme.push_back(*e);
}

bool ferme::etatdansferme(etat *e){
    for(int i=0;i<tferme.size();i++){
        if(e->list==tferme[i].list)
            return true;
    }
    return false;
}