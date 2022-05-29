#include <iostream>
#include <string>
#include "../header/item.hpp"

using namespace std;

Item::Item(string nm, string des, int val) {
    name = nm;
    description = des;
    value = val;
}