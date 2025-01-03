#pragma once
#include "GameObject.h"

class RotatingGear : public GameObject
{
	bool isClockWise; // if it is true then direction is clockwise, if it is false then direction is anticlockwise
public:
	RotatingGear(const CellPosition& gearposition, bool clockwise); // A constructor for initialization
	virtual void Draw(Output* pOut) const; // Draws a rotating gear in a selected cell
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the flag
	bool GetisClockWise() const; // Getter for the direction
	void setrevDirection();// setter 
	virtual void Save(ofstream& outfile, int Count, int* Locations_1, int* Locations_2);
	/*virtual GameObject* Load(const CellPosition& pos, bool isClockwise, std::ifstream& infile);*/
	virtual ~RotatingGear();
};

