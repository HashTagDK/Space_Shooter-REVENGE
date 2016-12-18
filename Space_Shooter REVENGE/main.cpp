#include <SFML/Graphics.hpp>
#include "Player.h"
#include "fire_Tile.h" 
#include "Stone1.h"
#include <vector>
#include<iostream>
#include"BoxCollieder.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	window.setPosition(sf::Vector2i(300, 300));
	Player player; 

	sf::Clock clock;
	sf::Time TimeSienceLastUpdate = sf::Time::Zero; 
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f); 
	sf::Time TimeSinceLastFire = sf::Time::Zero; 
	float deltaFire = .01f;

	/*--------------FIRE TILE-------------*/ 
	vector<fire_Tile> fire_Tile_Array; 
	vector<fire_Tile>::const_iterator iterator_fire; 

	/*-----------Stone1-------------------*/
	vector<Stone1> kamien;
	kamien.emplace_back(); 
	kamien.front().rect.setPosition(sf::Vector2f(100.f, 10.0f));
	int counter; 

	/*Colisoon*/
	BoxCollieder box1;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		} 
		window.clear();
		TimeSienceLastUpdate += clock.restart();
		while (TimeSienceLastUpdate >= TimePerFrame) { 
			/*kamien test*/ 
			
			//box1.DetectCollision(&fire_Tile_Array, &kamien); 
			
			/*test */
			bool destroyFireTile; 
			
			for (std::vector<fire_Tile>::iterator it = fire_Tile_Array.begin(); it != fire_Tile_Array.end(); ) {
				destroyFireTile = false;
				if (!kamien.empty()) {
					
					for (std::vector<Stone1>::iterator it2 = kamien.begin(); it2 != kamien.end(); ) {
						if ((*it).rect.getGlobalBounds().intersects((*it2).rect.getGlobalBounds()))
						{
							destroyFireTile = true;
							cout << "******ColisonDETECTED!*******\n";
							it2 = kamien.erase(it2);
						}

						else it2++;
					}
				}
				
				if (destroyFireTile) {
					it = fire_Tile_Array.erase(it);
				
				}
				else {
					it++;
				}
			} 
			/*-------------------------------------------------------------------------------*/
			/*wyzwalanie fire*/
			TimeSienceLastUpdate -= TimePerFrame; 
			TimeSinceLastFire += TimePerFrame;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && TimeSinceLastFire.asSeconds() >= deltaFire) {
				fire_Tile_Array.emplace_back();
				fire_Tile_Array.back().rect.setPosition(player.rect.getPosition());
				TimeSinceLastFire = sf::Time::Zero;
				cout << "j"; 
			}	
			/*inkremntacj wystêpuje tylko wprzypadku gdy nie usuwany elemntu. 
			jêsli go usuwamy to funkcja zwraca adres na nastêpny element  */
			for (vector<fire_Tile>::iterator it = fire_Tile_Array.begin(); it != fire_Tile_Array.end();) {
				float positionY = (*it).sprite.getPosition().y;  
			
				if (positionY < -10.f)
					it = fire_Tile_Array.erase(it); 
				else {
					(*it).Update(TimePerFrame.asSeconds()); 
					it++;
				}
				 
			}  

			//update stone
			for (std::vector<Stone1>::iterator it2 = kamien.begin(); it2 != kamien.end(); it2++) {
				(*it2).Update(TimePerFrame.asSeconds(), 1.f);
			}


			
			player.setPosition(TimePerFrame.asSeconds());
		}
		/*Render()*/

		for (vector<fire_Tile>::iterator it = fire_Tile_Array.begin(); it != fire_Tile_Array.end(); it++) {
			window.draw((*it).sprite);
		}
		
		for (vector<Stone1>::iterator it = kamien.begin(); it != kamien.end(); it++) {
			window.draw((*it).sprite);
		} 

		window.draw(player.sprite);
		window.display();
	}

	return 0;
}