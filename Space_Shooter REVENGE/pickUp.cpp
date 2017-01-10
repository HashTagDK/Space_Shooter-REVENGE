#include "pickUp.h"



PickUpNode::PickUpNode(typeOfPickUp type)
{
	m_pType = type;

	m_panimationTime = sf::Time::Zero; 
	
	if (type == PickUpNode::Coin) {
		m_pAnimationincrement = 0; 
		coin = true; 
	}

	if (type == PickUpNode::HealthAdd)
		hP = true;
	if (type == PickUpNode::SpeedUp)
		speedUp = true; 
	if (type == PickUpNode::WeaponUp)
		weaponUp = true;
}


PickUpNode::~PickUpNode()
{
} 

bool PickUpNode::isCoin() {
	return coin;
} 

bool PickUpNode::isHP() {
	return hP;
} 

bool PickUpNode::isSpeedUp() {
	return speedUp;
}

bool PickUpNode::isWeaponAdd() {
	return weaponUp;
}

float PickUpNode::getScore() {
	return m_pScore;
} 

void PickUpNode::setScoreValue(float score) {
	m_pScore = score;
}

void PickUpNode::update(sf::Time deltaTime) {
	sprite.setPosition(rect.getPosition());
	move(deltaTime); 
	
	if(m_pType == Coin)
		animate(deltaTime);
} 

//16 jest na szsytwno do coins
void PickUpNode::animate(sf::Time deltaTime) {
	m_panimationTime += deltaTime;

	if (m_pAnimationincrement > 2) m_pAnimationincrement = 0;
	if (m_panimationTime.asSeconds() > .1f) {
		sprite.setTextureRect(sf::IntRect(16 * m_pAnimationincrement, 0, 16, 20));

		m_panimationTime = sf::Time::Zero;
		m_pAnimationincrement++;
	}
}