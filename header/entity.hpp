#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>

using namespace std;

class Entity {
    protected: 
        double maxHealth;
        double currHealth;
        double defense;
        double attack;
        double critRate;
        int level;

        // temporary stat buffs will be added to the Entity's true stats, they are stored so they can be subtracted later.
        int tempHealth;
        int tempAttack;
        int tempDefense;
        double tempCritRate;

        // tracks percentage-based stat buffs, every +1 results in a 25% increase
        int attackBoost = 0;
        int defenseBoost = 0;
        int critBoost = 0;

    public:
        Entity(){
            maxHealth = 20;
            currHealth = 20;
            attack = 13;
            defense = 10;
            critRate = 0.15;
            level = 5;
        }
        Entity(int lvl) {
            maxHealth = 12 + (lvl*2);
            currHealth = maxHealth;
            attack = 6 + (lvl*1.7);
            defense = 6 + (lvl);
            critRate = 0.15;
            level = lvl;
        }
        Entity(double atk, double def, double hth, int lvl){
            maxHealth = hth;
            currHealth = hth;
            attack = atk;
            defense = defense;
            critRate = 0.15;
            level = lvl;
            //  resetTempStats();
        }

        int getHealth();
	    double getAttackDamage();

        void levelUp(int lvl) {
            maxHealth += (lvl*2);
            currHealth = maxHealth;
            attack += (lvl*1.7);
            defense += lvl;
        }
        
        // used to get current stats for combat purposes
        double const getMaxHealth() { return maxHealth; }
        double const getCurrHealth() { return currHealth; }
        double const getDefense() { return defense * (1 + (defenseBoost*0.25)); }
        double const getAttack() { return attack * (1 + (attackBoost*0.25)); }
        double const getCritRate() { return critRate + (critBoost*0.15); }

        // adds additional permanent stats to the character
        void addMaxHealthAndCurrHealth(double val) { maxHealth += val; currHealth += val; }
        void addMaxHealth(double val) { maxHealth += val; }
        void addCurrHealth(double val) { currHealth += val; }
        void addDefense(double val) { defense += val; }
        void addAttack(double val) { attack += val; }

        // adds temporary buffs or debuffs to the character
        void addTempHealth(double val) { maxHealth += val; currHealth += val; tempHealth += val; }
        void addTempAttack(double val) { attack += val; tempAttack += val; }
        void addTempDefense(double val) { defense += val; tempDefense += val; }
        void addTempCritRate(double val) { critRate += val; tempCritRate += val; }
    
        // removes buffs & debuffs to the character, removal of health is different
        void removeTempHealth();
        void removeTempAttack() { attack -= tempAttack; tempAttack = 0; }
        void removeTempDefense() { defense -= tempDefense; tempDefense = 0; }
        void removeTempCritRate() { critRate -= tempCritRate; critRate = 0; }

        // removes all temporary stats, not just one
        void resetTempStats();

        void addAttackBoost(int val) { attackBoost += val; }
        void addDefenseBoost(int val) { defenseBoost += val; }
        void addCritBoost(int val) { critBoost += val; }

        //removes all boosts
        void resetBoosts();
        
        // the charcter takes damage;
        double takedmg(double dmg);

        // the character is fully healed;
        void fullheal() { currHealth = maxHealth + tempHealth; }
};

#endif
