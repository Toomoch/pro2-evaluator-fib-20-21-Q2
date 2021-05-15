/** @file Cjt_usuaris.hh
    @brief Especificació de la classe Cjt_usuaris
*/
#ifndef CJT_USUARI_HH
#define CJT_USUARI_HH

/// \cond
#include <iostream>
#include <string>
#include <list>
/// \endcond
#include "Usuari.hh"
#include "Cjt_cursos.hh"
using namespace std;

/** @class Cjt_usuaris
    @brief Representa el tipus Cjt_usuaris
*/
class Cjt_usuaris{
    private:
        map <string, Usuari> mapa;
    public:
        //Constructors
        /** @brief Constructor predeterminat
        \pre Cert
        \post Crea un Usuari amb curs = 0 (no està inscrit)
        */
        Cjt_usuaris();

        //Modificadors
        /** @brief Afegeix un usuari amb id = u al Cjt d'Usuaris
        \pre Usuari no existent al conjunt
        \post Nou element al conjunt d'Usuaris amb id = u
        */
        void afegir_usuari(string u);
        
        /** @brief Elimina l'usuari del Cjt d'usuaris amb id = eu
        \pre Cert
        \post Elimina l'usuari de la llista d'usuaris amb id = eu
        */
        void eliminar_usuari(string u);
        
        /** @brief Omple el conjunt d'usuaris 
        \pre Cert
        \post Conjunt d'Usuaris omplert amb els Usuaris donats
        */
        void llegir_usuaris(int nu);
        
        /** @brief Inscriu l'usuari u al curs c
        \pre Usuari existent
        \post Inscriu l'usuari u al curs c
        */
        void cjt_inscriure_curs(const int &c, const string &u, Cjt_sesions &q, Cjt_cursos &C);
        
        /** @brief Realitza un enviament de problema de l'Usuari u
        \pre Cert
        \post Realitza un enviament de problema de l'Usuari u
        */
        void enviament(string u, string p, int r);

        //Consultors
        /** @brief Retorna el numero del curs en que està inscrit l'usuari
        \pre Usuari existent
        \post Retorna el numero del curs en que està inscrit l'usuari (en cas contrari retorna 0)
        */
        int curs_inscrit(string u);

        /** @brief Escriu els problemes resolts del Usuari
        \pre Cert
        \post Escriu els problemes resolts del Usuari
        */
        void escriu_resolts_cjt(string u);

        /** @brief Escriu els problemes enviables del Usuari
        \pre Cert
        \post Escriu els problemes enviables del Usuari
        */
        void escriu_enviables_cjt(string u);

        /** @brief Escriu els Usuaris pertanyents al conjunt
        \pre Cert
        \post Escriu els Usuaris del conjunt amb els seus enviaments respectius
        */
        void llistar_usuaris();

        /** @brief Escriu l'Usuari u pertanyent al conjunt
        \pre Cert
        \post Escriu l'Usuari u del conjunt amb els seus enviaments respectius
        */
        void llistar_usuari(string u);

        /** @brief Indica si l'usuari està al conjunt
        \pre Cert
        \post Indica si l'usuari està al conjunt
        */
        bool existeix_usuari(string u);

};
#endif