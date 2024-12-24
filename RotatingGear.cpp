#include "RotatingGear.h"
#include "Player.h"



RotatingGear::RotatingGear(const CellPosition& gearposition, bool clockwise) : GameObject(gearposition)
{
	isClockWise = clockwise;
}

void RotatingGear::Draw(Output* pOut) const
{
	pOut->DrawRotatingGear(position, isClockWise);
}

void RotatingGear::setrevDirection()
{
	if (GetisClockWise() == true)
	{
		isClockWise = false;
	}
	else
	{
		isClockWise = true;
	}
}

void RotatingGear::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Print a message and change the message according to direction of rotation 
	// "You have reached a rotating gear, you will rotate (clockwise/ anti-clockwise) Click to continue ..." and wait mouse click

	int x, y;
	Output* pOut = pGrid->GetOutput();
	string directionMessage;
	if (GetisClockWise() == true)
	{
		directionMessage = "clockwise";
	}
	else { directionMessage = "anti-clockwise"; }

	pOut->PrintMessage("You have reached a rotating gear, you will rotate (" + directionMessage + ") Click to continue ...");
	Input* pIn = pGrid->GetInput();
	pIn->GetPointClicked(x, y);


	//2- Apply the roating gear's effect by rotating the player according to the direction

	if (GetisClockWise() == true)
	{
		isClockWise = false;
	}
	else
	{
		isClockWise = true;
	}
}
bool RotatingGear::GetisClockWise() const
{
	return isClockWise;
}



RotatingGear::~RotatingGear()
{
}