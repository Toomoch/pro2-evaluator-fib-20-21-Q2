/** @file Sesio.hh
    @brief Especificació de la classe Sesio
*/
#ifndef SESIO_HH
#define SESIO_HH

/// \cond
#include <iostream>
#include <string>
#include "BinTree.hh"
/// \endcond
//#include "Cjt_ids.hh"
#include "Usuari.hh"
#include "Curs.hh"
using namespace std;

/** @class Sesio
    @brief Representa el tipus Sesio
*/
class Sesio{
    private:
    /** @brief Bintree on s'emmagatzemen els problemes pertanyents a la sessio amb el seu identificador */
        BinTree<string> tree;

        /** @brief Enter on s'emmagatzema el numero de problemes que hi ha  */
        int numprob;

        /** @brief Llegeix la sessió en forma preordre d'arbre binari
        \pre Els problemes existeixen i no es repeteixen
        \post Llegeix la sessió en forma preordre d'arbre binari
        */
        static void preordre_llegir_ses(BinTree <string> &temp);

        /** @brief Escriu la sessió en forma post de l'arbre binari
        \pre Els problemes existeixen i no es repeteixen
        \post Escriu els problemes de la sessió en forma post de l'arbre binari
        */
        static void post_escriure_ses(const BinTree <string> &t);

        /** @brief Inserta els fills del problema al contenidor del Usuari 
        \pre Problema existent a la sesio
        \post Inserta els fills del problema al contenidor del Usuari (crida a <em>afegir_enviable<em>.)
        */
        void troba_afegeix_fulles_arbre(const BinTree<string> &t, const string &p, Usuari &u);

        /** @brief Inserta els problemes de la sesio al contenidor del Usuari
        \pre ses = nom de la sesio i interseccio = false
        \post Inserta els problemes de la sesio amb el nom d'aquesta al contenidor del Usuari
        */
        static void afegir_enviable(const BinTree<string> &t, Usuari &u);

        /** @brief Afegeix la arrel no resolta de la sesio a l'Usuari 
        \pre Existeix la sessió i no és buida
        \post Afegeix la(s) arrel(s) que estigui per resoldre de la sesio a l'Usuari (crida a <em>afegir_enviable<em>)
        */
        static void afegir_problemes_usuari_tree(const BinTree<string>& t, Usuari& u);
    public:
    //Constructors
    /** @brief Contructor predeterminat
    \pre Cert
    \post Crea una sesió buida
    */
    Sesio();

    //Consultors
    /** @brief Retorna el numero problemes que té la sessió
    \pre Existeix la sessió i no és buida
    \post Retorna el numero problemes que té la sessió
    */
    int num_problemes() const;

    /** @brief Escriu els problemes de la sesió
    \pre Cert
    \post Escriu els problemes de la sesió
    */
    void escriu_ses() const;

    //Modificadors
    /** @brief Llegeix la sessió en forma d'arbre binari
    \pre Els problemes existeixen i no es repeteixen
    \post Llegeix la sessió en forma d'arbre binari
    */
    void llegir_ses();

    /** @brief Indica si el curs té interseccio de problemes
    \pre ses = nom de la sesio
    \post Indica si el curs té interseccio de problemes
    */
    bool inters_pre_inserta_contenidor_curs(const string &ses, Curs &c);

    /** @brief Inserta els problemes de la sesio al contenidor del curs
    \pre ses = nom de la sesio i interseccio = false
    \post Inserta els problemes de la sesio amb el nom d'aquesta al contenidor del curs
    */
    void inserta_contenidor_curs(const string &ses, Curs &c, const BinTree<string> &t, bool &interseccio);
    
    /** @brief Calcula i retorna el numero de problemes que té la sessió
    \pre Cert
    \post Calcula i retorna el numero de problemes que té la sessió
    */
    int calc_numero_problemes(const BinTree <string> &temp);

    /** @brief Inserta els fills del problema al contenidor del Usuari 
    \pre Problema existent a la sesio
    \post Inserta els fills del problema al contenidor del Usuari (crida a <em>troba_afegeix_fulles_arbre<em>.)
    */
    void pre_troba_afegeix_fulles(const string &p, Usuari &u);

    /** @brief Afegeix la arrel corresponent de la sesio a l'Usuari 
    \pre Existeix la sessió i no és buida
    \post Afegeix la(s) arrel(s) que estigui per resoldre de la sesio a l'Usuari (crida a <em>afegir_enviable<em>. o <em>afegir_problemes_usuari_tree<em>.)
    */
    void arrel(Usuari &u);


};
#endif