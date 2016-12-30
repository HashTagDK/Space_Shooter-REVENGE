#include "pickUp.h"



PickUp::PickUp()
{
}


PickUp::~PickUp()
{
} 

bool PickUp::isCoin() {
	return Coin;
} 

bool PickUp::isHP() {
	return HP;
} 

bool PickUp::isImprovment() {
	return Improvment;
}
