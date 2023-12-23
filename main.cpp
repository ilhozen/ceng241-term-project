#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;
const string COMPOUNDCOLOR = "Green";

void centeredMessage(string text)
{
    int space, counter;
    space = 78 - text.length();
    cout << "-";
    for(counter=1; counter<= (space/2); counter++)
    {
        cout << " ";
    }
    cout << text;
    for(counter=1; counter<= (space/2); counter++)
    {
        cout << " ";
    }
    cout << "-" << endl;
}
void alignMessages(string text)
{
    int space, counter;
    cout << "-";
    for(counter = 1; counter <= 5; counter++)
    {
        cout << " ";
    }
    cout << text;
    space = 73 - text.length(); 
    for(counter = 1; counter <= space; counter++)
    {
        cout << " ";
    }
    cout << "-" << endl;
}

void alignMessagesColor(string text, int k)
{
    HANDLE console;
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    int space, counter;
    cout << "-";
    for(counter = 1; counter <= 5; counter++)
    {
        cout << " ";
    }
    SetConsoleTextAttribute(console, k);
    cout << text;
    SetConsoleTextAttribute(console, 7);
    space = 73 - text.length();
    for(counter = 1; counter <= space; counter++)
    {
        cout << " ";
    }
    cout << "-" << endl;
}

/*void printGameEnd()
{
	centeredMessage("[...CAMERA RECORDS...]");
	centeredMessage("(While Patrick is struggling to breathe on the ground, Henry crouches next to him and looks at his father.)");
	alignMessages("HENRY: This is the medicine that your favorite son Jack found, Dad... Unless you count what I added to it.");
	alignMessages("PATRICK: Henry (cough) I've always loved you, son--");
	alignMessages("HENRY: Even when you're on the brink of death, you're lying, Dad!");
	alignMessages("So be quiet and listen to the fun part: ");
	
	alignMessages("PATRICK: Henry...boy, you...how could you do this?");
	alignMessages("You know that once they see the drug Jack found in your system, your beautiful son will be in prison for the rest of his life, right?");
	centeredMessages("Now Patrick lies motionless on the ground.");
	centeredMessage("Henry cannot control his tears and stands over his father for a while longer.");
	
} WILL BE FIXED */  

class Item //Class for the items we will use
{
	private:
		string Name;
	public:
		void setName(string name) { Name = name; }
		string getName() { return Name; } 
};

class Box: public Item 
{
	private:
		char Symbol;
	public:
		void setSymbol(char symbol) { Symbol = symbol; }
		char getSymbol() { return Symbol; }
};

class ExperimentMaterial: public Item
{
protected:
    bool used;
public:
    bool isUsed(){ return used; }
    void setUsed(int c){
        if (c == 1){
            used = true;
        }else{
            used = false;
        }
    }
};

class Page: public Item
{
	private:
		vector<string>text;
		bool read;
	public:
		void printNotebook(){
			for(int i = 0 ; i < text.size() ; i++){
				cout << text[i] << endl;			
			}
		}
		void isRead(int Read){
			if(Read == 1){
				read = true;
			}
			else{
				read = false;
			}
		}
		void setText(string Text){text.push_back(Text);}
};
	
class Plants: public Item
{
	private:
		int leafNum, date;
		string color, name;
	public:
		void setColor(string Color){ color = Color; }
		void setDate(int Date){ date = Date; }
		void setleafNum(int LeafNum){ leafNum = LeafNum; }
		void setName(string Name){ name = Name; }
		
		string getName() { return name;}
		string getColor() { return color;}
		int getLeafNum() { return leafNum;}
		int getDate() { return date;}
};

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

class DoorLock : public Lock{
public:
    DoorLock(string code)
    : Lock(code) {}
    void checkCode(string givenCode, bool *basementDoor, bool *labDoor){
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
        else if(*basementDoor == false && givenCode != getCode()){
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
			cout << "Type '*' to Continue: "; //BAK BURAYA(??)
    		cin >> cont;
        }
        else if(*labDoor == false && givenCode != getCode()){
        	cout << "\n--------------------------------------------------------------------------------" << endl;
            alignMessages("This doesn't seem like the right password... I should check my notes."); //bu mesajı basmadan direkt seraya geçiyor!!!
        }
    };
};

class ComputerLock : public Lock{
public:
    ComputerLock(string code)
    : Lock(code) {}
    void checkCode(string givenCode, bool *basementDoor, bool *labDoor){
        if(*basementDoor == false && *labDoor == false){
            cout << "\n--------------------------------------------------------------------------------" << endl;
            cout << "-     Enter the password: ___                                                  -" << endl;
            cout << "-                                                                              -" << endl;
            cout << "-     'Looks like i need to find the password to access camera records...'     -" << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
        }
        else{
            cout << "\n--------------------------------------------------------------------------------" << endl;
            alignMessages("Enter the password: " + givenCode);
            printGameEnd();
        }
    }
};

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

