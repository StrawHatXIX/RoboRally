#include "WaterPit.h"
#include "Player.h"
#include <string>
#include <iostream>
using namespace std;

WaterPit::WaterPit(const CellPosition& waterPitPosition) :GameObject(waterPitPosition)
{
}

void WaterPit::Draw(Output* pOut) const
{
	pOut->DrawWaterPit(position);
}

void WaterPit::Apply(Grid* pGrid, Player* pPlayer)
{
	int x, y;
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message, make sure to edit this message according to which player wins "You drowned in a water pit. Player (0/1) wins !  Click to continue ..." and wait mouse click

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();



	pOut->PrintMessage("You drowned in a water pit. Player (" + to_string(pGrid->GetCurrentPlayer()->GetplayerNum()) + ") wins !   Click to continue ...");
	pIn->GetPointClicked(x, y);
	pGrid->GetCurrentPlayer()->SetHealth(0);

	string info = "P" + to_string(pGrid->GetCurrentPlayer()->GetplayerNum());


	pGrid->GetCurrentPlayer()->AppendPlayerInfo(info);
	pOut->PrintPlayersInfo(info);




	// 2- Apply the water pit's effect by setting the player's health which drowned to zero and ending the game
	// 3- Update the players info which is displayed (check Grid class and decide which function to use)
}

void WaterPit::Save(ofstream& outfile, int Count, int* Locations_1, int* Locations_2)
{
	outfile << Count << endl;
	for (int i = 0; i < Count; i++)
	{
		outfile << Locations_1[i] << endl;
	}
}

WaterPit::~WaterPit()
{
}
