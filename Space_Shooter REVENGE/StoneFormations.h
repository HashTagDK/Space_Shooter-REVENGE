#pragma once 
#include "StoneNode.h"  
#include <stdlib.h> 
#include<vector>
class StoneFormations
{
public:
	StoneFormations();
	~StoneFormations(); 
	enum levelDificulty {
		veryEasy = 1,
		Easy = 2,
		Normal = 3,
		Medium = 4,
		Hard = 6,
		Brutal = 8,
		Extrem = 11
	};
	void SetArrowFormation();
	void SetSingleStone(sf::Vector2f position); 
	void SetBigTriangle(); 
	void SetRandom(levelDificulty level);

	void update(sf::Time deltaTime); 
	void render(sf::RenderWindow &window_);

	
	
private: 
	vector<StoneNode> m_stoneVector;
	StoneNode stoneExample;

};

