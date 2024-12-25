#pragma once
#include "GameObject.h"

class DangerZone :public GameObject
{
public:
	DangerZone(const CellPosition& dangerZonePosition);
	virtual void Draw(Output* pOut) const; // Draws a danger zone in the cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the danger zone by reducing the robot's health by 1

	virtual void Save(ofstream& outfile, int Count, int* Locations_1, int* Locations_2);

	virtual GameObject* Load(const CellPosition& pos, std::ifstream& infile);


	virtual ~DangerZone();
};

