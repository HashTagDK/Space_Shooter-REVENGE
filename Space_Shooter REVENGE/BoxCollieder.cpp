#include "BoxCollieder.h"



BoxCollieder::BoxCollieder()
{
}


BoxCollieder::~BoxCollieder()
{
}

void BoxCollieder::DetectCollision(std::vector<fire_Tile> *fireTilleArray, vector<StoneNode> *stone) {
	
	bool destroyFireTile;
	for (std::vector<fire_Tile>::iterator it = (*fireTilleArray).begin(); it != (*fireTilleArray).end(); ) {
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
			it = (*fireTilleArray).erase(it);
			;
		}
		else {
			it++;
		}
	}
}
