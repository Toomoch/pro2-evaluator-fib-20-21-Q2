/** @file Curs.cc
    @brief Implementació de la clase Curs
*/
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

void Curs::inc_inscrits()
{
    ++inscrits;
}

void Curs::dec_inscrits()
{
    --inscrits;
}

void Curs::inc_acabaments()
{
    ++acabaments;
}

bool Curs::insertar_prob_ses(const string &p, const string &ses)
{
    pair <map<string,string>::iterator,bool> parell = ses_prob.insert(make_pair(p, ses));
    return not parell.second;
}

void Curs::escriure_curs() const
{
    cout<<num_inscrits()<<" "<<ses_del_curs.size()<<" "<<"(";

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

int Curs::num_sesions() const
{
    return ses_del_curs.size();
}

int Curs::num_inscrits() const
{
    return inscrits;
}

int Curs::num_acabaments() const
{
    return acabaments;
}

string Curs::curs_sesio_problema(const string &p) const
{
    map <string,string>::const_iterator it = ses_prob.find(p);
    if (it != ses_prob.end()) return it->second;
    else return "-";
}

string Curs::curs_sesio_iteratiu(const int &i) const
{
    return ses_del_curs[i];
}

