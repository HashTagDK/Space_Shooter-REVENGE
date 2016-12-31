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
	//m_stoneFormation.SetSingleStone(sf::Vector2f(50, 10));
	positionInQue = 0;
	lifeTimeOfGameScreen = sf::Time::Zero; 
}


GameScreen::~GameScreen()
{
} 

void GameScreen::handleInput(sf::RenderWindow& window) {
	//tuaj ma byæ wywo³¹nie metody z klasy player, firetile, stone
	//które trmu odpowiada 
	player_.handleInput();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
		Game::Screen = std::make_shared<GameOVerScreen>(player_.score);
	}
}

void GameScreen::update(sf::Time delta)
{
	m_boxCollider.DetectCollision(&player_, &m_stoneFormation.m_stoneVector, &m_pickups.pickUpVector, &m_pickups);
	player_.update(delta);
	m_stoneFormation.update(delta);
	//backgorund
	updateBackgorund();
	backgorund[0].update(delta); 
	backgorund[1].update(delta); 
	updateHealthBar(); 
	updateScore();
	
	//enemy
	enemyController(delta);
	// pick ups 
	m_pickups.Update(delta);
	//sprawdzanie czy hp  nie jest poni¿ej 0
	if (player_.hp <= 0)
		Game::Screen = std::make_shared<GameOVerScreen>(player_.score);
}


	

void GameScreen::render(sf::RenderWindow& window) {
	window.draw(backgorund[0].sprite);
	window.draw(backgorund[1].sprite);
	
	m_stoneFormation.render(window);
	m_pickups.Render(window);

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

void GameScreen::enemyController(sf::Time deltaTime) {
	lifeTimeOfGameScreen += deltaTime; 


	if (positionInQue == 0) {
		positionInQue++; 
		m_stoneFormation.SetRandom(StoneFormations::Normal, 10, 10.f);
	} 
	if (positionInQue == 1 && lifeTimeOfGameScreen.asSeconds() > 5.f) {
		positionInQue++; 
		m_stoneFormation.SetArrowFormation();
	}

	if (positionInQue == 2 && lifeTimeOfGameScreen.asSeconds() > 10.f) {
		positionInQue++; 
		m_stoneFormation.SetRandom(StoneFormations::Normal, 20, 20.f);
	} 

	if (positionInQue == 3 && lifeTimeOfGameScreen.asSeconds() > 22.f) {
		positionInQue++; 
		m_stoneFormation.SetRandom(StoneFormations::Hard, 15, 50.f);
	}
}
