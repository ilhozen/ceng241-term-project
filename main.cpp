#include <iostream>
#include <string>
#include <vector>

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
		
		void printInfo(){
			cout << "Name : " << name << endl;
			cout << "Planting Date : " << date << endl;
			cout << "Color : " << color << endl;
			cout << "Number of Leaves : " << leafNum << endl;
		}
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

void allignMessages(string text)
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


int printBasement() //printing menu for the room 1: Basement
{
	int investigateChoice;
	cout << "\n--------------------------------------------------------------------------------" << endl;
	cout << "-                                   BASEMENT                                   -" << endl;
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
	cout << "-                                     DESK                                     -" << endl;
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
	cout << "-     Enter the password:                                                      -" << endl;
	cout << "-                                                                              -" << endl;
	cout << "-     'Looks like i need to find the password to access camera records...'     -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl; 
}

void printBasement_ControlNotebook(string labEquipment[10]) //primting control notebook's content
{
	cout << "\n--------------------------------------------------------------------------------" << endl;
	cout << "-                                 EQUIPMENT                                   -" << endl;
	for(int i=0; i < 10; i++)
	{
		allignMessages(labEquipment[i]);
	}
	cout << "--------------------------------------------------------------------------------" << endl;		
}

int printLab() //printing menu for the room 2: Laboratory
{
	int investigateChoice;
	cout << "\n--------------------------------------------------------------------------------" << endl;
	cout << "-                                  LABORATORY                                  -" << endl;
	cout << "-     1. Desk                                                                  -" << endl;
	cout << "-     2. Lab Equipment                                                         -" << endl;
	cout << "-     3. Clock                                                                 -" << endl;
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
	cout << "-                                     DESK                                     -" << endl;
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
	cout << "-                           BACK OF THE FRAME                                  -" << endl;
	cout << "-                                                                              -" << endl;
	cout << "-     4502                                                                     -" << endl;  //renkleri unutma
	cout << "-     2356                                                                     -" << endl;
	cout << "-     2107                                                                     -" << endl;
	cout << "-     7119                                                                     -" << endl;
	cout << "-     9864                                                                     -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
}

void printLab_CompoundNotebook()
{
	cout << "\n--------------------------------------------------------------------------------" << endl;
	cout << "-                         NOTEBOOK OF COMPOUNDS                                -" << endl;
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
	cout << "-                           EXPERIMENT MATERIAL                                -" << endl;
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
	cout << "-                                 GREENHOUSE                                   -" << endl;
	cout << "-     1. Security Camera                                                       -" << endl;
	cout << "-     2. Plants                                                                -" << endl;
	cout << "-                                                                              -" << endl;
	cout << "-     0. PERSONAL NOTES                                                        -" << endl;
	cout << "-                                                                              -" << endl;
	cout << "      Choose to investigate: ";
	cin >> investigateChoice;
	return investigateChoice;
}

int checkNote(vector <Note> vec, int a){
    for (Note p : vec) {
        if (a == p.getId()){
            return 1;
        }
    }
    return 0;
}

void PersonalNotes(vector <Note> vec)
{
	cout << "\n--------------------------------------------------------------------------------" << endl;
	cout << "-      LABORATORY                                                              -" << endl;
	cout << "-                                                                              -" << endl;
	if(checkNote(vec, 21) == 1)
	{
		cout << "-      1. The clock has stopped at 3 o'clock.                                  -" << endl; 
	}
	else
	{
		cout << "-      1. ?????????                                                            -" << endl;
	}
	if(checkNote(vec, 22) == 1)
	{
		cout << "-      2. There must be a connection between the broken clock and             -\n";
		cout << "-      the compound written in the notebook.                                   -" << endl; 
	}
	else
	{
		cout << "-      2. ?????????                                                            -" << endl;
	}
	if(checkNote(vec, 23) == 1)
	{
		cout << "-      3. There are codes in different colors behind the picture.              -" << endl;	
	}
	else
	{
		cout << "-      3. ?????????                                                            -" << endl;
	}
}

int main() {

    vector <Note> personalNotes;
    Note noteLab1("The clock has stopped at 3 o'clock.", 21);
    Note noteLab2("There must be a connection between the broken clock and the compound written in the notebook.", 22);
    Note noteLab3("There are codes in different colors behind the picture", 23);

    Box boxes[10];
    char j = 'A';
    for (int i = 0; i < 10; i++) //assigning symbols to boxes
    {
    	boxes[i].setSymbol(j);
    	j++;
	}

	string labEquipment[10] = {"!!!Glasses" , "Coats" , "!Volumetric flask" , "Gloves" , "Test tube" , "Microscope" , "!!!!Funnel" , "!!Beaker" , "Magnet" , "Pipette"};
	string compounds[5] = {"1. yellow + red" , "2. blue + red" , "3. blue + yellow" , "4. brown + blue" , "5. brown + red"};
	
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
	
	/*   hikaye için yazım fikri

	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "-             Henry : What do you mean that you can not find him?!             -" << endl;
	cout << "-                                [press SPACE]                                 -" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	*/
	
	int investigateChoice;
	int checkClock = 0, checkNotebook = 0;
	
	do{
		investigateChoice = printBasement();
		if(investigateChoice == 1) //Desk
		{
			do{
				investigateChoice = printBasement_Desk();
				if(investigateChoice == 1) //Computer
				{
					printBasement_Computer();
				}
				else if(investigateChoice == 2) //Control Notebook
				{
					printBasement_ControlNotebook(labEquipment);
				}
			}while(investigateChoice >= 0 && investigateChoice < 3);
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
							personalNotes.push_back(noteLab3);
						}	
					}while(investigateChoice != 2);
				}
				else if(investigateChoice == 2) //Notebook Of Compounds
				{
					printLab_CompoundNotebook();
					checkNotebook = 1;
					if(checkClock == 1)
					{
						personalNotes.push_back(noteLab2);
					}
				}
				else if(investigateChoice == 0) //Personal Notes
				{
					PersonalNotes(personalNotes);
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
			personalNotes.push_back(noteLab1);
			checkClock = 1;
			if(checkNotebook == 1)
			{
				personalNotes.push_back(noteLab2);
			}
		}
		else if(investigateChoice == 0) //Personal Notes
		{
			PersonalNotes(personalNotes);
		}
	}while(investigateChoice >= 0 && investigateChoice <= 3);


	return 0;
}