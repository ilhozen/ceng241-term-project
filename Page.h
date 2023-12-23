#include <iostream>
#include <vector>
#include <string>
#include "Item.h"

#ifndef CENG241_TERM_PROJECT_PAGE_H
#define CENG241_TERM_PROJECT_PAGE_H

using namespace std;

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


#endif //CENG241_TERM_PROJECT_PAGE_H
