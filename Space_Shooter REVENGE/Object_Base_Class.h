#pragma once 

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <cmath>
//#include "ResourcePath.hpp"
#include <cstdlib>
#include <functional>
//#include <tgmath.h>
#include <deque>
#include <list>
#include <vector>
//#include <unistd.h>
using namespace std;

class Object_Base_Class
{
public:
	Object_Base_Class();
	~Object_Base_Class(); 
 
	sf::RectangleShape rect; 
	sf::Sprite sprite;
	sf::Text text;
	sf::Texture texture; 
	
	void update(sf::Time deltaTime);     
	void render(sf::RenderWindow& window_); 
	float movementSpeed;

	/* 4 stany w kt�rych mo�e zlale�� si� objekt*/
	enum stateOfObject {
		notActive, //stworzony obiekt, poza polem widoku gracza, nie mo�e wchodiz� w kolizje, position.y < 0 
		Active, //obiekt mo�e wchodiz� w kolizje position.y > 0 && position.t < 800
		Dead,	// obiket zosta� zniszczony przez player, tutaj mo�e pojawi� si� jaki� bonus, obiekt r�wnie� si� porusza ale wolniej albo wcake
		toErase // obiekt do skasowania - position.y > 800 || obiekt=przeciwnik->bonus zebrany przez player
	};

	stateOfObject m_stateOfObject;
	float Damage;
protected:
	void move(sf::Time deltaTime); 
	sf::Vector2f move_vector; 
	
};

