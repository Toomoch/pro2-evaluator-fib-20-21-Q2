/** @file Sesio.hh
    @brief Especificació de la classe Sesio
*/
#ifndef SESIO_HH
#define SESIO_HH

/// \cond
#include <iostream>

#include "BinTree.hh"
/// \endcond
#include "Cjt_ids.hh"
#include "Usuari.hh"
using namespace std;

/** @class Sesio
    @brief Representa el tipus Sesio
*/
class Sesio{
    private:
        BinTree<string> tree;
        Cjt_ids setprob;
        int numprob;
    public:
    //Constructors
    /** @brief Contructor predeterminat
    \pre Cert
    \post Crea una sesió buida
    */
    Sesio();

    //Consultors
    /** @brief Calcula i retorna el numero de problemes que té la sessió
    \pre Cert
    \post Calcula i retorna el numero de problemes que té la sessió
    */
    int calc_numero_problemes(const BinTree <string> &temp);

    /** @brief Retorna el numero problemes que té la sessió
    \pre Existeix la sessió i no és buida
    \post Retorna el numero problemes que té la sessió
    */
    int num_problemes();

    /** @brief Retorna el problema arrel de la sesió
    \pre Existeix la sessió i no és buida
    \post Retorna el problema arrel de la sesió
    */
    string arrel();

    /** @brief Escriu els problemes de la sesió
    \pre Cert
    \post Escriu els problemes de la sesió
    */
    void escriu_ses();

    void preorde_escriure_ses(const BinTree <string> &t);

    /** @brief Retorna true si el problema p existeix a la sesió 
    \pre Cert
    \post Retorna true si el problema p existeix a la sesió
    */
    bool ses_prob_find(string p);

    bool buscar(const BinTree<string> &t, string &p);
    
    
    //Modificadors
    /** @brief Llegeix la sessió en forma d'arbre binari
    \pre Els problemes existeixen i no es repeteixen
    \post Llegeix la sessió en forma d'arbre binari
    */
    void llegir_ses();

    /** @brief Llegeix la sessió en forma preordre d'arbre binari
    \pre Els problemes existeixen i no es repeteixen
    \post Llegeix la sessió en forma preordre d'arbre binari
    */
    void preordre_llegir_ses(BinTree <string> &temp);

    /** @brief Retorna el conjunt de problemes que conté la sessió
    \pre Cert
    \post Retorna el conjunt de problemes que conté la sessió
    */
    Cjt_ids problemes_sesio();

    void wtf(const BinTree<string> &y, string &p, bool &copy);
};
#endif