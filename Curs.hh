/** @file Curs.hh
    @brief Especificació de la classe Curs
*/
#ifndef CURS_HH
#define CURS_HH

/// \cond
#include <iostream>
#include <string>
#include <vector>
#include <map>
/// \endcond

using namespace std;

/** @class Curs
    @brief Representa el tipus Curs
*/
class Curs{
    private:
        /** @brief Vector on s'emmagatzemen les sesions que pertanyen al curs */
        vector <string> ses_del_curs;

        /** @brief Enter on s'emmagatzema el numero d'inscrits */
        int inscrits;

        /** @brief Enter on s'emmagatzema el numero de cops que s'ha acabat el curs */
        int acabaments;

        /** @brief Mapa on s'emmagatzemen tots els problemes pertanyents al curs amb la seva sesio respectiva */
        map <string,string> ses_prob;
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

    /** @brief Incrementa el nombre d'acabaments en 1
    \pre Cert
    \post Incrementa el nombre de cops que s'ha completat el curs en 1
    */    
    void inc_acabaments();

    /** @brief Afegeix al contenidor el problema p i la sesió ses
    \pre Cert
    \post Afegeix al contenidor el parell format per l'identificador de un problema p i l'identificador de una sesió ses
    */ 
    bool insertar_prob_ses(const string &p, const string &ses);

    //Consultors
    /** @brief Escriu el Curs i les seves característiques
    \pre Cert
    \post Escriu les característiques del curs: nombre d'usuaris que l'han completat, nombre d'inscrits, nombre de sesions i els identificadors d'aquestes
    */
    void escriure_curs() const;

    /** @brief Retorna el nombre de sesions del curs
    \pre Cert
    \post Retorna el nombre de sesions que hi ha al curs
    */
    int num_sesions() const;

    /** @brief Retorna el nombre d'inscrits en el curs
    \pre Cert
    \post Retorna el nombre d'inscrits que hi ha al curs
    */
    int num_inscrits() const;

    /** @brief Retorna el nombre d'acabaments del curs
    \pre Cert
    \post Retorna les vegades que s'ha completat el curs
    */
    int num_acabaments() const;

    /** @brief Retorna la sesió del problema donat
    \pre Cert
    \post Retorna la sesió del problema donat i si no existeix retorna "-"
    */
    string curs_sesio_problema(const string &p) const;

    /** @brief Retorna la sesió que està a la posició i
    \pre 0<=i<nombre de sesions
    \post Retorna la sesió que està a la posició i del contenidor
    */
    string curs_sesio_iteratiu(const int &i) const;

};

#endif