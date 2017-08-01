#include "Player.h"



Player::Player()
{
	hp = 100.f;
	score = 0;

	move_vector = sf::Vector2f(0, 0);
	movementSpeed = 250.f;
	rect.setSize(sf::Vector2f(45, 45)); 
	rect.setPosition(240, 750); 
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && rect.getPosition().y > 150 ) {
		this->move_vector.y = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && rect.getPosition().y < 770) {
		this->move_vector.y = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && rect.getPosition().x < 480) {
		this->move_vector.x = 1;
		sprite.setTextureRect(sf::IntRect(188, 0, 45, 45));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && rect.getPosition().x > 10 ) {
		this->move_vector.x = -1;
		sprite.setTextureRect(sf::IntRect(0, 0, 45, 45));
	}  

	

	//obs³uga przycisków ataku 
	playerShoot = false;
	timeSienceLastFire += clock.restart();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && timeSienceLastFire > tilesPerSecond) {
		timeSienceLastFire = sf::Time::Zero;
		cout << "J pressed\n";
		/*fireTileVector_.emplace_back();
		(fireTileVector_.back()).rect.setPosition(this->rect.getPosition()); */ 
		// wstawiæ coœ co wywo³a w game screen addFireTile 
		playerShoot = true;
		musicController.play_fireTileShoot();
	}
}  

bool Player::isEnableShoot() {
	return playerShoot;
}

//tutaj wystêpuje maskowanie funckji update dziedziczonej z Object_Base_Class !!!!!!
void Player::update(sf::Time deltaTime) { 
	
	updatePlayer(deltaTime);
	/*for (std::vector<fire_TileNODE>::iterator it = fireTileVector_.begin(); it != fireTileVector_.end(); it++) {
		(*it).update(deltaTime);
	}*/ 
}

//maskowanie funckji dziedziczonej render() 
void Player::render(sf::RenderWindow& window) {
	Object_Base_Class::render(window); 

	/*for (std::vector<fire_TileNODE>::iterator it = fireTileVector_.begin(); it != fireTileVector_.end(); it++) {
		(*it).render(window);
	}*/ 
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

void Player::setTilesPerSecond(float decrement) {
	tilesPerSecond = sf::seconds(tilesPerSecond.asSeconds() - decrement);
	cout << "tiles per seconds : " << tilesPerSecond.asSeconds() << endl;
} 

float Player::getTilePerSoecon() {
	return tilesPerSecond.asSeconds();
}




