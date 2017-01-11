#pragma once
#include "enemyShip1.h" 
#include"fireTilleController.h"
class enemyBOSS :
	public enemyShip1
{
public:
	enemyBOSS();
	~enemyBOSS(); 

	void setFire(sf::Time deltaTime, fireTilleController& fireTileController); 
	void updateBossPosition(sf::Vector2f positionOfPlayer, sf::Time deltaTime);
private: 
	sf::Time timeBetweenDoubleShoot;
	sf::Time timeBetweenLaserAttack; 
	sf::Time timeFromLastLaserAttack;
	int hp; 

	float fastOfTracking = 1;
	void setLaserAttack(fireTilleController& fireTileController);
};

