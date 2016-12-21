#include "Object_Base_Class.h"



Object_Base_Class::Object_Base_Class()
{  
}


Object_Base_Class::~Object_Base_Class()
{
} 

void Object_Base_Class::render(sf::RenderWindow& window_) {
	window_.draw(sprite);
}

void Object_Base_Class::update(sf::Time deltaTime) {
	sprite.setPosition( rect.getPosition() );
	move(deltaTime);
} 

void Object_Base_Class::move(sf::Time deltaTime) {
	move_vector.x *= deltaTime.asSeconds(); 
	move_vector.y *= deltaTime.asSeconds();
	rect.move(move_vector);
}