#include "weapon.hpp"
#include <iostream>

int main() {
    Weapon* test = new Weapon("Staff", 5, "zap", "Common");
    // cout << test->printStats() << endl;
    cout << test->printFound() << endl;

    Weapon* test2 = new Weapon(test, 5);
    // cout << test2->printStats() << endl;
    cout << test2->printFound() << endl;

    Weapon* test3 = new Weapon("Staff", 30, "zap");
    // cout << test3->printStats() << endl;
    cout << test3->printFound() << endl;

    Weapon* test4 = new Weapon("Chicken", 30, 5, "zap", "Illegal");
    // cout << test4->printStats() << endl;
    cout << test4->printFound() << endl;

    // for (int i = 0; i < 15; i++) {
    //     Weapon* test5 = new Weapon("Club", 5, "bonk");
    //     cout << test5->printFound() << endl;
    //     delete test5;
    // }
}
