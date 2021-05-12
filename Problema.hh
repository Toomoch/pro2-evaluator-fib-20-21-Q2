/** @file Problema.hh
    @brief Especificació de la classe Problema 
*/
#ifndef PROBLEMA_HH
#define PROBLEMA_HH

/// \cond
#include <iostream>
#include <string>
/// \endcond
using namespace std;

/** @class Problema
    @brief Representa el tipus Problema
*/
class Problema {

private:
    int total;
    int exit;
public:

    //Constructors
    /** @brief Constructor predeterminat
    \pre Cert
    \post Crea un problema buit
    */
    Problema();

    //Modificadors
    /** @brief Incrementa el total d'enviaments en 1
    \pre Es fa un nou enviament
    \post Incrementa el total d'enviaments del problema en 1
    */
    void afegeix_env_total();

    /** @brief Incrementa el total d'enviaments exitosos en 1
    \pre Es fa un nou enviament correcte
    \post Incrementa el total d'enviaments exitosos del problema en 1
    */
    void afegeix_env_exit();

    //Consultors
    /** @brief Retorna el número de enviaments totals del problema
    \pre Cert
    \post Retorna el número de enviaments totals del problema
    */
    int env_totals();

    /** @brief Retorna el número de enviaments exitosos del problema
    \pre Cert
    \post Retorna el número de enviaments exitosos del problema
    */
    int env_exit();

    
    //** @brief Escriu el problema 
    //\pre Cert
    //\post Escriu el problema
    //*/
    //void escriure_problema();
    

    
};

#endif