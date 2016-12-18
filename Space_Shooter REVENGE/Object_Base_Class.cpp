#include "Object_Base_Class.h"



Object_Base_Class::Object_Base_Class()
{
}


Object_Base_Class::~Object_Base_Class()
{
}

void Object_Base_Class::Update(float deltaTime) {
	sprite.setPosition(rect.getPosition());
	Movement(deltaTime);
	
} 

void Object_Base_Class::Update(float deltatime, float rotationIncrement) {
	sprite.setPosition(rect.getPosition()); 
	Movement(deltatime); 
	sprite.setRotation(sprite.getRotation() + rotationIncrement);
}

void Object_Base_Class::Update(sf::Vector2f movement) {
	sprite.setPosition(rect.getPosition()); 
	Movement(movement);
}
void Object_Base_Class::Movement(float deltaTime) {
	rect.move(sf::Vector2f(.0f, deltaTime*movemntSpeed));
} 

void Object_Base_Class::Movement(sf::Vector2f movement) {
	rect.move(movement);
}