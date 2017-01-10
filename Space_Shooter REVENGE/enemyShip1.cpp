#include "enemyShip1.h"



enemyShip1::enemyShip1()
{ 
	move_vector = sf::Vector2f(0, 0);
	movementSpeed = 50.f;
	rect.setSize(sf::Vector2f(100, 50));
	//rect.setPosition(240, 750);
	//sprite.setOrigin((rect.getSize().x / 2), (rect.getSize().y / 2));
	if (!texture.loadFromFile("..\\\\sprite\\enemy1.png"))
		cout << "B³a¹d przy wczytywnaiu tekstury";
	else {
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0, 0, 100, 50));
	} 
	hp = 50;
	Damage = 50; 
	timeFromLastShoot = sf::Time::Zero;
}


enemyShip1::~enemyShip1()
{
} 

void enemyShip1::decrementHP(int score) {
	hp -= score;
} 

int enemyShip1::getHP() {
	return hp;
}
