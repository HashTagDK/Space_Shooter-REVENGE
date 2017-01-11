#pragma once 
#include "Object_Base_Class.h"
class enemyShip1 : public Object_Base_Class
{
public:
	enum typeOfEnemy {
		basicTYPE = 0,
		Boss1
	};

	enemyShip1(typeOfEnemy type);
	~enemyShip1(); 

	
	void decrementHP(int value);
	int getHP();
	sf::Time timeFromLastShoot;
	typeOfEnemy getTypeOfEnemy();
private:  
	typeOfEnemy m_typeOfObject;
	int hp;
};

