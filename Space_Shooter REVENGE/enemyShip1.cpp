#include "enemyShip1.h"



enemyShip1::enemyShip1( enemyShip1::typeOfEnemy type)
{  
	//ustawienie jakiego typu jest objekt 
	m_typeOfObject = type; 

	if (type == enemyShip1::basicTYPE) {
		move_vector = sf::Vector2f(0, 0);
		movementSpeed = 100.f;
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
	
	else if (type == enemyShip1::Boss1) {
		move_vector = sf::Vector2f(0, 0);
		movementSpeed = 0.001f;
		rect.setSize(sf::Vector2f(200, 200));
		//rect.setPosition(240, 750);
		//sprite.setOrigin((rect.getSize().x / 2), (rect.getSize().y / 2));
		if (!texture.loadFromFile("..\\\\sprite\\boss1.png"))
			cout << "B³a¹d przy wczytywnaiu tekstury";
		else {
			sprite.setTexture(texture);
			sprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
		}
		hp = 100;
		Damage = 50;
		timeFromLastShoot = sf::Time::Zero;
		m_stateOfObject = enemyShip1::notActive;
	}
}

enemyShip1::typeOfEnemy enemyShip1::getTypeOfEnemy() {
	return m_typeOfObject;
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
