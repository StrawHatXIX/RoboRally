#include "ExecuteCommandAction.h"

ExecuteCommandAction::ExecuteCommandAction(ApplicationManager* pApp) : Action(pApp) {}

// ============ Virtual Functions ============

void ExecuteCommandAction::ReadActionParameters()
{

}

void ExecuteCommandAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	int PlayerNum = pGrid->GetCurrPlayer(); //getter for current player's number
	Player* pPlayer = pGrid->GetCurrentPlayer();

	Command * savedCommands = pPlayer->GetSavedCommands();

	if (savedCommands)
	{
		pPlayer->Move(pGrid, savedCommands);
		if (PlayerNum == 0)
		{
			pGrid->SetCurrentPlayer(1);
		}
		else
		{
			pGrid->SetCurrentPlayer(0);
		}
	}
}

ExecuteCommandAction :: ~ExecuteCommandAction() {}