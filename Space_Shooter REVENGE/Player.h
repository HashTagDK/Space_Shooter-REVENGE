#pragma once  
#include"fire_Tile.h"

#include "Object_Base_Class.h" 

class Player : public Object_Base_Class
{
public:
	Player();
	~Player(); 
	
	void handleInput();
	void update(sf::Time deltaTime); 
	void render(sf::RenderWindow& window);
	
private :  
	void updatePlayer(sf::Time deltaTime);
	fire_Tile fireSingle;
	std::vector<fire_Tile> fireTileVector_;
	void move(sf::Time deltaTime);
	
	sf::Time timeSienceLastFire; 
	sf::Time tilesPerSecond;
	sf::Clock clock;
};


