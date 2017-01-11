#pragma once  
#include"fire_Tile.h"
#include"SFML\Graphics.hpp"
class fireTilleController
{
public:
	fireTilleController();
	~fireTilleController(); 

	void update(sf::Time deltaTime); 
	void render(sf::RenderWindow& window_);  
	void AddFireTile(sf::Vector2f position, fire_TileNODE::typeOFFireTile type); 
	void AddLaserAttack(sf::Vector2f position, fire_TileNODE::typeOFFireTile type);
	std::vector<fire_TileNODE> fireTileVector;
private: 
	fire_TileNODE playerFireTile; 
	fire_TileNODE enemyFireTile;
	fire_TileNODE laserAttack;
};

