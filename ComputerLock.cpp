#include "projectfun.h"
#include "ComputerLock.h"

    ComputerLock :: ComputerLock(string code)
            : Lock(code) {}
    void ComputerLock :: checkCode(string givenCode, bool *basementDoor, bool *labDoor){
        char cont;
        if(*basementDoor == false && *labDoor == false){
            cout << "\n--------------------------------------------------------------------------------" << endl;
            cout << "-     Enter the password: ___                                                  -" << endl;
            cout << "-                                                                              -" << endl;
            cout << "-     'Looks like i need to find the password to access camera records...'     -" << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
        }
        else{
            system("cls");
            cout << "\n--------------------------------------------------------------------------------" << endl;
            alignMessages("(You go back to the basement to check the computer)");
            alignMessages("Enter the password: " + givenCode);
            centeredMessage("[press '*'] ");
            cin >> cont;
            printGameEnd();
            cout << "-                                                                              -" << endl;
            centeredMessage("[press '*' to end the game] ");
            cin >> cont;
        }
    }