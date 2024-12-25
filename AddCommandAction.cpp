#include "AddCommandAction.h"

AddCommandAction::AddCommandAction(ApplicationManager* pApp) : Action(pApp)
{
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

	pGrid->SelectCommand();

	bool saved = pPlayer->SetSavedCommands(pGrid->SelectCommand());

	if (!saved)
	{
		pOut->PrintMessage("Maximum number of saved commands reached");
	}
}

AddCommandAction :: ~AddCommandAction() {}