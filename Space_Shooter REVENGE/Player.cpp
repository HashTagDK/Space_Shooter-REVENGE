#include "Player.h"



Player::Player()
{
	rect.setSize(sf::Vector2f(45, 45)); 
	rect.setPosition(300, 300); 
	sprite.setOrigin((rect.getSize().x / 2), (rect.getSize().y / 2));
	if (!texture.loadFromFile("..\\\\sprite\\palyer_lvl1.png"))
		cout << "B³a¹d przy wczytywnaiu tekstury"; 
	else {
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(94, 0, 45, 45));
	}
	
}


Player::~Player()
{
} 

void Player::setPosition(float deltaTime) {
	/*movment*/
	sprite.setTextureRect(sf::IntRect(94, 0, 45, 45));
	sf::Vector2f move_vector(0, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			move_vector.y = -moveSpeed*deltaTime;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			move_vector.y = moveSpeed*deltaTime;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			move_vector.x = moveSpeed*deltaTime;
			sprite.setTextureRect(sf::IntRect(188, 0, 45, 45));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			move_vector.x = -moveSpeed*deltaTime;
			sprite.setTextureRect(sf::IntRect(0, 0, 45, 45));
		} 

		//rect.move(move_vector); ]
		Update(move_vector);
}