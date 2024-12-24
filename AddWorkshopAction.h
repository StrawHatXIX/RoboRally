#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Workshop.h"

class AddWorkshopAction :public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]
	CellPosition WorkshopPos; // 1- The position of the WorkShop
public:

	AddWorkshopAction(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads action parameters 

	virtual void Execute(); // Creates a new Workshop Object 
	// then Sets this WorkShop object to the GameObject Pointer of its Cell

	~AddWorkshopAction();
};