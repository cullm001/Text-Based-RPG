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
            cout << "Health:  " << play->getplayer()->getCurrHealth() << "/" << play->getplayer()->getMaxHealth() << endl;     
            cout << "Enemy:   " << monster->getCurrHealth() << endl;
            cout << "------------------------------------\n  Attack\t\t  Bag\n  Ability\t\tRun\n-------------------------------------\n";
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
                int bob;
                cin.clear();
                cin >> bob;
                if(bob == 1){
                    pattack();
                }else if(bob == 2){
                    accessbag(); 
                }else if(bob == 3){
                    ability();
                }else{
                    run();
                }
                mattack();
        }
            cout << "You've defeated the monster!!" << endl;
            cout << "You have earned " << loot->getname() << endl;
        
        }
};

#endif //blah
