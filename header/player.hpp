#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.hpp"

class Player : public Entity {
    public:
        void levelUp(int levels);
};

#endif