#include "ouvert.h"
#include <stack>
#include "etat.h"
using namespace std;

stack<etat> ouvert;

 bool ouvert::Isempty(){
     if (ouvert.empty())
        return true;
    return false;

 }

etat ouvert::tete(){
    return ouvert.pop();
}