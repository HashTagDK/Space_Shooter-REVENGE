#pragma once 
#include "Object_Base_Class.h"


class fire_Tile : public Object_Base_Class
{
public:
	fire_Tile();
	~fire_Tile(); 

	void Update(float deltaTime);
private: 
	float movmentSpeed = -400.f; 
	float damadge = .5f;
	void moveForward(float deltaTime); 
	static sf::Texture textureTile;
	static int i;
};

