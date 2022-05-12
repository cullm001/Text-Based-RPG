#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "item.hpp"

class Player : public Item {
    public:
        void levelUp(int levels);
};

#endif