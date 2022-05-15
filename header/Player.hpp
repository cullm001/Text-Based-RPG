#include "Bag.hpp"
#include "Item.hpp"
#include "../header/character.hpp"





using namespace std;

class Player: public character{
    private:
      Bag userBag;
      Weapon userWeapon;
    public:
      void levelup();
      virtual int Attack();
      virtual void Class_ability();
};
