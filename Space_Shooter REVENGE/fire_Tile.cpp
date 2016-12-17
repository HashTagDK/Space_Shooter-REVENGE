#include "fire_Tile.h"

sf::Texture fire_Tile::textureTile;


fire_Tile::fire_Tile()
{
	rect.setSize(sf::Vector2f(9, 19));
	rect.setPosition(0, 0);
	sprite.setOrigin((rect.getSize().x/2+5), (rect.getSize().y / 2));
	if (!textureTile.loadFromFile("..\\\\sprite\\bullet1.png"))
		cout << "B³¹d przy wczytywaniu textury do byllet1.png!!!!!!"; 
	else {
		sprite.setTexture(textureTile);  
		sprite.setTextureRect(sf::IntRect(0, 0, 9, 19));
		cout << "Stworzona obiekt!";
	}	
}


fire_Tile::~fire_Tile()
{
} 
void fire_Tile::Update(float deltaTime) {
	sprite.setPosition(rect.getPosition());  
	moveForward(deltaTime);
}

void fire_Tile::moveForward(float deltaTime) { 
	rect.move(sf::Vector2f(.0f, movmentSpeed*deltaTime));
}
 
