#pragma once
#include "Weapon.h"

class Laser : public Weapon
{
public:
	Laser(int a = 2);
	virtual void apply(Grid* pGrid);
};