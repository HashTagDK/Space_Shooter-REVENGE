#pragma once 
#include "fire_Tile.h"	
#include "StoneNode.h" 
#include "Player.h" 
#include <vector>
#include "MusicController.h"
class BoxCollieder
{
public:
	BoxCollieder();
	~BoxCollieder(); 

	void DetectCollision(Player *player, vector<StoneNode> *stone);  

private:
	void GarbagCollector(vector<fire_Tile> *fireTileVector, vector<StoneNode> *stoneVector);
	MusicController musicController;
};

