#include "AddDangerZoneAction.h"

AddDangerzoneAction::AddDangerzoneAction(ApplicationManager* pApp) : Action(pApp)
{

}

void AddDangerzoneAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	pOut->PrintMessage("New DangerZone: Click on its position...");
	DangerZonePos = pIn->GetCellClicked();


	pOut->ClearStatusBar();
}


void AddDangerzoneAction::Execute()
{
	ReadActionParameters();

	DangerZone* pDangerZone = new DangerZone(DangerZonePos);

	Grid* pGrid = pManager->GetGrid();


	bool added = pGrid->AddObjectToCell(pDangerZone);

	if (!added)
	{

		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
}

AddDangerzoneAction :: ~AddDangerzoneAction()
{

}
