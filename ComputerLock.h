#include "Lock.h"

#ifndef CENG241_TERM_PROJECT_COMPUTERLOCK_H
#define CENG241_TERM_PROJECT_COMPUTERLOCK_H


class ComputerLock : public Lock{
public:
    ComputerLock(string code);
    void checkCode(string givenCode, bool *basementDoor, bool *labDoor);
};

#endif //CENG241_TERM_PROJECT_COMPUTERLOCK_H
