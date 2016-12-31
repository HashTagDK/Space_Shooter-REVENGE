#include "Game.h"

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 30.f);

/*ustawiamy Screen aby wskazywa³ na kalsê GameScreem która dziedziczy po Screen 
	w tej klasie s¹ <MUSZ¥! byæ> zaimplementowane metody czysto wirtualne z interfejsu Screen*/
//std::shared_ptr<Screen> Game::Screen = std::make_shared<GameScreen>();

std::shared_ptr<Screen> Game::Screen = std::make_shared<StartScreen>();

Game::Game() : window_(sf::VideoMode(Game::Width, Game::Height), "Space_Shooter REVENGE") //lista incjacyjna (Window)
{
}

Game::~Game()
{
} 

void Game::handleInput()
{
	sf::Event event; 

	while (window_.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window_.close();
	} 

	Game::Screen->handleInput(window_);
}

void Game::update(sf::Time delta) {
	Game::Screen->update(delta);
}

void Game::render() {
	window_.clear();
	Game::Screen->render(window_); 
	window_.display();
} 

void Game::run() {
	sf::Clock clock; 
	sf::Time timeSinceLastUpdate = sf::Time::Zero; 

	while (window_.isOpen()) {
		sf::Time delta = clock.restart(); 
		timeSinceLastUpdate += delta; 

		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame; 
			handleInput(); 
			update(TimePerFrame);
		} 

		render();
	}
}