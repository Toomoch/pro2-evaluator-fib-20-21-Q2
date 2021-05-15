#include "Cjt_usuaris.hh"
Cjt_usuaris::Cjt_usuaris()
{

}

void Cjt_usuaris::llegir_usuaris(const int &nu)
{
    
    string s;
    for (int i = 0; i < nu; i++)
    {
        Usuari u;
        cin>>s;
        mapa.insert(pair <string, Usuari> (s,u));
    }
    
}

void Cjt_usuaris::afegir_usuari(const string &u)
{
    Usuari au;
    int oldsize = mapa.size();
    mapa.insert(pair<string,Usuari> (u,au));
    int newsize = mapa.size();
    if (oldsize != newsize)
    {
        cout<<newsize<<endl;
    }
    else 
    {
        cout<<"error: el usuario ya existe"<<endl;
    }
}

void Cjt_usuaris::eliminar_usuari(const string &u)
{
    mapa.erase(u);
    cout<<mapa.size()<<endl;
}

int Cjt_usuaris::curs_inscrit(const string &u)
{
    return mapa[u].curs_usuari();
}

bool Cjt_usuaris::existeix_usuari(const string &u) {
    map<string, Usuari>::iterator it;
    it = mapa.find(u);
    if (it == mapa.end()) return false;
    else return true;
}

void Cjt_usuaris::escriu_resolts_cjt(const string &u)
{
    mapa[u].escriu_resolts();
}

void Cjt_usuaris::escriu_enviables_cjt(const string &u)
{
    mapa[u].escriu_enviables();
}

void Cjt_usuaris::llistar_usuaris()
{
    for (map <string, Usuari>::iterator it = mapa.begin(); it != mapa.end(); ++it)
    {
        cout<<(*it).first<<"("<<(*it).second.total()<<","<<(*it).second.intent()<<","<<(*it).second.resolt()<<","<<(*it).second.curs_usuari()<<")"<<endl;
    }
    
}

void Cjt_usuaris::llistar_usuari(const string &u)
{
    
    cout<<u<<"("<<mapa[u].total()<<","<<mapa[u].intent()<<","<<mapa[u].resolt()<<","<<mapa[u].curs_usuari()<<")"<<endl;
    
}

void Cjt_usuaris::cjt_inscriure_curs(const int &c, const string &u, Cjt_sesions &q, Cjt_cursos &C)
{
    map<std::string, Usuari>::iterator it = mapa.find(u);
    C.inscriu_cjt_cursos(c, (*it).second, q);
    mapa[u].inscriure_curs(c);
}
/*
void Cjt_usuaris::enviament(const string &u, const string &p, const int &r) 
{
    map <string,Usuari>::iterator it = mapa.find(u);
    
    if (r==1) 
    {
        (*it).second.treure_enviable(p);
        int curs = (*it).second.curs_usuari();

    }
    else 
    {
        
    }
    (*it).second.afegir_intentats(p);
}
*/