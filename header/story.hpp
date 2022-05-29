#include <iostream>
#include <thread>        
#include <chrono>
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

class Story {
    public:
        Story(Bag inventory, Player* adventurer) {
	    this->inventory = inventory;
            this->adventurer = adventurer;
	}
        ~Story() {
	    delete adventurer;
	}
        Player* getPlayer() {
	    return adventurer;
	}
        void story() {
            string decision = "";
            string anyKey;
        
            srand(time(0));
        
            int fightCounter = 0; //Level up after 1 fight, then level up after 2 fights, and so on
            int levelTrigger = 1;
            int promptCounter = 0;
        
            Item* str = new strengthpot(); // boosts their attack stat by 25%
            Item* heal = new healthpot(); // heals 25% of the player's health
            inventory.add(heal);
        
            cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << choices[0] << endl;
            cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;
            for(unsigned int i = 0; i < size_choices;) {
                while(decision != "l" && decision != "r") {
                    cout << "> ";
                    cin >> decision;
                    if(decision == "l") {
                        i = i * 2 + 1; //Visit left child
                    }
                    else if(decision == "r") {
                         i = i * 2 + 2; //Visit right child
                    }
                    else {
                         cout << "Sorry that's not a valid choice, please type in 'l' for left or 'r' for right" << endl;
                    }
                }
        
                cout << choices[i] << endl; //Prints enemy encounter
                cout << endl;
                this_thread::sleep_for(chrono::seconds(2));

                int dropRoll = rand() % 2; // randomly decides the drop for the encounter, if the roll is 0, then you just get the heal potion
                Item* drop = heal;
                if(dropRoll == 1) { drop = str;}

                combat fight(&inventory, check_enemy(choices[i], adventurer->getLevel()), drop);
                fight.printStats();
                fight.start("You have encountered a " + fight.getMonster()->getName() + "!");
                inventory.add(heal);
                fightCounter++;
                if(levelTrigger == fightCounter) { //Level up checkpoint
                    print_level_up();
                    levelTrigger++;
                    fightCounter = 0;
                }
                cout << endl;
	            cout << "Would you like to use an item in your bag? (Enter 'y' for yes or 'n' for no)" << endl;
                item_checkpoint(decision);
                press_continue();
                chest();
                cout << endl;

                if(rand() % 10 + 1 < 9) { //90% chance of an enemy approaching from behind
                    this_thread::sleep_for(chrono::seconds(2));
                    cout << "As you continue exploring you hear something run up from behind you." << endl;
		            combat fight(&inventory, check_enemy(choices[i], adventurer->getLevel()), heal);
                    fight.printStats();
                    fight.start("A " + fight.getMonster()->getName() + " jumps at you from behind!");
                    inventory.add(heal);
                    fightCounter++;

                    if(levelTrigger == fightCounter) { //Level up checkpoint
                        print_level_up();
                        levelTrigger++;
                        fightCounter = 0;
                    }

                    cout << endl;
                    cout << "Would you like to use an item in your bag? (Enter 'y' for yes or 'n' for no)" << endl;
                    item_checkpoint(decision);
                    press_continue();
                    chest();
                }
                
		        press_continue();
		
                cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                cout << prompt[promptCounter] << endl; //Prints new prompt
                cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                cout << endl;
                promptCounter++;
                decision = "";
            }
            //Boss Battle
            this_thread::sleep_for(chrono::seconds(2));
            cout << "As you keep inspecting this mystery, you notice a huge door in front of you. Similar to the other dungeons you explored, this must be where the boss resides." << endl; 
            cout << endl;
            this_thread::sleep_for(chrono::seconds(2));
            cout << "You then mentally and physically prepare yourself to clear this dungeon and hopefully reap the benefits." << endl;
            cout << endl;
            this_thread::sleep_for(chrono::seconds(2));
  
            cout << "Would you like to use an item in your bag? (Enter 'y' for yes or 'n' for no)" << endl; 
            item_checkpoint(decision);

	    press_continue();

            cout << "You then open the door and are greeted with the boss, a Hobgoblin" << endl;
            this_thread::sleep_for(chrono::seconds(2));
            HobgoblinBoss* boss = new HobgoblinBoss(adventurer->getLevel()); 
            combat fight(&inventory, boss, heal);
            fight.printStats();
            cout << endl;
            fight.start("The Hobgoblin charges straight at you.");
        }
    
