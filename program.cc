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
    //cout<<"llegint prob"<<endl;
    int nprob;
    cin>>nprob;
    Cjt_problemes p;
    string temp;
    p.llegir_Cjt_problemes(nprob);

    //cout<<"llegint ses"<<endl;
    int nsesio;
    cin>>nsesio;
    Cjt_sesions q;
    q.llegir_cjt_sesions(nsesio);

    //cout<<"llegint cursos"<<endl;
    int ncurs;
    cin>>ncurs;
    Cjt_cursos c;
    c.llegeix_cjt_cursos(ncurs);
    

    //cout<<"llegint users"<<endl;
    int m;
    cin>>m;
    Cjt_usuaris u;
    u.llegir_usuaris(m);
    
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
            
            string ses_ns;
            cin>>ses_ns;
            cout<<"#"<<comando;
            cout<<" "<<ses_ns<<endl;
            if (not q.existeix_sesio(ses_ns)) q.afegir_sesio(ses_ns);
            else cout<<"error: la sesion ya existe"<<endl;
            
        }
        
        else if (comando == "nuevo_curso" or comando == "nc")
        {
            cout<<"#"<<comando<<endl;
            c.afegir_curs_al_cjt(q);
        }
        
        else if (comando == "alta_usuario" or comando == "a")
        {

            string usernou;
            cin>>usernou;
            cout<<"#"<<comando;
            cout<<" "<<usernou<<endl;
            u.afegir_usuari(usernou);
        }
        else if (comando == "baja_usuario" or comando == "b")
        {
            
            string userdel;
            cin>>userdel;
            cout<<"#"<<comando;
            cout<<" "<<userdel<<endl;
            if (u.existeix_usuari(userdel)) 
            {
                
                int cu_b = u.curs_inscrit(userdel);
                u.eliminar_usuari(userdel);

                if (cu_b != 0) c.dec_inscrits_cjt(cu_b);
                
            }
            else cout<<"error: el usuario no existe"<<endl;
            
        }
        
        else if (comando == "inscribir_curso" or comando == "i")
        {
            string usr;
            cin>>usr;
            int cursusr;
            cin>>cursusr;
            cout<<"#"<<comando;
            cout<<" "<<usr<<" "<<cursusr<<endl;
            if (u.existeix_usuari(usr))
            {
                if (c.existeix_curs(cursusr))
                {
                    
                    if (u.curs_inscrit(usr) == 0) {
                        list <string> sesions = c.llista_ses_cjt(cursusr);
                        list <string> arrel = q.arrel_cjt(sesions);
                        u.inscriure_usuari_curs(usr, cursusr, arrel);
                        c.inc_inscrits_cjt(cursusr);
                        cout<<c.num_inscrits_cjt(cursusr)<<endl;

                    }
                    else cout<<"error: usuario inscrito en otro curso"<<endl;
                }
                else cout<<"error: el curso no existe"<<endl;
            }
            else cout<<"error: el usuario no existe"<<endl;
            
        }
        
        else if (comando == "curso_usuario" or comando == "cu")
        {
            
            string usrcurs;
            cin>>usrcurs;
            cout<<"#"<<comando;
            cout<<" "<<usrcurs<<endl;
            if (u.existeix_usuari(usrcurs)) 
            {
                cout<<u.curs_inscrit(usrcurs)<<endl;
            }
            else cout<<"error: el usuario no existe"<<endl;

            
        }
        
        else if (comando == "sesion_problema" or comando == "sp")
        {
            int cursprob;
            string probses;
            cin>>cursprob>>probses;
            cout<<"#"<<comando;
            cout<<" "<<cursprob<<" "<<probses<<endl;
            
            if (c.existeix_curs(cursprob)) 
            {
                if (p.existeix_problema(probses)) 
                {
                    list <string> l = c.llista_ses_cjt(cursprob);
                    /*
                    for (list<string>::iterator it = l.begin(); it != l.end(); ++it)
                    {
                        cout<<(*it)<<endl;
                    }
                    cout<<"-----------"<<endl;
                    */
                    string sesfound = q.ses_prob_find_cjt(l, probses);
                    if (sesfound == "-") cout<<"error: el problema no pertenece al curso"<<endl;
                    else cout<<sesfound<<endl;

                }
                else cout<<"error: el problema no existe"<<endl;

            }
            else cout<<"error: el curso no existe"<<endl;
            
            
        }
        
        else if (comando == "problemas_resueltos" or comando == "pr")
        {
            string usresol;
            cin>>usresol;
            cout<<"#"<<comando;
            cout<<" "<<usresol<<endl;
            if (u.existeix_usuari(usresol))
            {
                if (u.curs_inscrit(usresol) != 0)
                {
                    u.escriu_resolts_cjt(usresol);
                }
                
            }
            else cout<<"error: el usuario no existe"<<endl;


            
        }
        
        else if (comando == "problemas_enviables" or comando == "pe")
        {
            string usrenv;
            cin>>usrenv;
            cout<<"#"<<comando;
            cout<<" "<<usrenv<<endl;
            
            if (u.existeix_usuari(usrenv))
            {
                if (u.curs_inscrit(usrenv) != 0)
                {
                    u.escriu_enviables_cjt(usrenv);
                }
                else cout<<"error: usuario no inscrito en ningun curso"<<endl;
                
            }
            else cout<<"error: el usuario no existe"<<endl;
        }
        
        else if (comando == "envio" or comando == "e")
        {
            
            string userenv, probenv;
            int r;
            cin>>userenv>>probenv>>r;
            cout<<"#"<<comando;
            cout<<" "<<userenv<<probenv<<r<<endl;
            //u.enviament(userenv, probenv, r);
            
        }
        
        else if (comando == "listar_problemas" or comando == "lp")
        {
            cout<<"#"<<comando<<endl;
            p.escriure_cjt_problemes();
        }
        else if (comando == "escribir_problema" or comando == "ep")
        {
            string prob_ep;
            cin>>prob_ep;
            cout<<"#"<<comando;
            cout<<" "<<prob_ep<<endl;
            if (p.existeix_problema(prob_ep)) p.escriure_problema(prob_ep);
            else cout<<"error: el problema no existe"<<endl;
            
        }
        
        else if (comando == "listar_sesiones" or comando == "ls")
        {
            cout<<"#"<<comando<<endl;
            q.escriure_cjt_sesio();
        }

        else if (comando == "escribir_sesion" or comando == "es")
        {
            string ses_es;
            cin>>ses_es;
            cout<<"#"<<comando<<" "<<ses_es<<endl;
            if (q.existeix_sesio(ses_es)) q.escriure_sesio(ses_es);
            else cout<<"error: la sesion no existe"<<endl;
            
        }
        
        else if (comando == "listar_cursos" or comando == "lc")
        {
            cout<<"#"<<comando<<endl;
            c.escriu_cjt_cursos();
        }

        else if (comando == "escribir_curso" or comando == "ec")
        {
            int cur_ec;
            cin>>cur_ec;
            cout<<"#"<<comando<<" "<<cur_ec<<endl;
            if (c.existeix_curs(cur_ec)) c.escriu_curs(cur_ec);
            else cout<<"error: el curso no existe"<<endl;
        }
        
        else if (comando == "listar_usuarios" or comando == "lu")
        {
            cout<<"#"<<comando<<endl;
            u.llistar_usuaris();
        }

        else if (comando == "escribir_usuario" or comando == "eu")
        {
            
            string usr_lu;
            cin>>usr_lu;
            cout<<"#"<<comando<<" "<<usr_lu<<endl;
            if (u.existeix_usuari(usr_lu)) u.llistar_usuari(usr_lu);
            else cout<<"error: el usuario no existe"<<endl;
        }
        
        cin>>comando;
    }
}