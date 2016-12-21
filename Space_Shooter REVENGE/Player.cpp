#include "Player.h"



Player::Player()
{
	move_vector = sf::Vector2f(0, 0);
	movementSpeed = 1000.f;
	rect.setSize(sf::Vector2f(45, 45)); 
	rect.setPosition(300, 300); 
	sprite.setOrigin((rect.getSize().x / 2), (rect.getSize().y / 2));
	if (!texture.loadFromFile("..\\\\sprite\\palyer_lvl1.png"))
		cout << "B³a¹d przy wczytywnaiu tekstury"; 
	else {
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(94, 0, 45, 45)); 
		
	}
	
}


Player::~Player()
{
	cout << "Delete Player\n";
} 
// zapisujemy do wektora w krór¹ stron ma siê poruszyæ player
void Player::handleInput() {
	sprite.setTextureRect(sf::IntRect(94, 0, 45, 45));
	
	//obs³uga ruchu
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		move_vector.y = -movementSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		move_vector.y = movementSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		move_vector.x = movementSpeed;
		sprite.setTextureRect(sf::IntRect(188, 0, 45, 45));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		move_vector.x = -movementSpeed;
		sprite.setTextureRect(sf::IntRect(0, 0, 45, 45));
	} 

	//obs³uga przycisków ataku
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
		cout << "J pressed\n";
		//fireTileVector_.push_back(fireSingle);
		fireTileVector_.emplace_back();
		(fireTileVector_.back()).rect.setPosition(this->rect.getPosition());
	}
}  

//tutaj wystêpuje maskowanie funckji update dziedziczonej z Object_Base_Class !!!!!!
void Player::update(sf::Time deltaTime) {
	Object_Base_Class::update(deltaTime); 
	for (std::vector<fire_Tile>::iterator it = fireTileVector_.begin(); it != fireTileVector_.end(); it++) {
		(*it).update(deltaTime);
	}
}

//maskowanie funckji dziedziczonej render() 
void Player::render(sf::RenderWindow& window) {
	Object_Base_Class::render(window); 

	for (std::vector<fire_Tile>::iterator it = fireTileVector_.begin(); it != fireTileVector_.end(); it++) {
		(*it).render(window);
	}
}
