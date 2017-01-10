#include"fireTilleController.h"  

fireTilleController::fireTilleController() : 
	playerFireTile( fire_TileNODE::playerFireTile ), 
	enemyFireTile ( fire_TileNODE::enemyFiretile )
{

}

fireTilleController::~fireTilleController() {

}

void fireTilleController::update(sf::Time deltaTime) {
	for (std::vector<fire_TileNODE>::iterator it = fireTileVector.begin(); it != fireTileVector.end(); it++)
		(*it).update(deltaTime);
}

void fireTilleController::render(sf::RenderWindow& window_) {
	for (std::vector<fire_TileNODE>::iterator it = fireTileVector.begin(); it != fireTileVector.end(); it++)
		(*it).render(window_);
}

void fireTilleController::AddFireTile(sf::Vector2f position, fire_TileNODE::typeOFFireTile type) {
	if (type == fire_TileNODE::playerFireTile)
		fireTileVector.push_back(playerFireTile);
	else if (type == fire_TileNODE::enemyFiretile)
		fireTileVector.push_back(enemyFireTile); 

	fireTileVector.back().rect.setPosition(position);
}