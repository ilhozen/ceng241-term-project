#include "Item.h"

#ifndef CENG241_TERM_PROJECT_BOX_H
#define CENG241_TERM_PROJECT_BOX_H

class Box: public Item
{
private:
    char Symbol;
public:
    void setSymbol(char symbol) { Symbol = symbol; }
    char getSymbol() { return Symbol; }
};

#endif //CENG241_TERM_PROJECT_BOX_H
