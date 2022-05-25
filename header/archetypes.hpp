#ifndef ARCHETYPES_HPP
#define ARCHETYPES_HPP

#include "player.hpp"
#include "Weapon/weapon.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Paladin : public Player {
    public:
        Paladin() : Player() {
            Weapon* flimsySword = new Weapon("Flimsy Sword", 1, "slashes");
            equip(flimsySword);
        }
        void class_ability() {
            this->addDefenseBoost(1);
        }
        string get_class_ability_line() {
            return "You call upon the heavens to protect you. A divine shield bolsters your defense.";
        }
};

class Wizard : public Player {
    public:
        Wizard() : Player() {
            Weapon* moldyStaff = new Weapon("Moldy Staff", 1, "blasts");
            equip(moldyStaff);
        }
        void class_ability() {
            srand(time(0));
            int choice = rand() % 3;
            if (choice == 0) { this->addAttackBoost(2); }
            if (choice == 1) { this->addDefenseBoost(2); }
            if (choice == 2) { this->addCritBoost(2); }
        }
        string get_class_ability_line() {
            return "You channel your magic into the air, and feel a tingling sensation. You feel more powerful but you're not sure how.";
        }
};

class Archer : public Player {
    public:
        Archer() : Player() {
            Weapon* brittleBow = new Weapon("Brittle Bow", 1, "shoots");
            equip(brittleBow);
        }
        void class_ability() {
            this->addCritBoost(1);
        }
        string get_class_ability_line() {
            return "You meditate for a moment and your focus sharpens greatly. Your crit rate has increased.";
        }
};

class Cleric : public Player {
    private:

    public:
        Cleric() : Player() {
            Weapon* rustyMace = new Weapon("Rusty Mace", 1, "smashes");
            equip(rustyMace);
        }
        void class_ability() {
            this->addCurrHealth(this->getMaxHealth()*0.25);
        }
        string get_class_ability_line() {
            return "You clasps your hands together and pray. You receive a heal of " + to_string((this->getMaxHealth()*0.25)) + "health.";
        }
};

class Barbarian : public Player {
    public:
        Barbarian() : Player() {
            Weapon* woodenHammer = new Weapon("Wooden Hammer", 1, "bonks");
            equip(woodenHammer);
        }
        void class_ability() {
            this->addAttackBoost(1);
        }
        string get_class_ability_line() {
            return "You shout towards the sky and enter a rage. You feel stronger.";
        }
};

#endif