/** @file Cjt_ids.hh
    @brief Especificació de la classe Cjt_ids
*/

#ifndef CJT_IDS_HH
#define CJT_IDS_HH

/// \cond
#include <set>
#include <string>

/// \endcond
using namespace std;


/** @class Cjt_ids
    @brief Representa el tipus Cjt_ids
*/
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
        
        set<string>::iterator principi()
        {
            return prob.begin();
        }

        set<string>::iterator final()
        {
            return prob.end();
        }

        bool existeix (const string &p)
        {
            if (prob.find(p)==prob.end()) return false;
            return true;
        }


};

#endif