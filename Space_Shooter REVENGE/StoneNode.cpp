#include "StoneNode.h"


//sf::Texture StoneNode::textureStone;

StoneNode::StoneNode()
{
	rect.setSize(sf::Vector2f(39, 25)); 
	sprite.setOrigin((rect.getSize().x / 2), (rect.getSize().y / 2));
	m_rotationIncrement = 4.f;
	movementSpeed = 200.f; 
	Damage = 20.f; 
	scoreAmount = 50;
	timeFormLastUpdate = sf::Time::Zero;
}


StoneNode::~StoneNode()
{

}  


void StoneNode::rotateStone() {
	rect.setRotation(rect.getRotation() + m_rotationIncrement); 
	sprite.setRotation(rect.getRotation());
}

/*void StoneNode::animationCoins() {
	if (animationIncrement > 2)
		animationIncrement = 0;
	else animationIncrement++;
	sprite.setTextureRect(sf::IntRect(16*animationIncrement, 0, 16, 20)); 
}*/