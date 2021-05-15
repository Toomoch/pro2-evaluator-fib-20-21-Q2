#include "Usuari.hh"
Usuari::Usuari()
{
    inscrit = 0;
    env = 0;
}

/*
void Usuari::modificar_curs(const int &nc) {
    
}


bool Usuari::curs_completat()
{
    
}
*/

int Usuari::curs_usuari() 
{
    return inscrit;
}

void Usuari::inscriure_curs(const int &c)
{
    inscrit = c;
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

void Usuari::treure_enviable(const string &p)
{
    map <string,int>::iterator it;
    it = enviables.find(p);
    ++(*it).second;
    
    resolts.insert(*it);
    enviables.erase(p);
    
}

void Usuari::afegir_intentats(const string &p)
{
    intentats.insert(p);
    ++env;
}

void Usuari::afegir_enviables(const string &p)
{
    enviables.insert(make_pair(p,0));
}