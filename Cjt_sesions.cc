/** @file Cjt_sesions.cc
    @brief Implementació de la clase Cjt_sesions
*/
#include "Cjt_sesions.hh"
Cjt_sesions::Cjt_sesions(){

}
void Cjt_sesions::llegir_cjt_sesions(const int &nsesio) {
    string identif;
    
    for (int i = 0; i < nsesio; i++)
    {
        Sesio sesi;
        cin>>identif;
        sesi.llegir_ses();
        sesions.insert(pair <string, Sesio> (identif, sesi));
    }
    
}


void Cjt_sesions::afegir_sesio(const string &identif)
{
    Sesio sesi;
    sesi.llegir_ses();
    sesions.insert(pair <string, Sesio> (identif, sesi));
    cout<<sesions.size()<<endl;
}


void Cjt_sesions::escriure_cjt_sesio() const
{
    for (map<string, Sesio>::const_iterator it = sesions.begin(); it != sesions.end(); ++it)
    {
        cout<<it->first<<" "<<it->second.num_problemes()<<" ";
        it->second.escriu_ses();
    }
    
}

void Cjt_sesions::escriure_sesio(const string &s) const
{
    map<string, Sesio>::const_iterator it = sesions.find(s);
    cout<<s<<" "<<it->second.num_problemes()<<" ";
    it->second.escriu_ses();
    
    
}

bool Cjt_sesions::existeix_sesio(const string &s) const
{
    map<string, Sesio>::const_iterator it = sesions.find(s);
    if (it == sesions.end()) return false;
    else return true;
}

bool Cjt_sesions::omplir_sesions_curs(Curs &c, const bool mirar_interseccio)
{
    int m = c.num_sesions();
    bool interseccio = true;
    int i = 0;
    if (mirar_interseccio)
    {
        while (i < m and interseccio)
        {
            string ses = c.curs_sesio_iteratiu(i);
            if (sesions[ses].pre_inserta_mapa_curs(ses, c)) interseccio = false;
            ++i;
        }
        
    }
    else 
    {
         while (i < m)
        {
            string ses = c.curs_sesio_iteratiu(i);
            sesions[ses].pre_inserta_mapa_curs(ses, c);
            ++i;
        }
    }
    return interseccio;
}

void Cjt_sesions::inscriu_cjt_sesio(const string &s, Usuari &u)
{
    sesions[s].arrel(u);
}

void Cjt_sesions::afegeix_fulles_cjt(const string &p, const string &s, Usuari &u)
{
    sesions[s].afegeix_fulles(p, u);
}