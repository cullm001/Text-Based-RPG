#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.hpp"
#include "Weapon/weapon.hpp"

using namespace std;
class Player : public Entity {
    private:
        string attackNoise = "punches";
        void setAttackNoise(string an) { attackNoise = an; }
    protected:
        Weapon* weapon = nullptr;
    public:
        Player(); //we'll put weapons here later
        Player(int lvl);
        Player(double a, double d, double h, int l);
        void equip(Weapon* wep);
        string getAttackNoise() { return attackNoise; }
        virtual void class_ability() = 0;
        virtual string get_class_ability_line() = 0;
};

#endif
