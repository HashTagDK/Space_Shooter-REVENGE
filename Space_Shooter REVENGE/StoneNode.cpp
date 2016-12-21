#include "StoneNode.h"


StoneNode::StoneNode()
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
	//const float Object_Base_Class::movemntSpeed = 100.f; 
	rotation = .0f;
	m_rotationIncrement = 10.f;
}


StoneNode::~StoneNode()
{
	cout << "-Delete_Object<Stone>-\n";
	rect.setSize(sf::Vector2f(31, 35));
	//rect.setPosition(300, 300);
	sprite.setOrigin((rect.getSize().x / 2), (rect.getSize().y / 2));
	if (!destroyAnimationTexture.loadFromFile("..\\\\sprite\\stone_destroy_animation.png"))
		cout << "B³a¹d przy wczytywnaiu tekstury";
	else {
		sprite.setTexture(destroyAnimationTexture);
		for(int i=0; i<7; i++)
			sprite.setTextureRect(sf::IntRect(31*i, 0, 31, 55));
	}
} 
