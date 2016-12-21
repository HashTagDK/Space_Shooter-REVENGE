#pragma once 
#include"Object_Base_Class.h"
class StoneNode : public Object_Base_Class
{
public:
	StoneNode();
	~StoneNode();
  
private: 
	float rotation; 
	float m_rotationIncrement;
	sf::Texture destroyAnimationTexture;
};

