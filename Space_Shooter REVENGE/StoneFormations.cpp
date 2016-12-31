#include "StoneFormations.h"



StoneFormations::StoneFormations()
{
	stoneExample.rect.setSize(sf::Vector2f(61, 29));
	//stworzenie objektu który bd wstawiany do stoneVector	
	if (!stoneExample.texture.loadFromFile("..\\\\sprite\\stone.png"))
		cout << "B³a¹d przy wczytywnaiu tekstury";
	else {
		//cout << "Wczytano stone";
		stoneExample.sprite.setTexture(stoneExample.texture);
		//stoneExample.sprite.setTextureRect(sf::IntRect(0, 35, 61, 29));
		stoneExample.sprite.setTextureRect(sf::IntRect(0, (35), 61, 29));
	} 
	
	if (!stoneExample.m_textureDead.loadFromFile("..\\\\sprite\\coin200.png"))
		cout << "B³a¹d przy wczytywnaiu tekstury coins 200";
}


StoneFormations::~StoneFormations()
{
}

/*------Formations--------------------------*/
void StoneFormations::SetArrowFormation() {
	float x = 0; 
	float y = -240;
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

void StoneFormations::SetBigTriangle() {
	float x = 0; 
	float y = -240;
	float rowAmount = 11;

	for (int i = 0; i < 7; i++){
		for (int i2 = rowAmount; i2 > -2; i2--) {
			stoneExample.rect.setRotation(rand() % 180 + 1); 
			stoneExample.rect.setPosition(sf::Vector2f(x, y)); 
			m_stoneVector.push_back(stoneExample);

			x += 39.f;
		} 
		rowAmount -= 2;
		y += 50.f;
		x = (i+1)*39.f;
	}
} 

void StoneFormations::SetRandom(levelDificulty level, int aomountOfRow, float spaceBetweenRows) {
	float x=0; 
	float y= - (aomountOfRow * spaceBetweenRows) - 800 ;

	for (int i = 0; i < aomountOfRow; i++) {
		int randomRow = rand() % level + 1;
		for (randomRow; randomRow > 0; randomRow--) {
			x = rand() % 460 + 0; 
			stoneExample.rect.setRotation(rand() % 180 + 1);
			stoneExample.rect.setPosition(sf::Vector2f(x, y));
			m_stoneVector.push_back(stoneExample);
		} 

		y += spaceBetweenRows;
	}
}
/*---------Update-----Render----------------*/
void StoneFormations::update(sf::Time deltaTime) {
	for (std::vector<StoneNode>::iterator it = m_stoneVector.begin(); it != m_stoneVector.end(); it++) {
		(*it).rotateStone();
		(*it).update(deltaTime); 
		(*it).timeFormLastUpdate += deltaTime;
		//animation 
		if ((*it).m_stateOfObject == Object_Base_Class::Dead && (*it).timeFormLastUpdate.asSeconds() > .05f ) {
			
			(*it).timeFormLastUpdate = sf::Time::Zero;
		}
			
	}
} 

void StoneFormations::render(sf::RenderWindow& window_) {
	for (std::vector<StoneNode>::iterator it = m_stoneVector.begin(); it != m_stoneVector.end(); it++) {
		(*it).render(window_);
	}
}