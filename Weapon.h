#pragma once
#include "Grid.h"
#include "Player.h"

class Weapon
{
protected:
	int damage;

public:
	Weapon(int a);
	 
	virtual void apply(Grid* pGrid) = 0;
};