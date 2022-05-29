#include "../header/story.hpp"
Story* archetype_choice();

int main()
{
    system("clear");
    string anyKey = "";
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << "|                                                 |" << endl;
    cout << "|               Gary Goomba Dungeon               |" << endl;
    cout << "|                                                 |" << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << endl;
    while(anyKey != "1" && anyKey != "2") {
        cout << "Menu:\n[1] Play\n[2] Exit" << endl;
        cout << ">";
        cin >> anyKey;
        if(anyKey == "1") break;
        else if(anyKey == "2") exit(0);
        else cout << "Sorry that is an invalid option, please type '1' to play and '2' to quit" << endl;
    }

    system("clear");
    
    Story* game = archetype_choice();

    cin.ignore();
    cout << "Press enter to continue . . ." << endl;
    cout << "> ";
    getline(cin, anyKey);
    system("clear");
    
    string start[6] = {"You are striving to become one of the best " + game->getPlayer()->getArchetype() + "s of all time.", 
    "However, things have not been going your way as of lately.",
    "You try joining clans so that you could gain some experience and clear some dungeons with them.",
    "But each of the clans consisted of useless members, so you feel like you made zero progress.",
    "However, hope arises when you hear rumors of a dungeon so-called \"Gary Goomba\" that had a tough boss and a powerful reward.",
    "Wasting no time you spring into action and decide to clear this dungeon."
    };
    
    for(unsigned int i = 0; i < 6; i++) {
        cout << start[i] << endl;
        cout << endl;
        this_thread::sleep_for(chrono::seconds(2));
    }

    cout << endl;
    cout << "Press enter to continue . . ." << endl;
    cout << "> ";
    getline(cin, anyKey);
    system("clear");
	
    game->story();

    cout << "Congratulations, you just cleared the Gary Goomba dungeon." << endl;

    return 0;

}

Story* archetype_choice() {
    string choice = "";
    Player* adventurer;
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
        cout << "Select the archetype of your liking" << endl;
        cout << "> ";
	cin >> choice;
        cout << endl;
        if(choice == "1") {
	    cout << "You have selected the Barbarian class! This class can raise its attack by going into a rage." << endl;
            adventurer = new Barbarian();
        }
	else if(choice == "2") {
	    cout << "You have selected the Wizard class! This class can randomly raise a stat by two stages by channeling magic." << endl;
            adventurer = new Wizard();
        }
        else if(choice == "3") {
	    cout << "You have selected the Archer class! This class can increase its crit rate by honing its focus." << endl;
            adventurer = new Archer();
        }

        else if(choice == "4") {
	    cout << "You have selected the Cleric class! This class can heal itself through prayer." << endl;
            adventurer = new Cleric();
        }

        else if(choice == "5") {
	    cout << "You have selected the Paladin class! This class can raise its defense with divine shields." << endl;
            adventurer = new Paladin();
        }
        else {
            cout << "Sorry that's not a valid choice, please type in the number corresponding to the archetype" << endl;
	}


        if(choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5") { //Confirms if the player wants the selected class after base stats and starter weapons stats print
            Bag inventory(adventurer);
            cout << "Your archetype's base stats:" << endl;
            Story* gameplay = new Story(inventory, adventurer);
            gameplay->print_base_stats(); 
            cout << endl;
            cout << "Your starter weapon:" << endl;
            cout << adventurer->getWeapon()->printStats() << endl;
            cout << endl;
            while(choice != "y" && choice != "n") {
                cout << "Are you sure you want the " << adventurer->getArchetype() << " class? Yes (y) or No (n)" << endl;
                cout << "> ";
                cin >> choice;
                if(choice == "y") {
	            return gameplay;
	        }
                else if(choice == "n") {
                    delete gameplay;
		    break;
	        }
                else {
		    cout << "Sorry that is not a valid option, type in 'y' for Yes and 'n' for No" << endl;
		}
            }
	}
    }
    return 0;
}
