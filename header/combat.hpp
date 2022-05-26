#ifndef COMBAT_HPP
#define COMBAT_HPP

#include <string>
#include <iostream>
#include <vector>
#include "item.hpp"
#include "player.hpp"
#include "entity.hpp"
#include "Enemies/Enemy.hpp"
#include "Enemies/Minion.hpp"
#include "Enemies/Boss.hpp"
#include "bag.hpp"
#include <cmath>

using namespace std;

class combat {
    private:
        Enemy *monster;
        Bag *play;
        Item *loot;
    public:
        combat(Bag *p, Enemy *e, Item *l) {
            play = p;
            monster = e;
            loot = l;
            srand(time(0));
        }
        ~combat(){}
        void print() {
            cout << "Health:  " << ceil(play->getplayer()->getCurrHealth()) << "/" << play->getplayer()->getMaxHealth() << " HP" << endl;    
            cout << "Enemy:   " << ceil(monster->getCurrHealth()) << "/" << monster->getMaxHealth() << " HP" << endl;
            cout << "------------------------------------\n  1. Attack\t2. Bag\n  3. Ability\t4. Run\n-------------------------------------\n";
            int rec = 0;
        }
        void pattack() {
            double dmg = play->getplayer()->getAttackDamage();
            int crit = rand() % 100;
            if (crit < (play->getplayer()->getCritRate()*100)) {
                dmg *= 1.5;
                cout << "You critically strike the " << monster->getName() << " for "<< (int) monster->takedmg(dmg) << " damage!\n";
                return;
            }
            cout << "You attack the " << monster->getName() << " for "<< (int) monster->takedmg(dmg) << " damage.\n";
            return;
        }
        void mattack() {
            double dmg = monster->move();
            int crit = rand() % 100;
            if ((crit < (monster->getCritRate()*100)) && dmg > 0) {
                dmg *= 1.5;
                cout << "It's a critical strike! ";
            }
            if(dmg > 0){
                cout << "The " + monster->getName() + " " + monster->getAttackNoise() + " you." + " You take " << (int) play->getplayer()->takedmg(dmg) << " points of damage.\n";
            } else {
                cout << monster->get_class_ability_line() << "\n" << endl;
            }
            // is this necessary?
            if(play->getplayer()->getCurrHealth() <= 0){
                cout << "You have died.\n";
                exit(0);
            }
            return;
        }
        void accessbag() {
            play->print();
        }
        void run() {
            cout << "You've failed to run away.\n";
        }
        void ability(){
            play->getplayer()->class_ability();
            cout << play->getplayer()->get_class_ability_line() << endl;
        }
        bool start(string start) {
            cout << start << endl;
            while(play->getplayer()->getCurrHealth() > 0 && monster->getCurrHealth() > 0) {
                print();
                int input;
                cin.clear();
                cin >> input;
                if(input == 1) {
                    pattack(); 
                } else if(input == 2) {
                    accessbag(); 
                } else if(input == 3) {
                    ability();
                } else {
                    run();
                }
                if (monster->getCurrHealth() > 0) {
                    mattack();
                }
                cout << endl;
            }
            if (play->getplayer()->getCurrHealth() > 0) {
                cout << "You've defeated the monster!!" << endl;
                cout << "You have earned a " << loot->getname() << ".\n" << endl;
                play->getplayer()->resetBoosts();
                play->getplayer()->resetTempStats();
                return true;
            }
            else {
                cout << "You were defeated in battle." << endl;
                return false; 
            }
        }
};

#endif //blah
