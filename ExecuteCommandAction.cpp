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

	Player* pPlayer = pGrid->GetCurrentPlayer();

	Command * savedCommands = pPlayer->GetSavedCommands();

	pPlayer->Move(pGrid, savedCommands);
}

ExecuteCommandAction :: ~ExecuteCommandAction() {}