#include "pickUp.h"



PickUpNode::PickUpNode()
{
	m_pAnimationincrement = 0; 
	m_panimationTime = sf::Time::Zero;
}


PickUpNode::~PickUpNode()
{
} 

bool PickUpNode::isCoin() {
	return Coin;
} 

bool PickUpNode::isHP() {
	return HP;
} 

bool PickUpNode::isImprovment() {
	return Improvment;
}

int PickUpNode::getScore() {
	return m_pScore;
} 

void PickUpNode::setScoreValue(int score) {
	m_pScore = score;
}

void PickUpNode::update(sf::Time deltaTime) {
	sprite.setPosition(rect.getPosition());
	move(deltaTime); 
	
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