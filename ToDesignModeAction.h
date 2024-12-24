#pragma once
#include "Action.h"
#include "Grid.h"

class ToDesignModeAction :
	public Action
{
	// [Action Parameters]
public:

	ToDesignModeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads action parameters 
	virtual void Execute(); // Changes to Design Mode 
	~ToDesignModeAction();
};

