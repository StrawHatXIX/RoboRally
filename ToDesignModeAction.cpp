#include "ToDesignModeAction.h"

ToDesignModeAction::ToDesignModeAction(ApplicationManager* pApp) : Action(pApp)
{
}
void ToDesignModeAction::ReadActionParameters()
{

}
void ToDesignModeAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->ClearCommandsBar();

	pOut->CreateDesignModeToolBar();

	pOut->PrintMessage("Switched to Design Mode");
}
ToDesignModeAction::~ToDesignModeAction()
{
}