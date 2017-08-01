#pragma once 
#include "Object_Base_Class.h"


class fire_TileNODE : public Object_Base_Class
{
public:
	enum typeOFFireTile {
		playerFireTile = 0,
		enemyFiretile, 
		laserAttack
	};
	fire_TileNODE(typeOFFireTile TYPE);
	~fire_TileNODE();  
	typeOFFireTile getTypeOfFireTile(); 
	sf::Time lifeTimeLaser; 
	void updateLaser(sf::Time lifeTime, sf::Vector2f bossPosition);
private:  
	float damadge = .5f;
	 sf::Texture textureTile;
	static int i;
	typeOFFireTile m_ptypeFire; 

	float laserBoost;
};

