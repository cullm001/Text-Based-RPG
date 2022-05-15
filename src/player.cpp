
#include "player.hpp"
#include "entity.hpp"

using namespace std;

void Player::levelUp(int levels) {
    int hthFactor = 1;
    int defFactor = 1;
    int atkFactor = 1;
    addMaxHealthAndCurrHealth(levels * hthFactor);
    addAttack(levels * atkFactor);
    addDefense(levels * defFactor);
}