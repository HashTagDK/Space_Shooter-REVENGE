#include "GameOVerScreen.h"



GameOVerScreen::GameOVerScreen(int score_) :
	score(score_)
{

	if (!backgoundTexture.loadFromFile("..\\\\sprite\\gameover.png"))
		std::cout << "Nie wczytano textury gameover!!!";
	else {
		backgroundSprite.setTextureRect(sf::IntRect(0, 0, 480, 800));
		backgroundSprite.setTexture(backgoundTexture);
		backgroundSprite.setPosition(sf::Vector2f(0, 0));
	}
	//ustawianie napisu do score: 
	if (!font.loadFromFile("..\\\\font\\ARCADECLASSIC.ttf"))
		cout << "Nie wczytano czcionki!!!" << endl;
	else
		scoreText = sf::Text(""+std::to_string(score) , font, 40);
	//scoreText.setColor(sf::Color::Red);
	scoreText.setPosition(220, 400); 
	musicController.play_dead();
}


GameOVerScreen::~GameOVerScreen()
{
} 

void GameOVerScreen::handleInput(sf::RenderWindow& window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		Game::Screen = std::make_shared<GameScreen>();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		Game::Screen = std::make_shared<StartScreen>();
	}
} 

void GameOVerScreen::update(sf::Time deltTime) {

} 

void GameOVerScreen::render(sf::RenderWindow& window) {
	window.draw(backgroundSprite); 
	window.draw(scoreText);
}
