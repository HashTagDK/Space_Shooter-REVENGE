#include "enemyShipController.h"


// przy bosie nie nie trzeba inicjowaæ typu, bo posiada on swoj¹ listê incjacyjn¹ która ma type=Boss1
enemyShipController::enemyShipController() : 
	enemyExample( enemyShip1::basicTYPE )
{
	timeBetweenShoot = sf::seconds(2.f); 
	
}


enemyShipController::~enemyShipController()
{
}

//Dodawanie strza³ów enemy 
void enemyShipController::update(sf::Time deltaTime, fireTilleController& fireTileController, sf::Vector2f playerPosition) {
	for (std::vector<enemyShip1>::iterator it = enemyShipVector.begin(); it != enemyShipVector.end(); it++) {
		(*it).timeFromLastShoot += deltaTime; 
		if ( (*it).timeFromLastShoot > timeBetweenShoot && (*it).getTypeOfEnemy() == enemyShip1::basicTYPE ) {
			sf::Vector2f position = (*it).rect.getPosition();
			sf::Vector2f size = (*it).rect.getSize();
			position +=sf::Vector2f( (size.x/2 + 5.f), size.y/2);
			
			fireTileController.AddFireTile(position, fire_TileNODE::enemyFiretile); 
			(*it).timeFromLastShoot = sf::Time::Zero;
			std::cout << "Stworzono EnemyFIRETILE*******" << endl;
		}
		(*it).update(deltaTime); 

	}
	enemyBoss.setFire(deltaTime, fireTileController);
	// pod¹¿anie za playerem! 
	enemyBoss.updateBossPosition(playerPosition, deltaTime);
	enemyBoss.update(deltaTime);
}

void enemyShipController::render(sf::RenderWindow& window_) {
	for (std::vector<enemyShip1>::iterator it = enemyShipVector.begin(); it != enemyShipVector.end(); it++)
		(*it).render(window_);
	//Boss 
	enemyBoss.render(window_);
}

void enemyShipController::AddEnemy(sf::Vector2f position) {
	enemyShipVector.push_back(enemyExample);
	enemyShipVector.back().rect.setPosition(position); 
} 

//FORMATIONS-------------------------------------------------------------------- 

/*	Single Enemy */
void enemyShipController::AddSingleEnemy(sf::Vector2f position) {
	AddEnemy(position);
	cout << "okoñ";
} 

/*	*/
void enemyShipController::SetRandom(int amountInRow, int aomountOfRow, float spaceBetweenRows) {
	amountInRow %= 5; 
	//sf::Vector2f positionE = sf::Vector2f(0, 0);
	struct positions {
		sf::Vector2f position;
		bool isCover = false;
	}pos[4];
	//position ; 
	float y = -(aomountOfRow * (spaceBetweenRows));
	for (int i = 0; i < 4; i++)
		pos[i].position = sf::Vector2f(i * 125, y);

	int x = 0;
	

	for (int i = 0; i < aomountOfRow; i++) {
		int randomRow = rand() % amountInRow + 1;
		for (randomRow; randomRow > 0; randomRow--) {
			do {
				x = rand() % 4 + 0;
			} while (pos[x].isCover);
			pos[x].isCover = true; 
			if (x == 0 || x == 3)
				AddEnemy(pos[x].position);
			else
				AddEnemy( sf::Vector2f(pos[x].position.x + rand() % 100 + 0, pos[x].position.y + rand() % 50 + 1) );
			
		}
		y += spaceBetweenRows;
		for (int i2 = 0; i2 < 4; i2++) {
			pos[i2].isCover = false; 
			pos[i2].position.y += spaceBetweenRows;
		}
			
	}
} 

//adding boss 
void enemyShipController::AddBoss() {
	enemyShipVector.push_back(enemyBoss); 
}