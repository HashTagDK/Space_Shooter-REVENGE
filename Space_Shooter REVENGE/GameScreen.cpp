#include "GameScreen.h"



GameScreen::GameScreen()
{
}


GameScreen::~GameScreen()
{
} 

void GameScreen::handleInput(sf::RenderWindow& window) {
	//tuaj ma by� wywo��nie metody z klasy player, firetile, stone
	//kt�re trmu odpowiada 
	player_.handleInput();
}

void GameScreen::update(sf::Time delta)
{
	player_.update(delta);
}


	

void GameScreen::render(sf::RenderWindow& window) {
	player_.render(window);
}

