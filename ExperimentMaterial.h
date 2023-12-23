#include "Item.h"

#ifndef CENG241_TERM_PROJECT_EXPERIMENTMATERIAL_H
#define CENG241_TERM_PROJECT_EXPERIMENTMATERIAL_H


class ExperimentMaterial: public Item
{
protected:
    bool used;
public:
    bool isUsed(){ return used; }
    void setUsed(int c){
        if (c == 1){
            used = true;
        }else{
            used = false;
        }
    }
};

#endif //CENG241_TERM_PROJECT_EXPERIMENTMATERIAL_H
