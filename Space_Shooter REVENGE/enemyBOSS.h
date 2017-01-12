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
	sf::Vector2f getPosition(); 
	void decrementHP(int value); 
	int getHP();
private: 
	sf::Time timeBetweenDoubleShoot;
	sf::Time timeBetweenCenterShoot;
	sf::Time timeBetweenLaserAttack; 
	sf::Time timeFromLastLaserAttack;
	sf::Time timeFromLastCenterShoot;
	int hp1; 

	float fastOfTracking = 1;
	void setLaserAttack(fireTilleController& fireTileController);
};

