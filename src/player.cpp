#include "../header/player.hpp"
#include "../header/entity.hpp"
#include "../header/Weapon/weapon.hpp"

using namespace std;

//constructors
Player::Player() : Entity() {}
Player::Player(int lvl) : Entity(lvl) {}
Player::Player(double a, double d, double h, int l) : Entity(a, d, h, l) {}

void Player::equip(Weapon* wep) {
    if (weapon != nullptr) { addAttack(-(weapon->getBoost())); delete weapon; }
    weapon = wep;
    setAttackNoise(weapon->getAttackDescription());
    addAttack(weapon->getBoost());
}
