#pragma once 
#include "Object_Base_Class.h"
class PickUp : public Object_Base_Class
{
public:
	PickUp();
	~PickUp(); 

	bool isCoin();
	bool isHP(); 
	bool isImprovment();
 
	const bool Coin = false; 
	const bool HP = false; 
	const bool Improvment = false;
};

