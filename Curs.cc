#include "Curs.hh"
Curs::Curs()
{
    inscrits = 0;
    acabaments = 0;
}

void Curs::llegir_curs(const int &nses)
{
    string sesi;
    for (int i = 0; i < nses; i++)
    {
        cin>>sesi;
        ses_del_curs.push_back(sesi);
    }
    
}


void Curs::escriure_curs()
{
    
    cout<<num_acabaments()<<" "<<num_inscrits()<<" "<<ses_del_curs.size()<<" "<<"(";

    list <string>::iterator it = ses_del_curs.begin();
    cout<<(*it);
    ++it;
    while (it != ses_del_curs.end())
    {
        cout<<" "<<(*it);
        ++it;
    }

    cout<<")"<<endl;
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

bool Curs::interseccio(Cjt_sesions &q)
{
    Cjt_ids base;
    string nombase;

    list<string>::iterator it = ses_del_curs.begin();
    base = q.problemes_cjt_sesio((*it));
    ++it;

    bool found = false;

    while (not found and it!=ses_del_curs.end())    //recorre les sesions
    {
        
        Cjt_ids temp = q.problemes_cjt_sesio((*it));
        set<string>::iterator it2 = temp.principi();

        while (not found and it2 != temp.final())   //recorre els problemes de cada sesio
        {
            found = not base.insertar((*it2));
            ++it2;
        }
        ++it;
    }
    return found;
}

string Curs::curs_sesio_problema_existeix(const string &p, Cjt_sesions &q)
{
    
    for (list<string>::iterator it = ses_del_curs.begin(); it != ses_del_curs.end(); ++it)
    {
        if (q.sesio_problema_existeix(p, (*it))) return (*it);
    }
    return "-";
}


void Curs::inscriu_curs(Usuari &u, Cjt_sesions &q)
{
    for (list<string>::iterator it = ses_del_curs.begin(); it != ses_del_curs.end(); ++it)
    {
        q.inscriu_cjt_sesio((*it), u);
    }
    ++inscrits;
    
}