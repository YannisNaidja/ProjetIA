#ifndef DEF_FILEREADER
#define DEF_FILEREADER
#include <string>
#include <fstream>
#include <iostream>
#include "etat.h"

class filereader {

    public:

        void remplir_etat_final(std::string nom_fic,etat *ef);
        void remplir_etat_initial(std::string nom_fic,etat *ei);
        int getnblignes(std::string nom_fic);
        int getnbcolonnes(std::string nom_fic,int nb_lignes);
        filereader();

};

        



#endif
