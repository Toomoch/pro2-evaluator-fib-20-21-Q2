#include "Cjt_cursos.hh"
Cjt_cursos::Cjt_cursos()
{

}

void Cjt_cursos::llegeix_cjt_cursos(int ncurs)
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

bool Cjt_cursos::existeix_curs(int c)
{
    if (c-1 < vec.size()) return true;
    else return false;
}

list <string> Cjt_cursos::llista_ses_cjt(int c)
{
    list <string> l = vec[c-1].llista_ses();
    return l;
}

void Cjt_cursos::inc_inscrits_cjt(int c)
{
    vec[c-1].inc_inscrits();
}

void Cjt_cursos::dec_inscrits_cjt(int c)
{
    vec[c-1].dec_inscrits();
}

int Cjt_cursos::num_inscrits_cjt(int c)
{
    return vec[c-1].num_inscrits();
}

/*
void Cjt_cursos::ses_prob_curs(int c, string p) 
{
    list <string> l = vec[c-1].llista_ses();
    
    
}
*/

void Cjt_cursos::escriu_cjt_cursos() 
{
    for (int i = 0; i < vec.size(); ++i)
    {
        
        list <string> l = vec[i].llista_ses();
        cout<<(i+1)<<" "<<vec[i].num_acabaments()<<" "<<vec[i].num_inscrits()<<" "<<l.size()<<" "<<"(";

        list <string>::iterator preit = (l.begin());
        cout<<(*preit);
        for (list <string>::iterator it = (++preit); it != l.end(); ++it)
        {
            cout<<" "<<(*it);
        }

        cout<<")"<<endl;
    }
    
}

void Cjt_cursos::escriu_curs(int c) 
{
    list <string> l = vec[c-1].llista_ses();
    cout<<c<<" "<<vec[c-1].num_acabaments()<<" "<<vec[c-1].num_inscrits()<<" "<<l.size()<<" "<<"(";

    list <string>::iterator preit = l.begin();
    cout<<(*preit);
    for (list <string>::iterator it = (++l.begin()); it != l.end(); ++it)
    {
        cout<<" "<<(*it);
    }

    cout<<")"<<endl;
    
    
}

