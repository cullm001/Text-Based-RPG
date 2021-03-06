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
        int tempHealth = 0;
        int tempAttack = 0;
        int tempDefense = 0;
        double tempCritRate = 0;

        // tracks percentage-based stat buffs, every +1 results in a 25% increase
        int attackBoost = 0;
        int defenseBoost = 0;
        int critBoost = 0;

    public:
        // constructors 
        Entity();
        Entity(int lvl);
        Entity(double atk, double def, double hth, int lvl);

	    double getAttackDamage(); // get the damage the character would cause
        double takedmg(double dmg); // the charcter takes damage;
        void fullheal() { currHealth = maxHealth; } // the character is fully healed;
        void heal(double val); // the character is partially healed
        void levelUp(int lvl); // the character is levelled up
        bool isBoosted(); // checks if the entity has any stat boosting effects
        
        // used to get current stats for combat purposes
        double const getMaxHealth() { return maxHealth; }
        double const getCurrHealth() { return currHealth; }
        double const getDefense() { return defense * (1 + (defenseBoost*0.5)); }
        double const getAttack() { return attack * (1 + (attackBoost*0.5)); }
        double const getCritRate() { return critRate + (critBoost*0.15); }
        int const getLevel() { return level; }

        // adds additional permanent stats to the character
        void addMaxHealthAndCurrHealth(double val) { maxHealth += val; currHealth += val; }
        void addMaxHealth(double val) { maxHealth += val; }
        void addCurrHealth(double val) { currHealth += val; }
        void addDefense(double val) { defense += val; }
        void addAttack(double val) { attack += val; }
        void addCritRate(double val) { critRate += val; }

        // adds temporary buffs or debuffs to the character
        void addTempHealth(double val) { maxHealth += val; currHealth += val; tempHealth += val; }
        void addTempAttack(double val) { attack += val; tempAttack += val; }
        void addTempDefense(double val) { defense += val; tempDefense += val; }
        void addTempCritRate(double val) { critRate += val; tempCritRate += val; }
    
        // removes buffs & debuffs to the character, removal of health is different
        void removeTempHealth();
        void removeTempAttack() { attack -= tempAttack; tempAttack = 0; }
        void removeTempDefense() { defense -= tempDefense; tempDefense = 0; }
        void removeTempCritRate() { critRate -= tempCritRate; tempCritRate = 0; }

        // removes all temporary stats, not just one
        void resetTempStats();

        // add boosts to stats, % based increases
        void addAttackBoost(int val) { attackBoost += val; }
        void addDefenseBoost(int val) { defenseBoost += val; }
        void addCritBoost(int val) { critBoost += val; }

        //removes all boosts
        void resetBoosts();
};

#endif
