#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;
const string COMPOUNDCOLOR = "Green";

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
		int code;
		bool opened;
	public:
		void setcode(int code){this->code=code;}
		int getcode() { return code;}
		void isOpened(int A){
        	if (A == 1){
            	opened = true;
        	}else{
            	opened = false;
        	}
        }
		void check_code(string entered_code){
			if(entered_code == "*******"){
				isOpened(1);
			}
			else 
				isOpened(0);
		}
};

class DoorLock:public Lock{
    private:
		string symbol_code;
	public:
		void setsymbol_code(char entered_symbol) { symbol_code = entered_symbol ; }
		string getsymbol_code() { return symbol_code ;}
		
};
class ComputerLock:public Lock{
	 private:
		string symbol_code;
	public:
		void setsymbol_code(char entered_symbol) { symbol_code = entered_symbol ;}
		string getsymbol_code() { return symbol_code ;}
		
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
int printBasement() //printing menu for the room 1: Basement
{
	int investigateChoice;
	cout << "\n--------------------------------------------------------------------------------" << endl;
	centeredMessage("BASEMENT");
	cout << "-     1. Desk                                                                  -" << endl;
	cout << "-     2. Boxes                                                                 -" << endl;
	cout << "-     3. Calendar                                                              -" << endl;
	cout << "-                                                                              -" << endl;
	cout << "-     0. PERSONAL NOTES                                                        -" << endl;
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
	cout << "-     1. Computer                                                              -" << endl;
	cout << "-     2. Control Notebook                                                      -" << endl;
	cout << "-     3. Return Back                                                           -" << endl;
	cout << "-                                                                              -" << endl;
	cout << "-     0. PERSONAL NOTES                                                        -" << endl;
	cout << "-                                                                              -" << endl;
	cout << "      Choose to investigate: ";
	cin >> investigateChoice;
	return investigateChoice;
}

void printBasement_Computer() //printing message for the computer (does not have the code)
{
	cout << "\n--------------------------------------------------------------------------------" << endl;
	cout << "-     Enter the password: ___                                                  -" << endl;
	cout << "-                                                                              -" << endl;
	cout << "-     'Looks like i need to find the password to access camera records...'     -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl; 
}

void printBasement_ControlNotebook(string labEquipment[10]) //printing control notebook's content
{
	cout << "\n--------------------------------------------------------------------------------" << endl;
	centeredMessage("EQUIPMENT");
	for(int i=0; i < 10; i++)
	{
		alignMessages(labEquipment[i]);
	}
	cout << "--------------------------------------------------------------------------------" << endl;		
}

void printBasement_Boxes(Box boxlist[10], string equipmentList[10]){
    cout << "\n--------------------------------------------------------------------------------" << endl;
    centeredMessage("BOXES");
        for(int i = 0; i<10;i++) {
            alignMessages(string(1, boxlist[i].getSymbol()) + " => " + equipmentList[i]);
        }
    cout << "--------------------------------------------------------------------------------" << endl;
}

void printBasement_Calendar()
{
    cout << "\n--------------------------------------------------------------------------------" << endl;
    centeredMessage("CALENDAR");
    alignMessages("Date 12/04 is circled. Everything else seems normal.");
}

int printLab() //printing menu for the room 2: Laboratory
{
	int investigateChoice;
	cout << "\n--------------------------------------------------------------------------------" << endl;
	centeredMessage("LABORATORY");
	cout << "-     1. Desk                                                                  -" << endl;
	cout << "-     2. Lab Equipment                                                         -" << endl;
	cout << "-     3. Clock                                                                 -" << endl;
	cout << "-     4. Door                                                                  -" << endl;
	cout << "-                                                                              -" << endl;
	cout << "-     0. PERSONAL NOTES                                                        -" << endl;
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
	cout << "-     1. Picture Frame                                                         -" << endl;
	cout << "-     2. Notebook                                                              -" << endl;
	cout << "-     3. Return Back                                                           -" << endl;
	cout << "-                                                                              -" << endl;
	cout << "-     0. PERSONAL NOTES                                                        -" << endl;
	cout << "-                                                                              -" << endl;
	cout << "      Choose to investigate: ";
	cin >> investigateChoice;
	return investigateChoice;
}

int printLab_PictureFrame()
{
	int investigateChoice;
	cout << "\n--------------------------------------------------------------------------------" << endl;
	cout << "-                      An old photograph of Smith family:                      -" << endl;
	cout << "-                     Jack, Henry and their dad Richard...                     -" << endl;
	cout << "-                                                                              -" << endl;
	cout << "-     1. Back of the frame                                                     -" << endl;
	cout << "-     2. Return Back                                                           -" << endl;
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
	centeredMessage("NOTEBOOK OF COMPOUNDS");
	cout << "-                                                                              -" << endl;
	cout << "-     1. Dinitrogen Monoxide +  Iodine Trichloride                             -" << endl;
	cout << "-     2. Iodine Trichloride + Silicon Dioxide                                  -" << endl;
	cout << "-     3. Dinitrogen Monoxide + Silicon Dioxide                                 -" << endl;
	cout << "-     4. Carbon Monoxide + Silicon Dioxide                                     -" << endl;
	cout << "-     5. Carbon Monoxide + Iodine Trichloride                                  -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
}

void printLab_Clock()
{
	cout << "\n--------------------------------------------------------------------------------" << endl;
	cout << "-     Looks like it has been working for a long time,                          -" << endl;
	cout << "-     but it has stopped at 3 o'clock.                                         -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
}

void printLabtoGreenhouse()
{
	cout << "\n--------------------------------------------------------------------------------" << endl;
	alignMessages("You are about to enter Greenhouse");
	alignMessages("You check back of the door and you saw a letter written on it: ");
	alignMessages("C");
	cout << "Press Enter: "; //BAK BURAYA
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
	centeredMessage("EXPERIMENT MATERIAL");
	cout << "-                                                                              -" << endl;
	cout << "-     1. Dinitrogen Monoxide                                                   -" << endl;
	cout << "-     2. Iodine Trichloride                                                    -" << endl;
	cout << "-     3. Silicon Dioxide                                                       -" << endl;
	cout << "-     4. Carbon Monoxide                                                       -" << endl;
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
	cout << "-     1. Security Camera                                                       -" << endl;
	cout << "-     2. Plants                                                                -" << endl;
	cout << "-                                                                              -" << endl;
	cout << "-     0. PERSONAL NOTES                                                        -" << endl;
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

void printGreenhouse_Plants(Plants plants[5])
{
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
}

int checkNote(vector <Note> vec, int a){
    for (Note p : vec) {
        if (a == p.getId()){
            return 1;
        }
    }
    return 0;
}

void PersonalNotes(vector <Note> vec, vector <Note> filled)
{
    cout << "\n--------------------------------------------------------------------------------" << endl;
    centeredMessage("PERSONAL NOTES");
    cout << "-                                                                              -" << endl;
    cout << "\n--------------------------------------------------------------------------------" << endl;
    cout << "-     BASEMENT NOTES                                                           -" << endl;
    cout << "-                                                                              -" << endl;
    if(checkNote(vec, 11) == 1)
    {
        alignMessages("1. " + filled[0].getHint());
    }
    else
    {
        cout << "-     1. ?????????                                                             -" << endl;
    }
    if(checkNote(vec, 12) == 1)
    {
        alignMessages("2. " + filled[1].getHint());
    }
    else
    {
        cout << "-     2. ?????????                                                             -" << endl;
    }
    if(checkNote(vec, 13) == 1)
    {
        alignMessages("3. " + filled[2].getHint());
    }
    else
    {
        cout << "-     3. ?????????                                                             -" << endl;
    }
    if(checkNote(vec, 14) == 1)
    {
        alignMessages("4. " + filled[3].getHint());
    }
    else
    {
        cout << "-     4. ?????????                                                             -" << endl;
    }
	cout << "\n--------------------------------------------------------------------------------" << endl;
	cout << "-     LABORATORY NOTES                                                         -" << endl;
	cout << "-                                                                              -" << endl;
	if(checkNote(vec, 21) == 1)
	{
		alignMessages("1. " + filled[4].getHint());
	}
	else
	{
		cout << "-     1. ?????????                                                             -" << endl;
	}
	if(checkNote(vec, 22) == 1)
	{
		alignMessages("2. " + filled[5].getHint());
	}
	else
	{
		cout << "-     2. ?????????                                                             -" << endl;
	}
	if(checkNote(vec, 23) == 1)
	{
		alignMessages("3. " + filled[6].getHint());
	}
	else
	{
		cout << "-     3. ?????????                                                             -" << endl;
	}
    cout << "\n--------------------------------------------------------------------------------" << endl;
    cout << "-     GREENHOUSE NOTES                                                         -" << endl;
    cout << "-                                                                              -" << endl;
    if(checkNote(vec, 31) == 1)
    {
        alignMessages("1. " + filled[7].getHint());
    }
    else
    {
        cout << "-     1. ?????????                                                             -" << endl;
    }
    if(checkNote(vec, 32) == 1)
    {
        alignMessages("2. " + filled[8].getHint());
    }
    else
    {
        cout << "-     2. ?????????                                                             -" << endl;
    }
}

void addNote(vector <Note> &vector, Note note){
    if(!checkNote(vector, note.getId())){
        vector.push_back(note);
    }
}

int main() {

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
    Note noteGreen2("There were 5 leaves on the plant that changed color.", 32);
    fullNotebook.push_back(noteBase1);
    fullNotebook.push_back(noteBase2);
    fullNotebook.push_back(noteBase3);
    fullNotebook.push_back(noteBase4);
    fullNotebook.push_back(noteLab1);
    fullNotebook.push_back(noteLab2);
    fullNotebook.push_back(noteLab3);
    fullNotebook.push_back(noteGreen1);
    fullNotebook.push_back(noteGreen2);

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
	
	/*   hikaye için yazım fikri

	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-             Henry : What do you mean that you can not find him?!             -" << endl;
	cout << "-                                [press SPACE]                                 -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	*/
	
	int investigateChoice;
	int checkClock = 0, checkNotebook = 0, doorLab;

    //BASEMENT
    
	do{
		investigateChoice = printBasement();
        system("cls");
		if(investigateChoice == 1) //Desk
		{
			do{
				investigateChoice = printBasement_Desk();
                system("cls");
				if(investigateChoice == 1) //Computer
				{
					printBasement_Computer();
                    addNote(personalNotes, noteBase4);
                    //personalNotes.push_back(noteBase4);
                    for(Note p: personalNotes){
                        cout << p.getHint()<<endl;
                    } //Here for testing of the addnote function
				}
				else if(investigateChoice == 2) //Control Notebook
				{
					printBasement_ControlNotebook(labEquipment);
                    addNote(personalNotes, noteBase2);
				}
                else if(investigateChoice == 0) //Personal Notes
                {
                    PersonalNotes(personalNotes, fullNotebook);
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
        else if(investigateChoice == 0) //Personal Notes
        {
            PersonalNotes(personalNotes, fullNotebook);
        }
	}while(investigateChoice >= 0 && investigateChoice <= 3);

	//LABORATORY
	
	do{
		investigateChoice = printLab();
		if(investigateChoice == 1) //Desk
		{
			do{
				investigateChoice = printLab_Desk();
				if(investigateChoice == 1) //Picture Frame
				{
					do
					{
						investigateChoice = printLab_PictureFrame();
						if(investigateChoice == 1) //Back of the picture frame
						{
							printLab_PictureFrame_Back();
							addNote(personalNotes, noteLab3);
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
					PersonalNotes(personalNotes, fullNotebook);
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
			doorLab = printLab_Door();
			if(doorLab == 1)
			{
				investigateChoice = 5;
			}
		}
		else if(investigateChoice == 0) //Personal Notes
		{
			PersonalNotes(personalNotes, fullNotebook);
		}
	}while(investigateChoice >= 0 && investigateChoice <= 4);

    //GREENHOUSE
    system("cls");
    do{
        investigateChoice = printGreenhouse();
        system("cls");
        if(investigateChoice == 1) //Security Camera
        {
            printGreenhouse_SecurityCam();
            addNote(personalNotes, noteGreen1);
        }
        else if(investigateChoice == 2) //Plants
        {
            printGreenhouse_Plants(plants);
            addNote(personalNotes, noteGreen2);
        }
        else if(investigateChoice == 0) //Personal Notes
        {
            PersonalNotes(personalNotes, fullNotebook);
        }
    }while(investigateChoice >= 0 && investigateChoice <= 2);

	return 0;
}