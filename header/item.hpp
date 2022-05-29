#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include "entity.hpp"
#include "player.hpp"


using namespace std;

class Item {
    protected:
        string name;
        string description;
    public:
        Item();
        Item(string nm, string des);
        virtual void use(Player *&p) = 0;
        string print() { return name + ", " + description; }
        virtual ~Item() = default;
        string getname() { return name; }
};

class healthpot: public Item
{
    private:
        int value;
    public:
        healthpot(string n, string d, int v) : Item (n, d) { value = v; }
        void use(Player *&p){
           cout << "You used a healing potion" << endl;
           p->heal(5);
        }
};

class strengthpot: public Item
{
     private:
        int value;
    public:
        strengthpot(string n, string d, int v) : Item (n, d) { value = v; }
        void use(Player *&p){
           cout << "You used a strength potion" << endl;
           p->addTempAttack(5);
        }
};

#endif //blah
