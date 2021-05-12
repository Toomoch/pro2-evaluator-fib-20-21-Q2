#include "Curs.hh"
Curs::Curs()
{
    inscrits = 0;
    acabaments = 0;
}

void Curs::llegir_curs(int nses)
{
    string sesi;
    for (int i = 0; i < nses; i++)
    {
        cin>>sesi;
        ses_del_curs.push_back(sesi);
    }
    
}

list <string> Curs::llista_ses() 
{
    return ses_del_curs;
}

void Curs::inc_inscrits()
{
    ++inscrits;
}

void Curs::dec_inscrits()
{
    --inscrits;
}

int Curs::num_inscrits(){
    return inscrits;
}

int Curs::num_acabaments()
{
    return acabaments;
}