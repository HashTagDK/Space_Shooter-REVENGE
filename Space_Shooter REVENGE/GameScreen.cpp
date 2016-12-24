#include "GameScreen.h"



GameScreen::GameScreen()
{
	//backGround 
	if (!backgorund[0].texture.loadFromFile("..\\\\sprite\\background1.png"))
		cout << "B³a¹d przy wczytywnaiu tekstury";
	else {
		//cout << "Wczytano stone";
		backgorund[0].sprite.setTexture(backgorund[0].texture);
		backgorund[0].sprite.setTextureRect(sf::IntRect(0, 0, 480, 800));

		backgorund[0].movementSpeed = 80.f;
		backgorund[1] = backgorund[0];
		backgorund[1].rect.setPosition(sf::Vector2f(0, -800));
	}
	

	//Formations
	m_stoneFormation.SetSingleStone(sf::Vector2f(50, 10));
	//m_stoneFormation.SetArrowFormation();
	//m_stoneFormation.SetBigTriangle(); 
	m_stoneFormation.SetRandom(StoneFormations::Extrem);
}


GameScreen::~GameScreen()
{
} 

void GameScreen::handleInput(sf::RenderWindow& window) {
	//tuaj ma byæ wywo³¹nie metody z klasy player, firetile, stone
	//które trmu odpowiada 
	player_.handleInput();
}

void GameScreen::update(sf::Time delta)
{
	player_.update(delta);
	m_stoneFormation.update(delta);
	//backgorund
	updateBackgorund();
	backgorund[0].update(delta); 
	backgorund[1].update(delta);
}


	

void GameScreen::render(sf::RenderWindow& window) {
	window.draw(backgorund[0].sprite);
	window.draw(backgorund[1].sprite);

	m_stoneFormation.render(window);
	player_.render(window); 
}

void GameScreen::updateBackgorund() {
	if (backgorund[0].rect.getPosition().y > 800)
		backgorund[0].rect.setPosition(sf::Vector2f(0, -800)); 
	if (backgorund[1].rect.getPosition().y > 800)
		backgorund[1].rect.setPosition(sf::Vector2f(0, -800));
}

