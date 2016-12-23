#include "Player.h"



Player::Player()
{
	move_vector = sf::Vector2f(0, 0);
	movementSpeed = 500.f;
	rect.setSize(sf::Vector2f(45, 45)); 
	rect.setPosition(300, 300); 
	sprite.setOrigin((rect.getSize().x / 2), (rect.getSize().y / 2));
	if (!texture.loadFromFile("..\\\\sprite\\palyer_lvl1.png"))
		cout << "B³a¹d przy wczytywnaiu tekstury"; 
	else {
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(94, 0, 45, 45)); 
	} 
	
	timeSienceLastFire = sf::Time::Zero;
	tilesPerSecond = sf::seconds(1.f);
}


Player::~Player()
{
	cout << "Delete Player\n";
} 
// zapisujemy do wektora w krór¹ stron ma siê poruszyæ player
void Player::handleInput() {
	sprite.setTextureRect(sf::IntRect(94, 0, 45, 45));
	this->move_vector = sf::Vector2f(0, 0);
	//obs³uga ruchu
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->move_vector.y = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->move_vector.y = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->move_vector.x = 1;
		sprite.setTextureRect(sf::IntRect(188, 0, 45, 45));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->move_vector.x = -1;
		sprite.setTextureRect(sf::IntRect(0, 0, 45, 45));
	} 

	//obs³uga przycisków ataku
	timeSienceLastFire += clock.restart();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && timeSienceLastFire > tilesPerSecond) {
		timeSienceLastFire = sf::Time::Zero;
		cout << "J pressed\n";
		//fireTileVector_.push_back(fireSingle);
		fireTileVector_.emplace_back();
		(fireTileVector_.back()).rect.setPosition(this->rect.getPosition());
	}
}  

//tutaj wystêpuje maskowanie funckji update dziedziczonej z Object_Base_Class !!!!!!
void Player::update(sf::Time deltaTime) {
	//Object_Base_Class::update(deltaTime);  
	updatePlayer(deltaTime);
	for (std::vector<fire_Tile>::iterator it = fireTileVector_.begin(); it != fireTileVector_.end(); it++) {
		//coœ zeruje move_vecro.y, trzba to znaleŸæ!!!
		//(*it).move_vector.y = (*it).movementSpeed;
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

void Player::move(sf::Time deltaTime) {
	move_vector.x *= deltaTime.asSeconds()*movementSpeed;
	move_vector.y *= deltaTime.asSeconds()*movementSpeed;
	rect.move(move_vector);
}   

void Player::updatePlayer(sf::Time deltaTime) {
	sprite.setPosition(rect.getPosition());
	move(deltaTime);
}



