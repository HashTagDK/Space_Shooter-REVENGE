#pragma once 
#include <SFML/Graphics.hpp>
#include"Screen.h" 
#include"Player.h"
#include"fire_Tile.h"
#include"StoneNode.h"


class GameScreen : public Screen
{
public:
	GameScreen();
	~GameScreen();   
	
	/*implementacja funkcji z interfesju*/
	void handleInput(sf::RenderWindow& window) override; 
	void update(sf::Time delta) override; 
	void render(sf::RenderWindow& window) override; 

private: 
	//obiketu kt�re bd wy�wietlane w obr�bie tego okna
	Player player_; 
	 
	std::vector<StoneNode> stoneVector_;
};

