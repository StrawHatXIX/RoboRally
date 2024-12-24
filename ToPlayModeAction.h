#pragma once
#include "Action.h"
class ToPlayModeAction :
	public Action
{
	// [Action Parameters]
public:

	ToPlayModeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads action parameters 
	virtual void Execute(); // Changes to Play Mode
	~ToPlayModeAction();
};

