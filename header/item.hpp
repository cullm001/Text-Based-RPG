#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
class Item {
    private:
        string name;
        int value;
        int effect;
    public:
        Item(string n, int v, int e);
        int use();//In the future this use will have the player obejct in it so it can modify it
        void print(); //print the description
};

#endif // RECTANGLE_HPP
