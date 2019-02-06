#include "ouvert.h"
#include <stack>
#include "etat.h"
#include <list>
using namespace std;

list<etat> Ferme;
stack<etat> Ouvert;


 bool ouvert::Isempty(){
     if (Ouvert.empty())
        return true;
    return false;

 }

etat ouvert::tete(){
    return Ouvert.top();
}

void ouvert::remove(){
    Ouvert.pop();

}

void ouvert::add_ferme(etat e){
    Ferme.push_front(e);
}

void ouvert::add_ouvert(etat e){
    Ouvert.push(e);
} 