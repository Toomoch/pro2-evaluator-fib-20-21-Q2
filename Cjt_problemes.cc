/** @file Cjt_problemes.cc
    @brief Implementació de la clase Cjt_problemes
*/
#include "Cjt_problemes.hh"
Cjt_problemes::Cjt_problemes(){}

void Cjt_problemes::afegeix_Cjt_problemes(const string &prob) {

    Problema p;
    int oldsize = problemes.size();
    problemes.insert(pair<string,Problema> (prob,p));
    int newsize = problemes.size();
    if (oldsize != newsize) cout<<newsize<<endl;
    else cout<<"error: el problema ya existe"<<endl;
}

void Cjt_problemes::llegir_Cjt_problemes(const int &np)
{
    string s;
    for (int i = 0; i < np; i++)
    {
        Problema p;
        cin>>s;
        problemes.insert(pair <string, Problema> (s,p));
    }
    
}

bool Cjt_problemes::existeix_problema(const string &p) const
{
    if (problemes.find(p) == problemes.end()) return false;
    else return true; 
}

void Cjt_problemes::escriure_cjt_problemes() const
{
    vector<pair<string, Problema>> ordenat;
    for (map <string, Problema>::const_iterator it = problemes.begin(); it != problemes.end(); ++it)
    {
        ordenat.push_back(*it);
    }
    
    sort(ordenat.begin(), ordenat.end(), cmp);
    for (int i = 0; i < ordenat.size(); ++i)
    {
        int t = ordenat[i].second.env_totals();
        int e = ordenat[i].second.env_exit();
        
        cout<<ordenat[i].first<<"("<<t<<","<<e<<","<<double((t+1))/(e+1)<<")"<<endl;
    }
    
}

void Cjt_problemes::escriure_problema(const string &p)
{
    int t = problemes[p].env_totals();
    int e = problemes[p].env_exit();
        
    cout<<p<<"("<<t<<","<<e<<","<<double((t+1))/(e+1)<<")"<<endl;
    
}

bool Cjt_problemes::cmp(const pair<string,Problema>& a, const pair<string,Problema>& b) {

    int t = a.second.env_totals();
    int e = a.second.env_exit();
    double a_rat = (t+1.0)/(e+1.0);

    t = b.second.env_totals();
    e = b.second.env_exit();
    double b_rat = (t+1.0)/(e+1.0);

    if(a_rat < b_rat) return true;

    else if(b_rat < a_rat) return false;
    
    else 
    {
        if(a.first < b.first) return true;
        else return false;
    }
}

void Cjt_problemes::inc_env_total_cjt(const string &p)
{
    problemes[p].inc_env_total();
}

void Cjt_problemes::inc_env_exit_cjt(const string &p)
{
    problemes[p].inc_env_exit();
}
