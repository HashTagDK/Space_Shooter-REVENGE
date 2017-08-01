#pragma once
#include"Screen.h"
#include"Game.h" 
#include"GameScreen.h"
class StartScreen : public IScreen
{
public:
	StartScreen();
	~StartScreen();
	
	/*implementacja funkcji z interfesju*/
	void handleInput(sf::RenderWindow& window) override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override; 
private:
	enum position {
		StartGame = 0,
		Exit = 1

	}; 
	int m_pos;
	void nextEnum();
	void prevEnum();
	position m_position; 
	sf::Vector2f m_positionVector;
	sf::Texture backgoundTexture; 
	sf::Sprite backgroundSprite;
	sf::Texture texturePointer; 
	sf::Sprite spritePointer;
};

