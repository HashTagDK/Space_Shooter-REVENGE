#pragma once 
#include "fire_Tile.h"	
#include "StoneNode.h" 
#include "Player.h" 
#include <vector>
class BoxCollieder
{
public:
	BoxCollieder();
	~BoxCollieder(); 

	void DetectCollision(std::vector<fire_Tile> *fireTilleArray, vector<StoneNode> *tone);
};

