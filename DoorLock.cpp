#include "projectfun.h"
#include "DoorLock.h"

    DoorLock::DoorLock(string code)
            : Lock(code) {}
    void DoorLock::checkCode(string givenCode, bool *basementDoor, bool *labDoor){
        if(*basementDoor == false && givenCode == getCode())
        {
            *basementDoor = true;
            char cont;
            cout << "\n--------------------------------------------------------------------------------" << endl;
            alignMessages("You are about to enter the Lab");
            alignMessages("You check the back of the door and you see a number written on it: ");
            alignMessages("1");
            cout << "Press '*' to Continue: ";
            cin >> cont;
        }
        else if(*basementDoor == false && givenCode != getCode())
        {
            cout << "\n--------------------------------------------------------------------------------" << endl;
            alignMessages("This doesn't seem like the right password... I should check my notes.");
        }
        else if (*labDoor == false && givenCode == getCode())
        {
            *labDoor = true;
            char cont;
            cout << "\n--------------------------------------------------------------------------------" << endl;
            alignMessages("You are about to enter Greenhouse");
            alignMessages("You check the back of the door and you saw a letter written on it: ");
            alignMessages("C");
            cout << "Type '*' to Continue: ";
            cin >> cont;
        }
        else if(*labDoor == false && givenCode != getCode())
        {
            cout << "\n--------------------------------------------------------------------------------" << endl;
            alignMessages("This doesn't seem like the right password... I should check my notes.");
        }
    }