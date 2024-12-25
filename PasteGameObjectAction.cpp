#include "PasteGameObjectAction.h"
#include "GameObject.h"
#include "Flag.h"
#include "WaterPit.h"
#include "DangerZone.h"
#include "Workshop.h"
#include "Antenna.h"
#include "RotatingGear.h"
#include "Belt.h"
PasteGameObjectAction::PasteGameObjectAction(ApplicationManager* pApp) : Action(pApp)
{
}
void PasteGameObjectAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Click on Cell to Paste From Clipboard ...");
}
void PasteGameObjectAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	CellPosition* Pos = &pIn->GetCellClicked(); 

	GameObject* GObject = pGrid->GetClipboard();

	GameObject* NewObject = nullptr;

	if (dynamic_cast<Flag*>(GObject) != nullptr && pGrid->FlagOnGrid() == false)
	{
		NewObject = new Flag(*Pos);  
	} else if (dynamic_cast<WaterPit*>(GObject) != nullptr)
	{ 
		NewObject = new WaterPit(*Pos); 
	} 
	else if (dynamic_cast<DangerZone*>(GObject) != nullptr)
	{ 
		NewObject = new DangerZone(*Pos);  
	}
	else if (dynamic_cast<Belt*>(GObject) != nullptr)
	{ 
		Belt* originalBelt = dynamic_cast<Belt*>(GObject); 
		if (originalBelt != nullptr) 
		{ 
			NewObject = new Belt(*Pos, originalBelt->GetEndPosition()); 
		} 
	} else if (dynamic_cast<Workshop*>(GObject) != nullptr)
	{ 
		NewObject = new Workshop(*Pos);  
	} 
	else if (dynamic_cast<Antenna*>(GObject) != nullptr && pGrid->AntennaOnGrid() == false)
	{ 
		NewObject = new Antenna(*Pos);
	} 
	else if (dynamic_cast<RotatingGear*>(GObject) != nullptr) 
	{
		RotatingGear* originalGear = dynamic_cast<RotatingGear*>(GObject); 
		if (originalGear != nullptr) 
		{ 
			NewObject = new RotatingGear(*Pos, originalGear->GetisClockWise());  
		} 
	} 	if (NewObject != nullptr)
	{
		if (pGrid->AddObjectToCell(NewObject))
		{
			pOut->PrintMessage("Object pasted successfully.");
		}
	}
}
PasteGameObjectAction::~PasteGameObjectAction()
{

}