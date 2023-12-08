#include <iostream>
#include <string>

using namespace std;
const string COMPOUNDCOLOR = "TEMP_COLOR";

class Item //Class for the items we will use
{
	private:
		string Name;
	public:
		void setName(string name) { Name = name; }  // !!! set name de koydum bu classlara ki değerleri alabilelim
		string getName() { return Name; } 
};

class Box: public Item //Sub-class of Item: Box
{
	private:
		char Symbol; //each of box has its own symbol
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

int main() {
    
    Box boxes[10];
    char j = 'A';
    for (int i = 0; i < 10; i++) //assigning symbols to boxes
    {
    	boxes[i].setSymbol(j);
    	j++;
	}

    
    
    return 0;
}
