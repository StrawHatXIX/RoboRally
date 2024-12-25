#pragma once
#include "Input.h"
#include "Output.h"
#include "LoadGridAction.h"
#include "Grid.h"
#include <iostream>
#include <fstream>  
LoadGridAction::LoadGridAction(ApplicationManager* pApp) : Action(pApp)
{
}
void LoadGridAction::ReadActionParameters()
{
    int x, y;

    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();



    pIn->GetPointClicked(x, y);
}

void LoadGridAction::Execute()
{
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    pOut->PrintMessage("Enter File Name to be Loaded");
    std::string filename = pIn->GetSrting(pOut);

    ifstream infile(filename);

    pGrid->LoadAll(infile, FlagType);
    pGrid->LoadAll(infile, WaterPitType);
    pGrid->LoadAll(infile, DangerZoneType);
    pGrid->LoadAll(infile, BeltType);
    pGrid->LoadAll(infile, WorkshopType);
    pGrid->LoadAll(infile, AntennaType);
    pGrid->LoadAll(infile, RotatingGearType);

    infile.close();
    pOut->PrintMessage("Grid " + filename + " loaded successfully");
}


LoadGridAction::~LoadGridAction()
{
}