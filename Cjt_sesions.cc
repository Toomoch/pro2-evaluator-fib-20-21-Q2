#include "Cjt_sesions.hh"
Cjt_sesions::Cjt_sesions(){

}
void Cjt_sesions::llegir_cjt_sesions(int nsesio) {
    string identif;
    
    for (int i = 0; i < nsesio; i++)
    {
        Sesio sesi;
        cin>>identif;
        sesi.llegir_ses();
        mapa.insert(pair <string, Sesio> (identif, sesi));
    }
    
}


void Cjt_sesions::afegir_sesio(string identif)
{
    Sesio sesi;
    sesi.llegir_ses();
    mapa.insert(pair <string, Sesio> (identif, sesi));
    cout<<mapa.size()<<endl;
}

list <string> Cjt_sesions::arrel_cjt(const list <string> &s)
{
    list <string>::const_iterator it;
    list <string> l;
    for (it = s.begin(); it != s.end(); ++it)
    {
        l.push_back(mapa[(*it)].arrel());
    }
    return l;
    
}

string Cjt_sesions::ses_prob_find_cjt(const list <string> &l, string p)
{
    for (list <string>::const_iterator it = l.begin(); it != l.end(); ++it)
    {
        if (mapa[(*it)].ses_prob_find(p)) return (*it);
    }
    return "-";
}

void Cjt_sesions::escriure_cjt_sesio()
{
    for (map<string, Sesio>::iterator it = mapa.begin(); it != mapa.end(); ++it)
    {
        cout<<(*it).first<<" "<<(*it).second.num_problemes()<<" ";
        (*it).second.escriu_ses();
    }
    
}

void Cjt_sesions::escriure_sesio(string s)
{
    
        cout<<s<<" "<<mapa[s].num_problemes()<<" ";
        mapa[s].escriu_ses();
    
    
}

bool Cjt_sesions::existeix_sesio(string u) {
    map<string, Sesio>::iterator it;
    it = mapa.find(u);
    if (it == mapa.end()) return false;
    else return true;
}