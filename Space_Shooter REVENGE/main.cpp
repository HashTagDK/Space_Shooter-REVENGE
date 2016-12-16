#include <SFML/Graphics.hpp>
#include "Player.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	window.setPosition(sf::Vector2i(300, 300));
	Player player;

	/*Loading sprite from path*/
	/*sf::Texture texturePlayer;
	if (!texturePlayer.loadFromFile("..\\\sprite\\palyer_lvl1.png"))
		return EXIT_FAILURE;  
	sf::Sprite spritePlayer( texturePlayer ); 
	spritePlayer.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	spritePlayer.setTextureRect(sf::IntRect(94, 0, 45, 45));*/
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		player.Update(); 
		player.Movement(); 


		window.clear();
		window.draw(player.sprite);
		window.display();
	}

	return 0;
}