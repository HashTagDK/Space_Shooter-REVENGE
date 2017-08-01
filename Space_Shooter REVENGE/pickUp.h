#pragma once 
#include "Object_Base_Class.h"
class PickUpNode : public Object_Base_Class
{
public:
	/*4 typy mo¿liwych do zebrania pickUp'ów*/
	enum typeOfPickUp {
		Coin = 0,
		HealthAdd,
		SpeedUp,
		WeaponUp
	};

	PickUpNode(typeOfPickUp type);
	~PickUpNode(); 

	bool isCoin();
	bool isHP(); 
	bool isSpeedUp(); 
	bool isWeaponAdd(); 

	float getScore();
	void setScoreValue(float score);

	 void update(sf::Time deltaTime);
	 void animate(sf::Time deltaTime);

private: 

	typeOfPickUp m_pType;
	bool coin = false;
	bool hP = false;
	bool speedUp = false;
	bool weaponUp = false;
	
	float m_pScore;

	sf::Time m_panimationTime; 
	int m_pAnimationincrement;

};

