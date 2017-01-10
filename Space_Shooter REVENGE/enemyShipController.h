#pragma once 
#include "enemyShip1.h" 
#include"fireTilleController.h"
class enemyShipController
{
public:
	enemyShipController();
	~enemyShipController(); 

	void update(sf::Time deltaTime, fireTilleController& fireTileController);
	void render(sf::RenderWindow& window_);
	
	std::vector<enemyShip1> enemyShipVector;
	//Enemy formation 
	void AddSingleEnemy( sf::Vector2f position );
private: 
	enemyShip1 enemyExample;
	void AddEnemy(sf::Vector2f position);
	sf::Time timeBetweenShoot;
};

