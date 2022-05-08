#include <iostream>
#include <string>
#include "../header/item.hpp"

using namespace std;

Item::Item(string n, string d, int v, int e){
    name = n;
    description = d;
    value = v;
    effect = e;
}

int Item::use(){
        cout  << name << endl;
        return 0;
        //this is temparay until someone makes the charcter class
}

void Item::print(){
    cout << "Name: " << name << endl;
    cout << "Effect: " << description << endl;      
}
