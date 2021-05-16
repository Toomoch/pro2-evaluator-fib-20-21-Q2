#include "Cjt_cursos.hh"
Cjt_cursos::Cjt_cursos()
{

}

void Cjt_cursos::llegeix_cjt_cursos(const int &ncurs)
{
    
    
    for (int i = 0; i < ncurs; i++)
    {
        Curs cur;
        int nses;
        cin>>nses;
        cur.llegir_curs(nses);
        vec.push_back(cur);
    }
    
}

void Cjt_cursos::afegir_curs_al_cjt(Cjt_sesions &q)
{
    
    Curs c;
    int nses;
    cin>>nses;
    c.llegir_curs(nses);
    if (c.interseccio(q)) cout<<"error: curso mal formado"<<endl;
    else 
    {
        vec.push_back(c);
        cout<<vec.size()<<endl;
    }
    

}

int Cjt_cursos::num_cjt_cursos()
{
    return vec.size();
}

bool Cjt_cursos::existeix_curs(const int &c)
{
    if (c-1 < vec.size()) return true;
    else return false;
}

void Cjt_cursos::inc_inscrits_cjt(const int &c)
{
    vec[c-1].inc_inscrits();
}

void Cjt_cursos::dec_inscrits_cjt(const int &c)
{
    vec[c-1].dec_inscrits();
}

int Cjt_cursos::num_inscrits_cjt(const int &c)
{
    return vec[c-1].num_inscrits();
}

void Cjt_cursos::escriu_cjt_cursos() 
{
    for (int i = 0; i < vec.size(); ++i)
    {
        cout<<i+1<<" ";
        vec[i].escriure_curs();
    }
    
}

void Cjt_cursos::escriu_curs(const int &c) 
{
    cout<<c<<" ";
    vec[c-1].escriure_curs();
    
    
}

string Cjt_cursos::cjt_cursos_sesio_problema_existeix(const int &c, const string &p, Cjt_sesions &q)
{
    return vec[c-1].curs_sesio_problema_existeix(p, q);

}

void Cjt_cursos::inscriu_cjt_cursos(const int &c, Usuari &u, Cjt_sesions &q)
{
    vec[c-1].inscriu_curs(u, q);
}

void Cjt_cursos::cjt_inc_acabaments(const int &c)
{
    vec[c-1].inc_acabaments();
}