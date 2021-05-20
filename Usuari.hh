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
        /** @brief Enter on s'emmagatzema el curs on està inscrit */
        int inscrit;
        /** @brief Enter on s'emmagatzema quants enviaments ha fet */
        int env;

        /** @brief Mapa on s'emmagatzemen tots els problemes que ha resolt l'Usuari i els seus intents*/
        map <string, int> resolts;

        /** @brief Mapa on s'emmagatzemen tots els problemes que pot resoldre l'Usuari i els seus intents*/
        map <string, int> enviables;

        /** @brief Set on s'emmagatzemen tots els problemes que ha enviat l'Usuari */
        set <string> intentats;
    public:
        //Constructors
        /** @brief Crea un Usuari amb curs = 0
        \pre Cert
        \post Crea un Usuari amb curs = 0 (no està inscrit)
        */
        Usuari();

        //Modificadors     
        /** @brief Inscriu l'usuari al curs c
        \pre Curs vàlid
        \post Inscriu l'usuari al curs c 
        */
        void inscriure_curs(const int &c);

        /** @brief Treu el problema d'enviables i l'afegeix a resolts
        \pre p pertany al cjt de problemes
        \post Treu el problema d'enviables i l'afegeix a resolts
        */
        void afegir_resolt(const string &p);

        /** @brief Afegeix el problema p als intentats
        \pre p pertany al cjt de problemes
        \post Afegeix el problema p als intentats
        */
        void afegir_intentats(const string &p);

        /** @brief Afegeix el problema p als enviables
        \pre p pertany al cjt de problemes
        \post Afegeix el problema p als enviables
        */
        void afegir_enviables(const string &p);

        /** @brief Incrementa en 1 els intents del problema enviable p
        \pre p pertany als problemes enviables
        \post Incrementa en 1 els intents del problema enviable p
        */
        void inc_enviable(const string &p);

        /** @brief L'usuari es dona de baixa del curs on està inscrit
        \pre Cert
        \post L'usuari es dona de baixa del curs on està inscrit
        */
        void acabar_curs();

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

        /** @brief Retorna el numero de problemes enviables de l'usuari 
        \pre Cert
        \post Retorna el numero de problemes enviables de l'usuari 
        */
        int enviable();

        /** @brief Retorna el numero de problemes intentats de l'usuari 
        \pre Cert
        \post Retorna el numero de problemes intentats de l'usuari 
        */
        int intent();

        /** @brief Retorna true si l'Usuari ha resolt el problema p
        \pre p pertany al cjt de problemes
        \post Retorna true si l'Usuari ha resolt el problema p i si no false
        */
        bool problema_resolt(const string &p);
        

        


};
#endif