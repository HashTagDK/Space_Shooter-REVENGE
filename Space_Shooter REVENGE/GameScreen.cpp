#include "GameScreen.h"



GameScreen::GameScreen()
{
	m_stoneFormation.SetSingleStone(sf::Vector2f(50, 10));
	m_stoneFormation.SetTriangleFormation();
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
	m_stoneFormation.update(delta);
}


	

void GameScreen::render(sf::RenderWindow& window) {
	m_stoneFormation.render(window);
	player_.render(window); 
}

