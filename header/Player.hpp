#include "Bag.hpp"
#include "Item.hpp"
#include "../header/character.hpp"





using namespace std;

class Player: public character{
    private:
      Bag userBag;
      Weapon userWeapon;
    public:
      virtual int Attack();
      virtual void Class_ability() = 0;
};