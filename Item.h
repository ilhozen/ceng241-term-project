#include <string>
#ifndef CENG241_TERM_PROJECT_ITEM_H
#define CENG241_TERM_PROJECT_ITEM_H
using namespace std;

class Item //Class for the items we will use
{
protected:
    string Name;
public:
    void setName(string name) { Name = name; }
    string getName() { return Name; }
};

#endif //CENG241_TERM_PROJECT_ITEM_H
