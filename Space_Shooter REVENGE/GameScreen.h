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
#include"PickUps.h"
#include"enemyShipController.h"

class GameScreen : public IScreen
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
	fireTilleController m_fireTilleController;
	enemyShipController m_enemyShipController;

	//pickUp 
	PickUps m_pickups;
	
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

	//czas po na zebrania pick upów po zabiciu bossa i przejscia do nastêpnego lvl 
	sf::Time timeFromKillingBoss; 

	sf::Text TextWin;
	sf::Font font; 

	bool bossDead = false;
};

