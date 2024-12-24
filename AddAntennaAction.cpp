#include "AddAntennaAction.h"

AddAntennaAction::AddAntennaAction(ApplicationManager* pApp) : Action(pApp)
{

}

void AddAntennaAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	if (pGrid->AntennaOnGrid())
	{
		int x, y; //dummy variables just for giving the user the chance to read the error message until they decide to click anywhere
		pOut->PrintMessage("Maximum Number of Antennas reached, Click anywhere to continue....");
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
		return;
	}

	pOut->PrintMessage("New Antenna: Click on its Start Cell ...");
	AntennaPos = pIn->GetCellClicked();

	///TODO (Done.S): Make the needed validations on the read parameters (I dont know)


	pOut->ClearStatusBar();
}


void AddAntennaAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a belt object with the parameters read from the user
	Antenna* pAntenna = new Antenna(AntennaPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager


	bool added = pGrid->AddObjectToCell(pAntenna);

	// if the GameObject cannot be added
	if (!added && pGrid->FlagOnGrid() == false)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the belt is created and added to the GameObject of its Cell, so we finished executing the AddBeltAction
}


AddAntennaAction:: ~AddAntennaAction()
{

}