int printBasement() //printing menu for the room 1: Basement
{
	int investigateChoice;
	cout << "\n--------------------------------------------------------------------------------" << endl;
	centeredMessage("BASEMENT");
	alignMessages("1. Desk");
	alignMessages("2. Boxes");
	alignMessages("3. Calendar");
	alignMessages("4. Door");
    cout << "-                                                                              -" << endl;
    alignMessages("0. PERSONAL NOTES");
    cout << "-                                                                              -" << endl;
	cout << "      Choose to investigate: ";
	cin >> investigateChoice;
	return investigateChoice;
}

int printBasement_Desk() //printing menu for the desk in Basement
{
	int investigateChoice;
	cout << "\n--------------------------------------------------------------------------------" << endl;
	centeredMessage("DESK");
	alignMessages("1. Computer");
	alignMessages("2. Control Notebook");
	alignMessages("3. Return Back");
	cout << "-                                                                              -" << endl;
	alignMessages("0. PERSONAL NOTES");
	cout << "-                                                                              -" << endl;
	cout << "      Choose to investigate: ";
	cin >> investigateChoice;
	return investigateChoice;
}

void printBasement_ControlNotebook(string labEquipment[10]) //printing control notebook's content
{
	cout << "\n--------------------------------------------------------------------------------" << endl;
	centeredMessage("EQUIPMENT ");
	for(int i=0; i < 10; i++)
	{
		alignMessages(labEquipment[i]);
	}
	cout << "--------------------------------------------------------------------------------" << endl;		
}

void printBasement_Boxes(Box boxlist[10], string equipmentList[10]){
    cout << "\n--------------------------------------------------------------------------------" << endl;
    centeredMessage("BOXES ");
        for(int i = 0; i<10;i++) {
            alignMessages(string(1, boxlist[i].getSymbol()) + " => " + equipmentList[i]);
        }
    cout << "--------------------------------------------------------------------------------" << endl;
}

void printBasement_Calendar()
{
	HANDLE console;
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "\n--------------------------------------------------------------------------------" << endl;
	centeredMessage("APRIL ");
	int counter = 1;
	
	for(int i=1; i<=30; i++)
	{
		cout << "-                   ";
		while(counter != 8)
		{
			if(i == 12)
			{
				SetConsoleTextAttribute(console, 4);
				cout << "   " << i;
				SetConsoleTextAttribute(console, 7);
			}
			else if(i/10 == 0)
			{
				cout << "    " << i;
			}
			else
			{
				cout << "   " << i;
			}
			counter++;
			i++;
		}
		counter = 1;
		for(int j=1; j<=24; j++)
		{
			cout << " ";
		}
		cout << "-";
		cout << "\n";
	}
	cout << "--------------------------------------------------------------------------------" << endl;	
}

void printBasementtoLab()
{
    char cont;
    cout << "\n--------------------------------------------------------------------------------" << endl;
    alignMessages("You are about to enter the Lab");
    alignMessages("You check the back of the door and you see a number written on it: ");
    alignMessages("1");
    cout << "Press '*' to Continue: ";
    cin >> cont;
}

string printBasement_Door()
{
    string password;
    cout << "\n--------------------------------------------------------------------------------" << endl;
    cout << "      Enter the password to enter the Lab: ";
    cin >> password;
    return password;
}

int printLab() //printing menu for the room 2: Laboratory
{
	int investigateChoice;
	cout << "\n--------------------------------------------------------------------------------" << endl;
	centeredMessage("LABORATORY");
	alignMessages("1. Desk");
	alignMessages("2. Lab Equipment");
	alignMessages("3. Clock");
	alignMessages("4. Door");
	cout << "-                                                                              -" << endl;
	alignMessages("0. PERSONAL NOTES");
	cout << "-                                                                              -" << endl;
	cout << "      Choose to investigate: ";
	cin >> investigateChoice;
	return investigateChoice;	
}

int printLab_Desk() //printing menu for the desk in Laboratory
{
	int investigateChoice;
	cout << "\n--------------------------------------------------------------------------------" << endl;
	centeredMessage("DESK");
	alignMessages("1. Picture Frame");
	alignMessages("2. Notebook");
	alignMessages("3. Return Back");
	cout << "-                                                                              -" << endl;
	alignMessages("0. PERSONAL NOTES");
	cout << "-                                                                              -" << endl;
	cout << "      Choose to investigate: ";
	cin >> investigateChoice;
	return investigateChoice;
}

