#include "BoxCollieder.h"



BoxCollieder::BoxCollieder()
{
}


BoxCollieder::~BoxCollieder()
{
}

void BoxCollieder::DetectCollision(Player *player, vector<StoneNode> *stoneVector, 
	vector<PickUpNode> * pickUps, PickUps * pickUpContoller, fireTilleController *fireTileVector_, 
	vector<enemyShip1> &enemyShipVector, enemyBOSS& boss) {

	//fireTile vs BOSS 
	for (std::vector<fire_TileNODE>::iterator it2 = (*fireTileVector_).fireTileVector.begin();
		it2 != (*fireTileVector_).fireTileVector.end(); it2++) {
		if ( boss.rect.getGlobalBounds().intersects((*it2).rect.getGlobalBounds()) && (*it2).getTypeOfFireTile() == fire_TileNODE::playerFireTile ) {
			boss.decrementHP((*it2).Damage);
			(*it2).m_stateOfObject = Object_Base_Class::toErase; 

			(*pickUpContoller).incrementCounterOfKilledEnemy();
			// adding pick up
			(*pickUpContoller).AddPickUp((*it2).rect.getPosition());
			musicController.play_destroy(); 

			if (boss.getHP() <= 0)
				boss.m_stateOfObject = Object_Base_Class::toErase;
		}
	}
	// stone vector-----------------------------------------------------------------------------------------------------------------------------
	for (std::vector<StoneNode>::iterator it = (*stoneVector).begin(); it != (*stoneVector).end(); it++) {
		if ((*player).rect.getGlobalBounds().intersects((*it).rect.getGlobalBounds()) && (*it).m_stateOfObject == Object_Base_Class::Active) {
			cout << "Player oberwa³ !" << endl; 
			(*it).m_stateOfObject = Object_Base_Class::toErase;

			(*player).hp -= (*it).Damage;
			cout << "hp: " << (*player).hp << endl;
			musicController.play_playerDamadge();
		}
		//uderzenie fireTile PLAYER
		else {
			for (std::vector<fire_TileNODE>::iterator it2 = (*fireTileVector_).fireTileVector.begin(); 
					it2 != (*fireTileVector_).fireTileVector.end(); it2++) {
				//--------PLAYER-----------------------------------------------
				if ((*it2).rect.getGlobalBounds().intersects((*it).rect.getGlobalBounds()) && 
					(*it).m_stateOfObject == Object_Base_Class::Active && 
					(*it2).getTypeOfFireTile()==fire_TileNODE::playerFireTile ) 
				{
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

	//enemyVector-------------------------------------------------------------------------------------------------------------------------------------
	if ((*player).rect.getGlobalBounds().intersects(boss.rect.getGlobalBounds()) && boss.m_stateOfObject == Object_Base_Class::Active) {
		(*player).hp = 0;
	}
	for (vector<enemyShip1>::iterator it = enemyShipVector.begin(); it != enemyShipVector.end(); it++) {
		if ((*player).rect.getGlobalBounds().intersects((*it).rect.getGlobalBounds()) && (*it).m_stateOfObject == Object_Base_Class::Active) {
			cout << "Player oberwa³ !" << endl;
			(*it).m_stateOfObject = Object_Base_Class::toErase;
			(*player).hp -= (*it).Damage;
			cout << "hp: " << (*player).hp << endl;
			musicController.play_playerDamadge();
		}
		//fireTile playera kolizje z przeciwnikami 
		for (std::vector<fire_TileNODE>::iterator it2 = (*fireTileVector_).fireTileVector.begin(); it2 != (*fireTileVector_).fireTileVector.end(); it2++) {
			if ((*it2).rect.getGlobalBounds().intersects((*it).rect.getGlobalBounds()) 
				&& (*it).m_stateOfObject == Object_Base_Class::Active 
				&& (*it2).getTypeOfFireTile() == fire_TileNODE::playerFireTile) {
				cout << "Pocisk trafi³ " << endl;
				
				(*it2).m_stateOfObject = Object_Base_Class::toErase;
				//odejmi damage od hp 
				(*it).decrementHP((*it2).Damage); 
				if ((*it).getHP() <= 0) {
					(*it).m_stateOfObject = Object_Base_Class::toErase;
					cout << "!!!!!!!!!!!!!!!--DEAD BOSSS--!!!!!!!!!!!!";
				}
				
				(*pickUpContoller).incrementCounterOfKilledEnemy();
				// adding pick up
				(*pickUpContoller).AddPickUp((*it).rect.getPosition());
				musicController.play_destroy();
			} 
			

		}
	} 
	// fire tile enemy 
	for (std::vector<fire_TileNODE>::iterator it2 = (*fireTileVector_).fireTileVector.begin(); it2 != (*fireTileVector_).fireTileVector.end(); it2++) {
		//ENEMY fireTILE----------------------------------------------
		//to bd tylko raz deklarowane bo jest wspólny vektor dla fireTile przeciwników i player 
		if ((*it2).rect.getGlobalBounds().intersects((*player).rect.getGlobalBounds()) && (*it2).getTypeOfFireTile() == fire_TileNODE::enemyFiretile) {
			cout << "***Pocisk trafi³ playera****" << endl;
			(*it2).m_stateOfObject = Object_Base_Class::toErase;

			musicController.play_playerDamadge();
			(*player).hp -= (*it2).Damage;
		}
	}
	// pick ups---------------------------------------------------------------------------------------------------------------------------------------
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

			if ((*it).isWeaponAdd() && (*player).getTilePerSoecon() > 0.25 ) {
				//dopisaæ coœ do tego weapon
				(*player).setTilesPerSecond( (*it).getScore() );
				
				cout << "Weapn UP!!!!!!!!";
			} 
			if ((*it).isSpeedUp() && (*player).movementSpeed < 450.f) {
				(*player).movementSpeed += (*it).getScore(); 
				cout << "SpeedUP!!!!!!!!!!!!!!";
			}
				
		}
	}

	GarbagCollector(&(*fireTileVector_).fireTileVector, &(*stoneVector), &(*pickUps), enemyShipVector, &boss);
}

void BoxCollieder::GarbagCollector(vector<fire_TileNODE> *fireTileVector, vector<StoneNode> *stoneVector, 
	vector<PickUpNode> *pickUp, vector<enemyShip1> &enemyShipVector,
	enemyBOSS* boss) 
{
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

	for (vector<enemyShip1>::iterator it = enemyShipVector.begin(); it != enemyShipVector.end(); ) {
		if ((*it).m_stateOfObject == Object_Base_Class::toErase || (*it).rect.getPosition().y > 900.f) {
			it = enemyShipVector.erase(it); 
			cout << "\n ********************Ereasing!***************";
		} 			
		else
			it++;
	} 
	// usuniêcie bosa!
	if ((*boss).m_stateOfObject == Object_Base_Class::toErase) {
		(*boss).rect.setPosition(sf::Vector2f(0, 1200));
	}
	
}