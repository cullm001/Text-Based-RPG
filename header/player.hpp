#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../header/entity.hpp"


using namespace std;
class Player : public Entity {
    private:
        //Weapon weapon;
        int random;
    public:
        Player(); //we'll put weapons here later
        ~Player();
        void levelUp();
        int Attack();
        virtual void ability();
};

#endif
