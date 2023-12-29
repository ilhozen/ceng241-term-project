#include <string>
#ifndef CENG241_TERM_PROJECT_ITEM_H
#define CENG241_TERM_PROJECT_ITEM_H
using namespace std;

class Item //Class for the items we will use
{
protected:
    string name;
public:
    void setName(string namee) { name = namee; }
    string getName() { return name; }
};

#endif //CENG241_TERM_PROJECT_ITEM_H
