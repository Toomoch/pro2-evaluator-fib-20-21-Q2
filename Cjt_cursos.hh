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
#include "Cjt_sesions.hh"
using namespace std;

/** @class Cjt_cursos
    @brief Representa el tipus Cjt_cursos
*/
class Cjt_cursos{
    private:
        /** @brief Vector on s'emmagatzemen els cursos pertanyents al conjunt */
        vector<Curs> cursos;
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
    void llegeix_cjt_cursos(const int &ncurs, Cjt_sesions &q);

    /** @brief Afegir un curs al conjunt de cursos
    \pre Nou curs no existent al conjunt
    \post Afegeix el curs donat al conjunt de cursos
    */
    void afegir_curs_al_cjt(const Curs &c);

    /** @brief Incrementa el nombre d'inscrits del curs donat en 1
    \pre Curs c existent al conjunt
    \post Incrementa el nombre d'inscrits del curs donat en 1
    */    
    void inc_inscrits_cjt(const int &c);

    /** @brief Decrementa el nombre d'inscrits del curs donat en 1
    \pre Curs c existent al conjunt
    \post Decrementa el nombre d'inscrits del curs donat en 1
    */    
    void dec_inscrits_cjt(const int &c);

    /** @brief Incrementa el nombre d'acabaments del curs donat en 1
    \pre Curs c existent al conjunt
    \post Incrementa el nombre de cops que s'ha completat el curs donat en 1
    */    
    void inc_acabaments_cjt(const int &c);

    //Consultors
    /** @brief Escriu els cursos pertanyents al conjunt
    \pre Cert
    \post Escriu els cursos pertanyents al conjunt
    */
    void escriu_cjt_cursos() const;

    /** @brief Iguala el curs donat amb el que té l'identificador c
    \pre Curs c existent al conjunt
    \post Iguala el Curs "curs" amb el del conjunt que té l'identificador c
    */
    void iguala_curs(const int &c, Curs &curs) const;

    /** @brief Escriu el curs donat
    \pre Curs c existent al conjunt
    \post Escriu el curs c donat del conjunt
    */
    void escriu_curs(const int &c) const;

    /** @brief Retorna el numero de cursos
    \pre Cert
    \post Retorna el numero de cursos que hi ha al conjunt
    */
    int num_cjt_cursos() const;

    /** @brief Indica si el curs està dins del conjunt
    \pre Cert
    \post Retorna true si el curs està dins del conjunt, si no retorna false
    */
    bool existeix_curs(const int &c) const;
    
    /** @brief Retorna el nombre d'inscrits en el curs donat
    \pre Curs c existent al conjunt
    \post Retorna el nombre d'inscrits en el curs donat
    */
    int num_inscrits_cjt(const int &c) const;

    /** @brief Retorna la sesió del problema donat en el curs c
    \pre Curs c existent al conjunt
    \post Retorna la sesió del problema donat en el curs c i si no existeix retorna "-"
    */
    string cjt_curs_sesio_problema(const int &c, const string &p) const;    
};
#endif