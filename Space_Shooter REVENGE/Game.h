#pragma once 
#include"Screen.h" 
#include<vector>  
#include<memory>
#include <SFML/Graphics.hpp> 
#include "GameScreen.h"


class Game
{
public:
	Game();
	~Game(); 

	void run(); 

	void handleInput(); 
	void update(sf::Time delta);  
	void render(); 

	static const int Width = 480;
	static const int Height = 800; 

	/*Wskaünik na interfejs z metodami wirtualnymi*/
	static std::shared_ptr<Screen> Screen; 

private:
	sf::RenderWindow window_; 
	
	static const sf::Time TimePerFrame;
};

