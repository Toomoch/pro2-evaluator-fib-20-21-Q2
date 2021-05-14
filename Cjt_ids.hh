/** @file Curs.hh
    @brief Especificació de la classe Curs
*/

#ifndef CJT_IDS_HH
#define CJT_IDS_HH

/// \cond
#include <set>
#include <string>

/// \endcond
using namespace std;

class Cjt_ids{
    private:
        set<string> prob;
    public:
        bool insertar(const string &p)
        {
            pair <set<string>::iterator,bool> ret;
            ret = prob.insert(p);
            return ret.second;
        }
        /*
        string pos(const set<string>::iterator &it)
        {
            return (*it);
        }
        */
        set<string>::iterator principi()
        {
            return prob.begin();
        }

        set<string>::iterator final()
        {
            return prob.end();
        }



};

#endif