int printLab_PictureFrame()
{
	int investigateChoice;
	cout << "\n--------------------------------------------------------------------------------" << endl;
	centeredMessage("An old photograph of Smith family:");
	centeredMessage("Jack, Henry and their dad Richard...");
	cout << "-                                                                              -" << endl;
	alignMessages("1. Back of the frame");
	alignMessages("2. Return Back");
	cout << "-                                                                              -" << endl;
	cout << "      Choose to investigate: ";
	cin >> 	investigateChoice;
	return investigateChoice;
}

void printLab_PictureFrame_Back()
{
	cout << "\n--------------------------------------------------------------------------------" << endl;
	centeredMessage("BACK OF THE FRAME ");
	cout << "-                                                                              -" << endl;
	alignMessagesColor("4502", 12);
	alignMessagesColor("2356", 14);
	alignMessagesColor("2107", 10);
	alignMessagesColor("7119", 13);
	alignMessagesColor("9864", 11);
	cout << "--------------------------------------------------------------------------------" << endl;
}

void printLab_CompoundNotebook()
{
	cout << "\n--------------------------------------------------------------------------------" << endl;
	centeredMessage("NOTEBOOK OF COMPOUNDS ");
	cout << "-                                                                              -" << endl;
	alignMessages("1. Dinitrogen Monoxide +  Iodine Trichloride");
	alignMessages("2. Iodine Trichloride + Silicon Dioxide");
	alignMessages("3. Dinitrogen Monoxide + Silicon Dioxide");
	alignMessages("4. Carbon Monoxide + Silicon Dioxide");
	alignMessages("5. Carbon Monoxide + Iodine Trichloride");
	cout << "--------------------------------------------------------------------------------" << endl;
}

void printLab_Clock()
{
	cout << "\n--------------------------------------------------------------------------------" << endl;
	alignMessages("Looks like it has been working for a long time,");
	alignMessages("but it has stopped at 3 o'clock.");
	cout << "--------------------------------------------------------------------------------" << endl;
}

void printLabtoGreenhouse()
{
    char cont;
	cout << "\n--------------------------------------------------------------------------------" << endl;
	alignMessages("You are about to enter Greenhouse");
	alignMessages("You check the back of the door and you saw a letter written on it: ");
	alignMessages("C");
	cout << "Type '*' to Continue: "; //BAK BURAYA(??)
    cin >> cont;
}

int printLab_Door()
{
	int password;
	cout << "\n--------------------------------------------------------------------------------" << endl;
	cout << "      Enter the password to enter Greenhouse: ";
	cin >> password;
	cout << "--------------------------------------------------------------------------------" << endl;
	if(password == 2107)
	{
		printLabtoGreenhouse();
		return 1;
	}
	else
	{
		alignMessages("The password is incorrect.");
		cout << "--------------------------------------------------------------------------------" << endl;
		return 0;
	}
}

void combine(int mat1, int mat2){
    if(mat1 == 1 && mat2 == 3 || mat2 == 1 && mat1 == 3){
        cout << "      You have combined Dinitrogen Monoxide and Silicon Dioxide.\n      It turned " << COMPOUNDCOLOR << endl;
    }else{
        cout << "      This doesn't seem like the correct formula,\n      I should check the notes to be sure.." << endl;
    }
}

void printLab_UseExpMat()
{
	int m1, m2;
	cout << "\n--------------------------------------------------------------------------------" << endl;
	centeredMessage("EXPERIMENT MATERIAL ");
	cout << "-                                                                              -" << endl;
	alignMessages("1. Dinitrogen Monoxide");
	alignMessages("2. Iodine Trichloride");
	alignMessages("3. Silicon Dioxide");
	alignMessages("4. Carbon Monoxide");
	cout << "-                                                                              -" << endl;
	cout << "      Choose to add to the beaker: ";
	cin >> m1 >> m2;
	combine(m1, m2);
}
			
int printGreenhouse()
{
	int investigateChoice;		
	cout << "\n--------------------------------------------------------------------------------" << endl;
	centeredMessage("GREENHOUSE");
	alignMessages("1. Security Camera");
	alignMessages("2. Plants");
	cout << "-                                                                              -" << endl;
	alignMessages("0. PERSONAL NOTES");
	cout << "-                                                                              -" << endl;
	cout << "      Choose to investigate: ";
	cin >> investigateChoice;
	return investigateChoice;
}

void printGreenhouse_SecurityCam()
{
    cout << "\n--------------------------------------------------------------------------------" << endl;
    alignMessages("'It is still working.'");
    alignMessages("'I must find the password as soon as possible to prove my innocence...'");
}

