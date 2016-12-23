#include "StoneFormations.h"



StoneFormations::StoneFormations()
{
	
	if (!stoneExample.texture.loadFromFile("..\\\\sprite\\stone.png"))
		cout << "B³a¹d przy wczytywnaiu tekstury";
	else {
		//cout << "Wczytano stone";
		stoneExample.sprite.setTexture(stoneExample.texture);
		stoneExample.sprite.setTextureRect(sf::IntRect(27, 20, 39, 25));
	}
}


StoneFormations::~StoneFormations()
{
}

void StoneFormations::SetTriangleFormation() {
	float x = 0; 
	float y = -150;
	for (int i = 0; i < 11; i++) {
		x += 39.f;
		if (i < 6)
			y += 30;
		else
			y -= 30;
		
		//m_stoneVector.emplace_back(sf::Vector2f(x, y));  
		stoneExample.rect.setRotation(rand() % 180 + 1);
		stoneExample.rect.setPosition(sf::Vector2f(x, y));
		m_stoneVector.push_back(stoneExample);
	}
} 

void StoneFormations::SetSingleStone(sf::Vector2f position){
	stoneExample.rect.setPosition(position); 
	m_stoneVector.push_back(stoneExample);
}

void StoneFormations::update(sf::Time deltaTime) {
	for (std::vector<StoneNode>::iterator it = m_stoneVector.begin(); it != m_stoneVector.end(); it++) {
		(*it).rotateStone();
		(*it).update(deltaTime); 
	}
} 

void StoneFormations::render(sf::RenderWindow& window_) {
	for (std::vector<StoneNode>::iterator it = m_stoneVector.begin(); it != m_stoneVector.end(); it++) {
		(*it).render(window_);
	}
}