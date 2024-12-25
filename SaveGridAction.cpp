#pragma once
#include "Input.h"
#include "Output.h"
#include "SaveGridAction.h"
#include "Grid.h"
#include <iostream>
#include <fstream>  

SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp) {}
void SaveGridAction::ReadActionParameters()
{
	int x, y;

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	pOut->PrintMessage("Saving Current Grid: Please Enter Grid Name When Prompted");
	pIn->GetPointClicked(x, y);

}

void SaveGridAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Enter File Name");
	string filename = pIn->GetSrting(pOut);

	ofstream outfile(filename);
	outfile.open(filename);
	pGrid->SaveAll(outfile, FlagType);
	pGrid->SaveAll(outfile, WaterPitType);
	pGrid->SaveAll(outfile, DangerZoneType);
	pGrid->SaveAll(outfile, BeltType);
	pGrid->SaveAll(outfile, WorkshopType);
	pGrid->SaveAll(outfile, AntennaType);
	pGrid->SaveAll(outfile, RotatingGearType);

	outfile.close();
	pOut->PrintMessage("Grid " + filename + " saved successfully");
}

SaveGridAction :: ~SaveGridAction()
{

}