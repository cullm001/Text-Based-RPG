#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>

using namespace std;

class Entity {
    protected: 
        int maxHealth;
        int currHealth;
        int defense;
        int attack;
        double critRate;

        // temporary stat buffs will be added to the Entity's true stats, they are stored so they can be subtracted later.
        int tempHealth;
        int tempAttack;
        int tempDefense;
        double tempCritRate;

    public:
        Entity(){
            maxHealth = 0;
            currHealth = 0;
            defense = 0;
            critRate = 0;
        }
        Entity(int attac, int defens, int health){
            maxHealth = health;
            currHealth = health;
            defense = defens;
            critRate = 0.5;
            //  resetTempStats();
        }


        
        int getHealth();
	    virtual int Attack() = 0;
        
        // used to get current stats for combat purposes
        int const getMaxHealth() { return maxHealth; }
        int const getCurrHealth() { return currHealth; }
        int const getDefense() { return defense; }
        int const getAttack() { return attack; }
        double const getCritRate() { return critRate; }

        // adds additional permanent stats to the character
        void addMaxHealthAndCurrHealth(int val) { maxHealth += val; currHealth += val; }
        void addMaxHealth(int val) { maxHealth += val; }
        void addCurrHealth(int val) { currHealth += val; }
        void addDefense(int val) { defense += val; }
        void addAttack(int val) { attack += val; }

        // adds temporary buffs or debuffs to the character
        void addTempHealth(int val) { maxHealth += val; currHealth += val; tempHealth += val; }
        void addTempAttack(int val) { attack += val; tempAttack += val; }
        void addTempDefense(int val) { defense += val; tempDefense += val; }
        void addTempCritRate(double val) { critRate += val; tempCritRate += val; }
    
        // removes buffs & debuffs to the character, removal of health is different
        void removeTempHealth();
        void removeTempAttack() { attack -= tempAttack; tempAttack = 0; }
        void removeTempDefense() { defense -= tempDefense; tempDefense = 0; }
        void removeTempCritRate() { critRate -= tempCritRate; critRate = 0; }
        // removes all temporary stats, not just one
        void resetTempStats();
        // the charcter take damage;
        //void takedmg(int dmg);
        void fullheal();
};

#endif
