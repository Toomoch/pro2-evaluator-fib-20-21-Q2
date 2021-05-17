/** @file Cjt_problemes.hh
    @brief Especificació de la classe Cjt_problemes
*/
#ifndef CJT_PROBLEMES_HH
#define CJT_PROBLEMES_HH

/// \cond
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
/// \endcond

#include "Problema.hh"
using namespace std;

/** @class Cjt_problemes
    @brief Representa el tipus Cjt_problemes
*/
class Cjt_problemes {

private:

    /** @brief Mapa on s'emmagatzemen els problemes pertanyents al conjunt amb el seu identificador */
    map <string, Problema> problemes;

    /** @brief Retorna true si l'element a va abans que el b
    \pre Cert
    \post Retorna true si l'element a va abans que el b en l'ordre, es mira primer per ratio i despres per l'identificador
    */
    static bool cmp(const pair<string,Problema>& a, const pair<string,Problema>& b);

public:

    //Constructors
    /** @brief Constructor predeterminat
    \pre Cert
    \post Crea un Conjunt de problemes buit
    */
    Cjt_problemes();

    //Modificadors
    /** @brief Afegeix un problema al Conjunt 
    \pre Cert
    \post Afegeix un problema al Conjunt de problemes
    */
    void afegeix_Cjt_problemes(const string &prob);

    /** @brief Llegeix un Conjunt
    \pre Nombre de problemes > 0
    \post Llegeix un Conjunt de problemes
    */
    void llegir_Cjt_problemes(const int &np);

    /** @brief Incrementa el total d'enviaments en 1 del problema p
    \pre Es fa un nou enviament
    \post Incrementa el total d'enviaments del problema en 1 problema p
    */
    void inc_env_total_cjt(const string &p);

    /** @brief Incrementa el total d'enviaments exitosos en 1 problema p
    \pre Es fa un nou enviament correcte
    \post Incrementa el total d'enviaments exitosos del problema en 1 problema p
    */
    void inc_env_exit_cjt(const string &p);

    //Consultor
    /** @brief Escriu el Conjunt de problemes ordenadament
    \pre Cert
    \post Escriu el Conjunt de problemes ordenats per ratio i en cas d'empat per l'identificador
    */
    void escriure_cjt_problemes() const;

    /** @brief Escriu el problema del Conjunt
    \pre Problema p existent al conjunt
    \post Escriu el problema del Conjunt
    */
    void escriure_problema(const string &p);

    /** @brief Indica si el problema p existeix al conjunt
    \pre Cert
    \post Indica si el problema p existeix al conjunt
    */
    bool existeix_problema(const string &p) const;

};

#endif