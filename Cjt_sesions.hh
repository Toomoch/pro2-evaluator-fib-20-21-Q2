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
    void afegir_sesio(const string &identif);

    /** @brief Llegir un conjunt de sesions
    \pre Nombre de sesions > 0
    \post Llegeix un conjunt de sesions
    */
    void llegir_cjt_sesions(const int &nsesio);

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
    void escriure_sesio(const string &s);

    /** @brief Indica si la sesió està al conjunt
    \pre Cert
    \post Indica si la sesió està al conjunt
    */
    bool existeix_sesio(const string &u);

    bool omplir_mapa_curs(Curs &c, const bool mirar_interseccio);

    //Cjt_ids problemes_cjt_sesio(const string &u);

    //bool sesio_problema_existeix(const string &p, const string &s);

    void inscriu_cjt_sesio(const string &s, Usuari &u);

    void afegeix_fulles_cjt(const string &p, const string &s, Usuari &u);
};
#endif