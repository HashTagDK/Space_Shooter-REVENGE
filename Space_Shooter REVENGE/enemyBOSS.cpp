#include "enemyBOSS.h"



enemyBOSS::enemyBOSS() : 
	enemyShip1( enemyShip1::Boss1 )
{
	timeBetweenDoubleShoot = sf::seconds(.8f);  
	timeBetweenCenterShoot = sf::seconds(.5f);
	timeFromLastShoot = sf::Time::Zero;
	
	timeBetweenLaserAttack = sf::seconds(5.f);
	
	//rect.setPosition(sf::Vector2f(rect.getPosition().x, -1200));  
	rect.setPosition(sf::Vector2f(-500, -1200));

	hp1 = 2000;
}


enemyBOSS::~enemyBOSS()
{
}  

void enemyBOSS::decrementHP(int value) {
	hp1 -= value;
} 
int enemyBOSS::getHP() {
	return hp1;
}

void enemyBOSS::setFire(sf::Time deltaTime, fireTilleController& fireTileController) {
	timeFromLastShoot += deltaTime;  
	timeFromLastLaserAttack += deltaTime; 
	timeFromLastCenterShoot += deltaTime;
	sf::Vector2f position = rect.getPosition();
	sf::Vector2f size = rect.getSize();
	
	if (timeFromLastCenterShoot > timeBetweenCenterShoot) {
		position += sf::Vector2f(((size.x / 5)*2 + 5.f), size.y / 4);
		timeFromLastCenterShoot = sf::Time::Zero;
		fireTileController.AddFireTile(position, fire_TileNODE::enemyFiretile);
	}
	if ( timeFromLastShoot > timeBetweenDoubleShoot) {
		
		position += sf::Vector2f((size.x / 5 + 5.f), size.y / 4);

		fireTileController.AddFireTile(position, fire_TileNODE::enemyFiretile);
		
		position += sf::Vector2f(((size.x / 5)*3 + 5.f), 0); 
		fireTileController.AddFireTile(position, fire_TileNODE::enemyFiretile);
		
		timeFromLastShoot = sf::Time::Zero;
		//std::cout << "Stworzono EnemyFIRETILE---B-O-S-S-*******" << endl;
	} 

	if (timeFromLastLaserAttack > timeBetweenLaserAttack) {
		setLaserAttack(fireTileController); 
		//cout << "LAser Atack" << endl;
		timeFromLastLaserAttack = sf::Time::Zero;
	}
		
} 

//laser ATTACK 
void enemyBOSS::setLaserAttack(fireTilleController& fireTileController) {
	fireTileController.AddLaserAttack(rect.getPosition(), fire_TileNODE::laserAttack);
}

void enemyBOSS::updateBossPosition(sf::Vector2f playerPosition, sf::Time deltaTime) {
	fastOfTracking = 1.1;
	sf::Vector2f move; 
	float x_pos;
	move = playerPosition - rect.getPosition();  
	x_pos = (move.x - rect.getSize().x/2)*deltaTime.asSeconds() * fastOfTracking;
	move = sf::Vector2f(x_pos, 0);
	move += rect.getPosition();
	if (m_stateOfObject == Object_Base_Class::Active) {
		rect.setPosition(move);
	}
} 

sf::Vector2f enemyBOSS::getPosition() {
	return rect.getPosition();
}
