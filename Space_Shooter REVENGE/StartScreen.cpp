#include "StartScreen.h"
#include<iostream>



StartScreen::StartScreen()
{
	if (!backgoundTexture.loadFromFile("..\\\\sprite\\startowaStrona.png"))
		std::cout << "Nie wczytano textury startPage!!!"; 
	else {
		backgroundSprite.setTextureRect(sf::IntRect(0,0, 480, 800)); 
		backgroundSprite.setTexture(backgoundTexture);
		backgroundSprite.setPosition(sf::Vector2f(0, 0));
	} 

	//pointer ship  
	m_pos = 0;
	m_positionVector = sf::Vector2f(130, 450);
	m_position = StartScreen::StartGame;
	if (!texturePointer.loadFromFile("..\\\\sprite\\palyer_lvl1.png"))
		std::cout << "B³a¹d przy wczytywnaiu tekstury";
	else {
		spritePointer.setTexture(texturePointer);
		spritePointer.setTextureRect(sf::IntRect(94, 0, 45, 45)); 
		spritePointer.setPosition(m_positionVector); 
		spritePointer.setRotation(90.f);
	}
}


StartScreen::~StartScreen()
{
}

void StartScreen::handleInput(sf::RenderWindow &window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && m_position!=StartScreen::StartGame) {
		m_positionVector.y -= 60.f;
		prevEnum();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && m_position != StartScreen::Exit) {
		m_positionVector.y += 60.f;
		nextEnum();
	}

	//obs³uga po wiciœniêciu entera na danej pozycji 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
		std::cout << "Enter pressed!";
		if (m_position == StartScreen::Exit)
			window.close(); 
		if (m_position == StartScreen::StartGame)
			Game::Screen = std::make_shared<GameScreen>();
	}
}

void StartScreen::render(sf::RenderWindow &window) {
	window.draw(backgroundSprite); 
	window.draw(spritePointer);
} 

void StartScreen::update(sf::Time deltaTime) {
	spritePointer.setPosition(m_positionVector);
}

void StartScreen::nextEnum() {
	m_position = (position)++m_pos;
}
void StartScreen::prevEnum() {
	m_position = (position)--m_pos;
}