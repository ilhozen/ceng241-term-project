#include <iostream>
#include <string>

using namespace std;

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
