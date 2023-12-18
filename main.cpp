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

    string getString() const {return hint;}

    int getId() const {return id;}
};

void allignMessages(string text)
{
	int space, counter;
	for(counter = 1; counter <= 5; counter++)
	{
		cout << " ";
	}
	cout << text;
	space = 45 - text.length();
	for(counter = 1; counter <= space; counter++)
	{
		cout << " ";
	}
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
	cout << "-     1. Picture                                                               -" << endl;
	cout << "-     2. Notebook                                                              -" << endl;
	cout << "-     3. Return Back                                                           -" << endl;
	cout << "-                                                                              -" << endl;
	cout << "-     0. PERSONAL NOTES                                                        -" << endl;
	cout << "-                                                                              -" << endl;
	cout << "      Choose to investigate: ";
	cin >> investigateChoice;
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
	
	do{
		investigateChoice = printBasement();
		if(investigateChoice == 1) //Desk
		{
			do{
				investigateChoice = printBasement_Desk();
				if(investigateChoice == 1) //Computer
				{
					cout << "\n--------------------------------------------------------------------------------" << endl;
					cout << "-     Enter the password:                                                      -" << endl;
					cout << "-                                                                              -" << endl;
					cout << "-     'Looks like i need to find the password to access camera records...'     -" << endl;
					cout << "--------------------------------------------------------------------------------" << endl; 
				}
				else if(investigateChoice == 2) //Control Notebook
				{
					cout << "\n--------------------------------------------------------------------------------" << endl;
					cout << 
				}
			}while(investigateChoice >= 0 && investigateChoice <= 3);
		}
	}while(investigateChoice >= 0 && investigateChoice <= 3);
	
	do{
		investigateChoice = printLab();
		if(investigateChoice == 1)
		{
			do{
				investigateChoice = printLab_Desk();
			}while(investigateChoice >= 0 && investigateChoice <= 3);
		}
	}while(investigateChoice >= 0 && investigateChoice <= 3);

	do{
		investigateChoice = printGreenhouse();
	}while(investigateChoice >= 0 && investigateChoice <= 2);
	
}
