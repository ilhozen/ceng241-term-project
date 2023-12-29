#include <string>
#include "Item.h"

#ifndef CENG241_TERM_PROJECT_PLANTS_H
#define CENG241_TERM_PROJECT_PLANTS_H


class Plants: public Item
{
private:
    int leafNum, date;
    string color;
public:
    void setColor(string Color){ color = Color; }
    void setDate(int Date){ date = Date; }
    void setleafNum(int LeafNum){ leafNum = LeafNum; }

    string getColor() { return color;}
    int getLeafNum() { return leafNum;}
    int getDate() { return date;}
};


#endif //CENG241_TERM_PROJECT_PLANTS_H
