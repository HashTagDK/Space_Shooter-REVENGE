#include "StoneNode.h"


//sf::Texture StoneNode::textureStone;

StoneNode::StoneNode()
{
	rect.setSize(sf::Vector2f(39, 25));
	//rect.setPosition(position); 
	sprite.setOrigin((rect.getSize().x / 2), (rect.getSize().y / 2));
	//rect.setPosition(sf::Vector2f(100, 100));
	/*sprite.setOrigin((rect.getSize().x / 2), (rect.getSize().y / 2));
	if (!textureStone.loadFromFile("..\\\\sprite\\stone.png"))
		cout << "B³a¹d przy wczytywnaiu tekstury";
	else {
		//cout << "Wczytano stone";
		sprite.setTexture(textureStone);
		sprite.setTextureRect(sf::IntRect(27, 20, 39, 25));
	} */

	m_rotationIncrement = 4.f;
	movementSpeed = 100.f; 
	Damage = 10.f; 
	scoreAmount = 50;
	timeFormLastUpdate = sf::Time::Zero;
}


StoneNode::~StoneNode()
{
	//cout << "-Delete_Object<Stone>-\n";
	/*rect.setSize(sf::Vector2f(31, 35));
	//rect.setPosition(300, 300);
	sprite.setOrigin((rect.getSize().x / 2), (rect.getSize().y / 2));
	if (!destroyAnimationTexture.loadFromFile("..\\\\sprite\\stone_destroy_animation.png"))
		cout << "B³a¹d przy wczytywnaiu tekstury";
	else {
		sprite.setTexture(destroyAnimationTexture);
		for(int i=0; i<7; i++)
			sprite.setTextureRect(sf::IntRect(31*i, 0, 31, 55));
	}*/
}  


void StoneNode::rotateStone() {
	rect.setRotation(rect.getRotation() + m_rotationIncrement); 
	sprite.setRotation(rect.getRotation());
}

void StoneNode::animationCoins() {
	if (animationIncrement > 2)
		animationIncrement = 0;
	else animationIncrement++;
	sprite.setTextureRect(sf::IntRect(16*animationIncrement, 0, 16, 20)); 
}