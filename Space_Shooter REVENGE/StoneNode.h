#pragma once 
#include"Object_Base_Class.h"
#include"SFML/Graphics.hpp" 



class StoneNode : public Object_Base_Class
{
public:
	StoneNode();
	~StoneNode(); 
	void rotateStone();
  
	sf::Texture m_textureDead; 
	
	sf::Time timeFormLastUpdate;
	int scoreAmount;
	float m_rotationIncrement;
};

