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
private:
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
		void setcode(int code){this->code=code}
		string getcode() { return code;} 
		void opened(int A){
        if (A == 1){
            opened = true;
        }else{
            opened = false;
        }
		int check_code(string entered_code){
			if(entered_code== *******){
				return (opened(1));
			}
			else 
				return opened(0);
		}
};

class DoorLock:public Lock{
    private:
		string symbol_code;
	public:
		void setsymbol_code(char entered_symbol) { symbol_code= entered_symbol  };
		char getsymbol_code() { return symbol_code };
		
};
class ComputerLock:public Lock{
	 private:
		string symbol_code;
	public:
		void setsymbol_code(char entered_symbol) { symbol_code= entered_symbol  };
		char getsymbol_code() { return symbol_code };
		
	
};*/

int main() {
    
    Box boxes[10];
    char j = 'A';
    for (int i = 0; i < 10; i++) //assigning symbols to boxes
    {
    	boxes[i].setSymbol(j);
    	j++;
	}

	string labEquipment[10] = {"Glasses" , "Coats" , "Flask" , "Gloves" , "Test tube" , "Microscope" , "Funnel" , "Beaker" , "Magnet" , "Pipette"};
	string compounds[5] = {"yellow + red" , "blue + yellow" , "blue + red" , "green + blue" , "green + red"};
	
	

	Page controlNotebook;
	Page notebookOfCompounds;
	
	for(int i = 0 ; i < 10 ; i++){
		controlNotebook.setText(labEquipment[i]);
	}
	
	for(int i = 0 ; i < 5 ; i++){
		notebookOfCompounds.setText(compounds[i]);
	}
}
