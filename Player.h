#include "Bag.h"
#include "Item.h"
#include "Character.h"

using namespace std;

class Player: public Character{
    private:
      Bag userBag;
      Weapon userWeapon;
    public:
      virtual int Attack();
      virtual void Class_ability() = 0;
};
