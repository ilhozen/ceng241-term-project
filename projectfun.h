#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "Box.h"
#include "Plants.h"
#include "Note.h"
#ifndef CENG241_TERM_PROJECT_PROJECTFUN_H
#define CENG241_TERM_PROJECT_PROJECTFUN_H
using namespace std;

void centeredMessage(string text);

void alignMessages(string text);

void alignMessagesColor(string text, int k);

void printGameEnd();

int printBasement();

int printBasement_Desk();

void printBasement_ControlNotebook(string labEquipment[10]);

void printBasement_Boxes(Box boxlist[10], string equipmentList[10]);

void printBasement_Calendar();

void printBasementtoLab();

string printBasement_Door();

int printLab();

int printLab_Desk();

int printLab_PictureFrame();

void printLab_PictureFrame_Back();

void printLab_CompoundNotebook();

void printLab_Clock();

void printLabtoGreenhouse();

string printLab_Door();

void combine(int mat1, int mat2);

void printLab_UseExpMat();

int printGreenhouse();

void printGreenhouse_SecurityCam();

void printGreenhouse_Plants(Plants plants[5], int check, int * finish);

int checkNote(vector <Note> vec, int a);

void PersonalNotes(vector <Note> vec, vector <Note> filled, string code);

void addNote(vector <Note> &vector, Note note);

#endif //CENG241_TERM_PROJECT_PROJECTFUN_H