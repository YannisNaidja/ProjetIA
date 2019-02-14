#include <fstream>
#include <iostream>
#include <string>
#include "etat.h"
#include "ouvert.h"
#include <vector>
#include "filereader.h"

using namespace std;

int main(void){

    etat ei;
    etat ef;
    string nom_fic("taquin_2x4.grid");
    filereader filer;

    filer.remplir_etat_initial(nom_fic,ei);
    filer.remplir_etat_final(nom_fic,ef);




    


            
            
            
        
    


}