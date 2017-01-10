#pragma once 
#include "Object_Base_Class.h"


class fire_TileNODE : public Object_Base_Class
{
public:
	enum typeOFFireTile {
		playerFireTile = 0,
		enemyFiretile
	};
	fire_TileNODE(typeOFFireTile TYPE);
	~fire_TileNODE();  
	typeOFFireTile getTypeOfFireTile();
private:  
	float damadge = .5f;
	static sf::Texture textureTile;
	static int i;
	typeOFFireTile typeFire;
};

