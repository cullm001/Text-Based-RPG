#ifndef ARCHETYPES_HPP
#define ARCHETYPES_HPP

#include "player.hpp"

using namespace std;

class Rogue : public Player {
    public:
        void Rogue::class_ability() {
            // incomplete
            return;
        }
};

class Wizard : public Player {
    public:
        void Wizard::class_ability() {
            // incomplete
            return;
        }
};

class Archer : public Player {
    public:
        void Archer::class_ability() {
            this->addTempCritRate(0.5);
        }
};

class Cleric : public Player {
    private:

    public:
        void Cleric::class_ability() {
            this->addCurrHealth(3);
        }
};

class Barbarian : public Player {
    private:

    public:
        void Barbarian::class_ability() {
            this->addTempAttack(3);
        }
};

#endif