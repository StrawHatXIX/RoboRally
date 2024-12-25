#include "CopyGameObjectAction.h"


CopyGameObjectAction::CopyGameObjectAction(ApplicationManager* pApp) : Action(pApp)
{
}
void CopyGameObjectAction::ReadActionParameters()
{
	
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Click on Cell to Copy it to Clipboard ...");
	
}
void CopyGameObjectAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	CellPosition* Pos = &pIn->GetCellClicked();

	pGrid->SetClipboard(pGrid->GetGameObjectGrid(Pos));

	
}
CopyGameObjectAction::~CopyGameObjectAction()
{
}