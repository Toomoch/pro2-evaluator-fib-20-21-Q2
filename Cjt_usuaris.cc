/** @file Cjt_usuaris.cc
    @brief Implementació de la clase Cjt_usuaris
*/
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
        cout<<it->first<<"("<<it->second.total()<<","<<it->second.resolt()<<","<<it->second.curs_usuari()<<")"<<endl;
    }

}

void Cjt_usuaris::llistar_usuari(const string &u)
{
    
    cout<<u<<"("<<mapa[u].total()<<","<<mapa[u].resolt()<<","<<mapa[u].curs_usuari()<<")"<<endl;
    
}

void Cjt_usuaris::cjt_inscriure_curs(const int &c, const string &u, Cjt_sesions &q, Cjt_cursos &C)
{
    Curs curs;
    C.iguala_curs(c, curs);
    int m = curs.num_sesions();
    map<std::string, Usuari>::iterator it = mapa.find(u);
    for (int i = 0; i < m; i++)
    {
        q.inscriu_cjt_sesio(curs.curs_sesio_iteratiu(i), it->second);
    }
    
    if (it->second.enviable() != 0)
    {

        
        it->second.inscriure_curs(c);
        
        C.inc_inscrits_cjt(c);

    }
    
}

void Cjt_usuaris::enviament(string &user, string &prob, int &r, Cjt_cursos &c, Cjt_problemes& p, Cjt_sesions& q) 
{
    
    map <string,Usuari>::iterator it = mapa.find(user);
    it->second.afegir_intentats(prob);
    
    if (r==1) 
    {   
        
        if (not it->second.esta_resolt_prob(prob))
        {
            it->second.inc_env();
            int curs = it->second.curs_usuari();
            p.inc_env_total_cjt(prob);
            p.inc_env_exit_cjt(prob);
            
            it->second.afegir_resolt(prob);        
        
            string ses = c.cjt_curs_sesio_problema(curs, prob);
        
            q.troba_fulles_afegeix_cjt(prob, ses, it->second);
        }
        else 
        {
            //p.inc_env_total_cjt(prob);
            
        }
        
    }
    else 
    {
        if (not it->second.esta_resolt_prob(prob)) 
        {
            p.inc_env_total_cjt(prob);
            it->second.inc_env();
        }
        
    }
    
    
    
}


void Cjt_usuaris::acabar_curs_cjt(const string &user)
{
    mapa[user].acabar_curs();
}
