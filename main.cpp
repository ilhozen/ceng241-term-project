#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "projectfun.h"
#include "Item.h"
#include "ExperimentMaterial.h"
#include "Box.h"
#include "Page.h"
#include "Plants.h"
#include "Lock.h"
#include "DoorLock.h"
#include "ComputerLock.h"
#include "Note.h"

using namespace std;

int main() {
	
	char cont;
	cout << "--------------------------------------------------------------------------------" << endl;
	centeredMessage("A biologist who discovered a worldwide sought-after drug... ");
	centeredMessage("[press '*'] ");
	cin >> cont;
	cout << "--------------------------------------------------------------------------------" << endl;
	centeredMessage("A brother who is after this medicine... ");
	centeredMessage("[press '*'] ");
	cin >> cont;
	cout << "--------------------------------------------------------------------------------" << endl;
	centeredMessage("A trap set to get the medicine... ");
	centeredMessage("[press '*'] ");
	cin >> cont;
	cout << "--------------------------------------------------------------------------------" << endl;
	centeredMessage("And a biologist trying to escape from this trap...");
	centeredMessage("[press '*'] ");
	cin >> cont;
	cout << "--------------------------------------------------------------------------------" << endl;
	system("cls");
	
	cout << "--------------------------------------------------------------------------------" << endl;
	centeredMessage(" ...MEANWHILE IN THE BASEMENT OF JACK'S HOUSE...");
	cout << "--------------------------------------------------------------------------------" << endl;
	alignMessages("JACK: What do you mean... you killed our father?");
	cout << "-                                                                              -" << endl;
	alignMessages("HENRY: You can't blame me, this is all your fault!");
	cout << "-                                                                              -" << endl;
	alignMessages("JACK: You're out of your mind, Henry. ");
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	centeredMessage(" (Henry leaves the basement in a rage and locks the door.)");
	centeredMessage(" (Jack slowly loses consciousness and forgets what just happened...)");
	centeredMessage("[press '*'] ");
	cin >> cont;
	system("cls");
	
    vector <Note> personalNotes;
    vector <Note> fullNotebook;
    Note noteBase1("There is a date circled on the calendar: 1204", 11);
    Note noteBase2("The control notebook has marks for specific laboratory equipment:     -\n"
                   "-        !volumetric flask, !!beaker, !!!glasses, !!!!funnel                   ", 12);
    Note noteBase3("There are letters on the boxes corresponding to                       -\n"
                   "-        the marked laboratory equipment : S O Z A                             ", 13);
    Note noteBase4("The computer has a password. I should find it.", 14);
    Note noteLab1("The clock has stopped at 3 o'clock.", 21);
    Note noteLab2("There must be a connection between the broken clock and               -\n"
				  "-        the compound written in the notebook.                                 ", 22);
    Note noteLab3("There are codes in different colors behind the picture", 23);
    Note noteGreen1("I haven't used the date marked on the calendar in the basement.", 31);
    Note noteGreen2("I need to use the compound I made on one of the plants.               -\n"
                    "-        Which one should I choose?                                            ", 32);
    fullNotebook.push_back(noteBase1);
    fullNotebook.push_back(noteBase2);
    fullNotebook.push_back(noteBase3);
    fullNotebook.push_back(noteBase4);
    fullNotebook.push_back(noteLab1);
    fullNotebook.push_back(noteLab2);
    fullNotebook.push_back(noteLab3);
    fullNotebook.push_back(noteGreen1);
    fullNotebook.push_back(noteGreen2);

    DoorLock basementLock("SOZA");
    DoorLock labLock("2107");
    ComputerLock computerLock("1C5");

	string labEquipment[10] = {"!!!Glasses" , "Coats" , "!Volumetric flask" , "Gloves" , "Test tube" , "Microscope" , "!!!!Funnel" , "!!Beaker" , "Magnet" , "Pipette"};
    string boxEquipment[10] = {"Glasses" , "Coats" , "Volumetric flask" , "Gloves" , "Test tube" , "Microscope" , "Funnel" , "Beaker" , "Magnet" , "Pipette"};
	string compounds[5] = {"1. yellow + red" , "2. blue + red" , "3. blue + yellow" , "4. brown + blue" , "5. brown + red"};

    Box boxes[10];
    boxes[0].setSymbol('Z');
    boxes[1].setSymbol('C');
    boxes[2].setSymbol('S');
    boxes[3].setSymbol('R');
    boxes[4].setSymbol('X');
    boxes[5].setSymbol('G');
    boxes[6].setSymbol('A');
    boxes[7].setSymbol('O');
    boxes[8].setSymbol('L');
    boxes[9].setSymbol('P');
	
	ExperimentMaterial m1;
	ExperimentMaterial m2;
	ExperimentMaterial m3;
	ExperimentMaterial m4;
	m1.setName("Dinitrogen Monoxide"); //yellow
	m2.setName("Iodine Trichloride"); //red
	m3.setName("Silicon Dioxide"); //blue
	m4.setName("Carbon Monoxide"); //brown 
	
	Page controlNotebook;
	Page notebookOfCompounds;

    for(int i = 0 ; i < 10 ; i++){
        boxes[i].setName(boxEquipment[i]);
    }

	for(int i = 0 ; i < 10 ; i++){
		controlNotebook.setText(labEquipment[i]);
	}
	
	for(int i = 0 ; i < 5 ; i++){
		notebookOfCompounds.setText(compounds[i]);
	}
	
	Plants plants[5];
	plants[0].setName("Jasmine");
	plants[0].setColor("yellow");
	plants[0].setDate(3012);
	plants[0].setleafNum(8);
	
	plants[1].setName("Tulip");
	plants[1].setColor("green");
	plants[1].setDate(1204);
	plants[1].setleafNum(5);
	
	plants[2].setName("Lotus");
	plants[2].setColor("red");
	plants[2].setDate(1010);
	plants[2].setleafNum(6);
	
	plants[3].setName("Sunflower");
	plants[3].setColor("purple");
	plants[3].setDate(2903);
	plants[3].setleafNum(20);
	
	plants[4].setName("Orchid");
	plants[4].setColor("blue");
	plants[4].setDate(1810);
	plants[4].setleafNum(10);
	
	int investigateChoice;
	int checkClock = 0, checkNotebook = 0, checkPlant = 0, checkFinish = 0;
    string userCode = " ";
    bool basementIsOpen, labIsOpen;
	basementIsOpen = basementLock.isOpen();
	labIsOpen = labLock.isOpen();
	string masterCode = "???";

    //BASEMENT
    
	do{
		investigateChoice = printBasement();
        if(investigateChoice != 4)
            system("cls");
		if(investigateChoice == 1) //Desk
		{
			do{
				investigateChoice = printBasement_Desk();
                system("cls");
				if(investigateChoice == 1) //Computer
				{
					computerLock.checkCode(masterCode, &basementIsOpen, &labIsOpen);
                    addNote(personalNotes, noteBase4);
				}
				else if(investigateChoice == 2) //Control Notebook
				{
					printBasement_ControlNotebook(labEquipment);
                    addNote(personalNotes, noteBase2);
				}
                else if(investigateChoice == 0) //Personal Notes
                {
                    PersonalNotes(personalNotes, fullNotebook, masterCode);
                }
                else if(investigateChoice < 0 || investigateChoice >= 4)
				{
        			alignMessages("Invalid choice. Try again!");
        			investigateChoice = 0;
				}
			}while(investigateChoice >= 0 && investigateChoice < 3);
		}
        else if(investigateChoice == 2) //Boxes
        {
            printBasement_Boxes(boxes, boxEquipment);
            if (checkNote(personalNotes, 12)){
                addNote(personalNotes, noteBase3);
            }

        }
        else if(investigateChoice == 3) //Calendar
        {
            printBasement_Calendar();
            addNote(personalNotes, noteBase1);
        }
        else if(investigateChoice == 4)
        {
            userCode = printBasement_Door();
            basementLock.checkCode(userCode, &basementIsOpen, &labIsOpen);
            if(basementIsOpen == 1)
            {
            	investigateChoice = 5;
			}
        }
        else if(investigateChoice == 0) //Personal Notes
        {
            PersonalNotes(personalNotes, fullNotebook, masterCode);
        }
        else if(investigateChoice < 0 || investigateChoice >= 5)
		{
        	alignMessages("Invalid choice. Try again!");
        	investigateChoice = 0;
		}
	}while(investigateChoice >= 0 && investigateChoice <= 4);

	//LABORATORY
	system("cls");
	masterCode = "1??";
	do{
		investigateChoice = printLab();
		if(investigateChoice != 4)
            system("cls");
		if(investigateChoice == 1) //Desk
		{
			do{
				investigateChoice = printLab_Desk();
				system("cls");
				if(investigateChoice == 1) //Picture Frame
				{
					do
					{
						investigateChoice = printLab_PictureFrame();
						system("cls");
						if(investigateChoice == 1) //Back of the picture frame
						{
							printLab_PictureFrame_Back();
							addNote(personalNotes, noteLab3);
						}
						else if(investigateChoice <= 0 && investigateChoice >= 3)
						{
							alignMessages("Invalid choice. Try again!");
        					investigateChoice = 0;
						}		
					}while(investigateChoice != 2);
				}
				else if(investigateChoice == 2) //Notebook Of Compounds
				{
					printLab_CompoundNotebook();
					checkNotebook = 1;
					if(checkClock == 1)
					{
						addNote(personalNotes, noteLab2);
					}
				}
				else if(investigateChoice == 0) //Personal Notes
				{
					PersonalNotes(personalNotes, fullNotebook, masterCode);
				}
				else if(investigateChoice < 0 || investigateChoice >= 4)
				{
        			alignMessages("Invalid choice. Try again!");
        			investigateChoice = 0;
				}
			}while(investigateChoice >= 0 && investigateChoice < 3);
		}
		else if(investigateChoice == 2) //Lab Equipm
		{
			printLab_UseExpMat();
		}
		else if(investigateChoice == 3) //Clock
		{
			printLab_Clock();
			addNote(personalNotes, noteLab1);
			checkClock = 1;
			if(checkNotebook == 1)
			{
				addNote(personalNotes, noteLab2);
			}
		}
		else if(investigateChoice == 4)
		{
			userCode = printLab_Door();
			labLock.checkCode(userCode, &basementIsOpen, &labIsOpen);
			if(labIsOpen == true)
            {
            	investigateChoice = 5;
			}
		}
		else if(investigateChoice == 0) //Personal Notes
		{
			PersonalNotes(personalNotes, fullNotebook, masterCode);
		}
		else if(investigateChoice < 0 || investigateChoice >= 5)
		{
        	alignMessages("Invalid choice. Try again!");
        	investigateChoice = 0;
		}
	}while(investigateChoice >= 0 && investigateChoice <= 4);

    //GREENHOUSE
    system("cls");
    masterCode = "1C?";
    do{
        investigateChoice = printGreenhouse();
        addNote(personalNotes, noteGreen1);
        system("cls");
        if(investigateChoice == 1) //Security Camera
        {
            printGreenhouse_SecurityCam();
        }
        else if(investigateChoice == 2) //Plants
        {
            printGreenhouse_Plants(plants, checkPlant, &checkFinish);
            addNote(personalNotes, noteGreen2);
            checkPlant = 1;
            if(checkFinish == 1)
            {
            	masterCode = "1C5";
            	computerLock.checkCode(masterCode, &basementIsOpen, &labIsOpen);
            	return 0;
			}
        }
        else if(investigateChoice == 0) //Personal Notes
        {
            PersonalNotes(personalNotes, fullNotebook, masterCode);
        }
        else if(investigateChoice < 0 || investigateChoice >= 3)
		{
        	alignMessages("Invalid choice. Try again!");
        	investigateChoice = 0;
		}
    }while(investigateChoice >= 0 && investigateChoice <= 2);

	return 0;
}