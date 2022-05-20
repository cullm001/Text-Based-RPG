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
            }else if(i > baglist.size()){
                cout << "Item does not exist" << endl;
            }

            swap(baglist.at(i-1), baglist.at((baglist.size()-1)));
            baglist.pop_back();
        }
        void print(){
            if(baglist.size() == 0){
                cout << "nothing in the bag, you wasted your turn" << endl;
                return;
            }
                
            for(int i = 0; i < baglist.size(); i++){
                cout << i+1 << ": " << baglist.at(i)->getname() << endl;
            }
            int bob;
            cin >> bob;
            use(bob);
        }
        void add(Item *b){
            baglist.push_back(b);
        }
        Player* getplayer(){
            return play;
        }
};

#endif //blah