void printGreenhouse_Plants(Plants plants[5], int check, int * finish)
{
    int plantChoice;
	cout << "\n--------------------------------------------------------------------------------" << endl;
    centeredMessage("PLANTS");
    for(int i=0; i < 5; i++)
    {
    	alignMessages("Name: " + plants[i].getName());
    	alignMessages("Color: " + plants[i].getColor());
    	alignMessages("Date: " + to_string(plants[i].getDate()));
    	alignMessages("Number Of Leaves: " + to_string(plants[i].getLeafNum()));
		cout << "\n";
	}
    if (check == 1){
        cout << "--------------------------------------------------------------------------------" << endl;
        alignMessages("1. Jasmine");
        alignMessages("2. Tulip");
        alignMessages("3. Sunflower");
        alignMessages("4. Lotus");
        alignMessages("5. Orchid");
        cout << "-                                                                              -" << endl;
        cout << "      Choose the plant you want to pour the compound on: ";
        cin >> plantChoice;
        if (plantChoice == 2){
            cout << "\n      You poured the compound on the plant." << endl;
            cout << "      The plant turned turquoise." << endl;
            cout << "\n      The plant's 5 leaves finally remind you of the final digit of the " <<endl;
            cout << "      computer password." <<endl;
            *finish = 1;
        }
        else
        {
        	cout << "-                                                                              -" << endl;
            alignMessages("Nothing happened.");
            alignMessages("'I should look at my notes and think carefully about this.'");
        }
    }
}

int checkNote(vector <Note> vec, int a){
    for (Note p : vec) {
        if (a == p.getId()){
            return 1;
        }
    }
    return 0;
}

void PersonalNotes(vector <Note> vec, vector <Note> filled, string code)
{
    cout << "\n--------------------------------------------------------------------------------" << endl;
    centeredMessage("PERSONAL NOTES");
    cout << "-                                                                              -" << endl;
    cout << "\n--------------------------------------------------------------------------------" << endl;
    alignMessages("BASEMENT NOTES");
    cout << "-                                                                              -" << endl;
    if(checkNote(vec, 11) == 1)
    {
        alignMessages("1. " + filled[0].getHint());
    }
    else
    {
    	alignMessages("1. ?????????");
    }
    if(checkNote(vec, 12) == 1)
    {
        alignMessages("2. " + filled[1].getHint());
    }
    else
    {
        alignMessages("2. ?????????");
    }
    if(checkNote(vec, 13) == 1)
    {
        alignMessages("3. " + filled[2].getHint());
    }
    else
    {
        alignMessages("3. ?????????");
    }
    if(checkNote(vec, 14) == 1)
    {
        alignMessages("4. " + filled[3].getHint());
    }
    else
    {
        alignMessages("4. ?????????");
    }
	cout << "\n--------------------------------------------------------------------------------" << endl;
	alignMessages("LABORATORY NOTES");
	cout << "-                                                                              -" << endl;
	if(checkNote(vec, 21) == 1)
	{
		alignMessages("1. " + filled[4].getHint());
	}
	else
	{
		alignMessages("1. ?????????");
	}
	if(checkNote(vec, 22) == 1)
	{
		alignMessages("2. " + filled[5].getHint());
	}
	else
	{
		alignMessages("2. ?????????");
	}
	if(checkNote(vec, 23) == 1)
	{
		alignMessages("3. " + filled[6].getHint());
	}
	else
	{
		alignMessages("3. ?????????");
	}
    cout << "\n--------------------------------------------------------------------------------" << endl;
    alignMessages("GREENHOUSE NOTES");
    cout << "-                                                                              -" << endl;
    if(checkNote(vec, 31) == 1)
    {
        alignMessages("1. " + filled[7].getHint());
    }
    else
    {
        alignMessages("1. ?????????");
    }
    if(checkNote(vec, 32) == 1)
    {
        alignMessages("2. " + filled[8].getHint());
    }
    else
    {
        alignMessages("2. ?????????");
    }
    cout << "\n--------------------------------------------------------------------------------" << endl;
    alignMessages("COMPUTER PASSWORD: " + code);
}

void addNote(vector <Note> &vector, Note note){
    if(!checkNote(vector, note.getId())){
        vector.push_back(note);
    }
}

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
	
	centeredMessage(" ...MEANWHILE IN THE BASEMENT OF JACK'S HOUSE...");
	cout << "--------------------------------------------------------------------------------" << endl;
	alignMessages("JACK: What do you mean... you killed our father?");
	cout << "\n";
	alignMessages("HENRY: You can't blame me, this is all your fault!");
	cout << "\n";
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
            printBasement_Boxes(boxes, labEquipment);
            addNote(personalNotes, noteBase3);
        }
        else if(investigateChoice == 3) //Boxes
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
			if(labIsOpen == 1)
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
	}while(investigateChoice >= 0 && investigateChoice < 4);

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
            	// go back to basement cout ...
            	masterCode = "1C5";
            	computerLock.checkCode(masterCode, &basementIsOpen, &labIsOpen);
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