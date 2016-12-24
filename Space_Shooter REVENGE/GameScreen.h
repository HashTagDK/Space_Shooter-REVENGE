#pragma once 
#include <SFML/Graphics.hpp>
#include"Screen.h" 
#include"Player.h"
#include"fire_Tile.h"
//#include"StoneNode.h" 
#include"StoneFormations.h"


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
	//obiketu które bd wyœwietlane w obrêbie tego okna
	Object_Base_Class backgorund[2];
	Player player_; 
	 
	std::vector<StoneNode> stoneVector_;
	StoneFormations m_stoneFormation; 
	
	void updateBackgorund();
};

