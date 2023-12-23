#include <iostream>
#include "Lock.h"

#ifndef CENG241_TERM_PROJECT_DOORLOCK_H
#define CENG241_TERM_PROJECT_DOORLOCK_H


class DoorLock : public Lock{
public:
    DoorLock(string code);
    void checkCode(string givenCode, bool *basementDoor, bool *labDoor);
};


#endif //CENG241_TERM_PROJECT_DOORLOCK_H
