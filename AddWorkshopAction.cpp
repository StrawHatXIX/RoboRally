#include "AddWorkshopAction.h"

AddWorkshopAction::AddWorkshopAction(ApplicationManager* pApp) : Action(pApp) {}
void AddWorkshopAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();




	pOut->PrintMessage("New WorkShop: Click on its position...");

	WorkshopPos = pIn->GetCellClicked();


	pOut->ClearStatusBar();
}

void AddWorkshopAction::Execute()
{
	ReadActionParameters();

	Workshop* pWorkshop = new Workshop(WorkshopPos);

	Grid* pGrid = pManager->GetGrid();


	bool added = pGrid->AddObjectToCell(pWorkshop);

	if (!added)
	{
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
}

AddWorkshopAction :: ~AddWorkshopAction()
{

}