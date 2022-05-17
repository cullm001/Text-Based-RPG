#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "../entity.hpp"
#include <string>
using namespace std;

class Enemy: public Entity{
	protected:
		string name;
	public:
		int Move();
}; 
#endif
