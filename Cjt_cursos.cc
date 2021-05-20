/** @file Cjt_cursos.cc
    @brief Implementació de la clase Cjt_cursos
*/
#include "Cjt_cursos.hh"
Cjt_cursos::Cjt_cursos()
{

}

void Cjt_cursos::llegeix_cjt_cursos(const int &ncurs, Cjt_sesions &q)
{
    
    for (int i = 0; i < ncurs; i++)
    {
        Curs curs;
        int nses;
        cin>>nses;
        curs.llegir_curs(nses);                  
        q.omplir_sesions_curs(curs, false);    //no mirem interseccio
        cursos.push_back(curs);
    }
    
}

void Cjt_cursos::afegir_curs_al_cjt(const Curs &c)
{
    cursos.push_back(c);
}

int Cjt_cursos::num_cjt_cursos() const
{
    return cursos.size();
}

bool Cjt_cursos::existeix_curs(const int &c) const
{
    if (c-1 < cursos.size()) return true;
    else return false;
}

void Cjt_cursos::inc_inscrits_cjt(const int &c)
{
    cursos[c-1].inc_inscrits();
}

void Cjt_cursos::dec_inscrits_cjt(const int &c)
{
    cursos[c-1].dec_inscrits();
}

int Cjt_cursos::num_inscrits_cjt(const int &c) const
{
    return cursos[c-1].num_inscrits();
}

void Cjt_cursos::iguala_curs(const int &c, Curs &curs) const
{

    curs = cursos[c-1];
}

void Cjt_cursos::escriu_cjt_cursos()  const
{
    for (int i = 0; i < cursos.size(); ++i)
    {
        cout<<i+1<<" ";
        cursos[i].escriure_curs();
    }
    
}

void Cjt_cursos::escriu_curs(const int &c)  const
{
    cout<<c<<" ";
    cursos[c-1].escriure_curs();
    
    
}

string Cjt_cursos::cjt_curs_sesio_problema(const int &c, const string &p) const
{
    return cursos[c-1].curs_sesio_problema(p);
}

void Cjt_cursos::inc_acabaments_cjt(const int &c)
{
    cursos[c-1].inc_acabaments();
}