/** @file Sesio.cc
    @brief Implementació de la clase Sesio
*/
#include "Sesio.hh"
Sesio::Sesio()
{
    numprob=0;
}

void Sesio::llegir_ses()
{
    BinTree <string> temp;
    preordre_llegir_ses(temp);
    tree = temp;
    numprob = calc_numero_problemes(temp);
}

void Sesio::preordre_llegir_ses(BinTree <string> &temp) 
{
    string problem;
    cin>>problem;
    if (problem != "0")
    {
        BinTree <string> l;
        preordre_llegir_ses(l);
        BinTree <string> r;
        preordre_llegir_ses(r);
        temp = BinTree <string> (problem, l, r);
    }
}

int Sesio::calc_numero_problemes(const BinTree <string> &temp){
    int num;
    if (temp.empty()) num = 0;
    else 
    {
        num = 1 + calc_numero_problemes(temp.left()) + calc_numero_problemes(temp.right());
    }
    return num;
}

bool Sesio::inters_pre_inserta_contenidor_curs(const string &ses, Curs &c)
{
    bool interseccio = false;
    inserta_contenidor_curs(ses, c, tree, interseccio);
    return interseccio;
}

void Sesio::inserta_contenidor_curs(const string &ses, Curs &c, const BinTree<string> &t, bool &interseccio)
{
    if(not t.empty() and not interseccio)
    {
            if(c.insertar_prob_ses(t.value(), ses))
            {
                interseccio = true;
            }

            else
            {
                inserta_contenidor_curs(ses, c, t.right(), interseccio);
                inserta_contenidor_curs(ses, c, t.left(), interseccio);
            }
    }
}


void Sesio::arrel(Usuari &u)
{
    if (u.resolt() == 0)
    {   
        u.afegir_enviables(tree.value());
    }
    else
    {
        afegir_problemes_usuari_tree(tree, u);
    }
    
}


void Sesio::afegir_problemes_usuari_tree(const BinTree<string>& t, Usuari& u)
{

    if (not t.empty())
    {    
        if (not u.problema_resolt(t.value()))
        {
            u.afegir_enviables(t.value());
        }
        else
        {
            if (not t.right().empty()) afegir_problemes_usuari_tree(t.right(),u);
            if (not t.left().empty()) afegir_problemes_usuari_tree(t.left(),u);
        }
    }
}

void Sesio::escriu_ses() const
{
    post_escriure_ses(tree);
    cout<<endl;
}

void Sesio::post_escriure_ses(const BinTree <string> &t)
{
    if (not t.empty())
    {
        cout<<"(";
        post_escriure_ses(t.left());
        post_escriure_ses(t.right());
        cout<<t.value();
        cout<<")";

    }

}

int Sesio::num_problemes() const
{
    return numprob;
}

void Sesio::pre_troba_afegeix_fulles(const string &p, Usuari &u)
{
    troba_afegeix_fulles_arbre(tree, p, u);
}

void Sesio::troba_afegeix_fulles_arbre(const BinTree<string> &t, const string &p, Usuari &u)
{
    if (not t.empty())
    {
        if (t.value() == p) afegir_enviable(t, u);
        else 
        {
            troba_afegeix_fulles_arbre(t.left(), p, u);
            troba_afegeix_fulles_arbre(t.right(), p, u);
        }
    }
}

void Sesio::afegir_enviable(const BinTree<string> &t, Usuari &u)
{
    if(not t.right().empty())
    {
        if(u.problema_resolt(t.right().value()))
        {
            afegir_enviable(t.right(),u);
        }

        else 
        {
            u.afegir_enviables(t.right().value());
        }
    }
    
    if(not t.left().empty())
    {
        if(u.problema_resolt(t.left().value()))
        {
            afegir_enviable(t.left(),u);
        }
        else
        {
            u.afegir_enviables(t.left().value());
        }
        
    }
}