#include "GameScreen.h"



GameScreen::GameScreen()
{
	//backGround 
	if (!backgorund[0].texture.loadFromFile("..\\\\sprite\\background1.png"))
		cout << "B³a¹d przy wczytywnaiu tekstury t³a";
	else {
		//cout << "Wczytano stone";
		backgorund[0].sprite.setTexture(backgorund[0].texture);
		backgorund[0].sprite.setTextureRect(sf::IntRect(0, 0, 480, 800));

		backgorund[0].movementSpeed = 80.f;
		backgorund[1] = backgorund[0];
		backgorund[1].rect.setPosition(sf::Vector2f(0, -800));
	}
	
	//ustawienie health bar: 
	sizeOfHealtBar = sf::Vector2f(150, 18);
	if (!healthBarTexture.loadFromFile("..\\\\sprite\\healtBar.png"))
		cout << "B³a¹d przy wczytywnaiu tekstury healtBar";
	else {
		healthBarSprite.setTextureRect(sf::IntRect(0, 0, sizeOfHealtBar.x, sizeOfHealtBar.y)); 
		healthBarSprite.setTexture(healthBarTexture);
		healthBarSprite.setPosition(sf::Vector2f(310, 15));
	}
	healthRectangeShape.setSize(sizeOfHealtBar);
	healthRectangeShape.setFillColor(sf::Color::Red); 
	healthRectangeShape.setPosition(sf::Vector2f(310, 15));
	
	//ustawianie napisu do score: 
	if (!m_font.loadFromFile("..\\\\font\\ARCADECLASSIC.ttf"))
		cout << "Nie wczytano czcionki!!!" << endl;
	else
		m_score = sf::Text("Score  0", m_font, 28);
	
	m_score.setPosition(20, 5);
	musicController.play_gameLoopMusicStage1();

	//Formations
	m_stoneFormation.SetSingleStone(sf::Vector2f(50, 10));
	//m_stoneFormation.SetArrowFormation();
	//m_stoneFormation.SetBigTriangle(); 
	m_stoneFormation.SetRandom(StoneFormations::Normal);
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
	m_boxCollider.DetectCollision(&player_, &m_stoneFormation.m_stoneVector);
	player_.update(delta);
	m_stoneFormation.update(delta);
	//backgorund
	updateBackgorund();
	backgorund[0].update(delta); 
	backgorund[1].update(delta); 
	updateHealthBar(); 
	updateScore();
}


	

void GameScreen::render(sf::RenderWindow& window) {
	window.draw(backgorund[0].sprite);
	window.draw(backgorund[1].sprite);
	m_stoneFormation.render(window);
	window.draw(healthRectangeShape);
	window.draw(healthBarSprite);
	window.draw(m_score);
	player_.render(window); 
}

void GameScreen::updateBackgorund() {
	if (backgorund[0].rect.getPosition().y > 800)
		backgorund[0].rect.setPosition(sf::Vector2f(0, -800)); 
	if (backgorund[1].rect.getPosition().y > 800)
		backgorund[1].rect.setPosition(sf::Vector2f(0, -800));
}

void GameScreen::updateHealthBar() {
	healthRectangeShape.setSize(sf::Vector2f(sizeOfHealtBar.x * (player_.hp / 100.f), sizeOfHealtBar.y));
}

void GameScreen::updateScore() {
	
	m_score.setString("Score  " + std::to_string(player_.score));
}
