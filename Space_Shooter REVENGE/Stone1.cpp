#include "Stone1.h"



Stone1::Stone1()
{
	rect.setSize(sf::Vector2f(39, 25));
	rect.setPosition(300, 300);
	sprite.setOrigin((rect.getSize().x / 2), (rect.getSize().y / 2));
	if (!texture.loadFromFile("..\\\\sprite\\stone.png"))
		cout << "B³a¹d przy wczytywnaiu tekstury";
	else {
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(27, 20, 39, 25));
	} 
	movemntSpeed = 100.f; 
	rotation = .0f;
	m_rotationIncrement = 10.f;
}


Stone1::~Stone1()
{
} 
