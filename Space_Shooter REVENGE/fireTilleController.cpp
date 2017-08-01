#include"fireTilleController.h"  

fireTilleController::fireTilleController() : 
	playerFireTile( fire_TileNODE::playerFireTile ), 
	enemyFireTile ( fire_TileNODE::enemyFiretile ), 
	laserAttack ( fire_TileNODE:: laserAttack )
{

}

fireTilleController::~fireTilleController() {

}

void fireTilleController::update(sf::Time deltaTime, sf::Vector2f bossPos) {
	for (std::vector<fire_TileNODE>::iterator it = fireTileVector.begin(); it != fireTileVector.end(); it++)
	{
		if ((*it).getTypeOfFireTile() == fire_TileNODE::laserAttack) {
			(*it).updateLaser( (*it).lifeTimeLaser, bossPos );
		}
		else
			(*it).update(deltaTime);
	}
		
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

void fireTilleController::AddLaserAttack(sf::Vector2f position, fire_TileNODE::typeOFFireTile type) {
	if (type == fire_TileNODE::laserAttack) {
		//tu ma byæ odanny inny firetile typu laser 
		/*cout << "LASER ATTACK!!!!!" << endl;
		fireTileVector.push_back( laserAttack );

		fireTileVector.back().rect.setPosition(position);*/
	}
}