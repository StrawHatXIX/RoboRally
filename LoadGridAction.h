#pragma once
#include "Action.h"
class LoadGridAction :
	public Action
{
	// [Action Parameters]
public:

	LoadGridAction(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads action parameters 
	virtual void Execute(); // ReCreates Grid From Saved File
	~LoadGridAction();
};

