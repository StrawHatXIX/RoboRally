#pragma once
#include "GameObject.h"

class Antenna :public GameObject
{
public:
	Antenna(const CellPosition& antennaPosition);
	virtual void Draw(Output* pOut) const; // Draws an antenna

	int Antenna::DetermineCurrentPlayer(CellPosition player1Pos, CellPosition player2Pos) const;

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the antenna by deciding the players turns



	virtual ~Antenna();
};