        void print_base_stats() {
            cout << "Level: " << adventurer->getLevel() << endl;
            cout << "Health: " << adventurer->getCurrHealth() << "/" << adventurer->getMaxHealth() << endl;
            cout << "Attack: " << adventurer->getAttack() << endl;
            cout << "Defense: " << adventurer->getDefense() << endl;
            cout << "Crit Rate: " << adventurer->getCritRate() << endl;
        }

    private:
        Bag inventory;
        Player* adventurer;
        const int size_choices = 15;
        const int size_prompt = 4;
        const string prompt[10] = {
            "You have defeated your first enemy and continue to explore the dungeon. There appears a dimly lit path to the left and a shiny path to the right. Which one will you explore? (l/r)",
            "You continue to survey the eerie dungeon and come across another set of paths. One with loud sounds and another with mist. Which one will you partake in? (l/r)",
            "As you get deeper into the dungeon, an additional pair of left and right paths come into your vision. Both paths radiating an immense pressure. Choose carefully. (l/r)",
            "You suddenly realize that the other path converged to where you are at. You feel get closer and closer to a discomforting, menacing prescence."
        };
        
        //Using i*2+1 to access left child and i*2+2 to access right child
        const string choices[100] = {
        "You have entered the infamous dungeon. As you traverse down the halls you stumble across a dark path to the left and another to the right. Which one will you choose? (l/r)", 
        //1st Level
        "You have chosen the left path and you hear a faint shhhhhh sound.", //Goblin
        "You have decided to take the right path and you see something jumping.", //Slime
        //2nd Level
        "You explore the left path and realize that you are hungry. Coincidently, a medium-sized chicken approaches you, but something bizarre occurs.", //Chicken
        "You decided to venture the right path. As you keep surveilling you feel an immense presence and something running towards you.", //Goblin
        "You have chosen the left path and you feel a small shake as if something heavy was jumping.", //Slime
        "You chose to proceed to the right path and you yearn for some food. A chicken walks up to you.", //Chicken
        //3rd Level
        "Upon exploring the left path, you realize that this dungeon ain't too bad aside from the chicken. You then hear a bouncing, slimy sound.", //Slime
        "While traversing the right path, you stumble across a natural, rocky slide. As you slide down deeper into the dungeon, a goblin jumps from the shadows.", //Goblin
        "As you continue to investigate the dungeon, you see something flapping its wings and fall gracefully.", //Chicken
        "You decided to investigate the right path. As you wonder why there are only 2 paths throughout the dungeon, a goblin leaps from the shadows.", //Goblin
        "You think to yourself that the dungeon is a piece of cake as you explore the left path. Then a something fat that is jumping comes into sight.", //Slime
        "You decided to venture the right path in which you hear a bawk bawk sound.", //Chicken
        "Decidingly, you inspect the left path and are immediately with a sole goblin.", //Goblin
        "You chose to proceed to the right path. As you keep inspecting, you see a cluster of small slimes that merge.", //Slime
        //4th Level
        "Decidingly, you investigate the left path and you suddenly feel an strong aura. You must be getting closer to the boss but a chicken gets in your way.", //Chicken
        "While exploring the right path you feel as if you are approaching the boss closer due to spiritual pressure. As you prepare yourself a human-shaped slime is approaching you." //Slime
        "You decided to traverse the left path, hoping to kill the boss for some notoriety. However out of nowhere,, a speedy goblin charges at you.", //Goblin
        "Ideally, you chose to venture out into the right path. You get closer to a radiating prescence. Just as you experience that feeling, a phat goblin comes into your sight.", //Goblin
        "Confidently, you have chosen to dip your feet into the left path where you hear a bawking noise becoming more comprehendable by the second.", //Chicken
        "So you chose to explore the right path. You feel noticeable spiritual pressure as if you are getting closer to the boss. These thoughts seemed to deter when am ugly goblin approaches you.", //Chicken
        "So you chose to traverse the left path. You feel the ground shaking as if something is jumping up and down repeatedly. You then brace for combat.", //Slime
        "Decidingly, you inspect the right path. You notice an unbearable prescence as you keep exploring. Then, under a fake hole, a goblin plops up.", //Goblin
        "So you decided to explore the left path and as you keep looking around, feisty chicken sprints towards you.", //Chicken
        "Confidently, you charge into the right path and a group of slimes appears in your sight. They all merge with each other.", //Slime
        "While exploring the left path, you feel a strange prescence. As you get closer to that prescence, a goblin comes at you from the shadows.", //Goblin
        "You chose the right path hoping to clear the dungeon. You notice that you are getting deeper into the dungeon and at the same time your feet sticks to a slimy rock.", //Slime
        "Confidently, you sprint past the left path yearning to kill the boss. From the ceiling, a goblin jumps on you." //Goblin
        "You have chosen to go to the right path. As you keep inspecting, you see the most macho chicken you have seen in your life." //Chicken
        "So you chose to proceed to the left path, eager to clear this dungeon. While dreaming of the notoriety and fame from clearing the dungeon, a shhh sound becomes hearable.", //Goblin
        "Upon exploring the right path, you feel a discomforting prescence as if something minister is nearby. As you feel that prescence, there is a bawking sound that is deafening.", //Chicken
        //"Upon exploring the left path, you hear an annoying plop, slimy sound. Here we go again." //Slime
        //"Upon exploring the right path, you yearn to kill the boss. You imagine of the clout you would obtain until you hear something flapping it wings." //Chicken
        }; 
        
