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
	
	
	void Update(float deltaTime);    
	void Update(float deltaTime, float rotationIncrement);
	void Update(sf::Vector2f movement);
private:
	void Movement(float deltaTime); 
	void Movement(sf::Vector2f movement);
protected: 
	float movemntSpeed;
};

