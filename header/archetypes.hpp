#ifndef ARCHETYPES_HPP
#define ARCHETYPES_HPP

#include "player.hpp"
#include "Weapon/weapon.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class TestArchetype : public Player {
    public:
        TestArchetype() : Player() { equipFirstWeapon(); setArchetype("Testing"); }
        TestArchetype(int lvl) : Player(lvl) { equipFirstWeapon(); setArchetype("Testing"); }
        void class_ability() {}
        string get_class_ability_line() {
            return "Success";
        }
        void equipFirstWeapon() {
            Weapon* testWeapon = new Weapon("Test Weapon", 5, "Test Noise", "Common");
            equip(testWeapon);
        }
};

class Paladin : public Player {
    public:
        Paladin() : Player() { equipFirstWeapon(); setArchetype("Paladin"); }
        Paladin(int lvl) : Player(lvl) { equipFirstWeapon(); setArchetype("Paladin"); }
        void class_ability() {
            this->addDefenseBoost(1);
        }
        string get_class_ability_line() {
            return "You call upon the heavens to protect you. A divine shield bolsters your defense.";
        }
        void equipFirstWeapon() {
            Weapon* flimsySword = new Weapon("Sword", 5, "slash", "Common");
            equip(flimsySword);
        }
};

class Wizard : public Player {
    public:
        Wizard() : Player() { equipFirstWeapon(); setArchetype("Wizard"); }
        Wizard(int lvl) : Player(lvl) { equipFirstWeapon(); setArchetype("Wizard"); }
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
        void equipFirstWeapon() {
            Weapon* moldyStaff = new Weapon("Staff", 5, "zap", "Common");
            equip(moldyStaff);
        }
};

class Archer : public Player {
    public:
        Archer() : Player() { equipFirstWeapon(); setArchetype("Archer"); }
        Archer(int lvl) : Player(lvl) { equipFirstWeapon(); setArchetype("Archer"); }
        void class_ability() {
            this->addCritBoost(1);
        }
        string get_class_ability_line() {
            return "You meditate for a moment and your focus sharpens greatly. Your crit rate has increased.";
        }
        void equipFirstWeapon() {
            Weapon* brittleBow = new Weapon("Bow", 5, "shoot", "Common");
            equip(brittleBow);
        }
};

class Cleric : public Player {
    public:
        Cleric() : Player() { equipFirstWeapon(); setArchetype("Cleric"); }
        Cleric(int lvl) : Player(lvl) { equipFirstWeapon(); setArchetype("Cleric"); }
        void class_ability() {
            this->heal(this->getMaxHealth()*0.25);
        }
        string get_class_ability_line() {
            return "You clasps your hands together and pray. You receive a heal of " + to_string((int)(this->getMaxHealth()*0.25)) + " health.";
        }
        void equipFirstWeapon() {
            Weapon* rustyMace = new Weapon("Mace", 5, "smite", "Common");
            equip(rustyMace);
        }
};

class Barbarian : public Player {
    public:
        Barbarian() : Player() { equipFirstWeapon(); setArchetype("Barbarian"); }
        Barbarian(int lvl) : Player(lvl) { equipFirstWeapon(); setArchetype("Barbarian"); }
        void class_ability() {
            this->addAttackBoost(1);
        }
        string get_class_ability_line() {
            return "You shout towards the sky and enter a rage. You feel stronger.";
        }
        void equipFirstWeapon() {
            Weapon* woodenHammer = new Weapon("Hammer", 5, "smash", "Common");
            equip(woodenHammer);
        }
};

#endif
