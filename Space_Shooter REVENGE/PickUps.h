#pragma once 
#include"pickUp.h" 
#include <vector>
class PickUps
{
public:
	PickUps();
	~PickUps(); 

	void AddPickUp(sf::Vector2f position); 
	void Render(sf::RenderWindow &window); 
	void Update(sf::Time deltaTime);

	std::vector<PickUpNode> pickUpVector;
	void incrementCounterOfKilledEnemy();
	
private:
	int counterOfKilledEnemy = 0; 
	int perioidBetweenPickUpDifferentThanCoin = 3; 
	int previousPickUp = 0;
	PickUpNode pickUpCoinExamle;
	PickUpNode pickUpHearthExample;
	PickUpNode pickUpWeaponUpExample; 
	PickUpNode pickUpSpeedUpExample;	
};

