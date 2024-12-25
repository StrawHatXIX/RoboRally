#pragma once
#include "Action.h"
class ExitAction :
    public Action
{
	

public:

	ExitAction(ApplicationManager* pApp);
	virtual void ReadActionParameters() ; // Reads parameters required for action to execute 
	// (code depends on action type so virtual)

	virtual void Execute() ;  // Executes action (code depends on action type so virtual)

	virtual ~ExitAction();  // Virtual Destructor
};

