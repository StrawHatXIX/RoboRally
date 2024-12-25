#include "Belt.h"
#include "Player.h"
#include "CellPosition.h"
Belt::Belt(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation (Hint fron seif : 7ot IsValid)
}

int Belt::NumCoveredCells()
{
	if (position.HCell() == endCellPos.HCell())//vertical belt
	{
		int temp = position.VCell() - endCellPos.VCell();
		int size = (temp > 0) ? (temp + 1) : (-temp + 1);
		return size;
	}

	if (position.VCell() == endCellPos.VCell())//horizontal belt
	{
		int temp = position.HCell() - endCellPos.HCell();
		int size = (temp > 0) ? (temp + 1) : (-temp + 1);
		return size;
	}
	return 0;
}


int* Belt::CoveredCells()//(Done.S)
{
	if (position.HCell() == endCellPos.HCell())//vertical belt
	{
		int temp = position.VCell() - endCellPos.VCell();
		int size = (temp > 0) ? (temp + 1) : (-temp + 1);
		int* Cells = new int[size];
		for (int i = 0; i < size; i++)
		{
			Cells[i] = position.GetCellNum() + i * 11;
		}
		return Cells;
	}

	if (position.VCell() == endCellPos.VCell())//horizontal belt
	{
		int temp = position.HCell() - endCellPos.HCell();
		int size = (temp > 0) ? (temp + 1) : (-temp + 1);
		int* Cells = new int[size];
		for (int i = 0; i < size; i++)
		{
			Cells[i] = position.GetCellNum() + i;
		}
		return Cells;
	}
	return nullptr;
}


void Belt::Draw(Output* pOut) const
{
	pOut->DrawBelt(position, endCellPos);
}

void Belt::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a belt. Click to continue ..." and wait mouse click

	int x, y;
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You have reached a belt. Click to continue ...");
	Input* pIn = pGrid->GetInput();
	pIn->GetPointClicked(x, y);


	// 2- Apply the belt's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that


	CellPosition endPos = GetEndPosition();

	// Use the UpdatePlayerCell function to move the player to end of belt 

	pGrid->UpdatePlayerCell(pPlayer, endPos);



}
CellPosition Belt::GetEndPosition() const
{
	return endCellPos;
}

void Belt::Save(ofstream& outfile, int Count, int* Locations_1, int* Locations_2)
{
	outfile << Count << endl;
	for (int i = 0; i < Count; i++)
	{
		outfile << Locations_1[i] << " " << Locations_2[i] << endl;
	}
}

GameObject* Belt::Load(const CellPosition& startPos, const CellPosition& endPos, std::ifstream& infile)
{
	// No additional data is needed beyond start and end positions
	return new Belt(startPos, endPos);
}



Belt::~Belt()
{
}
