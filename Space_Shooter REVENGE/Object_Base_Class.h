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

private:
	void move(sf::Time deltaTime); 
	
protected: 
	sf::Vector2f move_vector;
};

