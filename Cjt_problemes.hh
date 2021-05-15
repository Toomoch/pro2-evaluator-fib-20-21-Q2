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
    map <string, Problema> mapa;

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

    //Consultor
    /** @brief Escriu el Conjunt de problemes
    \pre Cert
    \post Escriu el Conjunt de problemes
    */
    void escriure_cjt_problemes();

    /** @brief Escriu el problema del Conjunt
    \pre Cert
    \post Escriu el problema del Conjunt
    */
    void escriure_problema(const string &p);

    /** @brief Indica si el problema p existeix al conjunt
    \pre Cert
    \post Indica si el problema p existeix al conjunt
    */
    bool existeix_problema(const string &p);

};

#endif