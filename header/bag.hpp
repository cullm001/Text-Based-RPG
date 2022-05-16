#ifndef BAG_HPP
#define BAG_HPP

#include <string>
#include <iostream>
#include <vector>
#include "item.hpp"
#include "player.hpp"

using namespace std;

class Bag {
    private:
        vector<Item*> baglist;
        Player *play;
    public:
        Bag(){
        play = new Player(); 
        }
        ~Bag(){}
        
        void use(int i){
            if(i > 0){
                int index = i - 1;
                baglist.at(index)->use(play);
            }
        }
        void print(){
            for(int i = 0; i < baglist.size(); i++){
                cout << i+1 << ": " << baglist.at(i)->getname() << endl;
            }
        }
        void add(Item *b){
            baglist.push_back(b);
        }
        Player* getplayer(){
            return play;
        }
};

#endif //blah
