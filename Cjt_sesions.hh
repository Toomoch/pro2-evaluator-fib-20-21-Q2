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
        /** @brief Mapa on s'emmagatzemen les Sesions pertanyents al conjunt amb el seu identificador */
        map<string, Sesio> sesions;
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

    /** @brief Omple el contenidor del curs c amb els problemes adequats
    \pre Cert
    \post Omple el contenidor del curs c amb els problemes de les sesions on està inscrit
    */
    bool omplir_sesions_curs(Curs &c, const bool mirar_interseccio);

    /** @brief Afegeix els problemes de la sesio s als enviables de l'Usuari u
    \pre Sesio existent al conjunt
    \post Afegeix els problemes de la sesio s al conjunt d'enviables de l'Usuari u
    */
    void inscriu_cjt_sesio(const string &s, Usuari &u);

    /** @brief Afegeix les fulles dels problemes de la sesio s als enviables de l'Usuari u
    \pre Sesio i problema existents als seus conjunts
    \post Afegeix les fulles dels problemes de la sesio s als enviables de l'Usuari u
    */
    void afegeix_fulles_cjt(const string &p, const string &s, Usuari &u);

    //Consultors
    /** @brief Escriu el conjunt de sesions
    \pre Cert
    \post Escriu el conjunt de sesions
    */
    void escriure_cjt_sesio() const;

    /** @brief Escriu una sesió del conjunt
    \pre Sesió existent al conjunt
    \post Escriu la sesió s donada     
    */
    void escriure_sesio(const string &s) const;

    /** @brief Indica si la sesió està al conjunt
    \pre Cert
    \post Indica si la sesió està al conjunt
    */
    bool existeix_sesio(const string &s) const;

};
#endif