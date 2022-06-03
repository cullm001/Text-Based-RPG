# Project Gary-Goomba
 
 > Authors: [Justin Lee](https://github.com/Sworddafence), [Keita Ichii](https://github.com/kichi004), [Chris Ullman](https://github.com/cullm001), [Isaiah Bernardino](https://github.com/isaiahpb)
 > 
 > "A text-based linear RPG with multiple classes and a randomized loot system.  Incorporates a fleshed out combat system with interesting mechanics such as crits, consumables and Class abilities."
 > * Project Reason
 >   * We decided to work on this project because it seems like it would be fun to come up with and implement class abilities, weapon attributes, and creative enemy types. It would be interesting to examine a game through the lens of a developer instead of a user.
 > * Languages/Tools/Technology
 >   * [Github](https://github.com/) - an online version control repository to allow easy collaboration
 >   * [C++](https://www.cplusplus.com/) - a well-known object-based programming language
 >   * [Secure Shell](https://www.ssh.com/) - used to remotely access the UCR hammer server
 >   * [Github Kanban Board](https://github.com/kanboard/kanboard) - Github’s version of an online framework to implement the Kanban work methodology
 >   * [GoogleTest Framework](https://github.com/google/googletest) - Google's C++ testing and mocking framework
 > * Project Features
 >   * Text-based input/output
 >     * Using singular character inputs like "1, 2, 3, 4, y, and n" to navigate story and combat menus. Receiving output in the form of text descriptions of what is happening.
 >   * 5 Classes, each with a unique class ability in combat
 >     * Ex: Barbarians can go into rage to deal more damage, Clerics can heal themselves, Archers can raise their crit rate 
 >   * 5 Weapons Types with randomly generated levels and rarities
 >     * Ex: Level 5 Common Weapon will have much less attack than a Level 5 Legendary Weapon
 >   * Multiple potion types to use before and in combat
 >     * Ex: Use a Strength Potion to raise your attack, use a Healing Potion to heal yourself. 
 >   * Unique enemies, each with their own combat style
 >     * Ex: Slimes increase their health and heal with their class ability, defeating them quickly will prevent them from becoming too strong
 >   * Linear storyline, but randomized loot system to receive items and weapons.
 >   
## UML Class Diagram
 > ![CS 100 Project UML - 6_1_22 drawio (2)](https://user-images.githubusercontent.com/100912526/171774057-a93efeb3-9262-4ee3-9c55-49c9855b4989.png)
 >  
 > Our text-based RPG will run primarily through the Story Class. After the user selects a Player Archetype (Paladin, Wizard, etc.), the main file instantiates the revevant Archetype and Bag, then instantiates a Story object with these components. The respective Archetype instantiates a Weapon, the one that is first equipped by the player at the start of the journey (Lvl. 5 Common Weapon), subsequent Weapon objects will be instantiated by the Story Class as potential dungeon clearing rewards.
 >  
 > The **Story Class** operates the choices the player makes in regards to the narrative plot (ie choosing left or right paths). When relevant, the Story Class instantiates Enemy objects (Boss or Minion objects), randomly selects a previously instantiated Item, and takes the Bag Object to create a Combat Object/Encounter.
 >  
 > The **Combat Class** operates the turnbased combat system of the game. This includes player choices, damage calculations, in-combat item usage, and outputting text descriptions. For damage, first the getAttackDamage() of the Entity Class is called and its output is used in the takedmg() function. For item usage, the Bag's print() and use(int i) functions are used to show the player's current items and then use an item in a certain slot. For class abilities, the Player or the Enemy's virtual function is overridden based on the subclass so that they accomplish different tasks based on the character. 
 > 
 > The **Entity Class** that all Player and Enemy objects derive from has a number of member variables and functions. It stores relevant RPG stats like levels, health, attack, defense, and crit rate; and temporary buffing effects like tempStats and Boosts. tempStats are temporary flat increases in stat values while Boosts are percentage-based increases (50% increase for every boost). For functions, the Entity Class has getters, setters, and other important features like getAttackDamage(), takedmg(), heal(), and levelUp(). 
 >  
 > Between the **Boss Class** and the **Minion Class**, currently the only difference between the two is how the move() function, used to select the monster's random move is calculated. The Boss Class has a 1/3 chance of using their ability, while the Minion Class has a 1/5 chance. 
 > 
 > The **Weapon Class** controls how a random weapon is generated and the weapon's strength. The strength (attack buff) of the weapon is determined by the rarity level of the weapon and the level. The rarity scaling ranges from Common, Uncommon, Rare, Epic, and Legendary. 

 ## Strategy Design Pattern - Player, Enemy, Item
 > * You should also update this README file by adding the following:
 >   * What design pattern(s) did you use? For each pattern you must explain in 4-5 sentences:
 >     * Why did you pick this pattern? And what feature did you implement with it?
 >     * How did the design pattern help you write better code?
 >   * An updated class diagram that reflects the design pattern(s) you used. You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description).
 >   * Make sure your README file (and Project board) are up-to-date reflecting the current status of your project. Previous versions of the README file should still be visible through your commit history.
> 
 > ## Final deliverable
 > All group members will give a demo to the TA/reader during lab time. The TA/reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 > Installation
 > <img width="778" alt="Installation screenshot" src="https://user-images.githubusercontent.com/90822210/171776038-1b1e9f13-b79f-4cfa-a25a-1be26b447798.png">
 > Start screen
 > <img width="778" alt="Installation screenshot" src="https://user-images.githubusercontent.com/90822210/171776073-7e0d3466-3827-4ec9-8781-60db738bf1ed.png">
 > Program running with input being denoted by lines starting with > 
 > <img width="1239" alt="Screen Shot 2022-06-02 at 7 36 32 PM" src="https://user-images.githubusercontent.com/90822210/171776121-fdc36d53-3fad-4275-8bda-25fabe8c26b1.png">
 > <img width="1198" alt="Screen Shot 2022-06-02 at 7 38 27 PM" src="https://user-images.githubusercontent.com/90822210/171776138-e2251b0e-dd9f-403e-b9e6-0341e0b0f8e7.png">
 > Program finishing by killing the final boss
 > <img width="997" alt="Screen Shot 2022-06-02 at 7 39 20 PM" src="https://user-images.githubusercontent.com/90822210/171776180-65b1bf04-80da-459e-9fab-149b910b776f.png">
 > Program running memcheck clean
 > ![image](https://user-images.githubusercontent.com/90822210/171776260-d6e10a46-dbd7-4606-b1d9-9e782264e990.png)




 ## Installation/Usage
 1. Clone this repository in Terminal (Mac) or Command Prompt (Windows) with the following command:
 ```
 $ git clone https://github.com/cs100/final-project-isaiah-keita-chris-justin.git
 ```
 2. Change into the directory that was created:
 ```
 $ cd final-project-isaiah-keita-chris-justin/
 ```
 3. Compile the code (`cmake3 .` if you are using `hammer`):
 ```
 $ cmake .
 $ make
 ```
 4. Run the executable:
 ```
 $ ./story
 ```
 5. You should be greeted with the title and the main menu
 ## Testing
 For testing we deccided to use Unit testing using the google test framework to test.
 We wrote 98 Unit tests in total testing everything from our combat class to the different player archetypes.
 We also created a YML file to test all of the unit tests every time something is merged into our master/main branch.
