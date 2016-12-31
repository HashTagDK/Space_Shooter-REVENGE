#include "PickUps.h"



PickUps::PickUps()
{
	if (!pickUpCoinExamle.texture.loadFromFile("..\\\\sprite\\coin200.png"))
		cout << "B³a¹d przy wczytywnaiu tekstury coins 200 <GameScreen>";
	else {
		pickUpCoinExamle.rect.setSize(sf::Vector2f(16, 20));
		pickUpCoinExamle.sprite.setTexture(pickUpCoinExamle.texture);
		pickUpCoinExamle.sprite.setTextureRect(sf::IntRect(0, 0, 16, 20));
		pickUpCoinExamle.m_stateOfObject = Object_Base_Class::Active; 
		pickUpCoinExamle.movementSpeed = 70.f;
		
		pickUpCoinExamle.setScoreValue(50.f); 
		
		pickUpCoinExamle.Coin = true;
	}
}


PickUps::~PickUps()
{
} 

void PickUps::AddPickUp(sf::Vector2f position) {

	pickUpCoinExamle.rect.setPosition(position);  
	pickUpVector.push_back(pickUpCoinExamle);
} 

void PickUps::Render(sf::RenderWindow& window_) {
	for (std::vector<PickUpNode>::iterator it = pickUpVector.begin(); it != pickUpVector.end(); it++) {
		window_.draw((*it).sprite);
	}	
}

void PickUps::Update(sf::Time deltaTime) {
	for (std::vector<PickUpNode>::iterator it = pickUpVector.begin(); it != pickUpVector.end(); it++) {
		(*it).update(deltaTime); 
		//std::cout << "x = " << (*it).rect.getPosition().x << "\ty = " << (*it).rect.getPosition().y << endl;
	}
		
}