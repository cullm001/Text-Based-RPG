#include <iostream>
#include <cstdlib>
#include <ctime>
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
void print_level_up(Bag);
Enemy* check_enemy(string, int);

const int size = 3;
const int size_prompt = 1;
const string prompt[10] = {
    "You have defeated your first enemy and continue to explore the dungeon. There appears a dimly lit path to the left and a shiny path to the right. Which one will you explore (l/r)",
};

//Using i*2+1 to access left child and i*2+2 to access right child
const string choices[100] = {
    "You have entered the infamous dungeon and as you traverse the dungeon you stumble across 2 dark paths to the left and to the right. Which one will you choose? (l/r)", 
    "You have chosen the left path and you hear a faint shhhhhh sound",
    "You have decided to take the right path and you see something jumping",
    "You explore the left path and realize that you are hungry. Coincidently, a medium-sized chicken approaches you, but something bizarre occurs",
    "You decided to venture the right path. As you keep surveilling you feel an immense presence and something running towards you"
    "You have chosen the left path and you feel a small shake as if something heavy was jumping",
    "You chose to proceed to the right path and you yearn for some food. A chicken walks up to you"
}; 




int main()
{
    system("clear");
    string anyKey;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << "|                                                 |" << endl;
    cout << "|               Gary Goomba's Dungeon             |" << endl;
    cout << "|                                                 |" << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << endl;
    while(anyKey != "1" && anyKey != "2") {
        cout << "[1] Play\n[2] Exit" << endl;
        cout << ">";
        cin >> anyKey;
        if(anyKey == "1") break;
        else if(anyKey == "2") exit(0);
        else cout << "Sorry that is an invalid option, please type '1' to play and '2' to quit" << endl;
    }

    system("clear");
    
    Player* adventurer = archetype_choice();
    Bag inventory(adventurer);

    cout << "Press any key and enter to continue . . ." << endl;
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
    cout << "|              [5] Paladin                |" << endl;
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
    string anyKey;
    
    int fightCounter = 0; //Level up after 1 fight, then level up after 2 fights, and so on
    int levelTrigger = 1;
    int promptCounter = 0;

    dmgpot dmg("strength potion", "When taken the user feels a slight boost to their muscles", 1);
    healthpot heal("healing potion", "When taken, a small angel pops out and sings a song", 1);
    inventory.add(&heal);

    cout << choices[0] << endl;
	
    for(unsigned int i = 0; i < size;) {
	while(decision != "l" && decision != "r") {
            cout << "> ";
	    cin >> decision;
	    if(decision == "l") {
                Enemy* goblin = new GoblinMinion(2);
	        i = i * 2 + 1;
                cout << choices[i] << endl;
                cout << endl;
	        combat fight(&inventory, check_enemy(choices[i], adventurer->getLevel()), &dmg);
                fight.start("From the shadows, an enemy charges towards you");
                inventory.add(&dmg);         
                fightCounter++;

	    }
	    else if(decision == "r") {
		 Enemy* slime = new SlimeMinion(2);
                 i = i * 2 + 2;
                 cout << choices[i] << endl;
                 cout << endl;
		 combat fight_two(&inventory, check_enemy(choices[i], adventurer->getLevel()), &heal);
		 fight_two.start("An enemy jumps you!");       
                 inventory.add(&heal);
                 fightCounter++;
	    }
	    else {
		 cout << "Sorry that's not a valid choice, please type in 'l' for left or 'r' for right" << endl;
	    }
        }
        if(levelTrigger == fightCounter) {
	    print_level_up(inventory);
            levelTrigger++;
            fightCounter = 0;
        }       
        cout << "Press any key to continue and enter . . ." << endl;
        cin >> anyKey;
        system("clear");
        cout << prompt[promptCounter] << endl;
        promptCounter++;
        cin.ignore();
        decision = "";
    }
}

void print_base_stats(Bag inventory) {
    cout << "Health: " <<  inventory.getplayer()->getCurrHealth() << "/" << inventory.getplayer()->getMaxHealth() << endl;
    cout << "Attack: " << inventory.getplayer()->getAttack() << endl;
    cout << "Defense: " << inventory.getplayer()->getDefense() << endl; 
    cout << "Crit Rate: " << inventory.getplayer()->getCritRate() << endl;
}

void print_level_up(Bag inventory) {
    cout << "----------------------------------------" << endl;
    cout << "| Congratulations, you gained 1 level! |" << endl; 
    cout << "----------------------------------------" << endl;
    print_base_stats(inventory);
    inventory.getplayer()->levelUp(1);
    cout << "      ↓      " << endl;
    print_base_stats(inventory);
}

//Makes and returns an enemy based on the choice the user made, that has the same level as the player
Enemy* check_enemy(string narrative, int level) {
    if(narrative.find("shh") || narrative.find("run")) {
	Enemy* goblin = new GoblinMinion(level);
        return goblin;
    }
    else if(narrative.find("jump")) {
	Enemy* slime = new SlimeMinion(level);
        return slime;
    }
    else {
	Enemy* chicken = new ChickenMinion(level);
        return chicken;
    }

}
