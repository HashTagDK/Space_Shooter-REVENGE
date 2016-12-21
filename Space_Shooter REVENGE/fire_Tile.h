#pragma once 
#include "Object_Base_Class.h"


class fire_Tile : public Object_Base_Class
{
public:
	fire_Tile();
	fire_Tile(const fire_Tile& fireCopy);
	~fire_Tile(); 


private:  
	float damadge = .5f;
	static sf::Texture textureTile;
	static int i;
};

