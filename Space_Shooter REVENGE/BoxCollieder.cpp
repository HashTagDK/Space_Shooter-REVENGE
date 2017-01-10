#include "BoxCollieder.h"



BoxCollieder::BoxCollieder()
{
}


BoxCollieder::~BoxCollieder()
{
}

void BoxCollieder::DetectCollision(Player *player, vector<StoneNode> *stoneVector, vector<PickUpNode> * pickUps, PickUps * pickUpContoller, fireTilleController *fireTileVector_) {


	for (std::vector<StoneNode>::iterator it = (*stoneVector).begin(); it != (*stoneVector).end(); it++) {
		if ((*player).rect.getGlobalBounds().intersects((*it).rect.getGlobalBounds()) && (*it).m_stateOfObject == Object_Base_Class::Active) {
			cout << "Player oberwa³ !" << endl; 
			(*it).m_stateOfObject = Object_Base_Class::toErase;

			(*player).hp -= (*it).Damage;
			cout << "hp: " << (*player).hp << endl;
			musicController.play_playerDamadge();
		}
		//uderzenie fireTile
		else {
			for (std::vector<fire_TileNODE>::iterator it2 = (*fireTileVector_).fireTileVector.begin(); it2 != (*fireTileVector_).fireTileVector.end(); it2++) {
				if ((*it2).rect.getGlobalBounds().intersects((*it).rect.getGlobalBounds()) && (*it).m_stateOfObject == Object_Base_Class::Active ) {
					cout << "Pocisk trafi³ " << endl;
					(*it).m_stateOfObject = Object_Base_Class::toErase;
					(*it2).m_stateOfObject = Object_Base_Class::toErase;
					
					(*pickUpContoller).incrementCounterOfKilledEnemy();
					// adding pick up
					(*pickUpContoller).AddPickUp( (*it).rect.getPosition() );
					musicController.play_destroy();
				
				}
				
			}
		}
	}
	// pick ups
	for (std::vector<PickUpNode>::iterator it = (*pickUps).begin(); it != (*pickUps).end(); it++) {
		if ((*player).rect.getGlobalBounds().intersects((*it).rect.getGlobalBounds())) {
			(*it).m_stateOfObject = Object_Base_Class::toErase;
			cout << "score: " << (*player).score << endl;
			musicController.play_collectCoins();
			
			if ((*it).isCoin()) {
				cout << "Colide with coin" << (*it).getScore() << endl;
				(*player).score += (*it).getScore();
			}
				//
				
			if ((*it).isHP()) {
				cout << "HP UP" << endl;
				(*player).hp += (*it).getScore();
				if ((*player).hp > 100) (*player).hp = 100;
			}

			if ((*it).isWeaponAdd()) {
				//dopisaæ coœ do tego weapon
				(*player).setTilesPerSecond( (*it).getScore() );
				
				cout << "Weapn UP!!!!!!!!";
			} 
			if ((*it).isSpeedUp()) {
				(*player).movementSpeed += (*it).getScore(); 
				cout << "SpeedUP!!!!!!!!!!!!!!";
			}
				
		}
	}

	GarbagCollector(&(*fireTileVector_).fireTileVector, &(*stoneVector), &(*pickUps));
}

void BoxCollieder::GarbagCollector(vector<fire_TileNODE> *fireTileVector, vector<StoneNode> *stoneVector, vector<PickUpNode> *pickUp) {
	for (std::vector<StoneNode>::iterator it = (*stoneVector).begin(); it != (*stoneVector).end();) {
		if ((*it).m_stateOfObject == Object_Base_Class::toErase || (*it).rect.getPosition().y  > 830.f) {
			it = (*stoneVector).erase(it);
		}
		else it++;
	} 

	for (std::vector<fire_TileNODE>::iterator it = (*fireTileVector).begin(); it != (*fireTileVector).end(); ) {
		if ((*it).m_stateOfObject == Object_Base_Class::toErase || (*it).rect.getPosition().y  < -20.f || (*it).rect.getPosition().y  > 820.f) {
			it = (*fireTileVector).erase(it);
		} 
		else it++;
	} 

	for (std::vector<PickUpNode>::iterator it = (*pickUp).begin(); it != (*pickUp).end(); ) {
		if ((*it).m_stateOfObject == Object_Base_Class::toErase || (*it).rect.getPosition().y > 830.f)
			it = (*pickUp).erase(it); 
		else it++;
	}
}