#include "enemyShipController.h"



enemyShipController::enemyShipController()
{
	timeBetweenShoot = sf::seconds(1.f);
}


enemyShipController::~enemyShipController()
{
}

void enemyShipController::update(sf::Time deltaTime, fireTilleController& fireTileController) {
	for (std::vector<enemyShip1>::iterator it = enemyShipVector.begin(); it != enemyShipVector.end(); it++) {
		(*it).timeFromLastShoot += deltaTime; 
		if ((*it).timeFromLastShoot > timeBetweenShoot) {
			sf::Vector2f position = (*it).rect.getPosition();
			sf::Vector2f size = (*it).rect.getSize();
			position +=sf::Vector2f( (size.x/2 + 5.f), size.y/2);
			
			fireTileController.AddFireTile(position, fire_TileNODE::enemyFiretile); 
			(*it).timeFromLastShoot = sf::Time::Zero;
			std::cout << "Stworzono EnemyFIRETILE*******" << endl;
		}
		(*it).update(deltaTime); 

	}
		
}

void enemyShipController::render(sf::RenderWindow& window_) {
	for (std::vector<enemyShip1>::iterator it = enemyShipVector.begin(); it != enemyShipVector.end(); it++)
		(*it).render(window_);
}

void enemyShipController::AddEnemy(sf::Vector2f position) {
	enemyShipVector.push_back(enemyExample);
	enemyShipVector.back().rect.setPosition(position);
} 

//FORMATIONS-------------------------------------------------------------------- 

void enemyShipController::AddSingleEnemy(sf::Vector2f position) {
	AddEnemy(position);
	cout << "okoñ";
}