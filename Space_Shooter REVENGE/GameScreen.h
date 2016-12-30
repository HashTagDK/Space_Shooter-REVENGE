#pragma once 
#include <SFML/Graphics.hpp>
#include"Screen.h"  
#include"GameOVerScreen.h"
#include"Player.h"
#include"fire_Tile.h"
//#include"StoneNode.h" 
#include"StoneFormations.h"
#include"BoxCollieder.h" 
#include<string.h> 
#include"MusicController.h"



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
	BoxCollieder m_boxCollider;
	std::vector<StoneNode> stoneVector_;
	StoneFormations m_stoneFormation; 
	
	//healt bar
	sf::Texture healthBarTexture;
	sf::Sprite healthBarSprite; 
	sf::RectangleShape healthRectangeShape; 
	sf::Vector2f sizeOfHealtBar;
	void updateHealthBar();
	void updateBackgorund(); 
	void updateScore();
	
	//score 
	sf::Text m_score;
	sf::Font m_font; 

	//music 
	MusicController musicController;

	void enemyController(sf::Time deltaTime);
	sf::Time lifeTimeOfGameScreen;
	int positionInQue;
};

