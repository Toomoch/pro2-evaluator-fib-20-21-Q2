#include "Cjt_problemes.hh"
Cjt_problemes::Cjt_problemes(){}

void Cjt_problemes::afegeix_Cjt_problemes(const string &prob) {

    Problema p;
    int oldsize = mapa.size();
    //pair< map<string, Problema>::iterator,bool> valor;
    //valor = mapa.insert(pair<string,Problema> (prob,p));
    mapa.insert(pair<string,Problema> (prob,p));
    int newsize = mapa.size();
    if (oldsize!=newsize) cout<<newsize<<endl;
    else cout<<"error: el problema ya existe"<<endl;
}

void Cjt_problemes::llegir_Cjt_problemes(const int &np)
{
    
    string s;
    for (int i = 0; i < np; i++)
    {
        Problema p;
        cin>>s;
        mapa.insert(pair <string, Problema> (s,p));
    }
    
}

bool Cjt_problemes::existeix_problema(const string &p)
{
    if (mapa.find(p) == mapa.end()) return false;
    else return true; 
}

void Cjt_problemes::escriure_cjt_problemes()
{
    vector<pair<string, Problema>> ordenat;
    for (map <string, Problema>::iterator it = mapa.begin(); it != mapa.end(); ++it)
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
    
        int t = mapa[p].env_totals();
        int e = mapa[p].env_exit();
        
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