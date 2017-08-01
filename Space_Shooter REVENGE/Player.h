#pragma once  
//#include"fire_Tile.h"
#include"MusicController.h"
#include "Object_Base_Class.h" 
#include"fireTilleController.h"
class Player : public Object_Base_Class
{
public:
	Player();
	~Player(); 
	
	void handleInput();
	void update(sf::Time deltaTime); 
	void render(sf::RenderWindow& window);

	//std::vector<fire_TileNODE> fireTileVector_;
	float hp;
	int score; 

	void setTilesPerSecond(float decrement); 
	float getTilePerSoecon();
	bool isEnableShoot();
private :  
	bool playerShoot = false;
	void updatePlayer(sf::Time deltaTime);
	//fire_TileNODE fireSingle;
	
	void move(sf::Time deltaTime);
	
	sf::Time timeSienceLastFire; 
	sf::Time tilesPerSecond;
	sf::Clock clock;
	MusicController musicController;
	
};


