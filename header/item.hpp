#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using namespace std;

class Item {
    private:
        string name;
        string description;
        int value;
        int effect;
    public:
        Item(string n, string d, int v, int e);
        int use();//In the future this use will have the player obejct in it so it can modify it
        void print(); //print the description
};

#endif //blah
