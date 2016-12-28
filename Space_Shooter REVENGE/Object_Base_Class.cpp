#include "Object_Base_Class.h"



Object_Base_Class::Object_Base_Class()
{  
	m_stateOfObject = Object_Base_Class::notActive;
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

	//zmiana stanu  

	// w warunkt mu si by�, gdy� inaczej zamiana stanu nast�puje bez niego w obr�bie podanych widelkek wsp�rz�dnych 
	if (rect.getPosition().y > 0 && movementSpeed > 0 && m_stateOfObject == Object_Base_Class::notActive)
		m_stateOfObject = Object_Base_Class::Active;
	if (rect.getPosition().y > 900 && movementSpeed > 0)
		m_stateOfObject = Object_Base_Class::toErase;
	
	//to dotyczy fireTile- usun�� jes�li wyjdzie za obrys widoku
	if (rect.getPosition().y < 0 && movementSpeed < 0)
		m_stateOfObject = Object_Base_Class::toErase;
} 

void Object_Base_Class::move(sf::Time deltaTime) {
	//move_vector.x += deltaTime.asSeconds()*movementSpeed; 
	move_vector.y = deltaTime.asSeconds()*movementSpeed;
	rect.move(move_vector);
} 

