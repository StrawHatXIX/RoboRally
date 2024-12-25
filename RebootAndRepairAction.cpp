#include "RebootAndRepairAction.h"

RebootAndRepairAction::RebootAndRepairAction(ApplicationManager* pApp) : Action(pApp)
{

}

void RebootAndRepairAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	Player * pPlayer = pGrid->GetCurrentPlayer();

	pOut->PrintMessage("Applying Repair Robot: click to refill health to 10");
	int x, y;
	pIn->GetPointClicked(x, y);

	pOut->ClearStatusBar();
}

void RebootAndRepairAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	int PlayerNum = pGrid->GetCurrPlayer(); //getter for current player's number
	Player* pPlayer = pGrid->GetCurrentPlayer(); //getter for current player's pointer

	pPlayer->SetHealth(10);


	if (PlayerNum == 0)
	{
		pGrid->SetCurrentPlayer(1);
	}
	else
	{
		pGrid->SetCurrentPlayer(0);
	}
}

RebootAndRepairAction :: ~RebootAndRepairAction()
{

}