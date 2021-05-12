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

string Sesio::arrel()
{
    return tree.value();
}

bool Sesio::ses_prob_find(string p)
{
   
    return buscar(tree, p);
}

bool Sesio::buscar(const BinTree<string> &t, string p)
{
    bool found;
    if (t.empty()) found = false;
    
    else if (t.value() == p) found = true;
    
    else 
    {   
        found = buscar(t.left(), p);
        if (not found)  found = buscar(t.right(), p);
        
    }
    return found;                                                              
}

void wtf(BinTree<string> &y, string p)
{
    if (y.value()==p)
    {
        if (y.value.em)
    }
}

void Sesio::escriu_ses()
{
    preorde_escriure_ses(tree);
    cout<<endl;
}

void Sesio::preorde_escriure_ses(const BinTree <string> &t)
{
    if (not t.empty())
    {
        cout<<"(";
        preorde_escriure_ses(t.left());
        preorde_escriure_ses(t.right());
        cout<<t.value();
        cout<<")";

    }

}

int Sesio::num_problemes()
{
    return numprob;
}
