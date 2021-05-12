#include "Usuari.hh"
Usuari::Usuari()
{
    inscrit = 0;
    env = 0;
}

/*
void Usuari::modificar_curs(int nc) {
    
}


bool Usuari::curs_completat()
{
    
}
*/

int Usuari::curs_usuari() 
{
    return inscrit;
}

void Usuari::inscriure_curs(const list <string> &p, int c)
{
    inscrit = c;
    for ( list <string>::const_iterator it = p.begin(); it != p.end(); ++it)
    {
        enviables.insert(make_pair((*it),0));
    }
    
    
}

void Usuari::escriu_resolts()
{
    for (map <string,int>::iterator it = resolts.begin(); it != resolts.end(); ++it)
    {
        cout<<(*it).first<<"("<<(*it).second<<")"<<endl;
    }
    
}

void Usuari::escriu_enviables()
{
    for (map <string,int>::iterator it = enviables.begin(); it != enviables.end(); ++it)
    {
        cout<<(*it).first<<"("<<(*it).second<<")"<<endl;
    }
    
}

int Usuari::resolt()
{
    return resolts.size();
}

int Usuari::total()
{
    return env;
}

int Usuari::intent()
{
    return intentats.size();
}

void Usuari::treure_enviable(string p)
{
    map <string,int>::iterator it;
    it = enviables.find(p);
    ++(*it).second;
    ++env;
    resolts.insert(*it);
    enviables.erase(p);
    
}

void Usuari::afegir_intentats(string p)
{
    intentats.insert(p);
}