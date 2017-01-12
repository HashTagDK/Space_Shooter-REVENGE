#pragma once 
#include"Screen.h"
#include"GameScreen.h" 
#include"StartScreen.h" 
#include<string.h>
#include"MusicController.h"

class GameOVerScreen : public Screen
{
public:
	
	GameOVerScreen(int score_);
	~GameOVerScreen();

	/*implementacja funkcji z interfesju*/
	void handleInput(sf::RenderWindow& window) override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;

private:  
	int score;
	sf::Text scoreText;
	sf::Font font;
	sf::Texture backgoundTexture;
	sf::Sprite backgroundSprite; 
	int currentLVL;
	MusicController musicController;
};

