#include "RebootAndRepairAction.h"

RebootAndRepairAction::RebootAndRepairAction(ApplicationManager* pApp) : Action(pApp)
{

}

void RebootAndRepairAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Applying Repair Robot: click to refill health to 10");
	int x, y;
	pIn->GetPointClicked(x, y);

	pOut->ClearStatusBar();
}

void RebootAndRepairAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Player* pPlayer = pGrid->GetCurrentPlayer();

	pPlayer->SetHealth(10);
}

RebootAndRepairAction :: ~RebootAndRepairAction()
{

}