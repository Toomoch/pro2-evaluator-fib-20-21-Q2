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

Cjt_ids Cjt_sesions::problemes_cjt_sesio(string u)
{
    return mapa[u].problemes_sesio();
}


bool Cjt_sesions::sesio_problema_existeix(const string &p, const string &s)
{
    //map<string,Sesio>::iterator it = mapa.find
    
    
    //while (it != mapa.begin())
    
    Cjt_ids probl_sesio;
        
    if (mapa[s].problemes_sesio().existeix(p)) return true;
    
    return false;
}

void Cjt_sesions::inscriu_cjt_sesio(const string &s, Usuari &u)
{
    u.afegir_enviables(mapa[s].arrel());
}