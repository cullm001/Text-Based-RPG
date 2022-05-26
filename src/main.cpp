#include <iostream>
#include "../header/item.hpp"
#include "../header/archetypes.hpp"
#include "../header/bag.hpp"
#include "../header/combat.hpp"
#include "../header/entity.hpp"
#include "../header/player.hpp"
#include "../header/item.hpp"
#include "../header/Enemies/Boss.hpp"
#include "../header/Enemies/Minion.hpp"
#include "../header/Enemies/Enemy.hpp"
#include "../header/Weapon/weapon.hpp"

using namespace std;

Player* archetype_choice();
void story(Player*, Bag);
void print_base_stats(Bag);


int main()
{
    string anyKey;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << "|                                                         |" << endl;
    cout << "|                                                         |" << endl;
    cout << "|                Gary Goomba's Labyrinth                  |" << endl;
    cout << "|                                                         |" << endl;
    cout << "|                                                         |" << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << endl;
    cout << "Press any key to continue . . ." << endl;
    cin >> anyKey;
    system("clear");
    
    Player* adventurer = archetype_choice();
    Bag inventory(adventurer);

    cout << "Press any key to continue . . ." << endl;
    cin >> anyKey;
    system("clear");

    story(adventurer, inventory);

    return 0;
}

Player* archetype_choice() {
    string choice;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << "|               Archetypes                |" << endl;
    cout << "|                                         |" << endl;
    cout << "|  [1] Barbarian           [2] Wizard     |" << endl;
    cout << "|  [3] Archer              [4] Cleric     |" << endl;
    cout << "|               [5] Paladin               |" << endl;
    cout << "|                                         |" << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << endl;
    while(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5") {
        cout << "Select the Archetype of your liking" << endl;
        cout << "> ";
	cin >> choice;
        cout << endl;
        if(choice == "1") {
	    cout << "You have selected the Barbarian class!" << endl;
            Player* adventurer = new Barbarian();
            return adventurer;
        }
	else if(choice == "2") {
	    cout << "You have selected the Wizard class!" << endl;
            Player* adventurer = new Wizard();
            return adventurer;
        }
        else if(choice == "3") {
	    cout << "You have selected the Archer class!" << endl;
            Player* adventurer = new Archer();
            return adventurer;
        }

        else if(choice == "4") {
	    cout << "You have selected the Cleric class!" << endl;
            Player* adventurer = new Cleric();
            return adventurer;
        }

        else if(choice == "5") {
	    cout << "You have selected the Paladin class!" << endl;
            Player* adventurer = new Paladin();
            return adventurer;
        }
        else {
            cout << "Sorry that's not a valid choice, please type in the number corresponding to the archetype" << endl;
	}
    }
}

void story(Player* adventurer, Bag inventory) {
    string decision = "";


    healthpot heal("healing potion", "When taken, a small angel pops out and sings a song", 1);
    inventory.add(&heal);
    cout << "You have entered the infamous dungeon and are presented to 2 dark paths to the left and to the right. Which one would you choose? (l/r)" << endl;

    while(decision != "l" && decision != "r") {
        cout << "> ";
	cin >> decision;
	if(decision == "l") {
            dmgpot dmg("strength potion", "When taken the user feels a slight boost to their muscles", 1);
	    Minion goblin = GoblinMinion(7, 5, 8, 2);
            combat fight(&inventory, &goblin, &dmg);
            inventory.add(&dmg);         
            print_base_stats(inventory);
            fight.start("From the shadows, a goblin charges at you!");
	}
        else if(decision == "r") {
            healthpot heal("healing potion", "When taken, a small angel pops out and sings a song", 1);
            Minion skeleton(10, 4, 7, "skeleton");
	    inventory.add(&heal);
            combat fight_two(&inventory, &skeleton, &heal);
            print_base_stats(inventory);
            fight_two.start("A skeleton speedily approaches you!");
            
	}
        else {
	    cout << "Sorry that's not a valid choice, please type in 'l' for left or 'r' for right" << endl;
        }
    }


}

void print_base_stats(Bag inventory) {
    cout << "Health - " <<  inventory.getplayer()->getCurrHealth() << "/" << inventory.getplayer()->getMaxHealth() << endl;
    cout << "Attack - " << inventory.getplayer()->getAttack() << endl;
    cout << "Defense - " << inventory.getplayer()->getDefense() << endl;
}





