#pragma once 
#include "Object_Base_Class.h" 

class Player : public Object_Base_Class
{
public:
	Player();
	~Player();

	void Update(); 
	void Movement(); 

private : 
	float moveSpeed = 0.1f;
};


