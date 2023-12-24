#include "projectfun.h"

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

void printGameEnd()
{
    cout << "--------------------------------------------------------------------------------" << endl;
    centeredMessage("[...CAMERA RECORDS...]");
    cout << "-                                                                              -" << endl;
    centeredMessage("(While Patrick is struggling to breathe on the ground,");
    centeredMessage("Henry crouches next to him and looks at his father.)");
    cout << "-                                                                              -" << endl;
    alignMessages("HENRY: This is the medicine that your favorite son Jack found, Dad...    -\n"
                  "-            Unless you count what I added to it.                              ");
    cout << "-                                                                              -" << endl;
    alignMessages("PATRICK: Henry (cough) but I've always loved you, son--");
    cout << "-                                                                              -" << endl;
    alignMessages("HENRY: Even when you're on the brink of death, you're lying, Dad!");
    alignMessages("       So be quiet and listen to the fun part: You know that once they   -\n"
                  "-            see the drug Jack found in your body, your beloved son will       -\n"
                  "-            be in prison for the rest of his life, right? What about          -\n"
                  "-            me, your son that you never loved and don't care about?           -\n"
                  "-            I will start living the best years of my life!                    ");
    cout << "-                                                                              -" << endl;
    alignMessages("PATRICK: Henry... son, you... how could you do this?");
    cout << "-                                                                              -" << endl;
    centeredMessage("(Now Patrick lies motionless on the ground.)");
    centeredMessage("(Henry cannot control his tears and stands over ");
    centeredMessage("his father for a while longer.) ");
}

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
    cout << "-                                                                              -\n";
    centeredMessage("APRIL ");
    centeredMessage("--------------------------");
    centeredMessage("Mo  Tu  We  Th  Fr  Sa  Su");
    cout << "-                        ";
    for(int i=1; i<=30; i++)
	{
		if(i == 12)
            {
                SetConsoleTextAttribute(console, 4);
                cout << "  " << i;
                SetConsoleTextAttribute(console, 7);
            }
        else if(i % 7 == 0)
		{
			if(i / 10 == 0)
			{
				cout << "   " << i << "                          -\n";
				cout << "-                        ";
			}
			else if(i / 10 != 0)
			{
				cout << "  " << i << "                          -\n";
				cout << "-                        ";
			}
		}
		else if(i / 10 == 0)
		{
			cout << "   " << i;
		}
		else if(i / 10 != 0)
		{
			cout << "  " << i;
		}
	}
	cout << "                                              -\n";
	centeredMessage("--------------------------");
	cout << "-                                                                              -\n";
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
    cout << "Type '*' to Continue: ";
    cin >> cont;
}

string printLab_Door()
{
    string password;
    cout << "\n--------------------------------------------------------------------------------" << endl;
    cout << "      Enter the password to enter the Greenhouse: ";
    cin >> password;
    return password;
}

void combine(int mat1, int mat2){
    if(mat1 == 1 && mat2 == 3 || mat2 == 1 && mat1 == 3){
        cout << "      You have combined Dinitrogen Monoxide and Silicon Dioxide.\n      It turned Green." << endl;
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
            char cont;
            cout << "\n      You poured the compound on the plant." << endl;
            cout << "      The plant turned turquoise." << endl;
            cout << "\n      The plant's 5 leaves finally remind you of the final digit of the " <<endl;
            cout << "      computer password." <<endl;
            *finish = 1;
            centeredMessage("[press '*'] ");
            cin >> cont;
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