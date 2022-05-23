#ifndef COMBAT_HPP
#define COMBAT_HPP

#include <string>
#include <iostream>
#include <vector>
#include "item.hpp"
#include "player.hpp"
#include "entity.hpp"
#include "Enemies/Enemy.hpp"
#include "bag.hpp"

using namespace std;

class combat {
    private:
        Enemy *monster;
        Bag *play;
        Item *loot;
    public:
        combat(Bag *p, Enemy *e, Item *l){
            play = p;
            monster = e;
            loot = l;
        }
        ~combat(){}
        int print(){
            cout << "Health:  " << play->getplayer()->getCurrHealth() << "/" << play->getplayer()->getMaxHealth() << " HP" << endl;    
            cout << "Enemy:   " << monster->getCurrHealth() << "/" << monster->getMaxHealth() << " HP" << endl;
            cout << "------------------------------------\n  1. Attack\t2. Bag\n  3. Ability\t4. Run\n-------------------------------------\n";
            int rec = 0;
        }
        void pattack(){
            int roll = play->getplayer()->Attack();
            int dmg = (roll*2)/(monster->getDefense());
            monster->takedmg(dmg);

            cout << "You attack the monster\nThe monster takes " << dmg << " damage\n";
            return;
        }
        void mattack(){
            int roll = monster->move();
            int dmg = (roll*2)/(play->getplayer()->getDefense());
            play->getplayer()->takedmg(dmg);
            if(roll > 0){
            cout << "You take " << dmg << " points of damage\n";
            }
            if(play->getplayer()->getCurrHealth() <= 0){
            cout << "You have died\n";
            exit(0);
            }
            return;
        }
        void accessbag(){
            play->print();
        }
        void run(){
            cout << "You've failed to run away\n";
        }
        void ability(){
            play->getplayer()->class_ability();
        }
        bool start(string start){
            cout << start << endl;
            while(play->getplayer()->getCurrHealth() > 0 && monster->getCurrHealth() > 0){
                print();
                int input;
                cin.clear();
                cin >> input;
                if(input == 1){
                    pattack(); // 
                }else if(input == 2){
                    accessbag(); 
                }else if(input == 3){
                    ability();
                }else{
                    run();
                }
                mattack(); // fix so that monster does not attack after dying, return false if death
        } // fix damage rolls
            cout << "You've defeated the monster!!" << endl; // fix so that you do not always win
            cout << "You have earned " << loot->getname() << endl;
        
        }
};

#endif //blah
