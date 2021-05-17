/** @mainpage
	En el mòdul program.cc es troba el programa principal de la plataforma Evaluator, una col·lecció de problemes programació.
*/

/** @file program.cc
    @brief Programa principal
    
    <em>Evaluator d'Usuaris</em>.
*/
/// \cond
#include <iostream>
/// \endcond
#include "Cjt_problemes.hh"
#include "Cjt_sesions.hh"
#include "Cjt_usuaris.hh"
#include "Cjt_cursos.hh"
using namespace std;


int main () 
{
    int nprob;
    cin>>nprob;
    Cjt_problemes p;
    p.llegir_Cjt_problemes(nprob);

    int nsesio;
    cin>>nsesio;
    Cjt_sesions q;
    q.llegir_cjt_sesions(nsesio);

    int ncurs;
    cin>>ncurs;
    Cjt_cursos c;
    c.llegeix_cjt_cursos(ncurs, q);
    
    int nuser;
    cin>>nuser;
    Cjt_usuaris u;
    u.llegir_usuaris(nuser);
    
    string comando;
    cin>>comando;
    while (comando!="fin")
    {
        
        if (comando == "nuevo_problema" or comando == "np")
        {
            
            string prob;
            cin>>prob;
            cout<<"#"<<comando;
            cout<<" "<<prob<<endl;
            p.afegeix_Cjt_problemes(prob);
        }

        else if (comando == "nueva_sesion" or comando == "ns")
        {
            
            string ses;
            cin>>ses;
            cout<<"#"<<comando;
            cout<<" "<<ses<<endl;
            if (not q.existeix_sesio(ses)) q.afegir_sesio(ses);
            else cout<<"error: la sesion ya existe"<<endl;
            
        }
        
        else if (comando == "nuevo_curso" or comando == "nc")
        {
            cout<<"#"<<comando<<endl;
            int nses;
            cin>>nses;
            Curs curs;
            curs.llegir_curs(nses);
            
            if (q.omplir_sesions_curs(curs, true))
            {
                c.afegir_curs_al_cjt(curs);
                cout<<c.num_cjt_cursos()<<endl;
            }
            else cout<<"error: curso mal formado"<<endl;
        }
        
        else if (comando == "alta_usuario" or comando == "a")
        {

            string user;
            cin>>user;
            cout<<"#"<<comando;
            cout<<" "<<user<<endl;
            u.afegir_usuari(user);
        }
        else if (comando == "baja_usuario" or comando == "b")
        {
            
            string user;
            cin>>user;
            cout<<"#"<<comando;
            cout<<" "<<user<<endl;
            if (u.existeix_usuari(user)) 
            {
                
                int curs = u.curs_inscrit(user);
                u.eliminar_usuari(user);

                if (curs != 0) c.dec_inscrits_cjt(curs);
                
            }
            else cout<<"error: el usuario no existe"<<endl;
            
        }
        
        else if (comando == "inscribir_curso" or comando == "i")
        {
            string user;
            cin>>user;
            int curs;
            cin>>curs;
            cout<<"#"<<comando;
            cout<<" "<<user<<" "<<curs<<endl;
            if (u.existeix_usuari(user))
            {
                if (c.existeix_curs(curs))
                {
                    if (u.curs_inscrit(user) == 0) {
                        
                        u.cjt_inscriure_curs(curs, user, q, c);
                        cout<<c.num_inscrits_cjt(curs)<<endl;

                    }
                    else cout<<"error: usuario inscrito en otro curso"<<endl;
                }
                else cout<<"error: el curso no existe"<<endl;
            }
            else cout<<"error: el usuario no existe"<<endl;
            
        }
        
        else if (comando == "curso_usuario" or comando == "cu")
        {
            
            string user;
            cin>>user;
            cout<<"#"<<comando;
            cout<<" "<<user<<endl;
            if (u.existeix_usuari(user)) 
            {
                cout<<u.curs_inscrit(user)<<endl;
            }
            else cout<<"error: el usuario no existe"<<endl;

        }
        
        else if (comando == "sesion_problema" or comando == "sp")
        {
            int curs;
            string prob;
            cin>>curs>>prob;
            cout<<"#"<<comando;
            cout<<" "<<curs<<" "<<prob<<endl;
            
            if (c.existeix_curs(curs)) 
            {
                if (p.existeix_problema(prob)) 
                {
                    string ses = c.cjt_curs_sesio_problema(curs, prob);
                    if (ses != "-") cout<<ses<<endl;
                    else cout<<"error: el problema no pertenece al curso"<<endl;

                }
                else cout<<"error: el problema no existe"<<endl;
            }
            else cout<<"error: el curso no existe"<<endl;
            
        }
        
        else if (comando == "problemas_resueltos" or comando == "pr")
        {
            string user;
            cin>>user;
            cout<<"#"<<comando;
            cout<<" "<<user<<endl;
            if (u.existeix_usuari(user))
            {
                u.escriu_resolts_cjt(user);
                
            }
            else cout<<"error: el usuario no existe"<<endl;
            
        }
        
        else if (comando == "problemas_enviables" or comando == "pe")
        {
            string user;
            cin>>user;
            cout<<"#"<<comando;
            cout<<" "<<user<<endl;
            
            if (u.existeix_usuari(user))
            {
                if (u.curs_inscrit(user) != 0)
                {
                    u.escriu_enviables_cjt(user);
                }
                else cout<<"error: usuario no inscrito en ningun curso"<<endl;
                
            }
            else cout<<"error: el usuario no existe"<<endl;
        }
        
        else if (comando == "envio" or comando == "e")
        {
            string user, prob;
            int r;
            cin>>user>>prob>>r;
            cout<<"#"<<comando;
            cout<<" "<<user<<" "<<prob<<" "<<r<<endl;
            
            u.enviament(user, prob, r, c, p, q);
            
        }
        
        else if (comando == "listar_problemas" or comando == "lp")
        {
            cout<<"#"<<comando<<endl;
            p.escriure_cjt_problemes();
        }

        else if (comando == "escribir_problema" or comando == "ep")
        {
            string prob;
            cin>>prob;
            cout<<"#"<<comando;
            cout<<" "<<prob<<endl;
            if (p.existeix_problema(prob)) p.escriure_problema(prob);
            else cout<<"error: el problema no existe"<<endl;
            
        }
        
        else if (comando == "listar_sesiones" or comando == "ls")
        {
            cout<<"#"<<comando<<endl;
            q.escriure_cjt_sesio();
        }

        else if (comando == "escribir_sesion" or comando == "es")
        {
            string ses;
            cin>>ses;
            cout<<"#"<<comando<<" "<<ses<<endl;
            if (q.existeix_sesio(ses)) q.escriure_sesio(ses);
            else cout<<"error: la sesion no existe"<<endl;
            
        }
        
        else if (comando == "listar_cursos" or comando == "lc")
        {
            cout<<"#"<<comando<<endl;
            c.escriu_cjt_cursos();
        }

        else if (comando == "escribir_curso" or comando == "ec")
        {
            int curs;
            cin>>curs;
            cout<<"#"<<comando<<" "<<curs<<endl;
            if (c.existeix_curs(curs)) c.escriu_curs(curs);
            else cout<<"error: el curso no existe"<<endl;
        }
        
        else if (comando == "listar_usuarios" or comando == "lu")
        {
            cout<<"#"<<comando<<endl;
            u.llistar_usuaris();
        }

        else if (comando == "escribir_usuario" or comando == "eu")
        {
            
            string user;
            cin>>user;
            cout<<"#"<<comando<<" "<<user<<endl;
            if (u.existeix_usuari(user)) u.llistar_usuari(user);
            else cout<<"error: el usuario no existe"<<endl;
        }

        cin>>comando;
    }
}