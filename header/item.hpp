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

class HealthPot: public Item
{
    public:
        HealthPot() : Item("Healing Potion", "When taken, a small angel pops out and sings a song to heal the user.", 5) {}
        HealthPot(string n, string d, int v = 5) : Item (n, d, v) {}
        string use(Player *&p){
            int healAmount = value * 0.05 * p->getMaxHealth(); // 5% of max health per value of the potion
            p->heal(healAmount);
            return "You used a healing potion. You restored " + to_string(healAmount) + " health.";
        }
};

class StrengthPot: public Item
{
    public:
        StrengthPot() : Item("Strength Potion", "When taken, the user feels a slight boost to their strength", 1) {}
        StrengthPot(string n, string d, int v = 1) : Item (n, d, v) {}
        string use(Player *&p){
           p->addAttackBoost(value);
           return "You used an strength potion. You temporarily boosted your attack.";
        }
};

class LuckPot : public Item
{
    public:
        LuckPot() : Item("Luck Potion", "When taken, the user will critically strike more often.", 1) {}
        LuckPot(string n, string d, int v = 1) : Item (n, d, v) {}
        string use(Player *&p){
           p->addCritBoost(value);
           return "You used an luck potion. You temporarily boosted your crit rate.";
        }
};

#endif //blah
