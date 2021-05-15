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
