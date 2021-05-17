/** @file Problema.cc
    @brief Implementació de la clase Problema
*/
#include "Problema.hh"
Problema::Problema(){
    total=0;
    exit=0;
}

int Problema::env_exit() const
{
    return exit;
}

int Problema::env_totals() const
{
    return total;
}

void Problema::inc_env_total()
{
    ++total;
}

void Problema::inc_env_exit()
{
    ++exit;
}
