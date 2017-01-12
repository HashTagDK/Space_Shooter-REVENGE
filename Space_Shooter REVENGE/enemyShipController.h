#pragma once 
#include "enemyShip1.h" 
#include "enemyBOSS.h"
#include"fireTilleController.h"
class enemyShipController
{
public:
	enemyShipController();
	~enemyShipController(); 

	void update(sf::Time deltaTime, fireTilleController& fireTileController, sf::Vector2f playerPosition);
	void render(sf::RenderWindow& window_);
	
	std::vector<enemyShip1> enemyShipVector;
	//Enemy formation 
	void AddSingleEnemy( sf::Vector2f position ); 
	void SetRandom(int amountInRow, int aomountOfRow, float spaceBetweenRows); 
	void AddBoss(); 
	sf::Vector2f getBossPos();
	enemyBOSS enemyBoss;
private: 
	enemyShip1 enemyExample; 
	

	void AddEnemy(sf::Vector2f position);
	sf::Time timeBetweenShoot;
};

