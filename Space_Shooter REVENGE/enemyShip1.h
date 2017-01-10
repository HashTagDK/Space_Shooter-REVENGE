#pragma once 
#include "Object_Base_Class.h"
class enemyShip1 : public Object_Base_Class
{
public:
	enemyShip1();
	~enemyShip1(); 

	void decrementHP(int value);
	int getHP();
	sf::Time timeFromLastShoot;
private: 
	int hp;
};

