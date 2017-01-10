#include "fire_Tile.h"

sf::Texture fire_TileNODE::textureTile;




fire_TileNODE::fire_TileNODE(typeOFFireTile TYPE) :
	typeFire(TYPE)
{
	rect.setSize(sf::Vector2f(9, 19));
	sprite.setOrigin((rect.getSize().x/2+5), (rect.getSize().y / 2));
	
	if (!textureTile.loadFromFile("..\\\\sprite\\bullet1.png"))
		cout << "B³¹d przy wczytywaniu textury do byllet1.png!!!!!!"; 
	else {
		sprite.setTexture(textureTile);  
		sprite.setTextureRect(sf::IntRect(0, 0, 9, 19));
		cout << "Stworzona obiekt!";
	}	

	if (typeFire == playerFireTile) {
		movementSpeed = -500.f;
	}
	else if (typeFire = enemyFiretile) {
		movementSpeed = 200.f;
	}
	
	move_vector = sf::Vector2f(0, 0);
	
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
	return typeFire;
}



