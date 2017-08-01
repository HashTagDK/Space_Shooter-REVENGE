#include "PickUps.h"



PickUps::PickUps() : 
	pickUpCoinExamle(PickUpNode::Coin), 
	pickUpHearthExample(PickUpNode::HealthAdd), 
	pickUpWeaponUpExample(PickUpNode::WeaponUp),
	pickUpSpeedUpExample(PickUpNode::SpeedUp)

{
	/*------------------Coin------------------------------------------------------------------*/
	if (!pickUpCoinExamle.texture.loadFromFile("..\\\\sprite\\coin200.png"))
		cout << "B³a¹d przy wczytywnaiu tekstury coins 200 <GameScreen>";
	else {
		pickUpCoinExamle.rect.setSize(sf::Vector2f(16, 20));
		pickUpCoinExamle.sprite.setTexture(pickUpCoinExamle.texture);
		pickUpCoinExamle.sprite.setTextureRect(sf::IntRect(0, 0, 16, 20));
		pickUpCoinExamle.m_stateOfObject = Object_Base_Class::Active;
		pickUpCoinExamle.movementSpeed = 70.f;

		pickUpCoinExamle.setScoreValue(50.f);

	}
	/*--------------------------Hp-Add--------------------------------------------------------*/
	if (!pickUpHearthExample.texture.loadFromFile("..\\\\sprite\\heart.png"))
		cout << "B³a¹d przy wczytywnaiu tekstury hearth <GameScreen>";
	else {
		pickUpHearthExample.rect.setSize(sf::Vector2f(25, 22));
		pickUpHearthExample.sprite.setTexture(pickUpHearthExample.texture);
		pickUpHearthExample.sprite.setTextureRect(sf::IntRect(0, 0, 25, 22));
		pickUpHearthExample.m_stateOfObject = Object_Base_Class::Active;
		pickUpHearthExample.movementSpeed = 70.f;
		
		pickUpHearthExample.setScoreValue(25.f);
		cout << "HP++";
	}
	/*--------------WEAPON-UP---------------------------------------------------------------*/
	if (!pickUpWeaponUpExample.texture.loadFromFile("..\\\\sprite\\weapon_speedUp.png"))
		cout << "B³a¹d przy wczytywnaiu tekstury weapon <GameScreen>";
	else {
		pickUpWeaponUpExample.rect.setSize(sf::Vector2f(20, 35));
		pickUpWeaponUpExample.sprite.setTexture(pickUpWeaponUpExample.texture);
		pickUpWeaponUpExample.sprite.setTextureRect(sf::IntRect(0, 0, 20, 35));
		pickUpWeaponUpExample.m_stateOfObject = Object_Base_Class::Active;
		pickUpWeaponUpExample.movementSpeed = 70.f;

		pickUpWeaponUpExample.setScoreValue(.05f);
		cout << "weapon++";
	} 
	/*--------------------Speed-UP---------------------------------------------*/
	if (!pickUpSpeedUpExample.texture.loadFromFile("..\\\\sprite\\weapon_speedUp.png"))
		cout << "B³a¹d przy wczytywnaiu tekstury speed <GameScreen>";
	else {
		pickUpSpeedUpExample.rect.setSize(sf::Vector2f(20, 35));
		pickUpSpeedUpExample.sprite.setTexture(pickUpSpeedUpExample.texture);
		pickUpSpeedUpExample.sprite.setTextureRect(sf::IntRect(0, 43, 20, 35));
		pickUpSpeedUpExample.m_stateOfObject = Object_Base_Class::Active;
		pickUpSpeedUpExample.movementSpeed = 70.f;

		pickUpSpeedUpExample.setScoreValue(10.f);
		cout << "weapon++";
	}
}


PickUps::~PickUps()
{
} 

void PickUps::AddPickUp(sf::Vector2f position) {
	counterOfKilledEnemy %= perioidBetweenPickUpDifferentThanCoin; 
	cout << "Perioid: " << counterOfKilledEnemy<< endl;
	
	position += sf::Vector2f(5.f, 5.f);
	int randPickUp;
	if (counterOfKilledEnemy == 0) {
		do 
		{
				randPickUp = rand() % 3 + 0;
		} while (randPickUp == previousPickUp);
		previousPickUp = randPickUp;
		 

		switch (randPickUp)
		{
		case 0: 
			pickUpWeaponUpExample.rect.setPosition(position);
			pickUpVector.push_back(pickUpWeaponUpExample);
			break; 
		case 1: 
			pickUpHearthExample.rect.setPosition(position);
			pickUpVector.push_back(pickUpHearthExample);
			break; 
		case 2:
			pickUpSpeedUpExample.rect.setPosition(position);
			pickUpVector.push_back(pickUpSpeedUpExample);
			break;
		default:
			
			break;
		}
		
	}
	else {
		pickUpCoinExamle.rect.setPosition(position);
		pickUpVector.push_back(pickUpCoinExamle);
	}
	
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

void PickUps::incrementCounterOfKilledEnemy() {
	counterOfKilledEnemy++;
}