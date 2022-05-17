#ifndef COMBAT_HPP
#define COMBAT_HPP

#include <string>
#include <iostream>
#include <vector>
#include "item.hpp"
#include "player.hpp"
#include "Enemies/Enemy.hpp"


using namespace std;

class combat {
    private:
        Enemy *monster;
        Player *play;
        Item *loot;
    public:
        combat(Player *p, Enemy *e, Item *l){
            play = p;
            monster = e;
            loot = l;
        }
        ~combat(){}
        int print(){
            cout << "-------------------------\n      Attack          Bag\n      Ability          Run\n";
            int rec = 0;
            cin >> rec;
            return rec;
        }
};

#endif //blah
