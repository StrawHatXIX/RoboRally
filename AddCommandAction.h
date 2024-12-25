#pragma once
#include "Action.h"
#include "Player.h"

class AddCommandAction : public Action
{
protected:

	ApplicationManager* pManager;	// Actions needs ApplicationManager to do their job

public:

	AddCommandAction(ApplicationManager* pApp);  // Constructor

	// ============ Virtual Functions ============

	virtual void ReadActionParameters(); // Reads parameters required for action to execute 
	// (code depends on action type so virtual)

	virtual void Execute();  // Executes action (code depends on action type so virtual)

	virtual ~AddCommandAction();  // Virtual Destructor
};
