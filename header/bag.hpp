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
        
        string use(int i){
            string output;
            if(i > 0){
                int index = i - 1;
                output = baglist.at(index)->use(play);
                swap(baglist.at(i-1), baglist.at((baglist.size()-1)));
                baglist.pop_back();
            }else if(i > baglist.size()){
                output = "The item does not exist.";
            }

            return output;
        }
        void print(){
            if(baglist.size() == 0){
                cout << "There is nothing in your bag." << endl;
                return;
            }
            cout << endl;
            cout << "Bag contents:" << endl;   
            for(int i = 0; i < baglist.size(); i++){
                cout << i+1 << ": " << baglist.at(i)->print() << endl;
            }
            int bob = baglist.size();
            while(bob >= baglist.size()) {
                cout << "Which item would you like to use, please type the number corresponding to the specific item." << endl;
                cout << "> ";
                cin >> bob;
                if(bob <= baglist.size()) {
		            cout << use(bob) << endl;
                    return;
		}
                else {
		    cout << "There is no item corresponding to the number you entered" << endl;
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
