#include "DeleteGameObjectAction.h"
DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) : Action(pApp)
{
}
void DeleteGameObjectAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Click on Cell to Clear it ...");

}
void DeleteGameObjectAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	CellPosition Pos = pIn->GetCellClicked();

	pGrid->RemoveObjectFromCell(Pos);
	pOut->DrawCell(Pos);
	pOut->ClearStatusBar();
}
DeleteGameObjectAction::~DeleteGameObjectAction()
{
}