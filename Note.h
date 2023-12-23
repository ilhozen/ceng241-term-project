#include <string>

#ifndef CENG241_TERM_PROJECT_NOTE_H
#define CENG241_TERM_PROJECT_NOTE_H
using namespace std;

class Note{
private:
    string hint;
    int id;
public:
    Note(string hint, int id)
            : hint(hint), id(id){}

    string getHint() const {return hint;}

    int getId() const {return id;}
};


#endif //CENG241_TERM_PROJECT_NOTE_H
