#pragma once 
#include"Object_Base_Class.h"
#include"SFML/Graphics.hpp"


class StoneNode : public Object_Base_Class
{
public:
	StoneNode();
	~StoneNode(); 
	void rotateStone();
  
private: 
	
	float m_rotationIncrement;
	sf::Texture destroyAnimationTexture;
	//static sf::Texture textureStone;
};

