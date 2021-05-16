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

int Usuari::enviable()
{
    return enviables.size();
}


int Usuari::total()
{
    return env;
}

int Usuari::intent()
{
    return intentats.size();
}

void Usuari::afegir_resolt(const string &p)
{
    //map <string,int>::iterator it;
    
    //it = enviables.find(p);
    //cout<<"despres"<<endl;
    //pair <string,int> parell = (*it);
    
     //sumem un intent
    
    resolts.insert(make_pair(p, enviables[p])); //insertem a resolts
    
    enviables.erase(p); //esborrem denviables
    //escriu_enviables();
    //cout<<n<<" esborrat "<<p<<endl;
    //escriu_enviables();
    //cout<<"---"<<endl;
    
}

void Usuari::afegir_intentats(const string &p)
{
    ++enviables[p];
    intentats.insert(p);
    ++env;
}

void Usuari::afegir_enviables(const string &p)
{
    //cout<<p<<endl;
    enviables.insert(make_pair(p,0));
}

void Usuari::inc_enviable(const string &p)
{
    ++enviables[p];
}

bool Usuari::problema_resolt(const string &p)
{
    if (resolts.count(p) == 1) return true;
    else return false;
}

void Usuari::acabar_curs()
{
    inscrit = 0;
}