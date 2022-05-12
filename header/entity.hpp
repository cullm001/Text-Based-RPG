#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>

using namespace std;

class Entity {
    private: 
        int maxHealth;
        int currHealth;
        int defense;
        int attack;
    protected:
        int tempHealth;
        int tempAttack;
        int tempDefense;
    public:
        virtual int Attack() const = 0;
        int Health();
};

#endif