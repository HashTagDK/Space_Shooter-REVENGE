#include "Player.h"



Player::Player()
{
	rect.setSize(sf::Vector2f(45, 45)); 
	rect.setPosition(300, 300); 

	if (!texture.loadFromFile("..\\\\sprite\\palyer_lvl1.png"))
		cout << "B³a¹d przy wczytywnaiu tekstury"; 
	else {
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(94, 0, 45, 45));
	}
		;
	
}


Player::~Player()
{
} 

void Player::Update() {
	sprite.setPosition(rect.getPosition());
} 

void Player::Movement() {
	/*movment*/
	sprite.setTextureRect(sf::IntRect(94, 0, 45, 45));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			rect.move(0, -moveSpeed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			rect.move(0, moveSpeed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			rect.move(moveSpeed, 0);
			sprite.setTextureRect(sf::IntRect(188, 0, 45, 45));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			rect.move(-moveSpeed, 0);
			sprite.setTextureRect(sf::IntRect(0, 0, 45, 45));
		}
}