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
        cout<<(*it).first<<"("<<(*it).second.total()<<","<<(*it).second.resolt()<<","<<(*it).second.intent()<<","<<(*it).second.curs_usuari()<<")"<<endl;
    }

}

void Cjt_usuaris::llistar_usuari(const string &u)
{
    
    cout<<u<<"("<<mapa[u].total()<<","<<mapa[u].resolt()<<","<<mapa[u].intent()<<","<<mapa[u].curs_usuari()<<")"<<endl;
    
}

void Cjt_usuaris::cjt_inscriure_curs(const int &c, const string &u, Cjt_sesions &q, Cjt_cursos &C)
{
    map<std::string, Usuari>::iterator it = mapa.find(u);
    C.inscriu_cjt_cursos(c, (*it).second, q);
    mapa[u].inscriure_curs(c);
}

void Cjt_usuaris::enviament(string &user, string &prob, int &r, Cjt_cursos &c, Cjt_problemes& p, Cjt_sesions& q) 
{
    
    map <string,Usuari>::iterator it = mapa.find(user);
    it->second.afegir_intentats(prob);
    
    if (r==1) 
    {   
        int curs = it->second.curs_usuari();
        //cout<<"abans"<<endl;
        
        p.inc_env_exit_cjt(prob);
        p.inc_env_total_cjt(prob);
        //it->second.inc_enviable(prob);
        it->second.afegir_resolt(prob);
        //escriu_resolts_cjt(user);
        
        //escriu_enviables_cjt(user);
        
        
        string ses = c.cjt_cursos_sesio_problema_existeix(curs, prob, q);
        
        
        
        q.afegeix_fulles_cjt(prob, ses, it->second);
        
        
        
        if (it->second.enviable() == 0)
        {
            it->second.acabar_curs();
            c.cjt_inc_acabaments(curs);
            c.dec_inscrits_cjt(curs);
        }
        
        
        
    }
    else 
    {
        p.inc_env_total_cjt(prob);
        
        
    }
    
}
