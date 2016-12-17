#pragma once 
#include "Object_Base_Class.h" 

class Player : public Object_Base_Class
{
public:
	Player();
	~Player();

	void Update(float deltaTime); 
	

private : 
	float moveSpeed = 300.f;
	void Movement(float deltaTime);
};


