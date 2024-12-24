#include "AddCommandAction.h"

AddCommandAction::AddCommandAction(ApplicationManager* pApp, Command command) : Action(pApp)
{
	this->command = command;
}

void AddCommandAction::ReadActionParameters()
{

}




void AddCommandAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	Player* pPlayer = pGrid->GetCurrentPlayer();

	bool saved = pPlayer->SetSavedCommands(command);

	if (!saved)
	{
		pOut->PrintMessage("Maximum number of saved commands reached");
	}
}

AddCommandAction :: ~AddCommandAction() {}