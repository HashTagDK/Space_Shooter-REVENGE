#pragma once 
#include "Object_Base_Class.h"
class PickUpNode : public Object_Base_Class
{
public:
	PickUpNode();
	~PickUpNode(); 

	bool isCoin();
	bool isHP(); 
	bool isImprovment(); 
	int getScore();
 
	 bool Coin = false; 
	 bool HP = false; 
	 bool Improvment = false;  
	 int m_socre; 
	 void setScoreValue(int score);

	 void update(sf::Time deltaTime);
	 void animate(sf::Time deltaTime);
private: 

	int m_pScore;

	sf::Time m_panimationTime; 
	int m_pAnimationincrement;

};

