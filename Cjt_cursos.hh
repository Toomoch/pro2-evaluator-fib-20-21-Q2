/** @file Cjt_cursos.hh
    @brief Especificació de la classe Cjt_cursos
*/
#ifndef CJT_CURSOS_HH
#define CJT_CURSOS_HH

/// \cond
#include <iostream>
#include <vector>
#include <list>
#include <string>
/// \endcond
#include "Curs.hh"
using namespace std;

/** @class Cjt_cursos
    @brief Representa el tipus Cjt_cursos
*/
class Cjt_cursos{
    private:
        vector<Curs> vec;
    public:

    //Constructors
    /** @brief Constructor predeterminat
    \pre Cert
    \post Crea un Conjunt de cursos buit
    */
    Cjt_cursos();

    //Modificadors
    /** @brief Modificador d'un conjunt de cursos
    \pre Nombre de cursos > 0
    \post Llegeix un conjunt de cursos
    */
    void llegeix_cjt_cursos(const int &ncurs);

    /** @brief Afegir un curs al conjunt de cursos
    \pre Nou curs no existent al conjunt
    \post Afegeix el curs donat al conjunt de cursos
    */
    void afegir_curs_al_cjt(Cjt_sesions &q);

    /** @brief Incrementa el nombre d'inscrits del curs donat en 1
    \pre Cert
    \post Incrementa el nombre d'inscrits del curs donat en 1
    */    
    void inc_inscrits_cjt(const int &c);

    /** @brief Decrementa el nombre d'inscrits del curs donat en 1
    \pre Cert
    \post Decrementa el nombre d'inscrits del curs donat en 1
    */    
    void dec_inscrits_cjt(const int &c);

    //Consultors
    /** @brief Escriu els cursos pertanyents al conjunt
    \pre Cert
    \post Escriu els cursos pertanyents al conjunt
    */
    void escriu_cjt_cursos();

    /** @brief Escriu el cursos donat
    \pre Cert
    \post Escriu el cursos donat
    */
    void escriu_curs(const int &u);

    /** @brief Retorna el numero de cursos
    \pre Cert
    \post Retorna el numero de cursos que hi ha al conjunt
    */
    int num_cjt_cursos();

    /** @brief Indica si el curs està dins del conjunt
    \pre Cert
    \post Indica si el curs està dins del conjunt
    */
    bool existeix_curs(const int &c);
    
    /** @brief Retorna el nombre d'inscrits en el curs donat
    \pre Cert
    \post Retorna el nombre d'inscrits en el curs donat
    */
    int num_inscrits_cjt(const int &c);

    void cjt_cursos_sesio_problema_existeix(const int &c, const string &p, Cjt_sesions &q);

    void inscriu_cjt_cursos(const int &c, Usuari &u, Cjt_sesions &q);

};
#endif