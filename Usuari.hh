/** @file Usuari.hh
    @brief Especificació de la classe Usuari
*/
#ifndef USUARI_HH
#define USUARI_HH

/// \cond
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <set>
/// \endcond

using namespace std;

/** @class Usuari
    @brief Representa el tipus Usuari
*/
class Usuari{
    private:
        int inscrit;
        int env;
        map <string, int> resolts;
        map <string, int> enviables;
        set <string> intentats;
    public:
        //Constructors
        /** @brief Crea un Usuari amb curs = 0
        \pre Cert
        \post Crea un Usuari amb curs = 0 (no està inscrit)
        */
        Usuari();

        /** @brief Crea un Usuari amb curs = nc
        \pre nc >=0
        \post Crea un Usuari amb curs = nc 
        */
        Usuari(int nc);

        //Modificadors     
        /** @brief Canvia el curs de l'usuari per nc
        \pre nc > 0 
        \post curs = nc
        */
        void modificar_curs(int nc);

        /** @brief Inscriu l'usuari al curs c
        \pre Curs vàlid
        \post Inscriu l'usuari al curs c
        */
        void inscriure_curs(const int &c);

        /** @brief Treu el problema d'enviables 
        \pre Problema existent
        \post Treu el problema d'enviables
        */
        void treure_enviable(const string &p);

        /** @brief Afegeix el problema p als intentats
        \pre p pertany al cjt de problemes
        \post Afegeix el problema p als intentats
        */
        void afegir_intentats(const string &p);

        void afegir_enviables(const string &p);

        //Consultors
        /** @brief Comprova que l'usuari que hagi completat el curs
        \pre Està inscrit a un curs
        \post Comprova que l'usuari que hagi completat el curs
        */
        bool curs_completat();

        /** @brief Retorna el curs en que esta inscrit l'usuari 
        \pre Està inscrit a un curs
        \post Retorna el curs en que esta inscrit l'usuari 
        */
        int curs_usuari();

        /** @brief Escriu els problemes resolts de l'usuari 
        \pre Cert
        \post Escriu els problemes resolts de l'usuari 
        */
        void escriu_resolts();

        /** @brief Escriu els problemes enviables de l'usuari 
        \pre Cert
        \post Escriu els problemes enviables de l'usuari 
        */
        void escriu_enviables();

        /** @brief Retorna el numero de problemes enviats de l'usuari 
        \pre Cert
        \post Retorna el numero de problemes enviats de l'usuari 
        */
        int total();

        /** @brief Retorna el numero de problemes resolts de l'usuari 
        \pre Cert
        \post Retorna el numero de problemes resolts de l'usuari 
        */
        int resolt();

        /** @brief Retorna el numero de problemes intentats de l'usuari 
        \pre Cert
        \post Retorna el numero de problemes intentats de l'usuari 
        */
        int intent();

        

        


};
#endif