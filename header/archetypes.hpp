#ifndef ARCHETYPES_HPP
#define ARCHETYPES_HPP

#include "player.hpp"
#include "Weapon/weapon.hpp"

using namespace std;

class Paladin : public Player {
    public:
        Paladin() : Player() {
            Weapon* flimsySword = new Weapon("Flimsy Sword", 1, "slashes");
            this->weapon = flimsySword;
        }
        void class_ability() {
            this->addDefense(3);
            return;
        }
};

class Wizard : public Player {
    public:
        Wizard() : Player() {
            Weapon* moldyStaff = new Weapon("Moldy Staff", 1, "blasts");
            this->weapon = moldyStaff;
        }
        void class_ability() {
            this->addAttack(1);
            this->addDefense(1);
            this->addMaxHealth(1);
            return;
        }
};

class Archer : public Player {
    public:
        Archer() : Player() {
            Weapon* brittleBow = new Weapon("Brittle Bow", 1, "shoots");
            this->weapon = brittleBow;
        }
        void class_ability() {
            this->addTempCritRate(0.25);
        }
};

class Cleric : public Player {
    private:

    public:
        Cleric() : Player() {
            Weapon* rustyMace = new Weapon("Rusty Mace", 1, "smashes");
            this->weapon = rustyMace;
        }
        void class_ability() {
            this->addCurrHealth(3);
        }
};

class Barbarian : public Player {
    public:
        Barbarian() : Player() {
            Weapon* woodenHammer = new Weapon("Wooden Hammer", 1, "bonks");
            this->weapon = woodenHammer;
        }
        void class_ability() {
            this->addTempAttack(3);
        }
};

#endif