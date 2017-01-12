#include "fire_Tile.h"



fire_TileNODE::fire_TileNODE(typeOFFireTile TYPE) :
	m_ptypeFire(TYPE)
{
	if (m_ptypeFire == laserAttack) {
		movementSpeed = 0;
		rect.setSize(sf::Vector2f(20, 60));
		//sprite.setOrigin((rect.getSize().x / 2 + 5), (rect.getSize().y / 2));

		if (!textureTile.loadFromFile("..\\\\sprite\\laser.png"))
			cout << "B³¹d przy wczytywaniu textury do laser.png!!!!!!";
		else {
			sprite.setTexture(textureTile);
			sprite.setTextureRect(sf::IntRect(0, 0, 20, 60));
			cout << "Stworzona obiekt! laseRRR";
		} 

		lifeTimeLaser = sf::seconds(4.f);
		laserBoost = 1.f;
	}

	else if (m_ptypeFire == playerFireTile || m_ptypeFire == enemyFiretile) {
		rect.setSize(sf::Vector2f(9, 20));
		sprite.setOrigin((rect.getSize().x / 2 + 5), (rect.getSize().y / 2));

		if (!textureTile.loadFromFile("..\\\\sprite\\bullet1.png"))
			cout << "B³¹d przy wczytywaniu textury do byllet1.png!!!!!!";
		else {
			sprite.setTexture(textureTile);
			sprite.setTextureRect(sf::IntRect(0, 0, 9, 19));
			cout << "Stworzona obiekt!";
		}
	}
		

		if (m_ptypeFire == playerFireTile) {
			movementSpeed = -500.f;
		}
		else if (m_ptypeFire == enemyFiretile) {
			movementSpeed = 200.f;
		}
	
	

	
	
	move_vector = sf::Vector2f(0, 0);
	Damage = 25;
}

/*fire_Tile::fire_Tile(const fire_Tile& fireCopy) {
	this->rect = fireCopy.rect;
	this->sprite = fireCopy.sprite; 
	this->texture = fireCopy.texture;
	this->movementSpeed = fireCopy.movementSpeed; 
	this->move_vector = fireCopy.move_vector;
	this->text = fireCopy.text;
}*/


fire_TileNODE::~fire_TileNODE()
{
	//cout << " -DELETE_OBJECT<FireTILE>- \n"; 
	/*animation*/
	/*rect.setSize(sf::Vector2f(31, 35));
	sprite.setOrigin((rect.getSize().x / 2 + 5), (rect.getSize().y / 2));
	if (!textureTile.loadFromFile("..\\\\sprite\\stone_destroy_animation.png"))
		cout << "B³¹d przy wczytywaniu textury do stone_destroy_animation 31 35.png!!!!!!";
	else {
		sprite.setTexture(textureTile);
		for(int i=0; i<7; i++)
			sprite.setTextureRect(sf::IntRect(31*i, 0, 31, 35));
		
	}*/
}   

fire_TileNODE::typeOFFireTile fire_TileNODE::getTypeOfFireTile() {
	return m_ptypeFire;
}

void fire_TileNODE::updateLaser(sf::Time lifeTime, sf::Vector2f bossPosition) {
	sf::Vector2f size; 
	rect.setPosition(bossPosition);
	size = rect.getSize(); 
	size = sf::Vector2f(size.x, size.y*lifeTime.asSeconds()*laserBoost); 
	size += rect.getSize();
	rect.setSize(size); 
	sprite.setScale(size);

}


