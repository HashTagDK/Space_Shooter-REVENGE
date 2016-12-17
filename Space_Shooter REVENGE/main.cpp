#include <SFML/Graphics.hpp>
#include "Player.h"
#include "fire_Tile.h"
#include <vector>
#include<iostream>

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
	float deltaFire = .5f;

	/*--------------FIRE TILE-------------*/ 
	vector<fire_Tile> fire_Tile_Array; 
	vector<fire_Tile>::const_iterator iterator_fire;
	
	int counter;

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
			player.Update(TimePerFrame.asSeconds());
		}
		/*Render()*/

		for (vector<fire_Tile>::iterator it = fire_Tile_Array.begin(); it != fire_Tile_Array.end(); it++) {
			window.draw((*it).sprite);
		}

		window.draw(player.sprite);
		window.display();
	}

	return 0;
}