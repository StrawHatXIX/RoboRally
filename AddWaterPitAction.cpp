#include "AddWaterPitAction.h"

AddWaterPitAction::AddWaterPitAction(ApplicationManager* pApp) : Action(pApp) {}


void AddWaterPitAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	pOut->PrintMessage("New WaterPit: Click on its position...");
	WaterPitPos = pIn->GetCellClicked();


	pOut->ClearStatusBar();
}

void AddWaterPitAction::Execute()
{
	ReadActionParameters();

	WaterPit* pWaterPit = new WaterPit(WaterPitPos);

	Grid* pGrid = pManager->GetGrid();


	bool added = pGrid->AddObjectToCell(pWaterPit);

	if (!added)
	{
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}

}

AddWaterPitAction :: ~AddWaterPitAction()
{

}
