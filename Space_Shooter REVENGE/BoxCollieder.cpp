#include "BoxCollieder.h"



BoxCollieder::BoxCollieder()
{
}


BoxCollieder::~BoxCollieder()
{
}

void BoxCollieder::DetectCollision(Player *player, vector<StoneNode> *stoneVector) {

	//bool destroyFireTile;
	/*for (std::vector<fire_Tile>::iterator it = (*player).fireTileVector_.begin(); it != (*player).fireTileVector_.end(); ) {
		destroyFireTile = false;
		for (std::vector<StoneNode>::iterator it2 = (*stone).begin(); it2 != (*stone).end(); ) {
			if ((*it).rect.getGlobalBounds().intersects((*it2).rect.getGlobalBounds())) {
				it2 = (*stone).erase(it2);
				destroyFireTile = true;
				cout << "******ColisonDETECTED!*******\n";
			}
			else it2++;
		}

		if (destroyFireTile) {
			it = (*player).fireTileVector_.erase(it);
			;
		}
		else {
			it++;
		}
	}*/

	for (std::vector<StoneNode>::iterator it = (*stoneVector).begin(); it != (*stoneVector).end(); it++) {
		if ((*player).rect.getGlobalBounds().intersects((*it).rect.getGlobalBounds()) && (*it).m_stateOfObject == Object_Base_Class::Active) {
			cout << "Player oberwa³ !" << endl;
			//(*it).m_stateOfObject = Object_Base_Class::Dead; 
			(*it).m_stateOfObject = Object_Base_Class::toErase;

			(*player).hp -= (*it).Damage;
			cout << "hp: " << (*player).hp << endl;
			musicController.play_playerDamadge();
		}
		else if ((*player).rect.getGlobalBounds().intersects((*it).rect.getGlobalBounds()) && (*it).m_stateOfObject == Object_Base_Class::Dead) {
			(*player).score += (*it).scoreAmount;
			(*it).m_stateOfObject = Object_Base_Class::toErase; 
			cout << "score: " << (*player).score << endl; 
			musicController.play_collectCoins();
		}
		else {
			for (std::vector<fire_Tile>::iterator it2 = (*player).fireTileVector_.begin(); it2 != (*player).fireTileVector_.end(); it2++) {
				if ((*it2).rect.getGlobalBounds().intersects((*it).rect.getGlobalBounds()) && (*it).m_stateOfObject == Object_Base_Class::Active ) {
					cout << "Pocisk trafi³ " << endl;
					(*it).m_stateOfObject = Object_Base_Class::Dead;
					(*it2).m_stateOfObject = Object_Base_Class::toErase;
					
					(*it).movementSpeed = 30.f;
					(*it).rect.setRotation(0);
					(*it).m_rotationIncrement = .0f;
					//zmiana tekstury i zmiana rozmiaru rect
					(*it).rect.setSize(sf::Vector2f(16, 20));
					(*it).sprite.setTexture((*it).m_textureDead);  

					musicController.play_destroy();
				
				}
				
			}
		}
	}

	GarbagCollector(&(*player).fireTileVector_, &(*stoneVector));
}

void BoxCollieder::GarbagCollector(vector<fire_Tile> *fireTileVector, vector<StoneNode> *stoneVector) {
	for (std::vector<StoneNode>::iterator it = (*stoneVector).begin(); it != (*stoneVector).end();) {
		if ((*it).m_stateOfObject == Object_Base_Class::toErase) {
			it = (*stoneVector).erase(it);
		}
		else it++;
	} 

	for (std::vector<fire_Tile>::iterator it = (*fireTileVector).begin(); it != (*fireTileVector).end(); ) {
		if ((*it).m_stateOfObject == Object_Base_Class::toErase) {
			it = (*fireTileVector).erase(it);
		} 
		else it++;
	}
}