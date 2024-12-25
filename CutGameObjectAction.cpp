#include "CutGameObjectAction.h"
CutGameObjectAction::CutGameObjectAction(ApplicationManager* pApp) : Action(pApp)
{
}
void CutGameObjectAction::ReadActionParameters()
{
	
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Click on Cell to Cut it...");
	
}
void CutGameObjectAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	CellPosition* Pos = &pIn->GetCellClicked();

	pGrid->SetClipboard(pGrid->GetGameObjectGrid(Pos));
	pGrid->RemoveObjectFromCell(*Pos);

	
}
CutGameObjectAction::~CutGameObjectAction()
{
}