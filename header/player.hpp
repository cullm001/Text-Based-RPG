#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.hpp"


using namespace std;
class Player : public Entity {
    private:
        //Weapon weapon;
    public:
        Player(); //we'll put weapons here later
        void levelUp();
        int Attack();
        virtual void ability();
};

#endif
