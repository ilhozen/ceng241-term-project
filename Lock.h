#include <string>

#ifndef CENG241_TERM_PROJECT_LOCK_H
#define CENG241_TERM_PROJECT_LOCK_H
using namespace std;

class Lock{
protected:
    string code;
    bool open;
public:
    Lock(string code)
            : code(code) {open = 0;}
    string getCode(){return code;}
    bool isOpen(){return open;}
    void setOpen(bool a) { open = a; }
    virtual void checkCode(string givenCode, bool *basementDoor, bool *labDoor) = 0;
};


#endif //CENG241_TERM_PROJECT_LOCK_H
