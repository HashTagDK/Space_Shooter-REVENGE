#pragma once 
#include "fire_Tile.h"	
#include "StoneNode.h" 
#include "Player.h" 
#include <vector>
#include "MusicController.h" 
#include "pickUp.h"
#include "PickUps.h"
class BoxCollieder
{
public:
	BoxCollieder();
	~BoxCollieder(); 

	void DetectCollision(Player *player, vector<StoneNode> *stone, vector<PickUpNode> *pickUp, PickUps * pickUpController);

private:
	void GarbagCollector(vector<fire_Tile> *fireTileVector, vector<StoneNode> *stoneVector, vector<PickUpNode> *pickUp);
	MusicController musicController;
};

