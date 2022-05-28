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
        play = nullptr; 
        }
        Bag(Player* p) {
            play = p;
        }
        ~Bag(){}
        
        void use(int i){
            if(i > 0){
                int index = i - 1;
                baglist.at(index)->use(play);
            }else if(i > baglist.size()){
                cout << "The item does not exist." << endl;
            }

            swap(baglist.at(i-1), baglist.at((baglist.size()-1)));
            baglist.pop_back();
        }
        void print(){
            if(baglist.size() == 0){
                cout << "There is nothing in your bag, you wasted your turn" << endl;
                return;
            }
            cout << endl;
            cout << "Bag contents:" << endl;   
            for(int i = 0; i < baglist.size(); i++){
                cout << i+1 << ": " << baglist.at(i)->getname() << endl;
            }
            int bob = baglist.size();
            while(bob >= baglist.size()) {
                cout << "Which item would you like to use, please type the number corresponding to the specific item." << endl;
                cout << "> ";
                cin >> bob;
                if(bob <= baglist.size()) {
		    use(bob);
                    return;
		}
                else {
		    cout << "Sorry there is no item corresponding to the number you entered" << endl;
		}
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
