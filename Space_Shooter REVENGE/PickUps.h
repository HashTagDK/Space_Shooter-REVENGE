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
private:
	PickUpNode pickUpCoinExamle;
	
};

