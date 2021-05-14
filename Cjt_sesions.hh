/** @file Cjt_sesions.hh
    @brief Especificació de la classe Cjt_sesions
*/
#ifndef CJT_SESIONS_HH
#define CJT_SESIONS_HH

/// \cond
#include <iostream>
#include <vector>
#include <map>
#include <list>
/// \endcond
#include "Sesio.hh"
#include "Cjt_ids.hh"

using namespace std;

/** @class Cjt_sesions
    @brief Representa el tipus Cjt_sesions
*/
class Cjt_sesions{
    private:
        map<string, Sesio> mapa;
    public:
    //Constructors
    /** @brief Crea un conjunt de sesions
    \pre Cert
    \post El resultat es un conjunt de sesions buit
    */
    Cjt_sesions();

    //Modificadors
    /** @brief Afegir una sesió al conjunt
    \pre La nova sesió no és existent dins del conjunt
    \post Afegeix una sesió al conjunt de sesions
    */
    void afegir_sesio(string identif);

    /** @brief Llegir un conjunt de sesions
    \pre Nombre de sesions > 0
    \post Llegeix un conjunt de sesions
    */
    void llegir_cjt_sesions(int nsesio);

    //Consultors
    /** @brief Escriure un conjunt de sesions
    \pre Cert
    \post Escriu un conjunt de sesions
    */
    void escriure_cjt_sesio();

    /** @brief Escriure una sesió del conjunt
    \pre Cert
    \post Retorna una sesió 
    */
    void escriure_sesio(string s);

    /** @brief Retorna una llista dels problemes arrel de la llista de sesions donada
    \pre Cert
    \post Retorna una llista dels problemes arrel de la llista de sesions donada
    */
    list <string> arrel_cjt(const list <string> &s);

    /** @brief Busca si el problema donat és a la llista de problemes donada
    \pre Cert
    \post Busca si el problema donat és a la llista de problemes donada
    */
    string ses_prob_find_cjt(const list <string> &l, string p);

    /** @brief Indica si la sesió està al conjunt
    \pre Cert
    \post Indica si la sesió està al conjunt
        */
    bool existeix_sesio(string u);

    Cjt_ids problemes_cjt_sesio(string u);
    /*
    string problemes_cjt_sesio_pos(const set<string>::iterator &it, string u);

    set<string>::iterator problemes_cjt_sesio_principi(string u);

    set<string>::iterator problemes_cjt_sesio_final(string u);
    */
};
#endif