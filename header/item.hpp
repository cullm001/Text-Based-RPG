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
        virtual void use(Player *&p) = 0;//In the future this use will have the player obejct in it so it can modify it
        void print(); //print the description
        virtual ~Item() = default;
        string getname(){
            return name;
        }
};
class healthpot: public Item
{
    private:
        int value;
    public:
        ~healthpot(){}
        healthpot(string n, string d, int v){
            name = n;
            description = d;
            value = v;
        }
        void use(Player *&p){
           p->heal(5);
        }
};
class dmgpot: public Item
{
     private:
        int value;
    public:
        ~dmgpot(){}
        dmgpot(string n, string d, int v){
            name = n;
            description = d;
            value = v;
        }
        void use(Player *&p){
           p->addTempAttack(5);
        }
};

#endif //blah
