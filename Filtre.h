#ifndef FILTRE_H
#define FILTRE_H

#include <vector>
#include <ACarte.h>
#include <memory>
using namespace std;

template <class T, class S>
class Filtre
{
    public:
        static vector<shared_ptr<S>> filtreClass(vector<shared_ptr<ACarte>> vec, bool withRoi) {
            vector<shared_ptr<ACarte>> v;
            for(shared_ptr<ACarte> element : vec) {
                if(dynamic_pointer_cast<T>(element) != NULL) {
                    if(withRoi) {
                        v.push_back(element);
                    } else {
                        if(!element->isRoi()) {
                            v.push_back(element);
                        }
                    }
                }
            }
            return v;
        }



};

#endif // FILTRE_H
