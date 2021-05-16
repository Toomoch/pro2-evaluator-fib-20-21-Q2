#include "Curs.hh"
Curs::Curs()
{
    inscrits = 0;
    acabaments = 0;
}

void Curs::llegir_curs(const int &nses)
{
    
    for (int i = 0; i < nses; i++)
    {
        string sesi;
        cin>>sesi;
        ses_del_curs.push_back(sesi);
    }
    
}



int Curs::num_sesions()
{
    return ses_del_curs.size();
}

void Curs::escriure_curs()
{
    
    cout<<num_acabaments()<<" "<<num_inscrits()<<" "<<ses_del_curs.size()<<" "<<"(";

    int i = 0;
    cout<<ses_del_curs[i];
    ++i;
    while (i < ses_del_curs.size())
    {
        cout<<" "<<ses_del_curs[i];
        ++i;
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


/*
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
*/
/*
string Curs::curs_sesio_problema_existeix(const string &p, Cjt_sesions &q)
{
    
    for (int i = 0; i < ses_del_curs.size(); ++i)
    {
        string temp = ses_del_curs[i];
        if (q.sesio_problema_existeix(p, temp)) return (temp);
    }
    return "-";
}
*/

bool Curs::insertar_prob_ses(const string &p, const string &ses)
{
    pair <map<string,string>::iterator,bool> parell = ses_prob.insert(make_pair(p, ses));
    return not parell.second;
}

string Curs::curs_sesio_problema(const string &p)
{
    map <string,string>::iterator it = ses_prob.find(p);
    if (it != ses_prob.end()) return it->second;
    else return "-";
}

string Curs::curs_sesio_iteratiu(const int &i)
{
    return ses_del_curs[i];
}
/*
void Curs::inscriu_curs(Usuari &u, Cjt_sesions &q)
{
    for (int i = 0; i < ses_del_curs.size(); ++i)
    {
        q.inscriu_cjt_sesio(ses_del_curs[i], u);
    }
    ++inscrits;
    
}
*/
void Curs::inc_acabaments()
{
    ++acabaments;
}