#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.hpp"
#include "Weapon/weapon.hpp"

using namespace std;
class Player : public Entity {
    private:
        string archetype = "Default";
    protected:
        Weapon* weapon = nullptr;
    public:
        Player(); //we'll put weapons here later
        ~Player(){
            delete weapon;
        }
        Player(int lvl);
        Player(double a, double d, double h, int l);
        void equip(Weapon* wep);
        void setArchetype(string i) { archetype = i; }
        string getArchetype() { return archetype; }
        Weapon* getWeapon() { return weapon; }
        virtual void class_ability() = 0;
        virtual string get_class_ability_line() = 0;
        virtual void equipFirstWeapon() = 0;
};

#endif