        void item_checkpoint(string decision) { //Allows user to use an item after each fight if the user doesn't level up or before the boss battle
            while(decision != "y" && decision != "n") {
                cout << "> ";
                cin >> decision;
                if(decision == "y") {
	            inventory.print();
                }
	       else if(decision == "n") {
	            break;
	       }
               else {
	            cout << "Sorry that is not a valid choice. Please type 'y' for yes or 'n' for no" << endl;
	       }
            }
	}

        void press_continue() {
            cin.ignore();
            cout << "Press enter to continue . . ." << endl;
            cout << "> ";
            cin.get();
            system("clear");
	}

	void print_level_up() {
            cout << "-----------------------------------------" << endl;
            cout << "| Congratulations, you gained 2 levels! |" << endl; 
            cout << "-----------------------------------------" << endl;
            print_base_stats();
            adventurer->levelUp(2);
            cout << "      ↓      " << endl;
            print_base_stats();
        }
   	
        //Summons an enemy based on the decision the user makes and the users level
        Enemy* check_enemy(string narrative, int level) {
            srand(time(0));
            if(narrative.find("shh") != -1 || narrative.find("run") != -1 || narrative.find("goblin") != -1) {
                Enemy* goblin = new GoblinMinion((rand() % 2) + level-3); //level-3 to level-2
                return goblin;
            }
            else if(narrative.find("jump") != -1 || narrative.find("slimy") != -1 || narrative.find("slime") != -1) {
                Enemy* slime = new SlimeMinion((rand() % 2) + level-3);
                return slime;
            }
            else {
                Enemy* chicken = new ChickenMinion((rand() % 2) + level-3);
                return chicken;
            }
        }
        
        void chest() {
            string choice;
            srand(time(0));
            int level = adventurer->getLevel();
            if(rand() % 5 + 1 < 5) {
                this_thread::sleep_for(chrono::seconds(1));
                cout << endl;
                cout << "----------------------------------------------------------" << endl;
                cout << "As you reach the end of the path, you see a wooden chest" << endl;
                Weapon* contents = new Weapon(adventurer->getWeapon(), (rand() % 5) + level-2);
                cout << contents->printFound() << endl;
                cout << "----------------------------------------------------------" << endl;
                cout << endl;
                cout << "Your weapon stats:" << endl;
                cout << adventurer->getWeapon()->printStats() << endl;
                cout << "        ↕       " << endl;
                cout << "Discovered weapon stats:" << endl;
                cout << contents->printStats() << endl;
                cout << endl;
                cout << "Would you like to equip this weapon? (y/n)" << endl;
                while(choice != "y" && choice != "n") {
                    cout << "> ";
                    cin >> choice;
                    if(choice == "y") {
                        cout << "You have equipped the " << contents->getRarity() << " " << contents->getType() << "!" << endl;
                        adventurer->equip(contents);
                    }
                    else if(choice == "n") {
                        delete contents;
                        break;
                    }
                    else {
                        cout << "Sorry you entered an invalid choice, type 'y' for yes or 'n' for no" << endl;
                    }
                }
            }
        }
};
