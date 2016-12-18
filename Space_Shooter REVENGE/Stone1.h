#pragma once 
#include"Object_Base_Class.h"
class Stone1 : public Object_Base_Class
{
public:
	Stone1();
	~Stone1(); 
  
private: 
	float rotation; 
	float m_rotationIncrement;
};

