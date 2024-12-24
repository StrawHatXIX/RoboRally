#include "AddRotatingGearAction.h"

AddRotatingGearAction::AddRotatingGearAction(ApplicationManager* pApp) :Action(pApp) {}


void AddRotatingGearAction::ReadActionParameters()
{
	///TODO (Done.S): Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read the gearPos
	pOut->PrintMessage("New Rotating Gear: Click on its position...");
	gearPos = pIn->GetCellClicked();

	// 4- Make the needed validations on the read parameters (I dont know more)

	// 3- Read whether the direction will be clockwise or not
	//need to think for more (Done.S)
	pOut->PrintMessage("Choose rotation direction (default is Clockwise) ; (1) ClockWise (2) CounterClockWise : ");
	int choice = pIn->GetInteger(pOut);
	if (choice == 2)
	{
		clockwise = false;
	}
	else
	{
		clockwise = true;
	}

	// 5- Clear status bar
	pOut->ClearStatusBar();
}


void AddRotatingGearAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	///TODO (Done.S): Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1-Create a rotating gear object
	// 	// Create a belt object with the parameters read from the user
	RotatingGear* pGear = new RotatingGear(gearPos, clockwise);

	// 2-get a pointer to the Grid from the ApplicationManager
	Grid* pGrid = pManager->GetGrid();


	// 3-Add the rotating object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pGear);


	// 4-Check if the rotating gear was added and print an errror message if flag couldn't be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		delete pGear;
		return;
	}
}

AddRotatingGearAction::~AddRotatingGearAction()
{
}
