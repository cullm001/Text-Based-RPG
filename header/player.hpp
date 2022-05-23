#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.hpp"
#include "Weapon/weapon.hpp"

using namespace std;
class Player : public Entity {
    protected:
        Weapon* weapon;
    public:
        Player(); //we'll put weapons here later
        void levelUp();
        int Attack();
        void takedmg(int i) {
            currHealth = currHealth - i;
            return;
        }
        virtual void class_ability();
        void heal() { currHealth = maxHealth; }
        void heal(int val) {
            currHealth += val;
            if (currHealth > maxHealth) { currHealth = maxHealth; }
        }
};

#endif
