/** @file Curs.hh
    @brief Especificació de la classe Curs
*/
#ifndef CURS_HH
#define CURS_HH

/// \cond
#include <iostream>
#include <string>
#include <list>
#include <set>
/// \endcond

#include "Cjt_sesions.hh"
using namespace std;

/** @class Curs
    @brief Representa el tipus Curs
*/
class Curs{
    private:
        list <string> ses_del_curs;
        int inscrits;
        int acabaments;
    public:
    //Constructors
    /** @brief Constructor predeterminat
    \pre Cert
    \post Crea un Curs buit
    */
    Curs();

    //Modificadors
    /** @brief Llegeix un curs
    \pre nses > 0
    \post Llegeix un Curs buit
    */
    void llegir_curs(const int &nses);

    /** @brief Incrementa el nombre d'inscrits en 1
    \pre Cert
    \post Incrementa el nombre d'inscrits en 1
    */    
    void inc_inscrits();

    /** @brief Decrementa el nombre d'inscrits en 1
    \pre Cert
    \post Decrementa el nombre d'inscrits en 1
    */    
    void dec_inscrits();

    //Consultors
    /** @brief Escriu el Curs i les seves característiques
    \pre Cert
    \post Escriu les característiques del curs: nombre d'usuaris que l'han completat, nombre d'inscrits, nombre de sesions i els identificadors d'aquestes
    */
    void escriure_curs();

    /** @brief Retorna el nombre d'inscrits en el curs
    \pre Cert
    \post Retorna el nombre d'inscrits en el curs
    */
    int num_inscrits();

    /** @brief Retorna el nombre de cops que s'ha completat el curs
    \pre Cert
    \post Retorna el nombre de cops que s'ha completat el curs
    */
    int num_acabaments();

    /** @brief Serà true si el curs té un conflicte de interseccio de problemes
    \pre Cert
    \post Retorna si el curs té un conflicte de interseccio de problemes
    */
    bool interseccio(Cjt_sesions &q);

    string curs_sesio_problema_existeix(const string &p, Cjt_sesions &q);

    void inscriu_curs(Usuari &u, Cjt_sesions &q);
    
};

#endif