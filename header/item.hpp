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
        int value;
    public:
        Item();
        Item(string nm, string des, int val);
        virtual string use(Player *&p) = 0;
        string print() { return name + ", " + description; }
        virtual ~Item() = default;
        string getname() { return name; }
};

class healthpot: public Item
{
    public:
        healthpot() : Item("Healing Potion", "When taken, a small angel pops out and sings a song to heal the user.", 5) {}
        healthpot(string n, string d, int v = 5) : Item (n, d, v) {}
        string use(Player *&p){
            int healAmount = value * 0.05 * p->getMaxHealth(); // 5% of max health per value of the potion
            p->heal(healAmount);
            return "You used a healing potion. You restored " + to_string(healAmount) + " health.";
        }
};

class strengthpot: public Item
{
    public:
        strengthpot() : Item("Strength Potion", "When taken, the user feels a slight boost to their strength", 1) {}
        strengthpot(string n, string d, int v = 1) : Item (n, d, v) {}
        string use(Player *&p){
           p->addAttackBoost(value);
           return "You used an strength potion. You temporarily boosted your attack.";
        }
};

class luckpot : public Item
{
    public:
        luckpot() : Item("Luck Potion", "When taken, the user will critically strike more often.", 1) {}
        luckpot(string n, string d, int v = 1) : Item (n, d, v) {}
        string use(Player *&p){
           p->addCritBoost(value);
           return "You used an luck potion. You temporarily boosted your crit rate.";
        }
};

#endif //blah
