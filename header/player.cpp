
#include "player.hpp"
#include "entity.hpp"

using namespace std;

void Player::levelUp(int levels) {
    int hthFactor = 1;
    int defFactor = 1;
    int atkFactor = 1;
    add_maxHealthAndCurrHealth(levels * hthFactor);
    add_attack(levels * atkFactor);
    add_defense(levels * defFactor);
}