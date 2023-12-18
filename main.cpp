#include <iostream>
#include <string>
#include <vector>

using namespace std;
const string COMPOUNDCOLOR = "TEMP_COLOR";

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

void combine(ExperimentMaterial mat1, ExperimentMaterial mat2){
    if(mat1.getName()== "TEMP_NAME" && mat2.getName()=="TEMP_NAME" || mat2.getName()== "TEMP_NAME" && mat1.getName()=="TEMP_NAME"){
        cout << "You have combined " << mat1.getName() << "and " << mat2.getName() << ". It turned " << COMPOUNDCOLOR << endl;
    }else{
        cout << "This doesn't seem like the correct formula, I should check the notes to be sure.." << endl;
        mat1.setUsed(0);
        mat2.setUsed(0);
    }
}

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

int checkNote(vector <Note> vec, int a){
    for (Note p : vec) {
        if (a == p.getId()){
            return 1;
        }
    }
    return 0;
}

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
	cout << "-                                 EQUIPMENTS                                   -" << endl;
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
	cout << "-     2. Lab Equipments                                                        -" << endl;
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

int printGreenhouse() //printing menu for room 3 : Greenhouse
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

int main() {

    vector<Note> personalNotes;
    Note note1("Test Note 1", 1);
    Note note2("Test Note 2", 2);
    Note note3("Test Note 3", 3);
    Note note4("Test Note 4", 4);
    Note note5("Test Note 5", 5);
    personalNotes.push_back(note1);
    personalNotes.push_back(note3);
    personalNotes.push_back(note4);

    for(int i = 1; i<=5; i++){
        cout << "Is Note " << i << " in the vector: " << checkNote(personalNotes, i) << endl;
    }

    Box boxes[10];
    char j = 'A';
    for (int i = 0; i < 10; i++) //assigning symbols to boxes
    {
    	boxes[i].setSymbol(j);
    	j++;
	}

	string labEquipment[10] = {"!!!Glasses" , "Coats" , "!Volumetric flask" , "Gloves" , "Test tube" , "Microscope" , "!!!!Funnel" , "!!Beaker" , "Magnet" , "Pipette"};
	string compounds[5] = {"yellow + red" , "blue + yellow" , "blue + red" , "green + blue" , "green + red"};
	
	

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
	
	/*do{
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
	
	do{
		investigateChoice = printLab();
		if(investigateChoice == 1)
		{
			do{
				investigateChoice = printLab_Desk();
				if(investigateChoice == 1) //Picture Frame
				{
					investigateChoice = printLab_PictureFrame();
				}
				else if(investigateChoice == 2) //Notebook Of Compounds
				{
					
				}
			}while(investigateChoice >= 0 && investigateChoice < 3);
		}
	}while(investigateChoice >= 0 && investigateChoice <= 3);

	do{
		investigateChoice = printGreenhouse();
	}while(investigateChoice >= 0 && investigateChoice <= 2);
*/
return 0;
}