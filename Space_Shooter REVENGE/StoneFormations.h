#pragma once 
#include "StoneNode.h"  
#include <stdlib.h> 
#include<vector>
class StoneFormations
{
public:
	StoneFormations();
	~StoneFormations(); 

	void SetTriangleFormation();
	void SetSingleStone(sf::Vector2f position); 
	void update(sf::Time deltaTime); 
	void render(sf::RenderWindow &window_);
private: 
	vector<StoneNode> m_stoneVector;
	StoneNode stoneExample;

};

