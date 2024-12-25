#include "DangerZone.h"
#include "Player.h"


DangerZone::DangerZone(const CellPosition& dangerZonePosition) : GameObject(dangerZonePosition)
{
}

void DangerZone::Draw(Output* pOut) const
{
	pOut->DrawDangerZone(position);
}

void DangerZone::Apply(Grid* pGrid, Player* pPlayer)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a danger zone. Click to continue ..." and wait mouse click

	int x, y;
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You have reached a danger zone. Click to continue ...");
	Input* pIn = pGrid->GetInput();
	pIn->GetPointClicked(x, y);

	// 2- Apply the danger zone's effect by reducing the health of the player by 1 

	int h = pGrid->GetCurrentPlayer()->GetHealth();

	pGrid->GetCurrentPlayer()->SetHealth(h - 1);


	// 3- Update the players info which is displayed (check Grid class and decide which function to use)
	string info = "P" + to_string(pGrid->GetCurrentPlayer()->GetplayerNum());

	pGrid->GetCurrentPlayer()->AppendPlayerInfo(info);
	pOut->PrintPlayersInfo(info);

}

void DangerZone::Save(ofstream& outfile, int Count, int* Locations_1, int* Locations_2)
{
	outfile << Count << endl;
	for (int i = 0; i < Count; i++)
	{
		outfile << Locations_1[i] << endl;
	}
}

DangerZone::~DangerZone()
{
}
