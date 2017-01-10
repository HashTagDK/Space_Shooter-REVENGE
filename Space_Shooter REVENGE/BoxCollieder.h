#pragma once 
#include "fire_Tile.h"	
#include "StoneNode.h" 
#include "Player.h" 
#include <vector>
#include "MusicController.h" 
#include "pickUp.h"
#include "PickUps.h" 
#include "fireTilleController.h" 
#include "enemyShip1.h"
class BoxCollieder
{
public:
	BoxCollieder();
	~BoxCollieder(); 

	void DetectCollision(Player *player, vector<StoneNode> *stone, vector<PickUpNode> *pickUp, PickUps * pickUpController, fireTilleController *fireTileVector_, vector<enemyShip1> &enemyShipVector);

private:
	void GarbagCollector(vector<fire_TileNODE> *fireTileVector, vector<StoneNode> *stoneVector, vector<PickUpNode> *pickUp, vector<enemyShip1> &enemyShipVector);
	MusicController musicController;
};

