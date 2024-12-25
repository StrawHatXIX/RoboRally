#include "Flag.h"


Flag::Flag(const CellPosition& flagposition) : GameObject(flagposition)
{

}

void Flag::Draw(Output* pOut) const
{
	pOut->DrawFlag(position);
}

void Flag::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a flag. Click to continue ..." and wait mouse click
	int x, y;
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You have reached the flag.Click to continue ...");
	Input* pIn = pGrid->GetInput();
	pIn->GetPointClicked(x, y);


	// 2- Apply the flag's effect by ending the game
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->SetEndGame(true);
}

void Flag::Save(ofstream& outfile, int Count, int* Locations_1, int* Locations_2)
{
	outfile << Count << endl << Locations_1[Count - 1] << endl;
}

GameObject* Flag::Load(const CellPosition& pos, std::ifstream& infile)
{
	// No additional data is required for a Flag
	return new Flag(pos);
}


Flag::~Flag()
{

}